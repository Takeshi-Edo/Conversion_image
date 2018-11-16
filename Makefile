###############################################
#  Autor :                       Nebout Yann  #
#  Name of project :        Reading BMP File  #
#  Starting date :        12th november 2018  #
#  Date of last release : 18th november 2018  #
###############################################

CC=gcc

SRCDIR=Src
HEADDIR=Include
EXECDIR=Bin

# Compiler Options
# Wall: screen warnings
# Werror: warning = erreur
# Wextra: Add specific warnings in addition to Wall
# g: gdb & valgrind asalysis
CFLAGS= -I$(HEADDIR) -Wall -c

# Executable file
EXEC= Bmp_Reading

# Where find the source files *.c and compiler will create object and exacutable files
SRC= $(wildcard $(SRCDIR)/*.c)
OBJ= $(SRC:$(SRCDIR)/%.c=%.o)

all: $(EXEC) .PHONY

Bmp_Reading : main.o Reading.o Error.o BMP.o
	$(CC) -o $(EXECDIR)/$@  $^ -lm

%.o: $(SRCDIR)/%.c
	$(CC) -o $@ -c  $< $(CFLAGS) 
# Create *.o files from *.c files
	
clean:
	rm -rf *.o *~
	
vclean:
	rm -rf $(EXEC)
	
.PHONY: clean