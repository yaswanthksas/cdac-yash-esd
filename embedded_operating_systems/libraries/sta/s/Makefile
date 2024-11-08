main: add.o sub.o main.o
	gcc -o main main.o sub.o add.o 
main.o:
	gcc -c main.c 
add.o:
	gcc -c add.c
sub.o:
	gcc -c sub.c
lib:
	ar -crv output.a sub.o add.o 
clean:
	rm -rf *.o main a.out output.a