CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
OBJ = ErrorChecking.o FileIO.o FuncPointer.o LinkedList.o main.o
EXEC = spellCheck

$(EXEC) : $(OBJ) check.o
	gcc -o $(EXEC) $(OBJ) check.o 

ErrorChecking.o : ErrorChecking.c ErrorChecking.h
	gcc $(CFLAGS) -c ErrorChecking.c

FileIO.o : FileIO.c FileIO.h SpellConf.h LinkedList.h
	gcc $(CLFAGS) -c FileIO.c

FuncPointer.o : FuncPointer.c FuncPointer.h check.h
	gcc $(CFLAGS) -c FuncPointer.c

LinkedList.o : LinkedList.c LinkedList.h
	gcc $(CFLAGS) -c LinkedList.c

main.o : main.c main.h check.h ErrorChecking.h FileIO.h FuncPointer.h SpellConf.h
	gcc $(CFLAGS) -c main.c

clean :
	rm -f $(EXEC) $(OBJ)
