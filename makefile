CC=gcc
CFLAGS=-c -g -Wall
OBJ=vgo.o lex.yy.o
DEPS=token.c

vgo: $(OBJ)
	$(CC) -o vgo $(OBJ) $(DEPS)

vgo.o: vgo.c
	$(CC) $(CFLAGS) vgo.c

llex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) lex.yy.c

lex.yy.c: vgolex.l vgo.tab.h
	flex vgolex.l

.PHONY: clean

binaries: vgo

clean:
	rm -f $(binaries) *.o