# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/trimsky/AsciiMachine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/trimsky/AsciiMachine/build

# Include any dependencies generated for this target.
include CMakeFiles/Ascii.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Ascii.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Ascii.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ascii.dir/flags.make

CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/AsciiSignal.cpp.o: CMakeFiles/Ascii.dir/flags.make
CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/AsciiSignal.cpp.o: ../AsciiMachineCurrent/API/src/AsciiSignal.cpp
CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/AsciiSignal.cpp.o: CMakeFiles/Ascii.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/trimsky/AsciiMachine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/AsciiSignal.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/AsciiSignal.cpp.o -MF CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/AsciiSignal.cpp.o.d -o CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/AsciiSignal.cpp.o -c /home/trimsky/AsciiMachine/AsciiMachineCurrent/API/src/AsciiSignal.cpp

CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/AsciiSignal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/AsciiSignal.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/trimsky/AsciiMachine/AsciiMachineCurrent/API/src/AsciiSignal.cpp > CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/AsciiSignal.cpp.i

CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/AsciiSignal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/AsciiSignal.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/trimsky/AsciiMachine/AsciiMachineCurrent/API/src/AsciiSignal.cpp -o CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/AsciiSignal.cpp.s

CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Color.cpp.o: CMakeFiles/Ascii.dir/flags.make
CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Color.cpp.o: ../AsciiMachineCurrent/API/src/Color.cpp
CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Color.cpp.o: CMakeFiles/Ascii.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/trimsky/AsciiMachine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Color.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Color.cpp.o -MF CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Color.cpp.o.d -o CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Color.cpp.o -c /home/trimsky/AsciiMachine/AsciiMachineCurrent/API/src/Color.cpp

CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Color.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Color.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/trimsky/AsciiMachine/AsciiMachineCurrent/API/src/Color.cpp > CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Color.cpp.i

CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Color.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Color.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/trimsky/AsciiMachine/AsciiMachineCurrent/API/src/Color.cpp -o CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Color.cpp.s

CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Entity.cpp.o: CMakeFiles/Ascii.dir/flags.make
CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Entity.cpp.o: ../AsciiMachineCurrent/API/src/Entity.cpp
CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Entity.cpp.o: CMakeFiles/Ascii.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/trimsky/AsciiMachine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Entity.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Entity.cpp.o -MF CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Entity.cpp.o.d -o CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Entity.cpp.o -c /home/trimsky/AsciiMachine/AsciiMachineCurrent/API/src/Entity.cpp

CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Entity.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/trimsky/AsciiMachine/AsciiMachineCurrent/API/src/Entity.cpp > CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Entity.cpp.i

CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Entity.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/trimsky/AsciiMachine/AsciiMachineCurrent/API/src/Entity.cpp -o CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Entity.cpp.s

CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/GUI_o.cpp.o: CMakeFiles/Ascii.dir/flags.make
CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/GUI_o.cpp.o: ../AsciiMachineCurrent/API/src/GUI_o.cpp
CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/GUI_o.cpp.o: CMakeFiles/Ascii.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/trimsky/AsciiMachine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/GUI_o.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/GUI_o.cpp.o -MF CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/GUI_o.cpp.o.d -o CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/GUI_o.cpp.o -c /home/trimsky/AsciiMachine/AsciiMachineCurrent/API/src/GUI_o.cpp

CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/GUI_o.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/GUI_o.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/trimsky/AsciiMachine/AsciiMachineCurrent/API/src/GUI_o.cpp > CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/GUI_o.cpp.i

CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/GUI_o.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/GUI_o.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/trimsky/AsciiMachine/AsciiMachineCurrent/API/src/GUI_o.cpp -o CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/GUI_o.cpp.s

CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Scene.cpp.o: CMakeFiles/Ascii.dir/flags.make
CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Scene.cpp.o: ../AsciiMachineCurrent/API/src/Scene.cpp
CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Scene.cpp.o: CMakeFiles/Ascii.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/trimsky/AsciiMachine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Scene.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Scene.cpp.o -MF CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Scene.cpp.o.d -o CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Scene.cpp.o -c /home/trimsky/AsciiMachine/AsciiMachineCurrent/API/src/Scene.cpp

CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Scene.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/trimsky/AsciiMachine/AsciiMachineCurrent/API/src/Scene.cpp > CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Scene.cpp.i

CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Scene.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/trimsky/AsciiMachine/AsciiMachineCurrent/API/src/Scene.cpp -o CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Scene.cpp.s

CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Server.cpp.o: CMakeFiles/Ascii.dir/flags.make
CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Server.cpp.o: ../AsciiMachineCurrent/API/src/Server.cpp
CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Server.cpp.o: CMakeFiles/Ascii.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/trimsky/AsciiMachine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Server.cpp.o -MF CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Server.cpp.o.d -o CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Server.cpp.o -c /home/trimsky/AsciiMachine/AsciiMachineCurrent/API/src/Server.cpp

CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/trimsky/AsciiMachine/AsciiMachineCurrent/API/src/Server.cpp > CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Server.cpp.i

CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/trimsky/AsciiMachine/AsciiMachineCurrent/API/src/Server.cpp -o CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Server.cpp.s

CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/utils.cpp.o: CMakeFiles/Ascii.dir/flags.make
CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/utils.cpp.o: ../AsciiMachineCurrent/API/src/utils.cpp
CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/utils.cpp.o: CMakeFiles/Ascii.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/trimsky/AsciiMachine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/utils.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/utils.cpp.o -MF CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/utils.cpp.o.d -o CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/utils.cpp.o -c /home/trimsky/AsciiMachine/AsciiMachineCurrent/API/src/utils.cpp

CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/trimsky/AsciiMachine/AsciiMachineCurrent/API/src/utils.cpp > CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/utils.cpp.i

CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/trimsky/AsciiMachine/AsciiMachineCurrent/API/src/utils.cpp -o CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/utils.cpp.s

# Object files for target Ascii
Ascii_OBJECTS = \
"CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/AsciiSignal.cpp.o" \
"CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Color.cpp.o" \
"CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Entity.cpp.o" \
"CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/GUI_o.cpp.o" \
"CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Scene.cpp.o" \
"CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Server.cpp.o" \
"CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/utils.cpp.o"

# External object files for target Ascii
Ascii_EXTERNAL_OBJECTS =

libAscii.a: CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/AsciiSignal.cpp.o
libAscii.a: CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Color.cpp.o
libAscii.a: CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Entity.cpp.o
libAscii.a: CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/GUI_o.cpp.o
libAscii.a: CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Scene.cpp.o
libAscii.a: CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/Server.cpp.o
libAscii.a: CMakeFiles/Ascii.dir/AsciiMachineCurrent/API/src/utils.cpp.o
libAscii.a: CMakeFiles/Ascii.dir/build.make
libAscii.a: CMakeFiles/Ascii.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/trimsky/AsciiMachine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libAscii.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Ascii.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Ascii.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ascii.dir/build: libAscii.a
.PHONY : CMakeFiles/Ascii.dir/build

CMakeFiles/Ascii.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Ascii.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Ascii.dir/clean

CMakeFiles/Ascii.dir/depend:
	cd /home/trimsky/AsciiMachine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/trimsky/AsciiMachine /home/trimsky/AsciiMachine /home/trimsky/AsciiMachine/build /home/trimsky/AsciiMachine/build /home/trimsky/AsciiMachine/build/CMakeFiles/Ascii.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Ascii.dir/depend

