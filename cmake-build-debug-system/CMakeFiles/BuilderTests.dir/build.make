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
CMAKE_COMMAND = "/Users/omrikaisari/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.6948.80/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/omrikaisari/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.6948.80/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/omrikaisari/CLionProjects/Assembler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/omrikaisari/CLionProjects/Assembler/cmake-build-debug-system

# Include any dependencies generated for this target.
include CMakeFiles/BuilderTests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BuilderTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BuilderTests.dir/flags.make

CMakeFiles/BuilderTests.dir/list.c.o: CMakeFiles/BuilderTests.dir/flags.make
CMakeFiles/BuilderTests.dir/list.c.o: ../list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/omrikaisari/CLionProjects/Assembler/cmake-build-debug-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/BuilderTests.dir/list.c.o"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/BuilderTests.dir/list.c.o   -c /Users/omrikaisari/CLionProjects/Assembler/list.c

CMakeFiles/BuilderTests.dir/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BuilderTests.dir/list.c.i"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/omrikaisari/CLionProjects/Assembler/list.c > CMakeFiles/BuilderTests.dir/list.c.i

CMakeFiles/BuilderTests.dir/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BuilderTests.dir/list.c.s"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/omrikaisari/CLionProjects/Assembler/list.c -o CMakeFiles/BuilderTests.dir/list.c.s

CMakeFiles/BuilderTests.dir/instruction_word.c.o: CMakeFiles/BuilderTests.dir/flags.make
CMakeFiles/BuilderTests.dir/instruction_word.c.o: ../instruction_word.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/omrikaisari/CLionProjects/Assembler/cmake-build-debug-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/BuilderTests.dir/instruction_word.c.o"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/BuilderTests.dir/instruction_word.c.o   -c /Users/omrikaisari/CLionProjects/Assembler/instruction_word.c

CMakeFiles/BuilderTests.dir/instruction_word.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BuilderTests.dir/instruction_word.c.i"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/omrikaisari/CLionProjects/Assembler/instruction_word.c > CMakeFiles/BuilderTests.dir/instruction_word.c.i

CMakeFiles/BuilderTests.dir/instruction_word.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BuilderTests.dir/instruction_word.c.s"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/omrikaisari/CLionProjects/Assembler/instruction_word.c -o CMakeFiles/BuilderTests.dir/instruction_word.c.s

CMakeFiles/BuilderTests.dir/parser.c.o: CMakeFiles/BuilderTests.dir/flags.make
CMakeFiles/BuilderTests.dir/parser.c.o: ../parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/omrikaisari/CLionProjects/Assembler/cmake-build-debug-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/BuilderTests.dir/parser.c.o"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/BuilderTests.dir/parser.c.o   -c /Users/omrikaisari/CLionProjects/Assembler/parser.c

CMakeFiles/BuilderTests.dir/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BuilderTests.dir/parser.c.i"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/omrikaisari/CLionProjects/Assembler/parser.c > CMakeFiles/BuilderTests.dir/parser.c.i

CMakeFiles/BuilderTests.dir/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BuilderTests.dir/parser.c.s"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/omrikaisari/CLionProjects/Assembler/parser.c -o CMakeFiles/BuilderTests.dir/parser.c.s

CMakeFiles/BuilderTests.dir/errors.c.o: CMakeFiles/BuilderTests.dir/flags.make
CMakeFiles/BuilderTests.dir/errors.c.o: ../errors.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/omrikaisari/CLionProjects/Assembler/cmake-build-debug-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/BuilderTests.dir/errors.c.o"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/BuilderTests.dir/errors.c.o   -c /Users/omrikaisari/CLionProjects/Assembler/errors.c

CMakeFiles/BuilderTests.dir/errors.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BuilderTests.dir/errors.c.i"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/omrikaisari/CLionProjects/Assembler/errors.c > CMakeFiles/BuilderTests.dir/errors.c.i

CMakeFiles/BuilderTests.dir/errors.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BuilderTests.dir/errors.c.s"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/omrikaisari/CLionProjects/Assembler/errors.c -o CMakeFiles/BuilderTests.dir/errors.c.s

CMakeFiles/BuilderTests.dir/code_table.c.o: CMakeFiles/BuilderTests.dir/flags.make
CMakeFiles/BuilderTests.dir/code_table.c.o: ../code_table.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/omrikaisari/CLionProjects/Assembler/cmake-build-debug-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/BuilderTests.dir/code_table.c.o"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/BuilderTests.dir/code_table.c.o   -c /Users/omrikaisari/CLionProjects/Assembler/code_table.c

CMakeFiles/BuilderTests.dir/code_table.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BuilderTests.dir/code_table.c.i"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/omrikaisari/CLionProjects/Assembler/code_table.c > CMakeFiles/BuilderTests.dir/code_table.c.i

CMakeFiles/BuilderTests.dir/code_table.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BuilderTests.dir/code_table.c.s"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/omrikaisari/CLionProjects/Assembler/code_table.c -o CMakeFiles/BuilderTests.dir/code_table.c.s

CMakeFiles/BuilderTests.dir/data_table.c.o: CMakeFiles/BuilderTests.dir/flags.make
CMakeFiles/BuilderTests.dir/data_table.c.o: ../data_table.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/omrikaisari/CLionProjects/Assembler/cmake-build-debug-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/BuilderTests.dir/data_table.c.o"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/BuilderTests.dir/data_table.c.o   -c /Users/omrikaisari/CLionProjects/Assembler/data_table.c

CMakeFiles/BuilderTests.dir/data_table.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BuilderTests.dir/data_table.c.i"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/omrikaisari/CLionProjects/Assembler/data_table.c > CMakeFiles/BuilderTests.dir/data_table.c.i

CMakeFiles/BuilderTests.dir/data_table.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BuilderTests.dir/data_table.c.s"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/omrikaisari/CLionProjects/Assembler/data_table.c -o CMakeFiles/BuilderTests.dir/data_table.c.s

CMakeFiles/BuilderTests.dir/symbol_table.c.o: CMakeFiles/BuilderTests.dir/flags.make
CMakeFiles/BuilderTests.dir/symbol_table.c.o: ../symbol_table.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/omrikaisari/CLionProjects/Assembler/cmake-build-debug-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/BuilderTests.dir/symbol_table.c.o"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/BuilderTests.dir/symbol_table.c.o   -c /Users/omrikaisari/CLionProjects/Assembler/symbol_table.c

CMakeFiles/BuilderTests.dir/symbol_table.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BuilderTests.dir/symbol_table.c.i"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/omrikaisari/CLionProjects/Assembler/symbol_table.c > CMakeFiles/BuilderTests.dir/symbol_table.c.i

CMakeFiles/BuilderTests.dir/symbol_table.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BuilderTests.dir/symbol_table.c.s"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/omrikaisari/CLionProjects/Assembler/symbol_table.c -o CMakeFiles/BuilderTests.dir/symbol_table.c.s

CMakeFiles/BuilderTests.dir/builder.c.o: CMakeFiles/BuilderTests.dir/flags.make
CMakeFiles/BuilderTests.dir/builder.c.o: ../builder.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/omrikaisari/CLionProjects/Assembler/cmake-build-debug-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/BuilderTests.dir/builder.c.o"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/BuilderTests.dir/builder.c.o   -c /Users/omrikaisari/CLionProjects/Assembler/builder.c

CMakeFiles/BuilderTests.dir/builder.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BuilderTests.dir/builder.c.i"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/omrikaisari/CLionProjects/Assembler/builder.c > CMakeFiles/BuilderTests.dir/builder.c.i

CMakeFiles/BuilderTests.dir/builder.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BuilderTests.dir/builder.c.s"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/omrikaisari/CLionProjects/Assembler/builder.c -o CMakeFiles/BuilderTests.dir/builder.c.s

CMakeFiles/BuilderTests.dir/builder_tests.c.o: CMakeFiles/BuilderTests.dir/flags.make
CMakeFiles/BuilderTests.dir/builder_tests.c.o: ../builder_tests.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/omrikaisari/CLionProjects/Assembler/cmake-build-debug-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/BuilderTests.dir/builder_tests.c.o"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/BuilderTests.dir/builder_tests.c.o   -c /Users/omrikaisari/CLionProjects/Assembler/builder_tests.c

CMakeFiles/BuilderTests.dir/builder_tests.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BuilderTests.dir/builder_tests.c.i"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/omrikaisari/CLionProjects/Assembler/builder_tests.c > CMakeFiles/BuilderTests.dir/builder_tests.c.i

CMakeFiles/BuilderTests.dir/builder_tests.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BuilderTests.dir/builder_tests.c.s"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/omrikaisari/CLionProjects/Assembler/builder_tests.c -o CMakeFiles/BuilderTests.dir/builder_tests.c.s

CMakeFiles/BuilderTests.dir/reader.c.o: CMakeFiles/BuilderTests.dir/flags.make
CMakeFiles/BuilderTests.dir/reader.c.o: ../reader.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/omrikaisari/CLionProjects/Assembler/cmake-build-debug-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/BuilderTests.dir/reader.c.o"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/BuilderTests.dir/reader.c.o   -c /Users/omrikaisari/CLionProjects/Assembler/reader.c

CMakeFiles/BuilderTests.dir/reader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BuilderTests.dir/reader.c.i"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/omrikaisari/CLionProjects/Assembler/reader.c > CMakeFiles/BuilderTests.dir/reader.c.i

CMakeFiles/BuilderTests.dir/reader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BuilderTests.dir/reader.c.s"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/omrikaisari/CLionProjects/Assembler/reader.c -o CMakeFiles/BuilderTests.dir/reader.c.s

CMakeFiles/BuilderTests.dir/printer.c.o: CMakeFiles/BuilderTests.dir/flags.make
CMakeFiles/BuilderTests.dir/printer.c.o: ../printer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/omrikaisari/CLionProjects/Assembler/cmake-build-debug-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/BuilderTests.dir/printer.c.o"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/BuilderTests.dir/printer.c.o   -c /Users/omrikaisari/CLionProjects/Assembler/printer.c

CMakeFiles/BuilderTests.dir/printer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BuilderTests.dir/printer.c.i"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/omrikaisari/CLionProjects/Assembler/printer.c > CMakeFiles/BuilderTests.dir/printer.c.i

CMakeFiles/BuilderTests.dir/printer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BuilderTests.dir/printer.c.s"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/omrikaisari/CLionProjects/Assembler/printer.c -o CMakeFiles/BuilderTests.dir/printer.c.s

CMakeFiles/BuilderTests.dir/files_handler.c.o: CMakeFiles/BuilderTests.dir/flags.make
CMakeFiles/BuilderTests.dir/files_handler.c.o: ../files_handler.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/omrikaisari/CLionProjects/Assembler/cmake-build-debug-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/BuilderTests.dir/files_handler.c.o"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/BuilderTests.dir/files_handler.c.o   -c /Users/omrikaisari/CLionProjects/Assembler/files_handler.c

CMakeFiles/BuilderTests.dir/files_handler.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BuilderTests.dir/files_handler.c.i"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/omrikaisari/CLionProjects/Assembler/files_handler.c > CMakeFiles/BuilderTests.dir/files_handler.c.i

CMakeFiles/BuilderTests.dir/files_handler.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BuilderTests.dir/files_handler.c.s"
	/opt/local/bin/gcc-mp-10 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/omrikaisari/CLionProjects/Assembler/files_handler.c -o CMakeFiles/BuilderTests.dir/files_handler.c.s

# Object files for target BuilderTests
BuilderTests_OBJECTS = \
"CMakeFiles/BuilderTests.dir/list.c.o" \
"CMakeFiles/BuilderTests.dir/instruction_word.c.o" \
"CMakeFiles/BuilderTests.dir/parser.c.o" \
"CMakeFiles/BuilderTests.dir/errors.c.o" \
"CMakeFiles/BuilderTests.dir/code_table.c.o" \
"CMakeFiles/BuilderTests.dir/data_table.c.o" \
"CMakeFiles/BuilderTests.dir/symbol_table.c.o" \
"CMakeFiles/BuilderTests.dir/builder.c.o" \
"CMakeFiles/BuilderTests.dir/builder_tests.c.o" \
"CMakeFiles/BuilderTests.dir/reader.c.o" \
"CMakeFiles/BuilderTests.dir/printer.c.o" \
"CMakeFiles/BuilderTests.dir/files_handler.c.o"

# External object files for target BuilderTests
BuilderTests_EXTERNAL_OBJECTS =

BuilderTests: CMakeFiles/BuilderTests.dir/list.c.o
BuilderTests: CMakeFiles/BuilderTests.dir/instruction_word.c.o
BuilderTests: CMakeFiles/BuilderTests.dir/parser.c.o
BuilderTests: CMakeFiles/BuilderTests.dir/errors.c.o
BuilderTests: CMakeFiles/BuilderTests.dir/code_table.c.o
BuilderTests: CMakeFiles/BuilderTests.dir/data_table.c.o
BuilderTests: CMakeFiles/BuilderTests.dir/symbol_table.c.o
BuilderTests: CMakeFiles/BuilderTests.dir/builder.c.o
BuilderTests: CMakeFiles/BuilderTests.dir/builder_tests.c.o
BuilderTests: CMakeFiles/BuilderTests.dir/reader.c.o
BuilderTests: CMakeFiles/BuilderTests.dir/printer.c.o
BuilderTests: CMakeFiles/BuilderTests.dir/files_handler.c.o
BuilderTests: CMakeFiles/BuilderTests.dir/build.make
BuilderTests: CMakeFiles/BuilderTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/omrikaisari/CLionProjects/Assembler/cmake-build-debug-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking C executable BuilderTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BuilderTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BuilderTests.dir/build: BuilderTests

.PHONY : CMakeFiles/BuilderTests.dir/build

CMakeFiles/BuilderTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BuilderTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BuilderTests.dir/clean

CMakeFiles/BuilderTests.dir/depend:
	cd /Users/omrikaisari/CLionProjects/Assembler/cmake-build-debug-system && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/omrikaisari/CLionProjects/Assembler /Users/omrikaisari/CLionProjects/Assembler /Users/omrikaisari/CLionProjects/Assembler/cmake-build-debug-system /Users/omrikaisari/CLionProjects/Assembler/cmake-build-debug-system /Users/omrikaisari/CLionProjects/Assembler/cmake-build-debug-system/CMakeFiles/BuilderTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BuilderTests.dir/depend

