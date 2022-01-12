Workspace "AsciiMachine"

Project "AsciiLib"
    setProjectType "SharedLib"
    -- system
    linkLib "SDL2" 
    linkLib "SDL2_ttf"
    linkLib "GL"

    addIncludePath "."

    addCompileOptions( "std=c++14" )
    files( "src/astd/*", "src/client/*", "src/common/*.cpp", "src/common/event/*", "src/common/util/*", "src/core/*" )

Project "AsciiGame"
    setProjectType "Application"
    linkLib "AsciiLib"
    linkLib "SDL2" 
    linkLib "SDL2_ttf"
    linkLib "GL"

    files( "testGame/*.cpp", "testGame/scene/*.cpp" )

-- Project "SpriteEditor"
   --  SetProjectType "Application"
   --  AddLibraryPath "bin/Release/"
   --  LinkLibrary "AsciiLib"

   --  Files( "se/SpriteEditor.cpp" )