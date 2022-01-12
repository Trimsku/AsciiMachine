Workspace "AsciiMachine"

Project "spam"
    setProjectType "Application"
    
    addIncludePath "src/"
    addCompileOptions( "std=c++11", "Os" )
    addDebugCompileOptions( "g", "O0" )

    files ( "src/*.cpp", "src/lua/onelua.cpp", "src/util/*.c*", "src/astd/*.cpp", "src/target/*.cpp" )