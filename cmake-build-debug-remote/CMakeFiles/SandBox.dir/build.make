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
include CMakeFiles/SandBox.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SandBox.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SandBox.dir/flags.make

CMakeFiles/SandBox.dir/sand_box.c.o: CMakeFiles/SandBox.dir/flags.make
CMakeFiles/SandBox.dir/sand_box.c.o: ../sand_box.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SandBox.dir/sand_box.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SandBox.dir/sand_box.c.o   -c /tmp/tmp.baeLfqmR5V/sand_box.c

CMakeFiles/SandBox.dir/sand_box.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SandBox.dir/sand_box.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/sand_box.c > CMakeFiles/SandBox.dir/sand_box.c.i

CMakeFiles/SandBox.dir/sand_box.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SandBox.dir/sand_box.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/sand_box.c -o CMakeFiles/SandBox.dir/sand_box.c.s

CMakeFiles/SandBox.dir/list.c.o: CMakeFiles/SandBox.dir/flags.make
CMakeFiles/SandBox.dir/list.c.o: ../list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/SandBox.dir/list.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SandBox.dir/list.c.o   -c /tmp/tmp.baeLfqmR5V/list.c

CMakeFiles/SandBox.dir/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SandBox.dir/list.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/list.c > CMakeFiles/SandBox.dir/list.c.i

CMakeFiles/SandBox.dir/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SandBox.dir/list.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/list.c -o CMakeFiles/SandBox.dir/list.c.s

CMakeFiles/SandBox.dir/instruction_word.c.o: CMakeFiles/SandBox.dir/flags.make
CMakeFiles/SandBox.dir/instruction_word.c.o: ../instruction_word.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/SandBox.dir/instruction_word.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SandBox.dir/instruction_word.c.o   -c /tmp/tmp.baeLfqmR5V/instruction_word.c

CMakeFiles/SandBox.dir/instruction_word.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SandBox.dir/instruction_word.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/instruction_word.c > CMakeFiles/SandBox.dir/instruction_word.c.i

CMakeFiles/SandBox.dir/instruction_word.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SandBox.dir/instruction_word.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/instruction_word.c -o CMakeFiles/SandBox.dir/instruction_word.c.s

CMakeFiles/SandBox.dir/parser.c.o: CMakeFiles/SandBox.dir/flags.make
CMakeFiles/SandBox.dir/parser.c.o: ../parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/SandBox.dir/parser.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SandBox.dir/parser.c.o   -c /tmp/tmp.baeLfqmR5V/parser.c

CMakeFiles/SandBox.dir/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SandBox.dir/parser.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/parser.c > CMakeFiles/SandBox.dir/parser.c.i

CMakeFiles/SandBox.dir/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SandBox.dir/parser.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/parser.c -o CMakeFiles/SandBox.dir/parser.c.s

CMakeFiles/SandBox.dir/errors.c.o: CMakeFiles/SandBox.dir/flags.make
CMakeFiles/SandBox.dir/errors.c.o: ../errors.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/SandBox.dir/errors.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SandBox.dir/errors.c.o   -c /tmp/tmp.baeLfqmR5V/errors.c

CMakeFiles/SandBox.dir/errors.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SandBox.dir/errors.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/errors.c > CMakeFiles/SandBox.dir/errors.c.i

CMakeFiles/SandBox.dir/errors.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SandBox.dir/errors.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/errors.c -o CMakeFiles/SandBox.dir/errors.c.s

CMakeFiles/SandBox.dir/code_table.c.o: CMakeFiles/SandBox.dir/flags.make
CMakeFiles/SandBox.dir/code_table.c.o: ../code_table.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/SandBox.dir/code_table.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SandBox.dir/code_table.c.o   -c /tmp/tmp.baeLfqmR5V/code_table.c

CMakeFiles/SandBox.dir/code_table.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SandBox.dir/code_table.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/code_table.c > CMakeFiles/SandBox.dir/code_table.c.i

CMakeFiles/SandBox.dir/code_table.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SandBox.dir/code_table.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/code_table.c -o CMakeFiles/SandBox.dir/code_table.c.s

CMakeFiles/SandBox.dir/data_table.c.o: CMakeFiles/SandBox.dir/flags.make
CMakeFiles/SandBox.dir/data_table.c.o: ../data_table.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/SandBox.dir/data_table.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SandBox.dir/data_table.c.o   -c /tmp/tmp.baeLfqmR5V/data_table.c

CMakeFiles/SandBox.dir/data_table.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SandBox.dir/data_table.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/data_table.c > CMakeFiles/SandBox.dir/data_table.c.i

CMakeFiles/SandBox.dir/data_table.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SandBox.dir/data_table.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/data_table.c -o CMakeFiles/SandBox.dir/data_table.c.s

CMakeFiles/SandBox.dir/symbol_table.c.o: CMakeFiles/SandBox.dir/flags.make
CMakeFiles/SandBox.dir/symbol_table.c.o: ../symbol_table.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/SandBox.dir/symbol_table.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SandBox.dir/symbol_table.c.o   -c /tmp/tmp.baeLfqmR5V/symbol_table.c

CMakeFiles/SandBox.dir/symbol_table.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SandBox.dir/symbol_table.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/symbol_table.c > CMakeFiles/SandBox.dir/symbol_table.c.i

CMakeFiles/SandBox.dir/symbol_table.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SandBox.dir/symbol_table.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/symbol_table.c -o CMakeFiles/SandBox.dir/symbol_table.c.s

CMakeFiles/SandBox.dir/builder.c.o: CMakeFiles/SandBox.dir/flags.make
CMakeFiles/SandBox.dir/builder.c.o: ../builder.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/SandBox.dir/builder.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SandBox.dir/builder.c.o   -c /tmp/tmp.baeLfqmR5V/builder.c

CMakeFiles/SandBox.dir/builder.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SandBox.dir/builder.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/builder.c > CMakeFiles/SandBox.dir/builder.c.i

CMakeFiles/SandBox.dir/builder.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SandBox.dir/builder.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/builder.c -o CMakeFiles/SandBox.dir/builder.c.s

CMakeFiles/SandBox.dir/reader.c.o: CMakeFiles/SandBox.dir/flags.make
CMakeFiles/SandBox.dir/reader.c.o: ../reader.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/SandBox.dir/reader.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SandBox.dir/reader.c.o   -c /tmp/tmp.baeLfqmR5V/reader.c

CMakeFiles/SandBox.dir/reader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SandBox.dir/reader.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/reader.c > CMakeFiles/SandBox.dir/reader.c.i

CMakeFiles/SandBox.dir/reader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SandBox.dir/reader.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/reader.c -o CMakeFiles/SandBox.dir/reader.c.s

CMakeFiles/SandBox.dir/printer.c.o: CMakeFiles/SandBox.dir/flags.make
CMakeFiles/SandBox.dir/printer.c.o: ../printer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/SandBox.dir/printer.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SandBox.dir/printer.c.o   -c /tmp/tmp.baeLfqmR5V/printer.c

CMakeFiles/SandBox.dir/printer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SandBox.dir/printer.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/printer.c > CMakeFiles/SandBox.dir/printer.c.i

CMakeFiles/SandBox.dir/printer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SandBox.dir/printer.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/printer.c -o CMakeFiles/SandBox.dir/printer.c.s

CMakeFiles/SandBox.dir/file_generator.c.o: CMakeFiles/SandBox.dir/flags.make
CMakeFiles/SandBox.dir/file_generator.c.o: ../file_generator.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/SandBox.dir/file_generator.c.o"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SandBox.dir/file_generator.c.o   -c /tmp/tmp.baeLfqmR5V/file_generator.c

CMakeFiles/SandBox.dir/file_generator.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SandBox.dir/file_generator.c.i"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.baeLfqmR5V/file_generator.c > CMakeFiles/SandBox.dir/file_generator.c.i

CMakeFiles/SandBox.dir/file_generator.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SandBox.dir/file_generator.c.s"
	/usr/bin/gcc-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.baeLfqmR5V/file_generator.c -o CMakeFiles/SandBox.dir/file_generator.c.s

# Object files for target SandBox
SandBox_OBJECTS = \
"CMakeFiles/SandBox.dir/sand_box.c.o" \
"CMakeFiles/SandBox.dir/list.c.o" \
"CMakeFiles/SandBox.dir/instruction_word.c.o" \
"CMakeFiles/SandBox.dir/parser.c.o" \
"CMakeFiles/SandBox.dir/errors.c.o" \
"CMakeFiles/SandBox.dir/code_table.c.o" \
"CMakeFiles/SandBox.dir/data_table.c.o" \
"CMakeFiles/SandBox.dir/symbol_table.c.o" \
"CMakeFiles/SandBox.dir/builder.c.o" \
"CMakeFiles/SandBox.dir/reader.c.o" \
"CMakeFiles/SandBox.dir/printer.c.o" \
"CMakeFiles/SandBox.dir/file_generator.c.o"

# External object files for target SandBox
SandBox_EXTERNAL_OBJECTS =

SandBox: CMakeFiles/SandBox.dir/sand_box.c.o
SandBox: CMakeFiles/SandBox.dir/list.c.o
SandBox: CMakeFiles/SandBox.dir/instruction_word.c.o
SandBox: CMakeFiles/SandBox.dir/parser.c.o
SandBox: CMakeFiles/SandBox.dir/errors.c.o
SandBox: CMakeFiles/SandBox.dir/code_table.c.o
SandBox: CMakeFiles/SandBox.dir/data_table.c.o
SandBox: CMakeFiles/SandBox.dir/symbol_table.c.o
SandBox: CMakeFiles/SandBox.dir/builder.c.o
SandBox: CMakeFiles/SandBox.dir/reader.c.o
SandBox: CMakeFiles/SandBox.dir/printer.c.o
SandBox: CMakeFiles/SandBox.dir/file_generator.c.o
SandBox: CMakeFiles/SandBox.dir/build.make
SandBox: CMakeFiles/SandBox.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking C executable SandBox"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SandBox.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SandBox.dir/build: SandBox

.PHONY : CMakeFiles/SandBox.dir/build

CMakeFiles/SandBox.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SandBox.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SandBox.dir/clean

CMakeFiles/SandBox.dir/depend:
	cd /tmp/tmp.baeLfqmR5V/cmake-build-debug-remote && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.baeLfqmR5V /tmp/tmp.baeLfqmR5V /tmp/tmp.baeLfqmR5V/cmake-build-debug-remote /tmp/tmp.baeLfqmR5V/cmake-build-debug-remote /tmp/tmp.baeLfqmR5V/cmake-build-debug-remote/CMakeFiles/SandBox.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SandBox.dir/depend
