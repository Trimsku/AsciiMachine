#include "spam.hpp"

extern "C" {
    #include "lua/lua.h"
    #include "lua/lauxlib.h"
    #include "lua/lualib.h"
}
#include <cstring>
#include "tclap/CmdLine.h"

enum OptionType {
    DEBUG,
    RELEASE,
    GLOBAL
};

/*** Project ***/
int projectType = -1;
int targetOS = -1;
int project_index = 0;
std::string files;
std::string name;
bool cc = false;
std::vector<std::string> library_names;
/*** Project end ***/
/*** Workspace ***/
spam::Workspace mWorkspace("unnamed_workspace");
/*** Workspace end ***/

static int AddIncludePath(lua_State * L) {
    spam::addIncludePath(lua_tostring(L, 1));
    return 1;
}

static int Workspace(lua_State * L) {
    mWorkspace.setName(lua_tostring(L, 1));
    return 1;
}

static int LinkLibrary(lua_State * L) {
    library_names.push_back(lua_tostring(L, 1));
    return 1;
}

static int AddLibraryPath(lua_State * L) {
    spam::addLibraryPath(lua_tostring(L, 1));
    return 1;
}

static int Project(lua_State * L) {
    if(project_index == 0 ) {
        ++project_index;
        name = lua_tostring(L, 1);
    } else {
        spam::LinuxProjectGenerator file(name.c_str());
        file.setProjectType(projectType);
        file.includeFiles(files.c_str(), " "); // All files;
        for(int i = 0; i < library_names.size(); i++) {
            file.linkLibrary(library_names[i]);
        }
        mWorkspace.addProject(file);

        name = lua_tostring(L, 1);
        files = "";
        library_names = {};
        ++project_index;
    }
    return 1;
}

static int Files(lua_State * L) {
    for(int i = 1; i <= lua_gettop(L); i++) {
        files += spam::includeFilesInFolder(lua_tostring(L, i));
    }
    return 1;
}

void AddCompileOptionsRaw(lua_State * L, int type) {
    int args = lua_gettop(L);
    for(int i = 1; i <= args; i++) {
        // For construction like `wx-config --cxxflags --libs`
        if(lua_tostring(L, i)[0] == '`') {
            bool isError = true;
            std::string options = "";
            for(int j = i; j <= args ; j++) {
                std::string option = lua_tostring(L, i);
                if(option[option.size()] == '`') {
                    isError = false;
                    break;
                } else {
                    options += option;
                    options += ' ';
                }
            }
            if(isError) {
                printf("SyntaxParseError: expected ` in CompileOptions");
                exit(0);
            } else {
                spam::addCompileOptions(options);
            }
        }
        spam::addCompileOptions(lua_tostring(L, i));
    }
}
static int AddCompileOptions(lua_State * L) {
    AddCompileOptionsRaw(L, OptionType::GLOBAL);
    return 1;
}
static int AddDebugCompileOptions(lua_State * L) {
    AddCompileOptionsRaw(L, OptionType::DEBUG);
    return 1;
}
static int AddReleaseCompileOptions(lua_State * L) {
    AddCompileOptionsRaw(L, OptionType::RELEASE);
    return 1;
}
static int GetTargetOS(lua_State * L) {
    if(targetOS == OSType::Linux) lua_pushstring(L, "linux");
    else if(targetOS == OSType::Windows) lua_pushstring(L, "windows");
    else if(targetOS == OSType::MacOS) lua_pushstring(L, "macos");
    else if(targetOS == OSType::Android) lua_pushstring(L, "android");
    else if(targetOS == OSType::iOS) lua_pushstring(L, "ios");
    else if(targetOS == OSType::Web) lua_pushstring(L, "web");
    else lua_pushstring(L, "none");
    return 1;
}

static int SetProjectType(lua_State * L) {
    if(strcmp(lua_tostring(L, 1), "Application") == 0)
        projectType = ProjectType::Application;
    else if(strcmp(lua_tostring(L, 1), "SharedLib") == 0)
        projectType = ProjectType::Library;
    else 
        printf("ParseError: there isn't `%s` in available project types. Available: Application, SharedLib", lua_tostring(L, 1));
    return 1;
}

int getTargetOS(std::string targetTypeArgValue) {
    std::string targetTypeArgValueInLC;
    std::transform(targetTypeArgValue.begin(), targetTypeArgValue.end(), targetTypeArgValueInLC.begin(),
            [](unsigned char c){ return std::tolower(c); });
    if(targetTypeArgValueInLC.compare("linux")) return OSType::Linux;
    else if(targetTypeArgValueInLC == std::string("windows")) return OSType::Windows;
    else if(targetTypeArgValueInLC == std::string("macos")) return OSType::MacOS;
    else if(targetTypeArgValueInLC == std::string("android")) return OSType::Android;
    else if(targetTypeArgValueInLC == std::string("ios")) return OSType::iOS;
    else if(targetTypeArgValueInLC == std::string("web")) return OSType::Web;
    else {
        printf("Your target-os value isn't valid! Valid values: [Linux, Windows, MacOS, Android, iOS, Web]");
        exit(0);
    }
    return 1;
}

int main(int argc, char** argv) {

    /*std::string help = "all commands; \n\
`--path-to-file=name`, `-p=name` - set path to lua file \n\
`--filename=name`, `-f=name` - set name for lua file \n\
`--generator=[gmake4, vs2017]`, `-g=[gmake4, vs2017]` - set generator\n\
`--spman-functions-help`, `-sfh` - return spman functions\n\
\n";*/

    std::string functions_help = 
"libs - libraries\n\
decl - declaration \n\n\n\
\tWorkspace \"your_workspace_name\"  - set the main workspace name\n\n\
\tProject \"your_project_name\" - set the project name. Set after `Workspace` decl.\n\n\
\tFiles (\"...\") - set files for compiling, set after `Project` decls. \n\n\
\tLinkLibrary \"library_name\" - get library from `any path`. \n\n\
\tAddLibraryPath \"library_path\" - add library path to project paths of libs.\n\n\
\tIsCrossCompiler - return true, if you add option --cc, otherwise false. \n\n\
\tAddCompileOptions \"...\" - add compile options. \n\n\
\tSetProjectType - set project type of project. Set after project decl. \n\n\
\tAddIncludePath - add include path to project include paths.";

    tclap::CmdLine cmd("spam - Simple Project auto-building tool for AsciiMachine", ' ', "1.0.0-beta");

    tclap::ValueArg<std::string> targetTypeArg("t", "target-os", "choose which OS you want to export the game to [Linux, Windows, MacOS, Android, iOS, Web, Emscripten]", true, "none", "string");
    tclap::ValueArg<std::string> filenameArg("f", "filename", "set name for input file(default: make.lua)", false, "make.lua", "string");
    tclap::ValueArg<std::string> pathToFileArg("p", "path-to-file", "set path to input file(default: .)", false, ".", "string");

    tclap::SwitchArg spamFunctionsHelp("s", "spam-functions-help", "Displays usage information and exits.", cmd, false);

    std::string path_to_file = ".";
    std::string input_name = "make.lua";

    cmd.add(targetTypeArg);
    cmd.add(filenameArg);
    cmd.add(pathToFileArg);

    cmd.parse(argc, argv);

    if( spamFunctionsHelp.getValue() ) {
        printf("%s", functions_help.c_str());
        exit(0);
    } 
    if( filenameArg.getValue() != "make.lua" ) {
        input_name = filenameArg.getValue();
    }
    if( pathToFileArg.getValue() != "." ) {
        path_to_file = pathToFileArg.getValue();
    }
    targetOS = OSType::Linux;

    int iErr = 0;
    lua_State *lua = luaL_newstate();
    lua_pushcfunction(lua, ::Workspace);
    lua_setglobal(lua, "Workspace");
    lua_pushcfunction(lua, ::Project);
    lua_setglobal(lua, "Project");
    lua_pushcfunction(lua, ::Files);
    lua_setglobal(lua, "files");
    lua_pushcfunction(lua, ::LinkLibrary);
    lua_setglobal(lua, "linkLib");
    lua_pushcfunction(lua, ::AddLibraryPath);
    lua_setglobal(lua, "libsPaths");
    lua_pushcfunction(lua, ::AddCompileOptions);
    lua_setglobal(lua, "addCompileOptions");
    lua_pushcfunction(lua, ::AddDebugCompileOptions);
    lua_setglobal(lua, "addDebugCompileOptions");
    lua_pushcfunction(lua, ::AddReleaseCompileOptions);
    lua_setglobal(lua, "addReleaseCompileOptions");
    lua_pushcfunction(lua, ::AddCompileOptions);
    lua_setglobal(lua, "addCompileOptions");
    lua_pushcfunction(lua, ::SetProjectType);
    lua_setglobal(lua, "setProjectType");
    lua_pushcfunction(lua, ::AddIncludePath);
    lua_setglobal(lua, "addIncludePath");
    lua_pushcfunction(lua, ::GetTargetOS);
    lua_setglobal(lua, "getTargetOS");
    
    luaopen_base (lua); 

    iErr = luaL_dofile(lua, (path_to_file + (path_to_file[path_to_file.size()] == '/'?input_name:"/"+input_name)).c_str());
    if (iErr != 0) {
        printf("LoadingError: %s\n", lua_tostring(lua, -1));
        exit(0);
    }
    lua_close (lua);

    spam::LinuxProjectGenerator last_project(name.c_str());
    last_project.setProjectType(projectType);
    last_project.includeFiles(files.c_str(), " "); // All files;
    for(int i = 0; i < library_names.size(); i++)
        last_project.linkLibrary(library_names[i]);
    mWorkspace.addProject(last_project);

    mWorkspace.generateFile(targetOS);

    return 0;
}