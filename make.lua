Workspace "AsciiMachine"

Project "AsciiLib"
    SetProjectType "SharedLib"
    -- system
    LinkLibrary "SDL2" 
    LinkLibrary "SDL2_ttf"

    AddIncludePath "."
    AddIncludePath "asciiengine/common/entity/"

    AddCompileOptions( "std=c++14" )
    Files( "src/astd/*", "src/client/*", "src/common/entity/*", "src/common/*", "src/common/event/*", "src/common/util/*", "src/core/*" )

Project "AsciiGame"
    SetProjectType "Application"
    AddLibraryPath "bin/Release/"
    LinkLibrary "AsciiLib"

    Files( "testGame/*.cpp", "testGame/scene/*.cpp" )

Project "SpriteEditor"
    SetProjectType "Application"
    AddLibraryPath "bin/Release/"
    LinkLibrary "AsciiLib"

    Files( "se/SpriteEditor.cpp" )