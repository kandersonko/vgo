CC=gcc
CFLAGS=-c -g -Wall
OBJ=vgo.o lex.yy.o token.o
binaries=vgo
files=vgo.c token.c token.h vgo.tab.h vgolex.l makefile

vgo: $(OBJ)
	$(CC) -o vgo $(OBJ) $(DEPS)

vgo.o: vgo.c
	$(CC) $(CFLAGS) vgo.c

llex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) lex.yy.c

lex.yy.c: vgolex.l vgo.tab.h
	flex vgolex.l

token.o: token.c
	$(CC) $(CFLAGS) token.c


deploy:
	zip -r hw1.zip $(files)

.PHONY: clean

clean:
	rm -f $(binaries) *.o lex.yy.c