# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "H:\Clion\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "H:\Clion\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = H:\learn\C++\Staff_management_system

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = H:\learn\C++\Staff_management_system\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Staff_management_system.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Staff_management_system.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Staff_management_system.dir/flags.make

CMakeFiles/Staff_management_system.dir/main.cpp.obj: CMakeFiles/Staff_management_system.dir/flags.make
CMakeFiles/Staff_management_system.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\learn\C++\Staff_management_system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Staff_management_system.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Staff_management_system.dir\main.cpp.obj -c H:\learn\C++\Staff_management_system\main.cpp

CMakeFiles/Staff_management_system.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Staff_management_system.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:\learn\C++\Staff_management_system\main.cpp > CMakeFiles\Staff_management_system.dir\main.cpp.i

CMakeFiles/Staff_management_system.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Staff_management_system.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:\learn\C++\Staff_management_system\main.cpp -o CMakeFiles\Staff_management_system.dir\main.cpp.s

CMakeFiles/Staff_management_system.dir/workerManager.cpp.obj: CMakeFiles/Staff_management_system.dir/flags.make
CMakeFiles/Staff_management_system.dir/workerManager.cpp.obj: ../workerManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\learn\C++\Staff_management_system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Staff_management_system.dir/workerManager.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Staff_management_system.dir\workerManager.cpp.obj -c H:\learn\C++\Staff_management_system\workerManager.cpp

CMakeFiles/Staff_management_system.dir/workerManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Staff_management_system.dir/workerManager.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:\learn\C++\Staff_management_system\workerManager.cpp > CMakeFiles\Staff_management_system.dir\workerManager.cpp.i

CMakeFiles/Staff_management_system.dir/workerManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Staff_management_system.dir/workerManager.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:\learn\C++\Staff_management_system\workerManager.cpp -o CMakeFiles\Staff_management_system.dir\workerManager.cpp.s

CMakeFiles/Staff_management_system.dir/employee.cpp.obj: CMakeFiles/Staff_management_system.dir/flags.make
CMakeFiles/Staff_management_system.dir/employee.cpp.obj: ../employee.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\learn\C++\Staff_management_system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Staff_management_system.dir/employee.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Staff_management_system.dir\employee.cpp.obj -c H:\learn\C++\Staff_management_system\employee.cpp

CMakeFiles/Staff_management_system.dir/employee.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Staff_management_system.dir/employee.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:\learn\C++\Staff_management_system\employee.cpp > CMakeFiles\Staff_management_system.dir\employee.cpp.i

CMakeFiles/Staff_management_system.dir/employee.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Staff_management_system.dir/employee.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:\learn\C++\Staff_management_system\employee.cpp -o CMakeFiles\Staff_management_system.dir\employee.cpp.s

CMakeFiles/Staff_management_system.dir/manager.cpp.obj: CMakeFiles/Staff_management_system.dir/flags.make
CMakeFiles/Staff_management_system.dir/manager.cpp.obj: ../manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\learn\C++\Staff_management_system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Staff_management_system.dir/manager.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Staff_management_system.dir\manager.cpp.obj -c H:\learn\C++\Staff_management_system\manager.cpp

CMakeFiles/Staff_management_system.dir/manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Staff_management_system.dir/manager.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:\learn\C++\Staff_management_system\manager.cpp > CMakeFiles\Staff_management_system.dir\manager.cpp.i

CMakeFiles/Staff_management_system.dir/manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Staff_management_system.dir/manager.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:\learn\C++\Staff_management_system\manager.cpp -o CMakeFiles\Staff_management_system.dir\manager.cpp.s

CMakeFiles/Staff_management_system.dir/boss.cpp.obj: CMakeFiles/Staff_management_system.dir/flags.make
CMakeFiles/Staff_management_system.dir/boss.cpp.obj: ../boss.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\learn\C++\Staff_management_system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Staff_management_system.dir/boss.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Staff_management_system.dir\boss.cpp.obj -c H:\learn\C++\Staff_management_system\boss.cpp

CMakeFiles/Staff_management_system.dir/boss.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Staff_management_system.dir/boss.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:\learn\C++\Staff_management_system\boss.cpp > CMakeFiles\Staff_management_system.dir\boss.cpp.i

CMakeFiles/Staff_management_system.dir/boss.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Staff_management_system.dir/boss.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:\learn\C++\Staff_management_system\boss.cpp -o CMakeFiles\Staff_management_system.dir\boss.cpp.s

# Object files for target Staff_management_system
Staff_management_system_OBJECTS = \
"CMakeFiles/Staff_management_system.dir/main.cpp.obj" \
"CMakeFiles/Staff_management_system.dir/workerManager.cpp.obj" \
"CMakeFiles/Staff_management_system.dir/employee.cpp.obj" \
"CMakeFiles/Staff_management_system.dir/manager.cpp.obj" \
"CMakeFiles/Staff_management_system.dir/boss.cpp.obj"

# External object files for target Staff_management_system
Staff_management_system_EXTERNAL_OBJECTS =

Staff_management_system.exe: CMakeFiles/Staff_management_system.dir/main.cpp.obj
Staff_management_system.exe: CMakeFiles/Staff_management_system.dir/workerManager.cpp.obj
Staff_management_system.exe: CMakeFiles/Staff_management_system.dir/employee.cpp.obj
Staff_management_system.exe: CMakeFiles/Staff_management_system.dir/manager.cpp.obj
Staff_management_system.exe: CMakeFiles/Staff_management_system.dir/boss.cpp.obj
Staff_management_system.exe: CMakeFiles/Staff_management_system.dir/build.make
Staff_management_system.exe: CMakeFiles/Staff_management_system.dir/linklibs.rsp
Staff_management_system.exe: CMakeFiles/Staff_management_system.dir/objects1.rsp
Staff_management_system.exe: CMakeFiles/Staff_management_system.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=H:\learn\C++\Staff_management_system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Staff_management_system.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Staff_management_system.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Staff_management_system.dir/build: Staff_management_system.exe

.PHONY : CMakeFiles/Staff_management_system.dir/build

CMakeFiles/Staff_management_system.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Staff_management_system.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Staff_management_system.dir/clean

CMakeFiles/Staff_management_system.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" H:\learn\C++\Staff_management_system H:\learn\C++\Staff_management_system H:\learn\C++\Staff_management_system\cmake-build-debug H:\learn\C++\Staff_management_system\cmake-build-debug H:\learn\C++\Staff_management_system\cmake-build-debug\CMakeFiles\Staff_management_system.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Staff_management_system.dir/depend
