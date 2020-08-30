OBJS	= list.o instruction_word.o parser.o errors.o code_table.o data_table.o symbol_table.o builder.o reader.o printer.o files_handler.o assembler.o
SOURCE	= list.c instruction_word.c parser.c errors.c code_table.c data_table.c symbol_table.c builder.c reader.c printer.c files_handler.c assembler.c
HEADER	= list.h instruction_word.h constants.h parser.h errors.h code_table.h data_table.h symbol_table.h builder.h reader.h printer.h files_handler.h
OUT	= assembler
CC	 = gcc
FLAGS	 = -g -c -Wall -pedantic -ansi
LFLAGS	 = -lm

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

list.o: list.c
	$(CC) $(FLAGS) list.c

instruction_word.o: instruction_word.c
	$(CC) $(FLAGS) instruction_word.c

parser.o: parser.c
	$(CC) $(FLAGS) parser.c

errors.o: errors.c
	$(CC) $(FLAGS) errors.c

code_table.o: code_table.c
	$(CC) $(FLAGS) code_table.c

data_table.o: data_table.c
	$(CC) $(FLAGS) data_table.c

symbol_table.o: symbol_table.c
	$(CC) $(FLAGS) symbol_table.c

builder.o: builder.c
	$(CC) $(FLAGS) builder.c

reader.o: reader.c
	$(CC) $(FLAGS) reader.c

printer.o: printer.c
	$(CC) $(FLAGS) printer.c

files_handler.o: files_handler.c
	$(CC) $(FLAGS) files_handler.c

assembler.o: assembler.c
	$(CC) $(FLAGS) assembler.c


clean:
	rm -f $(OBJS) $(OUT)