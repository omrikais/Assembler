# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/tmp.baeLfqmR5V

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.baeLfqmR5V/cmake-build-debug-remote

# Include any dependencies generated for this target.
include CMakeFiles/Assembler.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Assembler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assembler.dir/flags.make

CMakeFiles/Assembler.dir/list.c.o: CMakeFiles/Assembler.dir/flags.make
CMakeFiles/Assembler.dir/list.c.o: ../list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Assembler.dir/list.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assembler.dir/list.c.o   -c /tmp/tmp.baeLfqmR5V/list.c

CMakeFiles/Assembler.dir/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assembler.dir/list.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/list.c > CMakeFiles/Assembler.dir/list.c.i

CMakeFiles/Assembler.dir/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assembler.dir/list.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/list.c -o CMakeFiles/Assembler.dir/list.c.s

CMakeFiles/Assembler.dir/instruction_word.c.o: CMakeFiles/Assembler.dir/flags.make
CMakeFiles/Assembler.dir/instruction_word.c.o: ../instruction_word.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Assembler.dir/instruction_word.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assembler.dir/instruction_word.c.o   -c /tmp/tmp.baeLfqmR5V/instruction_word.c

CMakeFiles/Assembler.dir/instruction_word.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assembler.dir/instruction_word.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/instruction_word.c > CMakeFiles/Assembler.dir/instruction_word.c.i

CMakeFiles/Assembler.dir/instruction_word.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assembler.dir/instruction_word.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/instruction_word.c -o CMakeFiles/Assembler.dir/instruction_word.c.s

CMakeFiles/Assembler.dir/parser.c.o: CMakeFiles/Assembler.dir/flags.make
CMakeFiles/Assembler.dir/parser.c.o: ../parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Assembler.dir/parser.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assembler.dir/parser.c.o   -c /tmp/tmp.baeLfqmR5V/parser.c

CMakeFiles/Assembler.dir/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assembler.dir/parser.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/parser.c > CMakeFiles/Assembler.dir/parser.c.i

CMakeFiles/Assembler.dir/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assembler.dir/parser.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/parser.c -o CMakeFiles/Assembler.dir/parser.c.s

CMakeFiles/Assembler.dir/errors.c.o: CMakeFiles/Assembler.dir/flags.make
CMakeFiles/Assembler.dir/errors.c.o: ../errors.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Assembler.dir/errors.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assembler.dir/errors.c.o   -c /tmp/tmp.baeLfqmR5V/errors.c

CMakeFiles/Assembler.dir/errors.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assembler.dir/errors.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/errors.c > CMakeFiles/Assembler.dir/errors.c.i

CMakeFiles/Assembler.dir/errors.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assembler.dir/errors.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/errors.c -o CMakeFiles/Assembler.dir/errors.c.s

CMakeFiles/Assembler.dir/code_table.c.o: CMakeFiles/Assembler.dir/flags.make
CMakeFiles/Assembler.dir/code_table.c.o: ../code_table.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Assembler.dir/code_table.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assembler.dir/code_table.c.o   -c /tmp/tmp.baeLfqmR5V/code_table.c

CMakeFiles/Assembler.dir/code_table.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assembler.dir/code_table.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/code_table.c > CMakeFiles/Assembler.dir/code_table.c.i

CMakeFiles/Assembler.dir/code_table.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assembler.dir/code_table.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/code_table.c -o CMakeFiles/Assembler.dir/code_table.c.s

CMakeFiles/Assembler.dir/data_table.c.o: CMakeFiles/Assembler.dir/flags.make
CMakeFiles/Assembler.dir/data_table.c.o: ../data_table.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Assembler.dir/data_table.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assembler.dir/data_table.c.o   -c /tmp/tmp.baeLfqmR5V/data_table.c

CMakeFiles/Assembler.dir/data_table.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assembler.dir/data_table.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/data_table.c > CMakeFiles/Assembler.dir/data_table.c.i

CMakeFiles/Assembler.dir/data_table.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assembler.dir/data_table.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/data_table.c -o CMakeFiles/Assembler.dir/data_table.c.s

CMakeFiles/Assembler.dir/symbol_table.c.o: CMakeFiles/Assembler.dir/flags.make
CMakeFiles/Assembler.dir/symbol_table.c.o: ../symbol_table.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/Assembler.dir/symbol_table.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assembler.dir/symbol_table.c.o   -c /tmp/tmp.baeLfqmR5V/symbol_table.c

CMakeFiles/Assembler.dir/symbol_table.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assembler.dir/symbol_table.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/symbol_table.c > CMakeFiles/Assembler.dir/symbol_table.c.i

CMakeFiles/Assembler.dir/symbol_table.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assembler.dir/symbol_table.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/symbol_table.c -o CMakeFiles/Assembler.dir/symbol_table.c.s

CMakeFiles/Assembler.dir/builder.c.o: CMakeFiles/Assembler.dir/flags.make
CMakeFiles/Assembler.dir/builder.c.o: ../builder.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/Assembler.dir/builder.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assembler.dir/builder.c.o   -c /tmp/tmp.baeLfqmR5V/builder.c

CMakeFiles/Assembler.dir/builder.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assembler.dir/builder.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/builder.c > CMakeFiles/Assembler.dir/builder.c.i

CMakeFiles/Assembler.dir/builder.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assembler.dir/builder.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/builder.c -o CMakeFiles/Assembler.dir/builder.c.s

CMakeFiles/Assembler.dir/builder_tests.c.o: CMakeFiles/Assembler.dir/flags.make
CMakeFiles/Assembler.dir/builder_tests.c.o: ../builder_tests.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/Assembler.dir/builder_tests.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assembler.dir/builder_tests.c.o   -c /tmp/tmp.baeLfqmR5V/builder_tests.c

CMakeFiles/Assembler.dir/builder_tests.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assembler.dir/builder_tests.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/builder_tests.c > CMakeFiles/Assembler.dir/builder_tests.c.i

CMakeFiles/Assembler.dir/builder_tests.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assembler.dir/builder_tests.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/builder_tests.c -o CMakeFiles/Assembler.dir/builder_tests.c.s

CMakeFiles/Assembler.dir/reader.c.o: CMakeFiles/Assembler.dir/flags.make
CMakeFiles/Assembler.dir/reader.c.o: ../reader.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/Assembler.dir/reader.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assembler.dir/reader.c.o   -c /tmp/tmp.baeLfqmR5V/reader.c

CMakeFiles/Assembler.dir/reader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assembler.dir/reader.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/reader.c > CMakeFiles/Assembler.dir/reader.c.i

CMakeFiles/Assembler.dir/reader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assembler.dir/reader.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/reader.c -o CMakeFiles/Assembler.dir/reader.c.s

# Object files for target Assembler
Assembler_OBJECTS = \
"CMakeFiles/Assembler.dir/list.c.o" \
"CMakeFiles/Assembler.dir/instruction_word.c.o" \
"CMakeFiles/Assembler.dir/parser.c.o" \
"CMakeFiles/Assembler.dir/errors.c.o" \
"CMakeFiles/Assembler.dir/code_table.c.o" \
"CMakeFiles/Assembler.dir/data_table.c.o" \
"CMakeFiles/Assembler.dir/symbol_table.c.o" \
"CMakeFiles/Assembler.dir/builder.c.o" \
"CMakeFiles/Assembler.dir/builder_tests.c.o" \
"CMakeFiles/Assembler.dir/reader.c.o"

# External object files for target Assembler
Assembler_EXTERNAL_OBJECTS =

Assembler: CMakeFiles/Assembler.dir/list.c.o
Assembler: CMakeFiles/Assembler.dir/instruction_word.c.o
Assembler: CMakeFiles/Assembler.dir/parser.c.o
Assembler: CMakeFiles/Assembler.dir/errors.c.o
Assembler: CMakeFiles/Assembler.dir/code_table.c.o
Assembler: CMakeFiles/Assembler.dir/data_table.c.o
Assembler: CMakeFiles/Assembler.dir/symbol_table.c.o
Assembler: CMakeFiles/Assembler.dir/builder.c.o
Assembler: CMakeFiles/Assembler.dir/builder_tests.c.o
Assembler: CMakeFiles/Assembler.dir/reader.c.o
Assembler: CMakeFiles/Assembler.dir/build.make
Assembler: CMakeFiles/Assembler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C executable Assembler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Assembler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assembler.dir/build: Assembler

.PHONY : CMakeFiles/Assembler.dir/build

CMakeFiles/Assembler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Assembler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Assembler.dir/clean

CMakeFiles/Assembler.dir/depend:
	cd /tmp/tmp.baeLfqmR5V/cmake-build-debug-remote && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.baeLfqmR5V /tmp/tmp.baeLfqmR5V /tmp/tmp.baeLfqmR5V/cmake-build-debug-remote /tmp/tmp.baeLfqmR5V/cmake-build-debug-remote /tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles/Assembler.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Assembler.dir/depend

