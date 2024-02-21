


StrList: libStrList.a Main.o
	gcc -Wall -g -o StrList Main.o libStrList.a

libStrList.a: StrList.o
	ar -rcs libStrList.a StrList.o

Main.o: Main.c
	gcc -Wall -c Main.c

StrList.o: StrList.c
	gcc -Wall -g -c StrList.c

clean:
	rm -f StrList Main.o StrList.o libStrList.a


