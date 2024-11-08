yash:	main.o add.o sub.o 
	gcc -o main add.o main.o sub.o 
main.o:
	gcc -c main.c
add.o:
	gcc -c add.c
sub.o:
	gcc -c sub.c
clean:
	rm -rf *.o main
dlib:
	gcc -o output.so add.o sub.o -shared -fPIC

