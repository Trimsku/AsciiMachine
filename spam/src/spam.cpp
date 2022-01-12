#include "spam.hpp"
#include <sys/stat.h>   // stat
#include <dirent.h>
#include <algorithm>
#include <functional>
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
    re_t pattern = re_compile(modificated_pattern.c_str());
    DIR *dir;
    struct dirent *ent;
    std::string files;
    if(( dir = opendir(folder.c_str())) != NULL ) {
        while ((ent = readdir(dir)) != NULL) {
            if(re_matchp(pattern, ent->d_name, &match_length) != -1) {
                if( strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0 ) {
                    if(!isInRootDir) files += folder + '/';
                    files += ent->d_name;
                    files += ' ';
                }
            }
        }
        closedir(dir);
    } else {
        printf("\"%s\" not a directory. \n", folder.c_str());
        closedir(dir);
        exit(0);
    }
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

bool nameComparsion(LinuxProjectGenerator &generator, std::string libName) {
    return generator.getName() == libName;
}

LinuxProjectGenerator::LinuxProjectGenerator(std::string _project_name) noexcept : super(_project_name) {}
LinuxProjectGenerator::~LinuxProjectGenerator() {} 

void LinuxProjectGenerator::linkLibrary(std::string name) {
    library_names.push_back(name);
}

void LinuxProjectGenerator::setProjectType(int _projectType) {
    projectType = _projectType;
}
int LinuxProjectGenerator::getProjectType() {
    return projectType;
}

void LinuxProjectGenerator::generateFile(Workspace &workspace) {
    FILE *fptr;
    if((fptr = fopen((name + ".mk").c_str(), "w")) != NULL) {
        std::vector<std::string> objs = astd::split(files, ' ');
        objs.erase(std::remove_if(objs.begin(), objs.end(), [](std::string str) -> bool { return str.empty(); }), objs.end());
        std::vector<std::string> filesInVector(objs);

        printf("Generating %s.mk for Linux build, generator 'GNU Make 4.0'...\n", name.c_str());

        push(TargetType::IFNDEF, "verbose");
            add("SILENT = @");
        pop();
        push(TargetType::IFEQ, "$(config)==debug"); {
            add("OBJS_DIR := obj/Debug\n");
            add("BIN_DIR := bin/Debug\n");
            add("INCLUDES := " + astd::asString(include_paths) + '\n');
            
            add("OBJS := ");
            std::transform(objs.begin(), objs.end(), objs.begin(), 
                [this](std::string str) -> std::string { 
                int extensionPointStrNumber = str.find_last_of('.');
                if(extensionPointStrNumber == std::string::npos) {
                    printf("In %s: file %s hasn't got extension(.cpp, .cxx, .c)! \n", name.c_str(), str.c_str());
                    exit(0);
                }
                std::string obj = str.substr(0, extensionPointStrNumber) + ".o" + ' ';
                int slashPos = obj.find_last_of('/'); slashPos = slashPos != std::string::npos ? slashPos+1 : 0;
                obj = "$(OBJS_DIR)/" + obj.substr(slashPos, obj.size());
                add(obj);
                return obj;
            }); 
            endl();

            add("LIBS := ");
            bool isHasGotSourcedLibs = false;
            for(std::string lib_name : library_names) {
                if(std::find_if(workspace.projects.begin(), workspace.projects.end(),  std::bind(nameComparsion,  std::placeholders::_1 , lib_name)) != workspace.projects.end()) {
                    isHasGotSourcedLibs = true;
                    add("$(BIN_DIR)/lib" + lib_name + ".so ");
                } else
                    add("-l" + lib_name + ' ');
            } 
            endl(); 

            add("LIB_PATHS := ");
            for(std::string path : debug_libraries_paths) add("-L" + path + ' ');
            for(std::string path : libraries_paths) add("-L" + path + ' ');
            endl();

            add("ALL_CPPFLAGS := $(CPP_FLAGS) $(CXX_FLAGS) -MMD -MP $(INCLUDES) ");
            if(projectType == ProjectType::Library) add("-fPIC ");

            std::vector<std::string> splittedOptions;
            if(!global_options.empty()) splittedOptions = astd::split(global_options, ' ');
            if(!debug_options.empty()) {
                std::vector<std::string> splittedDebugOptions = astd::split(debug_options, ' ');
                splittedOptions.insert(splittedOptions.end(), splittedDebugOptions.begin(), splittedDebugOptions.end());
            }

            for(std::string option : splittedOptions) 
                if(!option.empty()) add('-' + option + ' ');
            endl();

            add("ALL_LDFLAGS := $(LDFLAGS) $(LIB_PATHS) ");
            if(projectType == ProjectType::Library) add("-shared -Wl,-soname=lib" + name + ".so -s ");
            if(isHasGotSourcedLibs) add("-Wl,-rpath,'$$ORIGIN' -s");
        } push(TargetType::ELSE); {
            add("OBJS_DIR := obj/Release\n");
            add("BIN_DIR := bin/Release\n");
            add("INCLUDES := " + astd::asString(include_paths) + '\n');

            add("OBJS := ");
            std::transform(objs.begin(), objs.end(), objs.begin(), 
                [this](std::string str) -> std::string { 
                int extensionPointStrNumber = str.find_last_of('.');
                if(extensionPointStrNumber == std::string::npos) {
                    printf("In %s: file %s hasn't got extension(.cpp, .cxx, .c)! \n", name.c_str(), str.c_str());
                    exit(0);
                }
                std::string obj = str.substr(0, extensionPointStrNumber) + ".o" + ' ';
                int slashPos = obj.find_last_of('/'); slashPos = slashPos != std::string::npos ? slashPos+1 : 0;
                obj = "$(OBJS_DIR)/" + obj.substr(slashPos, obj.size());
                add(obj);
                return obj;
            }); 
            endl();

            add("LIBS := ");
            bool isHasGotSourcedLibs = false;
            for(std::string lib_name : library_names) {
                if(std::find_if(workspace.projects.begin(), workspace.projects.end(), std::bind(nameComparsion,  std::placeholders::_1, lib_name)) != workspace.projects.end()) {
                    isHasGotSourcedLibs = true;
                    add("bin/Release/lib" + lib_name + ".so ");
                } else
                    add("-l" + lib_name + ' ');
            } 
            endl(); 

            add("LIB_PATHS := ");
            if(!release_libraries_paths.empty()) {
                for(std::string path : release_libraries_paths) add("-L" + path + ' ');
            }
            if(!libraries_paths.empty()) {
                for(std::string path : libraries_paths) add("-L" + path + ' ');
            }
            endl();

            add("ALL_CPPFLAGS := $(CPP_FLAGS) $(CXX_FLAGS) -MMD -MP $(INCLUDES) ");
            if(projectType == ProjectType::Library) add("-fPIC ");

            std::vector<std::string> splittedOptions;
            if(!global_options.empty()) splittedOptions = astd::split(global_options, ' ');
            if(!release_options.empty()) {
                std::vector<std::string> splittedReleaseOptions = astd::split(release_options, ' ');
                splittedOptions.insert(splittedOptions.end(), splittedReleaseOptions.begin(), splittedReleaseOptions.end());
            }

            for(std::string option : splittedOptions) 
                if(!option.empty()) add('-' + option + ' ');
            endl();

            add("ALL_LDFLAGS := $(LDFLAGS) $(LIB_PATHS) ");
            if(projectType == ProjectType::Library) add("-shared -Wl,-soname=lib" + name + ".so -s ");
            if(isHasGotSourcedLibs) add("-Wl,-rpath,'$$ORIGIN' -s");
        } pop();

        add("CXX := g++\n");
        std::string libPreffix = projectType == ProjectType::Library ? "lib" : "";
        std::string libExtension = projectType == ProjectType::Library ? ".so" : "";
        std::string bin_name = libPreffix + name + libExtension;
        push(TargetType::MAKEFILE_TARGET, "[all] { create_dirs $(OBJS) $(BIN_DIR)/" + bin_name + "}"); pop(); endl();
        push(TargetType::MAKEFILE_TARGET, "[ $(BIN_DIR)/" + bin_name + "] { }");
            add("$(SILENT) echo Linking $@...\n");
            add("$(SILENT) $(CXX) $(OBJS) $(ALL_LDFLAGS) $(LIBS) -o $@ "); 
        pop();
        endl();
        push(TargetType::MAKEFILE_TARGET, "[.PHONY] { create_dirs clean }"); pop();
        push(TargetType::MAKEFILE_TARGET, "[create_dirs]{}");
	        add("$(SILENT) mkdir -p $(OBJS_DIR)\n");
	        add("$(SILENT) mkdir -p $(BIN_DIR)");
        pop();
        push(TargetType::MAKEFILE_TARGET, "[clean]{}");
            add("rm -f $(OBJS_DIR)/*\n");
	        add("rm -f $(BIN_DIR)/*");
        pop();
        for(int i = 0; i < objs.size(); ++i) {
            push(TargetType::MAKEFILE_TARGET, '[' + objs[i] + "]{" + filesInVector[i] + '}');
                add("$(SILENT) echo Building $@...\n");
                add("$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o \"$@\" -MF \"$(@:%.o=%.d)\" -c \"$<\" ");
            pop();
            endl();
        }
        add("-include $(OBJS:%.o=%.d)");
        fputs(getContent().c_str(), fptr);
    } else {
        printf("Can't create %s.mk!", name.c_str());
        exit(0);
    }
}

std::string LinuxProjectGenerator::getName() {
    return name;
}
}

namespace spam {

Workspace::Workspace(std::string _name) : name(_name) {}
Workspace::~Workspace() {}

void Workspace::addProject(spam::LinuxProjectGenerator &project) {
    projects.push_back(project);
}

void Workspace::generateFile(int targetOS) {
    FILE *fptr;
    if( (fptr = fopen(("Makefile"), "w")) != NULL ) {
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
            projects[i].generateFile(*this);
        }
    }
}

}