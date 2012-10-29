# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/win7/Dropbox/Project/Server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/win7/Dropbox/Project/Server

# Include any dependencies generated for this target.
include network/CMakeFiles/networkBase.dir/depend.make

# Include the progress variables for this target.
include network/CMakeFiles/networkBase.dir/progress.make

# Include the compile flags for this target's objects.
include network/CMakeFiles/networkBase.dir/flags.make

network/CMakeFiles/networkBase.dir/ThreadPool.cpp.o: network/CMakeFiles/networkBase.dir/flags.make
network/CMakeFiles/networkBase.dir/ThreadPool.cpp.o: network/ThreadPool.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/win7/Dropbox/Project/Server/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object network/CMakeFiles/networkBase.dir/ThreadPool.cpp.o"
	cd /root/win7/Dropbox/Project/Server/network && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/networkBase.dir/ThreadPool.cpp.o -c /root/win7/Dropbox/Project/Server/network/ThreadPool.cpp

network/CMakeFiles/networkBase.dir/ThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/networkBase.dir/ThreadPool.cpp.i"
	cd /root/win7/Dropbox/Project/Server/network && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/win7/Dropbox/Project/Server/network/ThreadPool.cpp > CMakeFiles/networkBase.dir/ThreadPool.cpp.i

network/CMakeFiles/networkBase.dir/ThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/networkBase.dir/ThreadPool.cpp.s"
	cd /root/win7/Dropbox/Project/Server/network && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/win7/Dropbox/Project/Server/network/ThreadPool.cpp -o CMakeFiles/networkBase.dir/ThreadPool.cpp.s

network/CMakeFiles/networkBase.dir/ThreadPool.cpp.o.requires:
.PHONY : network/CMakeFiles/networkBase.dir/ThreadPool.cpp.o.requires

network/CMakeFiles/networkBase.dir/ThreadPool.cpp.o.provides: network/CMakeFiles/networkBase.dir/ThreadPool.cpp.o.requires
	$(MAKE) -f network/CMakeFiles/networkBase.dir/build.make network/CMakeFiles/networkBase.dir/ThreadPool.cpp.o.provides.build
.PHONY : network/CMakeFiles/networkBase.dir/ThreadPool.cpp.o.provides

network/CMakeFiles/networkBase.dir/ThreadPool.cpp.o.provides.build: network/CMakeFiles/networkBase.dir/ThreadPool.cpp.o

network/CMakeFiles/networkBase.dir/TaskManager.cpp.o: network/CMakeFiles/networkBase.dir/flags.make
network/CMakeFiles/networkBase.dir/TaskManager.cpp.o: network/TaskManager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/win7/Dropbox/Project/Server/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object network/CMakeFiles/networkBase.dir/TaskManager.cpp.o"
	cd /root/win7/Dropbox/Project/Server/network && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/networkBase.dir/TaskManager.cpp.o -c /root/win7/Dropbox/Project/Server/network/TaskManager.cpp

network/CMakeFiles/networkBase.dir/TaskManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/networkBase.dir/TaskManager.cpp.i"
	cd /root/win7/Dropbox/Project/Server/network && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/win7/Dropbox/Project/Server/network/TaskManager.cpp > CMakeFiles/networkBase.dir/TaskManager.cpp.i

network/CMakeFiles/networkBase.dir/TaskManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/networkBase.dir/TaskManager.cpp.s"
	cd /root/win7/Dropbox/Project/Server/network && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/win7/Dropbox/Project/Server/network/TaskManager.cpp -o CMakeFiles/networkBase.dir/TaskManager.cpp.s

network/CMakeFiles/networkBase.dir/TaskManager.cpp.o.requires:
.PHONY : network/CMakeFiles/networkBase.dir/TaskManager.cpp.o.requires

network/CMakeFiles/networkBase.dir/TaskManager.cpp.o.provides: network/CMakeFiles/networkBase.dir/TaskManager.cpp.o.requires
	$(MAKE) -f network/CMakeFiles/networkBase.dir/build.make network/CMakeFiles/networkBase.dir/TaskManager.cpp.o.provides.build
.PHONY : network/CMakeFiles/networkBase.dir/TaskManager.cpp.o.provides

network/CMakeFiles/networkBase.dir/TaskManager.cpp.o.provides.build: network/CMakeFiles/networkBase.dir/TaskManager.cpp.o

network/CMakeFiles/networkBase.dir/CommonSocketThread.cpp.o: network/CMakeFiles/networkBase.dir/flags.make
network/CMakeFiles/networkBase.dir/CommonSocketThread.cpp.o: network/CommonSocketThread.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/win7/Dropbox/Project/Server/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object network/CMakeFiles/networkBase.dir/CommonSocketThread.cpp.o"
	cd /root/win7/Dropbox/Project/Server/network && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/networkBase.dir/CommonSocketThread.cpp.o -c /root/win7/Dropbox/Project/Server/network/CommonSocketThread.cpp

network/CMakeFiles/networkBase.dir/CommonSocketThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/networkBase.dir/CommonSocketThread.cpp.i"
	cd /root/win7/Dropbox/Project/Server/network && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/win7/Dropbox/Project/Server/network/CommonSocketThread.cpp > CMakeFiles/networkBase.dir/CommonSocketThread.cpp.i

network/CMakeFiles/networkBase.dir/CommonSocketThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/networkBase.dir/CommonSocketThread.cpp.s"
	cd /root/win7/Dropbox/Project/Server/network && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/win7/Dropbox/Project/Server/network/CommonSocketThread.cpp -o CMakeFiles/networkBase.dir/CommonSocketThread.cpp.s

network/CMakeFiles/networkBase.dir/CommonSocketThread.cpp.o.requires:
.PHONY : network/CMakeFiles/networkBase.dir/CommonSocketThread.cpp.o.requires

network/CMakeFiles/networkBase.dir/CommonSocketThread.cpp.o.provides: network/CMakeFiles/networkBase.dir/CommonSocketThread.cpp.o.requires
	$(MAKE) -f network/CMakeFiles/networkBase.dir/build.make network/CMakeFiles/networkBase.dir/CommonSocketThread.cpp.o.provides.build
.PHONY : network/CMakeFiles/networkBase.dir/CommonSocketThread.cpp.o.provides

network/CMakeFiles/networkBase.dir/CommonSocketThread.cpp.o.provides.build: network/CMakeFiles/networkBase.dir/CommonSocketThread.cpp.o

network/CMakeFiles/networkBase.dir/ScopeMutex.cpp.o: network/CMakeFiles/networkBase.dir/flags.make
network/CMakeFiles/networkBase.dir/ScopeMutex.cpp.o: network/ScopeMutex.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/win7/Dropbox/Project/Server/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object network/CMakeFiles/networkBase.dir/ScopeMutex.cpp.o"
	cd /root/win7/Dropbox/Project/Server/network && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/networkBase.dir/ScopeMutex.cpp.o -c /root/win7/Dropbox/Project/Server/network/ScopeMutex.cpp

network/CMakeFiles/networkBase.dir/ScopeMutex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/networkBase.dir/ScopeMutex.cpp.i"
	cd /root/win7/Dropbox/Project/Server/network && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/win7/Dropbox/Project/Server/network/ScopeMutex.cpp > CMakeFiles/networkBase.dir/ScopeMutex.cpp.i

network/CMakeFiles/networkBase.dir/ScopeMutex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/networkBase.dir/ScopeMutex.cpp.s"
	cd /root/win7/Dropbox/Project/Server/network && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/win7/Dropbox/Project/Server/network/ScopeMutex.cpp -o CMakeFiles/networkBase.dir/ScopeMutex.cpp.s

network/CMakeFiles/networkBase.dir/ScopeMutex.cpp.o.requires:
.PHONY : network/CMakeFiles/networkBase.dir/ScopeMutex.cpp.o.requires

network/CMakeFiles/networkBase.dir/ScopeMutex.cpp.o.provides: network/CMakeFiles/networkBase.dir/ScopeMutex.cpp.o.requires
	$(MAKE) -f network/CMakeFiles/networkBase.dir/build.make network/CMakeFiles/networkBase.dir/ScopeMutex.cpp.o.provides.build
.PHONY : network/CMakeFiles/networkBase.dir/ScopeMutex.cpp.o.provides

network/CMakeFiles/networkBase.dir/ScopeMutex.cpp.o.provides.build: network/CMakeFiles/networkBase.dir/ScopeMutex.cpp.o

network/CMakeFiles/networkBase.dir/condition.cpp.o: network/CMakeFiles/networkBase.dir/flags.make
network/CMakeFiles/networkBase.dir/condition.cpp.o: network/condition.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/win7/Dropbox/Project/Server/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object network/CMakeFiles/networkBase.dir/condition.cpp.o"
	cd /root/win7/Dropbox/Project/Server/network && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/networkBase.dir/condition.cpp.o -c /root/win7/Dropbox/Project/Server/network/condition.cpp

network/CMakeFiles/networkBase.dir/condition.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/networkBase.dir/condition.cpp.i"
	cd /root/win7/Dropbox/Project/Server/network && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/win7/Dropbox/Project/Server/network/condition.cpp > CMakeFiles/networkBase.dir/condition.cpp.i

network/CMakeFiles/networkBase.dir/condition.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/networkBase.dir/condition.cpp.s"
	cd /root/win7/Dropbox/Project/Server/network && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/win7/Dropbox/Project/Server/network/condition.cpp -o CMakeFiles/networkBase.dir/condition.cpp.s

network/CMakeFiles/networkBase.dir/condition.cpp.o.requires:
.PHONY : network/CMakeFiles/networkBase.dir/condition.cpp.o.requires

network/CMakeFiles/networkBase.dir/condition.cpp.o.provides: network/CMakeFiles/networkBase.dir/condition.cpp.o.requires
	$(MAKE) -f network/CMakeFiles/networkBase.dir/build.make network/CMakeFiles/networkBase.dir/condition.cpp.o.provides.build
.PHONY : network/CMakeFiles/networkBase.dir/condition.cpp.o.provides

network/CMakeFiles/networkBase.dir/condition.cpp.o.provides.build: network/CMakeFiles/networkBase.dir/condition.cpp.o

network/CMakeFiles/networkBase.dir/Thread.cpp.o: network/CMakeFiles/networkBase.dir/flags.make
network/CMakeFiles/networkBase.dir/Thread.cpp.o: network/Thread.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/win7/Dropbox/Project/Server/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object network/CMakeFiles/networkBase.dir/Thread.cpp.o"
	cd /root/win7/Dropbox/Project/Server/network && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/networkBase.dir/Thread.cpp.o -c /root/win7/Dropbox/Project/Server/network/Thread.cpp

network/CMakeFiles/networkBase.dir/Thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/networkBase.dir/Thread.cpp.i"
	cd /root/win7/Dropbox/Project/Server/network && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/win7/Dropbox/Project/Server/network/Thread.cpp > CMakeFiles/networkBase.dir/Thread.cpp.i

network/CMakeFiles/networkBase.dir/Thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/networkBase.dir/Thread.cpp.s"
	cd /root/win7/Dropbox/Project/Server/network && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/win7/Dropbox/Project/Server/network/Thread.cpp -o CMakeFiles/networkBase.dir/Thread.cpp.s

network/CMakeFiles/networkBase.dir/Thread.cpp.o.requires:
.PHONY : network/CMakeFiles/networkBase.dir/Thread.cpp.o.requires

network/CMakeFiles/networkBase.dir/Thread.cpp.o.provides: network/CMakeFiles/networkBase.dir/Thread.cpp.o.requires
	$(MAKE) -f network/CMakeFiles/networkBase.dir/build.make network/CMakeFiles/networkBase.dir/Thread.cpp.o.provides.build
.PHONY : network/CMakeFiles/networkBase.dir/Thread.cpp.o.provides

network/CMakeFiles/networkBase.dir/Thread.cpp.o.provides.build: network/CMakeFiles/networkBase.dir/Thread.cpp.o

# Object files for target networkBase
networkBase_OBJECTS = \
"CMakeFiles/networkBase.dir/ThreadPool.cpp.o" \
"CMakeFiles/networkBase.dir/TaskManager.cpp.o" \
"CMakeFiles/networkBase.dir/CommonSocketThread.cpp.o" \
"CMakeFiles/networkBase.dir/ScopeMutex.cpp.o" \
"CMakeFiles/networkBase.dir/condition.cpp.o" \
"CMakeFiles/networkBase.dir/Thread.cpp.o"

# External object files for target networkBase
networkBase_EXTERNAL_OBJECTS =

network/libnetworkBase.a: network/CMakeFiles/networkBase.dir/ThreadPool.cpp.o
network/libnetworkBase.a: network/CMakeFiles/networkBase.dir/TaskManager.cpp.o
network/libnetworkBase.a: network/CMakeFiles/networkBase.dir/CommonSocketThread.cpp.o
network/libnetworkBase.a: network/CMakeFiles/networkBase.dir/ScopeMutex.cpp.o
network/libnetworkBase.a: network/CMakeFiles/networkBase.dir/condition.cpp.o
network/libnetworkBase.a: network/CMakeFiles/networkBase.dir/Thread.cpp.o
network/libnetworkBase.a: network/CMakeFiles/networkBase.dir/build.make
network/libnetworkBase.a: network/CMakeFiles/networkBase.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libnetworkBase.a"
	cd /root/win7/Dropbox/Project/Server/network && $(CMAKE_COMMAND) -P CMakeFiles/networkBase.dir/cmake_clean_target.cmake
	cd /root/win7/Dropbox/Project/Server/network && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/networkBase.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
network/CMakeFiles/networkBase.dir/build: network/libnetworkBase.a
.PHONY : network/CMakeFiles/networkBase.dir/build

network/CMakeFiles/networkBase.dir/requires: network/CMakeFiles/networkBase.dir/ThreadPool.cpp.o.requires
network/CMakeFiles/networkBase.dir/requires: network/CMakeFiles/networkBase.dir/TaskManager.cpp.o.requires
network/CMakeFiles/networkBase.dir/requires: network/CMakeFiles/networkBase.dir/CommonSocketThread.cpp.o.requires
network/CMakeFiles/networkBase.dir/requires: network/CMakeFiles/networkBase.dir/ScopeMutex.cpp.o.requires
network/CMakeFiles/networkBase.dir/requires: network/CMakeFiles/networkBase.dir/condition.cpp.o.requires
network/CMakeFiles/networkBase.dir/requires: network/CMakeFiles/networkBase.dir/Thread.cpp.o.requires
.PHONY : network/CMakeFiles/networkBase.dir/requires

network/CMakeFiles/networkBase.dir/clean:
	cd /root/win7/Dropbox/Project/Server/network && $(CMAKE_COMMAND) -P CMakeFiles/networkBase.dir/cmake_clean.cmake
.PHONY : network/CMakeFiles/networkBase.dir/clean

network/CMakeFiles/networkBase.dir/depend:
	cd /root/win7/Dropbox/Project/Server && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/win7/Dropbox/Project/Server /root/win7/Dropbox/Project/Server/network /root/win7/Dropbox/Project/Server /root/win7/Dropbox/Project/Server/network /root/win7/Dropbox/Project/Server/network/CMakeFiles/networkBase.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : network/CMakeFiles/networkBase.dir/depend

