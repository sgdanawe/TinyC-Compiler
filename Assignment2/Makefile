a.out:main.o libtoylib.a
	c++ main.o -L. -ltoylib
main.o:main.c toylib.h
	c++ -Wall -c main.c
libtoylib.a:ass2_18CS30015.o
	ar -rcs libtoylib.a ass2_18CS30015.o
ass2_18CS30015.o:ass2_18CS30015.cpp toylib.h
	c++ -Wall -c ass2_18CS30015.cpp
clean:
	rm a.out main.o libtoylib.a ass2_18CS30015.o