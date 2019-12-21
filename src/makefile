CC=gcc
CFLAGS=-c -g -Wall
OBJ=vgo.o lex.yy.o token.o tree.o symtab.o stack.o semantic.o type.o typecheck.o tac.o codegen.o final.o utils.o go.tab.o 
binaries=vgo
files=vgo.c token.c token.h symtab.c symtab.h stack.c stack.h semantic.c semantic.h type.c type.h typecheck.h typecheck.c tac.h tac.c codegen.h codegen.c final.h final.c go.tab.h go.y vgolex.l rules.h tree.c tree.h utils.c utils.h makefile
DEPS = rules.h
zip_name=hw6

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

semantic.o: semantic.c
	$(CC) $(CFLAGS) semantic.c

symtab.o: symtab.c
	$(CC) $(CFLAGS) symtab.c

stack.o: stack.c
	$(CC) $(CFLAGS) stack.c

type.o: type.c
	$(CC) $(CFLAGS) type.c

typecheck.o: typecheck.c
	$(CC) $(CFLAGS) typecheck.c

tac.o: tac.c
	$(CC) $(CFLAGS) tac.c

codegen.o: codegen.c
	$(CC) $(CFLAGS) codegen.c

final.o: final.c
	$(CC) $(CFLAGS) final.c

utils.o: utils.c
	$(CC) $(CFLAGS) utils.c

go.tab.o: go.tab.c
	$(CC) $(CFLAGS) go.tab.c

go.tab.c go.tab.h: go.y
	bison -d go.y

deploy:
	zip -r $(zip_name).zip $(files)

.PHONY: clean

clean:
	rm -f $(binaries) *.o lex.yy.c