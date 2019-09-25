CC=gcc
CFLAGS=-c -g -Wall
OBJ=vgo.o lex.yy.o token.o tree.o utils.o go.tab.o
binaries=vgo
files=vgo.c token.c token.h go.tab.h vgolex.l makefile
DEPS = rules.h

vgo: $(OBJ)
	$(CC) -o vgo $(OBJ) $(DEPS)

vgo.o: vgo.c
	$(CC) $(CFLAGS) vgo.c

llex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) lex.yy.c

lex.yy.c: vgolex.l go.tab.h
	flex vgolex.l

token.o: token.c
	$(CC) $(CFLAGS) token.c

tree.o: tree.c
	$(CC) $(CFLAGS) tree.c

utils.o: utils.c
	$(CC) $(CFLAGS) utils.c

go.tab.o: go.tab.c
	$(CC) $(CFLAGS) go.tab.c

go.tab.c go.tab.h: go.y
	bison -d go.y

deploy:
	zip -r hw1.zip $(files)

.PHONY: clean

clean:
	rm -f $(binaries) *.o lex.yy.c