# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\x64\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\x64\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\hay boy\CLionProjects\BigIntegerUseVector"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\hay boy\CLionProjects\BigIntegerUseVector\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/BigIntegerUseVector.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/BigIntegerUseVector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BigIntegerUseVector.dir/flags.make

CMakeFiles/BigIntegerUseVector.dir/main.cpp.obj: CMakeFiles/BigIntegerUseVector.dir/flags.make
CMakeFiles/BigIntegerUseVector.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\hay boy\CLionProjects\BigIntegerUseVector\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BigIntegerUseVector.dir/main.cpp.obj"
	D:\MingW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BigIntegerUseVector.dir\main.cpp.obj -c "C:\Users\hay boy\CLionProjects\BigIntegerUseVector\main.cpp"

CMakeFiles/BigIntegerUseVector.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BigIntegerUseVector.dir/main.cpp.i"
	D:\MingW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\hay boy\CLionProjects\BigIntegerUseVector\main.cpp" > CMakeFiles\BigIntegerUseVector.dir\main.cpp.i

CMakeFiles/BigIntegerUseVector.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BigIntegerUseVector.dir/main.cpp.s"
	D:\MingW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\hay boy\CLionProjects\BigIntegerUseVector\main.cpp" -o CMakeFiles\BigIntegerUseVector.dir\main.cpp.s

CMakeFiles/BigIntegerUseVector.dir/BigInteger.cpp.obj: CMakeFiles/BigIntegerUseVector.dir/flags.make
CMakeFiles/BigIntegerUseVector.dir/BigInteger.cpp.obj: ../BigInteger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\hay boy\CLionProjects\BigIntegerUseVector\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BigIntegerUseVector.dir/BigInteger.cpp.obj"
	D:\MingW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BigIntegerUseVector.dir\BigInteger.cpp.obj -c "C:\Users\hay boy\CLionProjects\BigIntegerUseVector\BigInteger.cpp"

CMakeFiles/BigIntegerUseVector.dir/BigInteger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BigIntegerUseVector.dir/BigInteger.cpp.i"
	D:\MingW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\hay boy\CLionProjects\BigIntegerUseVector\BigInteger.cpp" > CMakeFiles\BigIntegerUseVector.dir\BigInteger.cpp.i

CMakeFiles/BigIntegerUseVector.dir/BigInteger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BigIntegerUseVector.dir/BigInteger.cpp.s"
	D:\MingW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\hay boy\CLionProjects\BigIntegerUseVector\BigInteger.cpp" -o CMakeFiles\BigIntegerUseVector.dir\BigInteger.cpp.s

CMakeFiles/BigIntegerUseVector.dir/Utils.cpp.obj: CMakeFiles/BigIntegerUseVector.dir/flags.make
CMakeFiles/BigIntegerUseVector.dir/Utils.cpp.obj: ../Utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\hay boy\CLionProjects\BigIntegerUseVector\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/BigIntegerUseVector.dir/Utils.cpp.obj"
	D:\MingW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BigIntegerUseVector.dir\Utils.cpp.obj -c "C:\Users\hay boy\CLionProjects\BigIntegerUseVector\Utils.cpp"

CMakeFiles/BigIntegerUseVector.dir/Utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BigIntegerUseVector.dir/Utils.cpp.i"
	D:\MingW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\hay boy\CLionProjects\BigIntegerUseVector\Utils.cpp" > CMakeFiles\BigIntegerUseVector.dir\Utils.cpp.i

CMakeFiles/BigIntegerUseVector.dir/Utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BigIntegerUseVector.dir/Utils.cpp.s"
	D:\MingW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\hay boy\CLionProjects\BigIntegerUseVector\Utils.cpp" -o CMakeFiles\BigIntegerUseVector.dir\Utils.cpp.s

CMakeFiles/BigIntegerUseVector.dir/Constructor.cpp.obj: CMakeFiles/BigIntegerUseVector.dir/flags.make
CMakeFiles/BigIntegerUseVector.dir/Constructor.cpp.obj: ../Constructor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\hay boy\CLionProjects\BigIntegerUseVector\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/BigIntegerUseVector.dir/Constructor.cpp.obj"
	D:\MingW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BigIntegerUseVector.dir\Constructor.cpp.obj -c "C:\Users\hay boy\CLionProjects\BigIntegerUseVector\Constructor.cpp"

CMakeFiles/BigIntegerUseVector.dir/Constructor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BigIntegerUseVector.dir/Constructor.cpp.i"
	D:\MingW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\hay boy\CLionProjects\BigIntegerUseVector\Constructor.cpp" > CMakeFiles\BigIntegerUseVector.dir\Constructor.cpp.i

CMakeFiles/BigIntegerUseVector.dir/Constructor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BigIntegerUseVector.dir/Constructor.cpp.s"
	D:\MingW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\hay boy\CLionProjects\BigIntegerUseVector\Constructor.cpp" -o CMakeFiles\BigIntegerUseVector.dir\Constructor.cpp.s

# Object files for target BigIntegerUseVector
BigIntegerUseVector_OBJECTS = \
"CMakeFiles/BigIntegerUseVector.dir/main.cpp.obj" \
"CMakeFiles/BigIntegerUseVector.dir/BigInteger.cpp.obj" \
"CMakeFiles/BigIntegerUseVector.dir/Utils.cpp.obj" \
"CMakeFiles/BigIntegerUseVector.dir/Constructor.cpp.obj"

# External object files for target BigIntegerUseVector
BigIntegerUseVector_EXTERNAL_OBJECTS =

BigIntegerUseVector.exe: CMakeFiles/BigIntegerUseVector.dir/main.cpp.obj
BigIntegerUseVector.exe: CMakeFiles/BigIntegerUseVector.dir/BigInteger.cpp.obj
BigIntegerUseVector.exe: CMakeFiles/BigIntegerUseVector.dir/Utils.cpp.obj
BigIntegerUseVector.exe: CMakeFiles/BigIntegerUseVector.dir/Constructor.cpp.obj
BigIntegerUseVector.exe: CMakeFiles/BigIntegerUseVector.dir/build.make
BigIntegerUseVector.exe: CMakeFiles/BigIntegerUseVector.dir/linklibs.rsp
BigIntegerUseVector.exe: CMakeFiles/BigIntegerUseVector.dir/objects1.rsp
BigIntegerUseVector.exe: CMakeFiles/BigIntegerUseVector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\hay boy\CLionProjects\BigIntegerUseVector\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable BigIntegerUseVector.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BigIntegerUseVector.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BigIntegerUseVector.dir/build: BigIntegerUseVector.exe
.PHONY : CMakeFiles/BigIntegerUseVector.dir/build

CMakeFiles/BigIntegerUseVector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BigIntegerUseVector.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BigIntegerUseVector.dir/clean

CMakeFiles/BigIntegerUseVector.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\hay boy\CLionProjects\BigIntegerUseVector" "C:\Users\hay boy\CLionProjects\BigIntegerUseVector" "C:\Users\hay boy\CLionProjects\BigIntegerUseVector\cmake-build-debug" "C:\Users\hay boy\CLionProjects\BigIntegerUseVector\cmake-build-debug" "C:\Users\hay boy\CLionProjects\BigIntegerUseVector\cmake-build-debug\CMakeFiles\BigIntegerUseVector.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/BigIntegerUseVector.dir/depend

