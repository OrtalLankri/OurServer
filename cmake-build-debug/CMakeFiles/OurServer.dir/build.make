# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/99/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/99/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adi/CLionProjects/OurServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adi/CLionProjects/OurServer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OurServer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OurServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OurServer.dir/flags.make

CMakeFiles/OurServer.dir/main.cpp.o: CMakeFiles/OurServer.dir/flags.make
CMakeFiles/OurServer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adi/CLionProjects/OurServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OurServer.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OurServer.dir/main.cpp.o -c /home/adi/CLionProjects/OurServer/main.cpp

CMakeFiles/OurServer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OurServer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adi/CLionProjects/OurServer/main.cpp > CMakeFiles/OurServer.dir/main.cpp.i

CMakeFiles/OurServer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OurServer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adi/CLionProjects/OurServer/main.cpp -o CMakeFiles/OurServer.dir/main.cpp.s

CMakeFiles/OurServer.dir/MySerialServer.cpp.o: CMakeFiles/OurServer.dir/flags.make
CMakeFiles/OurServer.dir/MySerialServer.cpp.o: ../MySerialServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adi/CLionProjects/OurServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OurServer.dir/MySerialServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OurServer.dir/MySerialServer.cpp.o -c /home/adi/CLionProjects/OurServer/MySerialServer.cpp

CMakeFiles/OurServer.dir/MySerialServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OurServer.dir/MySerialServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adi/CLionProjects/OurServer/MySerialServer.cpp > CMakeFiles/OurServer.dir/MySerialServer.cpp.i

CMakeFiles/OurServer.dir/MySerialServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OurServer.dir/MySerialServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adi/CLionProjects/OurServer/MySerialServer.cpp -o CMakeFiles/OurServer.dir/MySerialServer.cpp.s

CMakeFiles/OurServer.dir/MyTestClientHandler.cpp.o: CMakeFiles/OurServer.dir/flags.make
CMakeFiles/OurServer.dir/MyTestClientHandler.cpp.o: ../MyTestClientHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adi/CLionProjects/OurServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OurServer.dir/MyTestClientHandler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OurServer.dir/MyTestClientHandler.cpp.o -c /home/adi/CLionProjects/OurServer/MyTestClientHandler.cpp

CMakeFiles/OurServer.dir/MyTestClientHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OurServer.dir/MyTestClientHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adi/CLionProjects/OurServer/MyTestClientHandler.cpp > CMakeFiles/OurServer.dir/MyTestClientHandler.cpp.i

CMakeFiles/OurServer.dir/MyTestClientHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OurServer.dir/MyTestClientHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adi/CLionProjects/OurServer/MyTestClientHandler.cpp -o CMakeFiles/OurServer.dir/MyTestClientHandler.cpp.s

CMakeFiles/OurServer.dir/Solver.cpp.o: CMakeFiles/OurServer.dir/flags.make
CMakeFiles/OurServer.dir/Solver.cpp.o: ../Solver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adi/CLionProjects/OurServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/OurServer.dir/Solver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OurServer.dir/Solver.cpp.o -c /home/adi/CLionProjects/OurServer/Solver.cpp

CMakeFiles/OurServer.dir/Solver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OurServer.dir/Solver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adi/CLionProjects/OurServer/Solver.cpp > CMakeFiles/OurServer.dir/Solver.cpp.i

CMakeFiles/OurServer.dir/Solver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OurServer.dir/Solver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adi/CLionProjects/OurServer/Solver.cpp -o CMakeFiles/OurServer.dir/Solver.cpp.s

CMakeFiles/OurServer.dir/StringReverser.cpp.o: CMakeFiles/OurServer.dir/flags.make
CMakeFiles/OurServer.dir/StringReverser.cpp.o: ../StringReverser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adi/CLionProjects/OurServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/OurServer.dir/StringReverser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OurServer.dir/StringReverser.cpp.o -c /home/adi/CLionProjects/OurServer/StringReverser.cpp

CMakeFiles/OurServer.dir/StringReverser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OurServer.dir/StringReverser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adi/CLionProjects/OurServer/StringReverser.cpp > CMakeFiles/OurServer.dir/StringReverser.cpp.i

CMakeFiles/OurServer.dir/StringReverser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OurServer.dir/StringReverser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adi/CLionProjects/OurServer/StringReverser.cpp -o CMakeFiles/OurServer.dir/StringReverser.cpp.s

CMakeFiles/OurServer.dir/FileCacheManager.cpp.o: CMakeFiles/OurServer.dir/flags.make
CMakeFiles/OurServer.dir/FileCacheManager.cpp.o: ../FileCacheManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adi/CLionProjects/OurServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/OurServer.dir/FileCacheManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OurServer.dir/FileCacheManager.cpp.o -c /home/adi/CLionProjects/OurServer/FileCacheManager.cpp

CMakeFiles/OurServer.dir/FileCacheManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OurServer.dir/FileCacheManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adi/CLionProjects/OurServer/FileCacheManager.cpp > CMakeFiles/OurServer.dir/FileCacheManager.cpp.i

CMakeFiles/OurServer.dir/FileCacheManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OurServer.dir/FileCacheManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adi/CLionProjects/OurServer/FileCacheManager.cpp -o CMakeFiles/OurServer.dir/FileCacheManager.cpp.s

# Object files for target OurServer
OurServer_OBJECTS = \
"CMakeFiles/OurServer.dir/main.cpp.o" \
"CMakeFiles/OurServer.dir/MySerialServer.cpp.o" \
"CMakeFiles/OurServer.dir/MyTestClientHandler.cpp.o" \
"CMakeFiles/OurServer.dir/Solver.cpp.o" \
"CMakeFiles/OurServer.dir/StringReverser.cpp.o" \
"CMakeFiles/OurServer.dir/FileCacheManager.cpp.o"

# External object files for target OurServer
OurServer_EXTERNAL_OBJECTS =

OurServer: CMakeFiles/OurServer.dir/main.cpp.o
OurServer: CMakeFiles/OurServer.dir/MySerialServer.cpp.o
OurServer: CMakeFiles/OurServer.dir/MyTestClientHandler.cpp.o
OurServer: CMakeFiles/OurServer.dir/Solver.cpp.o
OurServer: CMakeFiles/OurServer.dir/StringReverser.cpp.o
OurServer: CMakeFiles/OurServer.dir/FileCacheManager.cpp.o
OurServer: CMakeFiles/OurServer.dir/build.make
OurServer: CMakeFiles/OurServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adi/CLionProjects/OurServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable OurServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OurServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OurServer.dir/build: OurServer

.PHONY : CMakeFiles/OurServer.dir/build

CMakeFiles/OurServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OurServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OurServer.dir/clean

CMakeFiles/OurServer.dir/depend:
	cd /home/adi/CLionProjects/OurServer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adi/CLionProjects/OurServer /home/adi/CLionProjects/OurServer /home/adi/CLionProjects/OurServer/cmake-build-debug /home/adi/CLionProjects/OurServer/cmake-build-debug /home/adi/CLionProjects/OurServer/cmake-build-debug/CMakeFiles/OurServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OurServer.dir/depend

