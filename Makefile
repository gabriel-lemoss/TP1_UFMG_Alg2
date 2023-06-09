#---------------------------------------------------------------------
# File       : Makefile
# Content       : Compile the compression program
# Author        : Gabriel Eduardo Lemos dos Santos (gabriel.lemos@dcc.ufmg.br)
# History      : 2023-05-06 - file created
#---------------------------------------------------------------------
# Options       : make all - Compiles all and generates the executable
#               : make clean - Removes object files and executable
#---------------------------------------------------------------------

CC = g++
SRC = src
INC = include
OBJ = obj
BIN = bin
CFLAGS = -Werror -Wall -I $(INC) -c -std=c++17
OBJS = $(OBJ)/trie.o $(OBJ)/main.o
EXE = main.exe

$(EXE) : $(OBJS)
	$(CC) $(OBJS) -o $(BIN)/$(EXE)

$(OBJ)/%.o : $(SRC)/%.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean :
	rm $(OBJ)/*.o $(BIN)/*.exe
