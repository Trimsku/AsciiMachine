Workspace "AsciiMachine"

Project "spam"
    setProjectType "Application"
    
    addIncludePath "."
    addCompileOptions( "std=c++11", "O2" )

    Files( "src/*.cpp", "src/lua/onelua.cpp", "src/util/*.c*", "src/astd/*.cpp" )