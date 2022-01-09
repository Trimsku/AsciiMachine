Workspace "AsciiMachine"

Project "AsciiLib"
    setProjectType "SharedLib"
    -- system
    linkLibrary "SDL2" 
    linkLibrary "SDL2_ttf"
    linkLibrary "GL"

    addIncludePath "."

    addCompileOptions( "std=c++14" )
    Files( "src/astd/*", "src/client/*", "src/common/*.cpp", "src/common/event/*", "src/common/util/*", "src/core/*" )

Project "AsciiGame"
    setProjectType "Application"
    linkLibrary "AsciiLib"
    linkLibrary "SDL2" 
    linkLibrary "SDL2_ttf"
    linkLibrary "GL"

    Files( "testGame/*.cpp", "testGame/scene/*.cpp" )

-- Project "SpriteEditor"
   --  SetProjectType "Application"
   --  AddLibraryPath "bin/Release/"
   --  LinkLibrary "AsciiLib"

   --  Files( "se/SpriteEditor.cpp" )