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

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /vagrant/workspace/CM_FW

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /vagrant/workspace/CM_FW/build

# Include any dependencies generated for this target.
include P2P/CMakeFiles/P2P.dir/depend.make

# Include the progress variables for this target.
include P2P/CMakeFiles/P2P.dir/progress.make

# Include the compile flags for this target's objects.
include P2P/CMakeFiles/P2P.dir/flags.make

P2P/CMakeFiles/P2P.dir/src/P2P.c.o: P2P/CMakeFiles/P2P.dir/flags.make
P2P/CMakeFiles/P2P.dir/src/P2P.c.o: ../P2P/src/P2P.c
	$(CMAKE_COMMAND) -E cmake_progress_report /vagrant/workspace/CM_FW/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object P2P/CMakeFiles/P2P.dir/src/P2P.c.o"
	cd /vagrant/workspace/CM_FW/build/P2P && /opt/fsl-networking/QorIQ-SDK-V1.7/sysroots/i686-fslsdk-linux/usr/bin/powerpc-fsl-linux-gnuspe/powerpc-fsl-linux-gnuspe-gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/P2P.dir/src/P2P.c.o   -c /vagrant/workspace/CM_FW/P2P/src/P2P.c

P2P/CMakeFiles/P2P.dir/src/P2P.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/P2P.dir/src/P2P.c.i"
	cd /vagrant/workspace/CM_FW/build/P2P && /opt/fsl-networking/QorIQ-SDK-V1.7/sysroots/i686-fslsdk-linux/usr/bin/powerpc-fsl-linux-gnuspe/powerpc-fsl-linux-gnuspe-gcc  $(C_DEFINES) $(C_FLAGS) -E /vagrant/workspace/CM_FW/P2P/src/P2P.c > CMakeFiles/P2P.dir/src/P2P.c.i

P2P/CMakeFiles/P2P.dir/src/P2P.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/P2P.dir/src/P2P.c.s"
	cd /vagrant/workspace/CM_FW/build/P2P && /opt/fsl-networking/QorIQ-SDK-V1.7/sysroots/i686-fslsdk-linux/usr/bin/powerpc-fsl-linux-gnuspe/powerpc-fsl-linux-gnuspe-gcc  $(C_DEFINES) $(C_FLAGS) -S /vagrant/workspace/CM_FW/P2P/src/P2P.c -o CMakeFiles/P2P.dir/src/P2P.c.s

P2P/CMakeFiles/P2P.dir/src/P2P.c.o.requires:
.PHONY : P2P/CMakeFiles/P2P.dir/src/P2P.c.o.requires

P2P/CMakeFiles/P2P.dir/src/P2P.c.o.provides: P2P/CMakeFiles/P2P.dir/src/P2P.c.o.requires
	$(MAKE) -f P2P/CMakeFiles/P2P.dir/build.make P2P/CMakeFiles/P2P.dir/src/P2P.c.o.provides.build
.PHONY : P2P/CMakeFiles/P2P.dir/src/P2P.c.o.provides

P2P/CMakeFiles/P2P.dir/src/P2P.c.o.provides.build: P2P/CMakeFiles/P2P.dir/src/P2P.c.o

# Object files for target P2P
P2P_OBJECTS = \
"CMakeFiles/P2P.dir/src/P2P.c.o"

# External object files for target P2P
P2P_EXTERNAL_OBJECTS =

P2P/libP2P.a: P2P/CMakeFiles/P2P.dir/src/P2P.c.o
P2P/libP2P.a: P2P/CMakeFiles/P2P.dir/build.make
P2P/libP2P.a: P2P/CMakeFiles/P2P.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library libP2P.a"
	cd /vagrant/workspace/CM_FW/build/P2P && $(CMAKE_COMMAND) -P CMakeFiles/P2P.dir/cmake_clean_target.cmake
	cd /vagrant/workspace/CM_FW/build/P2P && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/P2P.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
P2P/CMakeFiles/P2P.dir/build: P2P/libP2P.a
.PHONY : P2P/CMakeFiles/P2P.dir/build

P2P/CMakeFiles/P2P.dir/requires: P2P/CMakeFiles/P2P.dir/src/P2P.c.o.requires
.PHONY : P2P/CMakeFiles/P2P.dir/requires

P2P/CMakeFiles/P2P.dir/clean:
	cd /vagrant/workspace/CM_FW/build/P2P && $(CMAKE_COMMAND) -P CMakeFiles/P2P.dir/cmake_clean.cmake
.PHONY : P2P/CMakeFiles/P2P.dir/clean

P2P/CMakeFiles/P2P.dir/depend:
	cd /vagrant/workspace/CM_FW/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /vagrant/workspace/CM_FW /vagrant/workspace/CM_FW/P2P /vagrant/workspace/CM_FW/build /vagrant/workspace/CM_FW/build/P2P /vagrant/workspace/CM_FW/build/P2P/CMakeFiles/P2P.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : P2P/CMakeFiles/P2P.dir/depend

