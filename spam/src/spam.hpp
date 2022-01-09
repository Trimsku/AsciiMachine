#ifndef SPMAN_HPP
#define SPMAN_HPP

#include <dirent.h>
//! Includes

#include <stdio.h>
#include <string>
#include "util/regex.h"
#include "util/GenUUID.hpp"
#include "astd/Container.hpp"

namespace spman { namespace priv {
// spman private macros
#define sfputs(text) fputs(text "\n", fptr)
// spman private macros
#define println(text, ...) printf(text "\n", __VA_ARGS__)
// spman private macros
#define putsln(text) puts(text "\n")
// spman private macros
#define sfprintf(text, ...) fprintf(fptr, text "\n", __VA_ARGS__)

}}

extern const char* help[9];
extern std::vector<std::string> libraries_paths;
extern std::vector<std::string> release_libraries_paths;
extern std::vector<std::string> debug_libraries_paths;
extern std::vector<std::string> include_paths;
extern std::string global_options;
extern std::string debug_options;
extern std::string release_options;

enum TargetType {
    Linux = 1,
    Windows = 2,
    MacOS = 3, // OSXCross 
    Android = 4,
    iOS = 6,
    Web = 5, // Emscripten
};
enum ProjectType {
    Application = 1,
    Library = 2,
};

//! Spman namespace.
namespace spam
{
    //! Util functions
    template<typename... Args>
    void addCompileOptions(Args ... args);
    std::string includeFilesInFolder(const char* folder_name_with_pattern);
    std::string includeFile(const char* filename);
    void addReleaseLibraryPath(const char* path_to_library);
    void addDebugLibraryPath(const char* path_to_library);
    void addLibraryPath(const char* path_to_library);
    void addIncludePath(const char* path_to_library);

    namespace priv
    {
        template<typename T>
        T add(T arg_);
 
        template<typename T, typename... Args>
        std::string add(T arg_, Args... args);
    } // namespace priv

    class Workspace;

    class Project {
        private:
            std::string files;
            std::string name;
            int projectType;
            std::vector<std::string> library_names;
        public:
            Project(std::string project_name);
            ~Project();

            void generateFile(int targetOS, spam::Workspace &mainWorkspace);

            template<typename T, typename... Args>
            void includeFiles(T first, Args... args);
            void linkLibrary(std::string name);
            void setProjectType(int projectType);
            int getProjectType();

            std::string getName();
            template<typename ... Args>
            friend void addCompileOptions(Args ... args);
    };

    //! Workspace class

    class Workspace {
        private:
            friend class spam::Project;
            std::vector<spam::Project> projects;
            std::string name;
        public:
            Workspace(std::string name);
            ~Workspace();
            void addProject(spam::Project &project);
            void generateFile(int targetOS);
            void createClass();
            inline void setName(std::string new_name) noexcept;
    };

    void Workspace::setName(std::string new_name) noexcept {
        name = new_name;
    }
    // Template functions

    template<typename T>
    T priv::add(T arg_){
        return arg_;
    }
    template<typename T, typename... Args>
    std::string priv::add(T arg_, Args... args) {
        std::string new_str(arg_);
        new_str += ' ';
        new_str += add(args...);
        return new_str;
    }

    template<typename T, typename... Args>
    void Project::includeFiles(T first, Args... args) {
        files += first;
        files += ' ';
        files += priv::add(args...); 
    }

    template<typename... Args>
    void addCompileOptions(Args ... args) {
        global_options += priv::add(args..., "");
    }
    template<typename... Args>
    void addDebugCompileOptions(Args ... args) {
        debug_options += priv::add(args..., "");
    }
    template<typename... Args>
    void addReleaseCompileOptions(Args ... args) {
        release_options += priv::add(args..., "");
    }
} // namespace spman
#endif // SPMAN_HPP