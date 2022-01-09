#include "spam.hpp"
#include <sys/stat.h>   // stat
#include <dirent.h>
#include <string.h>

std::vector<std::string> libraries_paths = {};
std::vector<std::string> release_libraries_paths = {};
std::vector<std::string> debug_libraries_paths = {};
std::vector<std::string> include_paths = {};
std::string global_options = "";
std::string release_options = "";
std::string debug_options = "";

const char* help[9] = {
    "Usage: make [config=name] [target]",
    "",
    "Configurations:",
	"\tdebug",
	"\trelease",
	"",
    "Targets:",
    "\tall (default)",
	"\tclean",    
};

namespace spam {

void addIncludePath(const char* path_to_library) {
    include_paths.push_back( "-I " + std::string(path_to_library) + ' ' );
}
void addLibraryPath(const char* path_to_library) {
    libraries_paths.push_back(path_to_library);
}
void addDebugLibraryPath(const char* path_to_library) {
    debug_libraries_paths.push_back(path_to_library);
}
void addReleaseLibraryPath(const char* path_to_library) {
    release_libraries_paths.push_back(path_to_library);
}

std::string includeFilesInFolder(const char* folder_files_with_pattern_raw) {
    //printf("start: includeFilesInFolder\n");
    std::string folder;
    std::string files_and_pattern;

    std::string folder_files_with_pattern(folder_files_with_pattern_raw);
    bool isInRootDir = folder_files_with_pattern.find_last_of('/') == std::string::npos;
    // isInRootDir, check if str without '/': 'main.cpp': true, 'src/some_file.cpp': false 
    if(isInRootDir) {
        folder = ".";
        files_and_pattern = folder_files_with_pattern;
    } else {
        folder = folder_files_with_pattern.substr(0, folder_files_with_pattern.find_last_of('/'));
        files_and_pattern = folder_files_with_pattern.substr(folder_files_with_pattern.find_last_of('/') + 1, folder_files_with_pattern.size());
    }
    // modificating pattern from syntactic sugar: *.cpp -> .*.cpp 
    std::string modificated_pattern;
    for(char symbol : files_and_pattern) {
        if(symbol == '*') modificated_pattern += '.';
        modificated_pattern += symbol;
    }
    int match_length;
    // pattern for files in current dir
    //printf("pattern: %s\n", modificated_pattern.c_str());
    re_t pattern = re_compile(modificated_pattern.c_str());
    DIR *dir;
    struct dirent *ent;
    std::string files;
    if(( dir = opendir(folder.c_str())) != NULL ) {
        while ((ent = readdir(dir)) != NULL) {
            if(re_matchp(pattern, ent->d_name, &match_length) != -1) {
                if( strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0 ) {
                    if(!isInRootDir) files += folder + '/';
                    //printf("folder: %s, ent->d_name: %s\n", folder.c_str(), ent->d_name);
                    files += ent->d_name;
                    files += ' ';
                }
                //printf("\nfiles: %s\n", files.c_str());
            }
        }
        closedir(dir);
    } else {
        printf("\"%s\" not a directory. \n", folder.c_str());
        closedir(dir);
        exit(0);
    }
    //printf("end: includeFilesInFolder\n");
    return files;
}

bool isFileExists(const char* name) {
    struct stat buffer;   
    return (stat(name, &buffer) == 0);
}

std::string includeFile(const char *filenameRaw) {
    if(!isFileExists(filenameRaw)) printf("File `%s` doesn't exist!", filenameRaw);
    std::string filename(filenameRaw);
    return filename;
}

}

namespace spam {

Project::Project(std::string _project_name) : name(_project_name) {}
Project::~Project() {} 

void Project::linkLibrary(std::string name) {
    library_names.push_back(name);
}

void Project::setProjectType(int _projectType) {
    projectType = _projectType;
}
int Project::getProjectType() {
    return projectType;
}

void Project::generateFile(int targetOS, spam::Workspace &workspace) {
    FILE *fptr;
    if((fptr = fopen((name + ".mk").c_str(), "w")) != NULL) {
        std::vector<std::string> objs;

        if(targetOS == TargetType::Linux) {
            printf("Generating %s.mk for Linux build, generator 'GNU Make 4.0'...\n", name.c_str());
            sfputs("ifndef verbose");
	            sfputs("\tSILENT = @");
            sfputs("endif");
            sfputs("ifeq ($(config),debug)");
                sfputs("\tOBJS_DIR := obj/Debug");
                sfputs("\tBIN_DIR := bin/Debug");
                sfprintf("\tLIB_PATHS := %s", astd::asString(debug_libraries_paths).c_str());
                sfprintf("\tARGS := %s", debug_options.c_str());
                fputs("\tLIBS := ", fptr);
                for(int i = 0; i < library_names.size(); i++) {
                    bool isSourced = false;
                    for(int j = 0; j < workspace.projects.size(); j++) {
                        if(library_names[i] == workspace.projects[j].name) {
                            isSourced = true;
                            fprintf(fptr, "bin/Debug/%s ", library_names[i].c_str());
                            break;
                        }
                    }
                    if(!isSourced) fprintf(fptr, "-l%s", library_names[i].c_str());
                }
            sfputs("\nelse");
                sfputs("\tOBJS_DIR := obj/Release");
                sfputs("\tBIN_DIR := bin/Release");
                sfprintf("\tINCLUDES := %s", astd::asString(include_paths).c_str());
                fputs("\tOBJS := ", fptr);
                std::vector<std::string> files_parsed = astd::split(files, ' ');
                for(int i = 0; i < files_parsed.size(); ++i) {
                    if(files_parsed[i].find('.') == std::string::npos && !files_parsed[i].empty()) {
                        printf("In %s: file %s hasn't got extension(.cpp, .cxx, .c)! \n", name.c_str(), files_parsed[i].c_str());
                        exit(0);
                    } else if(files_parsed[i].find('.') != std::string::npos && !files_parsed[i].empty()) {
                        std::string rawObj = astd::split(files_parsed[i], '.')[0] + ".o" + ' ';
                        std::string obj;
                        if(rawObj.find_last_of('/') != std::string::npos)
                            obj = "$(OBJS_DIR)/" + rawObj.substr(rawObj.find_last_of('/')+1, rawObj.size());
                        else obj = "$(OBJS_DIR)/" + rawObj;
                        fputs(obj.c_str(), fptr);
                        objs.push_back(obj);
                    } else files_parsed.erase(files_parsed.begin() + i);
                }

                fputs("\n\tLIBS := ", fptr);
                bool isHasGotSourced = false;
                for(int i = 0; i < library_names.size(); ++i) {
                    bool isSourced = false;
                    for(int j = 0; j < workspace.projects.size(); ++j) {
                        if(library_names[i] == workspace.projects[j].name && workspace.projects[i].name != name) {
                            isSourced = true;
                            isHasGotSourced = true;
                            fprintf(fptr, "bin/Release/lib%s.so ", library_names[i].c_str());
                            break;
                        }
                    }
                    if(!isSourced) fprintf(fptr, "-l%s ", library_names[i].c_str());
                }
                fputs("\n\tLIB_PATHS := ", fptr);
                for(int i = 0; i < debug_libraries_paths.size(); ++i) fprintf(fptr, "-L %s ", debug_libraries_paths[i].c_str());
                for(int i = 0; i < libraries_paths.size(); ++i) fprintf(fptr, "-L %s ", libraries_paths[i].c_str());

                fputs("\n\tALL_CPPFLAGS := $(CPP_FLAGS) $(CXX_FLAGS) -MMD -MP $(INCLUDES) ", fptr);
                fputs( (projectType == ProjectType::Library ? "-fPIC " : ""), fptr);
                std::vector<std::string> splittedOptions;
                if(global_options != "") {
                    splittedOptions = astd::split(global_options, ' ');
                }
                if(release_options != "") {
                    std::vector<std::string> splittedReleaseOptions = astd::split(release_options, ' ');
                    splittedOptions.insert(splittedOptions.end(), splittedReleaseOptions.begin(), splittedReleaseOptions.end());
                }
                for(int i = 0; i < splittedOptions.size(); i++) {
                    if(splittedOptions[i] != "") fprintf(fptr, "-%s ", splittedOptions[i].c_str());
                }
                fputs("\n\tALL_LDFLAGS := $(LDFLAGS) $(LIB_PATHS) ", fptr);
                if(projectType == ProjectType::Library) fprintf(fptr, "-shared -Wl,-soname=lib%s.so -s ", name.c_str());
                if(isHasGotSourced)fputs("-Wl,-rpath,'$$ORIGIN' -s", fptr);
            sfputs("\nendif");
            sfputs("\nCXX := g++");

            sfprintf("$(BIN_DIR)/%s%s%s: create_dirs $(OBJS)", 
                    (projectType == ProjectType::Library ? "lib" : ""), 
                    name.c_str(), 
                    (projectType == ProjectType::Library ? ".so" : ""));
            sfputs("\t$(SILENT) $(CXX) $(OBJS) $(ALL_LDFLAGS) $(LIBS) -o $@ ");
            sfputs("");
            sfputs("\n.PHONY: create_dirs clean");
            sfputs("create_dirs:");
	            sfputs("\t$(SILENT) mkdir -p $(OBJS_DIR)");
	            sfputs("\t$(SILENT) mkdir -p $(BIN_DIR)");
            sfputs("clean:");
	            sfputs("\trm -f $(OBJS_DIR)/*");
	            sfputs("\trm -f $(BIN_DIR)/*\n");
        for(int i = 0; i < objs.size(); ++i) {
            sfprintf("%s: %s", objs[i].c_str(), files_parsed[i].c_str());
                sfputs("\t$(SILENT) echo Building $@...");
                sfputs("\t$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o \"$@\" -MF \"$(@:%.o=%.d)\" -c \"$<\" ");
        }
            sfputs("-include $(OBJS:%.o=%.d)");
            
        } else if(targetOS == TargetType::Windows) {

        } else if(targetOS == TargetType::MacOS) {

        } else if(targetOS == TargetType::iOS) {

        } else if(targetOS == TargetType::Android) {

        } else if(targetOS == TargetType::Web) {

        }
    } else {
        printf("Can't create %s.mk!", name.c_str());
        exit(0);
    }
}

std::string Project::getName() {
    return name;
}
}

namespace spam {

Workspace::Workspace(std::string _name) : name(_name) {}
Workspace::~Workspace() {}

void Workspace::addProject(spam::Project &project) {
    projects.push_back(project);
}

void Workspace::generateFile(int targetOS) {
    FILE *fptr;
    if(targetOS == TargetType::Linux && (fptr = fopen(("Makefile"), "w")) != NULL) {
        printf("Note: you can use 'make -j[i]'(when [i] is number of threads) for more fast build\n\n");
        puts("Generating Makefile for Linux build, generator 'GNU Make 4.0'...");
        sfputs("ifndef config");
            sfputs("\tconfig=release");
        sfputs("endif\n");

        sfputs("ifndef verbose");
            sfputs("\tSILENT = @");
        sfputs("endif\n");

        sfputs("ifeq ($(config),debug)");
            sfputs("\tGCONFIG = debug");
        sfputs("else");
            sfputs("\tGCONFIG = release");
        sfputs("endif\n");

        fputs("PROJECTS := ", fptr);
        for(int i = 0; i < projects.size(); i++) fprintf(fptr, "%s ", projects[i].getName().c_str());

        sfputs("\n.PHONY: all help $(PROJECTS)\n");
        sfputs("\nall: $(PROJECTS)\n");
        for(int i = 0; i < projects.size(); i++) {
            sfprintf("%s:", projects[i].getName().c_str());
                sfprintf("\t$(SILENT) echo \"==== Building %s ($(GCONFIG)) ====\"", projects[i].getName().c_str());
                sfprintf("\t$(SILENT) $(MAKE) --no-print-directory -C . -f %s.mk config=$(GCONFIG)", projects[i].getName().c_str());
        }
        fputs("\nclean:\n", fptr);
        for(int i = 0; i < projects.size(); i++) 
            sfprintf("\t$(SILENT) $(MAKE) --no-print-directory -C . -f %s.mk clean", projects[i].getName().c_str());

        sfputs("help:");
        for(int i = 0; i < 9; i++) sfprintf("\t$(SILENT) echo \"%s\"", help[i]);
            
        for(int i = 0; i < projects.size(); i++) 
            sfprintf("\t$(SILENT) echo \"\t%s\"", projects[i].getName().c_str());

        for(int i = 0; i < projects.size(); i++) {
            projects[i].generateFile(targetOS, *this);
        }
    }
}

}