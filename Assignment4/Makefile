Test_Output.txt: a.out asgn4_18CS30015_test.c
	./a.out < asgn4_18CS30015_test.c
a.out: lex.yy.c y.tab.c asgn4_18CS30015.o
	gcc lex.yy.c y.tab.c asgn4_18CS30015.o -lfl

lex.yy.c: asgn4_18CS30015.l
	flex asgn4_18CS30015.l

y.tab.c: asgn4_18CS30015.y
	yacc -dtv asgn4_18CS30015.y

assign4_18CS30015.o: asgn4_18CS30015.c
	gcc -c asgn4_18CS30015.c

clean:
	rm y.tab.c y.tab.h a.out lex.yy.c y.output asgn4_18CS30015.o
