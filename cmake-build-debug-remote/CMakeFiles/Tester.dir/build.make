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
include CMakeFiles/Tester.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tester.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tester.dir/flags.make

CMakeFiles/Tester.dir/list.c.o: CMakeFiles/Tester.dir/flags.make
CMakeFiles/Tester.dir/list.c.o: ../list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Tester.dir/list.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tester.dir/list.c.o   -c /tmp/tmp.baeLfqmR5V/list.c

CMakeFiles/Tester.dir/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tester.dir/list.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/list.c > CMakeFiles/Tester.dir/list.c.i

CMakeFiles/Tester.dir/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tester.dir/list.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/list.c -o CMakeFiles/Tester.dir/list.c.s

CMakeFiles/Tester.dir/instruction_word.c.o: CMakeFiles/Tester.dir/flags.make
CMakeFiles/Tester.dir/instruction_word.c.o: ../instruction_word.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Tester.dir/instruction_word.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tester.dir/instruction_word.c.o   -c /tmp/tmp.baeLfqmR5V/instruction_word.c

CMakeFiles/Tester.dir/instruction_word.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tester.dir/instruction_word.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/instruction_word.c > CMakeFiles/Tester.dir/instruction_word.c.i

CMakeFiles/Tester.dir/instruction_word.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tester.dir/instruction_word.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/instruction_word.c -o CMakeFiles/Tester.dir/instruction_word.c.s

CMakeFiles/Tester.dir/parser.c.o: CMakeFiles/Tester.dir/flags.make
CMakeFiles/Tester.dir/parser.c.o: ../parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Tester.dir/parser.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tester.dir/parser.c.o   -c /tmp/tmp.baeLfqmR5V/parser.c

CMakeFiles/Tester.dir/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tester.dir/parser.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/parser.c > CMakeFiles/Tester.dir/parser.c.i

CMakeFiles/Tester.dir/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tester.dir/parser.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/parser.c -o CMakeFiles/Tester.dir/parser.c.s

CMakeFiles/Tester.dir/errors.c.o: CMakeFiles/Tester.dir/flags.make
CMakeFiles/Tester.dir/errors.c.o: ../errors.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Tester.dir/errors.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tester.dir/errors.c.o   -c /tmp/tmp.baeLfqmR5V/errors.c

CMakeFiles/Tester.dir/errors.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tester.dir/errors.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/errors.c > CMakeFiles/Tester.dir/errors.c.i

CMakeFiles/Tester.dir/errors.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tester.dir/errors.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/errors.c -o CMakeFiles/Tester.dir/errors.c.s

CMakeFiles/Tester.dir/code_table.c.o: CMakeFiles/Tester.dir/flags.make
CMakeFiles/Tester.dir/code_table.c.o: ../code_table.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Tester.dir/code_table.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tester.dir/code_table.c.o   -c /tmp/tmp.baeLfqmR5V/code_table.c

CMakeFiles/Tester.dir/code_table.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tester.dir/code_table.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/code_table.c > CMakeFiles/Tester.dir/code_table.c.i

CMakeFiles/Tester.dir/code_table.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tester.dir/code_table.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/code_table.c -o CMakeFiles/Tester.dir/code_table.c.s

CMakeFiles/Tester.dir/data_table.c.o: CMakeFiles/Tester.dir/flags.make
CMakeFiles/Tester.dir/data_table.c.o: ../data_table.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Tester.dir/data_table.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tester.dir/data_table.c.o   -c /tmp/tmp.baeLfqmR5V/data_table.c

CMakeFiles/Tester.dir/data_table.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tester.dir/data_table.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/data_table.c > CMakeFiles/Tester.dir/data_table.c.i

CMakeFiles/Tester.dir/data_table.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tester.dir/data_table.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/data_table.c -o CMakeFiles/Tester.dir/data_table.c.s

CMakeFiles/Tester.dir/symbol_table.c.o: CMakeFiles/Tester.dir/flags.make
CMakeFiles/Tester.dir/symbol_table.c.o: ../symbol_table.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/Tester.dir/symbol_table.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tester.dir/symbol_table.c.o   -c /tmp/tmp.baeLfqmR5V/symbol_table.c

CMakeFiles/Tester.dir/symbol_table.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tester.dir/symbol_table.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/symbol_table.c > CMakeFiles/Tester.dir/symbol_table.c.i

CMakeFiles/Tester.dir/symbol_table.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tester.dir/symbol_table.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/symbol_table.c -o CMakeFiles/Tester.dir/symbol_table.c.s

CMakeFiles/Tester.dir/builder.c.o: CMakeFiles/Tester.dir/flags.make
CMakeFiles/Tester.dir/builder.c.o: ../builder.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/Tester.dir/builder.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tester.dir/builder.c.o   -c /tmp/tmp.baeLfqmR5V/builder.c

CMakeFiles/Tester.dir/builder.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tester.dir/builder.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/builder.c > CMakeFiles/Tester.dir/builder.c.i

CMakeFiles/Tester.dir/builder.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tester.dir/builder.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/builder.c -o CMakeFiles/Tester.dir/builder.c.s

CMakeFiles/Tester.dir/tester.c.o: CMakeFiles/Tester.dir/flags.make
CMakeFiles/Tester.dir/tester.c.o: ../tester.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/Tester.dir/tester.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tester.dir/tester.c.o   -c /tmp/tmp.baeLfqmR5V/tester.c

CMakeFiles/Tester.dir/tester.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tester.dir/tester.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/tester.c > CMakeFiles/Tester.dir/tester.c.i

CMakeFiles/Tester.dir/tester.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tester.dir/tester.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/tester.c -o CMakeFiles/Tester.dir/tester.c.s

CMakeFiles/Tester.dir/reader.c.o: CMakeFiles/Tester.dir/flags.make
CMakeFiles/Tester.dir/reader.c.o: ../reader.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/Tester.dir/reader.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tester.dir/reader.c.o   -c /tmp/tmp.baeLfqmR5V/reader.c

CMakeFiles/Tester.dir/reader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tester.dir/reader.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/reader.c > CMakeFiles/Tester.dir/reader.c.i

CMakeFiles/Tester.dir/reader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tester.dir/reader.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/reader.c -o CMakeFiles/Tester.dir/reader.c.s

CMakeFiles/Tester.dir/printer.c.o: CMakeFiles/Tester.dir/flags.make
CMakeFiles/Tester.dir/printer.c.o: ../printer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/Tester.dir/printer.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tester.dir/printer.c.o   -c /tmp/tmp.baeLfqmR5V/printer.c

CMakeFiles/Tester.dir/printer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tester.dir/printer.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/printer.c > CMakeFiles/Tester.dir/printer.c.i

CMakeFiles/Tester.dir/printer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tester.dir/printer.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/printer.c -o CMakeFiles/Tester.dir/printer.c.s

CMakeFiles/Tester.dir/file_generator.c.o: CMakeFiles/Tester.dir/flags.make
CMakeFiles/Tester.dir/file_generator.c.o: ../file_generator.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/Tester.dir/file_generator.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tester.dir/file_generator.c.o   -c /tmp/tmp.baeLfqmR5V/file_generator.c

CMakeFiles/Tester.dir/file_generator.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tester.dir/file_generator.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/file_generator.c > CMakeFiles/Tester.dir/file_generator.c.i

CMakeFiles/Tester.dir/file_generator.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tester.dir/file_generator.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/file_generator.c -o CMakeFiles/Tester.dir/file_generator.c.s

# Object files for target Tester
Tester_OBJECTS = \
"CMakeFiles/Tester.dir/list.c.o" \
"CMakeFiles/Tester.dir/instruction_word.c.o" \
"CMakeFiles/Tester.dir/parser.c.o" \
"CMakeFiles/Tester.dir/errors.c.o" \
"CMakeFiles/Tester.dir/code_table.c.o" \
"CMakeFiles/Tester.dir/data_table.c.o" \
"CMakeFiles/Tester.dir/symbol_table.c.o" \
"CMakeFiles/Tester.dir/builder.c.o" \
"CMakeFiles/Tester.dir/tester.c.o" \
"CMakeFiles/Tester.dir/reader.c.o" \
"CMakeFiles/Tester.dir/printer.c.o" \
"CMakeFiles/Tester.dir/file_generator.c.o"

# External object files for target Tester
Tester_EXTERNAL_OBJECTS =

Tester: CMakeFiles/Tester.dir/list.c.o
Tester: CMakeFiles/Tester.dir/instruction_word.c.o
Tester: CMakeFiles/Tester.dir/parser.c.o
Tester: CMakeFiles/Tester.dir/errors.c.o
Tester: CMakeFiles/Tester.dir/code_table.c.o
Tester: CMakeFiles/Tester.dir/data_table.c.o
Tester: CMakeFiles/Tester.dir/symbol_table.c.o
Tester: CMakeFiles/Tester.dir/builder.c.o
Tester: CMakeFiles/Tester.dir/tester.c.o
Tester: CMakeFiles/Tester.dir/reader.c.o
Tester: CMakeFiles/Tester.dir/printer.c.o
Tester: CMakeFiles/Tester.dir/file_generator.c.o
Tester: CMakeFiles/Tester.dir/build.make
Tester: CMakeFiles/Tester.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking C executable Tester"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tester.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tester.dir/build: Tester

.PHONY : CMakeFiles/Tester.dir/build

CMakeFiles/Tester.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tester.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tester.dir/clean

CMakeFiles/Tester.dir/depend:
	cd /tmp/tmp.baeLfqmR5V/cmake-build-debug-remote && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.baeLfqmR5V /tmp/tmp.baeLfqmR5V /tmp/tmp.baeLfqmR5V/cmake-build-debug-remote /tmp/tmp.baeLfqmR5V/cmake-build-debug-remote /tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles/Tester.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tester.dir/depend

