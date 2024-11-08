mains:	main.o add.o sub.o mul.o div.o 
	gcc -o mains main.o add.o sub.o mul.o div.o
main.o:
	gcc -c main.c
add.o:
	gcc -c add.c
sub.o:
	gcc -c sub.c
mul.o:
	gcc -c mul.c
div.o:
	gcc -c div.c 
clean:
	rm -rf *.o mains a.out
static:
	ar -crv lib.a add.o sub.o mul.o div.o 


