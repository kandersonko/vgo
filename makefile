CC=gcc
CFLAGS=-c -g -Wall
OBJ=vgo.o lex.yy.o token.o
# DEPS=token.c
DEPS=



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

.PHONY: clean

binaries: vgo

clean:
	rm -f $(binaries) *.o