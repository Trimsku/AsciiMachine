Workspace "AsciiMachine"

Project "AsciiGame"
    SetProjectType "Application"

    LinkLibrary "SDL2" 
    LinkLibrary "SDL2_ttf"

    AddIncludePath "."
    AddIncludePath "asciiengine/common/entity/"
    AddCompileOptions( "std=c++14" )

    Files( "src/astd/*", "src/client/*", "src/common/entity/*", "src/common/*", "src/common/event/*", "src/common/util/*", "src/core/*" )
    Files( "testGame/*.cpp", "testGame/scene/*.cpp" )
