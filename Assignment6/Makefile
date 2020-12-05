all: compile.out

compile: lex.yy.o y.tab.o ass6_18CS10025_translator.o 
	g++ lex.yy.o y.tab.o ass6_18CS10025_translator.o -lfl -o compile
	# Enter 'make run' to generate Quad and Assembly Language File , then 'make test' to generate all output files 
y.tab.o:	y.tab.c
	g++ -c y.tab.c

lex.yy.o:	lex.yy.c
	g++ -c lex.yy.c

lex.yy.c:	ass6_18CS10025.l y.tab.c
	flex ass6_18CS10025.l

y.tab.c:	ass6_18CS10025.y
	yacc --verbose -dtv ass6_18CS10025.y

ass6_18CS10025_translator.o: ass6_18CS10025_translator.h ass6_18CS10025_translator.cxx
	g++ -c ass6_18CS10025_translator.cxx

myl.o:	myl.c myl.h
	gcc -c myl.c

clean:
	rm compile.out compile y.tab.o lex.yy.o lex.yy.c y.tab.c y.tab.h y.output ass6_18CS10025_translator.o libass2_18CS10025.a ass2_18CS10025.o quad_lists0.out quad_list1.out quad_list2.out quad_list3.out quad_list4.out quad_list5.out quad_list6.out quad_list7.out quad_list8.out test0 test1 test2 test3 test4 test5 test6 test7 test8 ass6_18CS10025_test0.s ass6_18CS10025_test0.o ass6_18CS10025_test1.s ass6_18CS10025_test1.o ass6_18CS10025_test2.s ass6_18CS10025_test2.o ass6_18CS10025_test3.s ass6_18CS10025_test3.o ass6_18CS10025_test4.s ass6_18CS10025_test4.o ass6_18CS10025_test5.s ass6_18CS10025_test5.o ass6_18CS10025_test6.s ass6_18CS10025_test6.o ass6_18CS10025_test7.s ass6_18CS10025_test7.o ass6_18CS10025_test8.s ass6_18CS10025_test8.o

run:
	./compile 1 < ass6_18CS10025_test1.c > ass6_18CS10025_test1.s
	./compile 2 <  ass6_18CS10025_test2.c > ass6_18CS10025_test2.s
	./compile 3 < ass6_18CS10025_test3.c > ass6_18CS10025_test3.s
	./compile 4 < ass6_18CS10025_test4.c > ass6_18CS10025_test4.s
	./compile 5 < ass6_18CS10025_test5.c > ass6_18CS10025_test5.s
	./compile 6 < ass6_18CS10025_test6.c > ass6_18CS10025_test6.s
	./compile 7 < ass6_18CS10025_test7.c > ass6_18CS10025_test7.s
	./compile 8 < ass6_18CS10025_test8.c > ass6_18CS10025_test8.s



test1: ass6_18CS10025_test1.o libass2_18CS10025.a
	gcc -no-pie ass6_18CS10025_test1.o -o test1 -L. -lass2_18CS10025
ass6_18CS10025_test1.o: myl.h
	gcc  -c ass6_18CS10025_test1.s

test2: ass6_18CS10025_test2.o libass2_18CS10025.a
	gcc -no-pie  ass6_18CS10025_test2.o -o test2 -L. -lass2_18CS10025
ass6_18CS10025_test2.o: myl.h
	gcc -Wall -c ass6_18CS10025_test2.s

test3: ass6_18CS10025_test3.o libass2_18CS10025.a
	gcc -no-pie ass6_18CS10025_test3.o -o test3 -L. -lass2_18CS10025
ass6_18CS10025_test3.o: myl.h
	gcc -Wall -c ass6_18CS10025_test3.s

test4: ass6_18CS10025_test4.o libass2_18CS10025.a
	gcc -no-pie  ass6_18CS10025_test4.o -o test4 -L. -lass2_18CS10025
ass6_18CS10025_test4.o: myl.h
	gcc -Wall -c ass6_18CS10025_test4.s

test5: ass6_18CS10025_test5.o libass2_18CS10025.a
	gcc -no-pie  ass6_18CS10025_test5.o -o test5 -L. -lass2_18CS10025
ass6_18CS10025_test5.o: myl.h
	gcc -Wall -c ass6_18CS10025_test5.s

test6: ass6_18CS10025_test6.o libass2_18CS10025.a
	gcc -no-pie  ass6_18CS10025_test6.o -o test6 -L. -lass2_18CS10025
ass6_18CS10025_test6.o: myl.h
	gcc -Wall -c ass6_18CS10025_test6.s

test7: ass6_18CS10025_test7.o libass2_18CS10025.a
	gcc -no-pie  ass6_18CS10025_test7.o -o test7 -L. -lass2_18CS10025
ass6_18CS10025_test7.o: myl.h
	gcc -Wall -c ass6_18CS10025_test7.s

test8: ass6_18CS10025_test8.o libass2_18CS10025.a
	gcc -no-pie  ass6_18CS10025_test8.o -o test8 -L. -lass2_18CS10025
ass6_18CS10025_test8.o: myl.h
	gcc -Wall -c ass6_18CS10025_test8.s


libass2_18CS10025.a: ass2_18CS10025.o
	ar -rcs libass2_18CS10025.a ass2_18CS10025.o

ass2_18CS10025.o: myl.c myl.h
	gcc -Wall -c myl.c -o ass2_18CS10025.o

testing: compile run test6
