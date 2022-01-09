# SPAM
Hello, this is SPAM, Simple Project auto-building tool for AsciiMachine, writed in c++, Inspired by spman and premake5.
```
Executable files, available: 
    For win32: releases/0.0.1/spm_win32.exe
    For win64: releases/0.0.1/spm_win64.exe
    For linux, x86_64: releases/0.0.1/spm_linux64
        (tested on Manjaro Linux x86_64, gnome 3.38.4)
```
```
TODO:
1. Add other platform support
```

Dev Dependency: musl

Arch Linux:

```sudo pacman -S musl```

I'm using tine-regex-c project:

First, https://github.com/kokke/tiny-regex-c, tiny_regex_c project.

Very simple example with main.cpp
```lua
Workspace "My_Workspace"

Project "My_Project"
    Files ( "main.cpp" )
```

... And that's example for building spman:
```lua
Workspace "AsciiMachine"

Project "spam"
    setProjectType "Application"
    
    addIncludePath "."
    addCompileOptions "std=c++11" 
    addReleaseCompileOptions "O2" 

    Files( "src/*.cpp", "src/lua/onelua.cpp", "src/util/*.c*", "src/astd/*.cpp" )
```
