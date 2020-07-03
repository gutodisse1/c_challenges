# RUNNING
run:
	./build/simple_make

# COMPILE AND LINKING
all: simple_make
 
simple_make: Prompt.o DoubleLinkedList.o
	gcc -o ./build/simple_make ./objects/Prompt.o ./objects/DoubleLinkedList.o
 
Prompt.o: ./source/Prompt.c ./source/DoubleLinkedList.h
	gcc -o ./objects/Prompt.o ./source/Prompt.c -c -W -Wall -ansi -pedantic

DoubleLinkedList.o: ./source/DoubleLinkedList.c ./source/DoubleLinkedList.h
	gcc -o ./objects/DoubleLinkedList.o ./source/DoubleLinkedList.c  -c -W -Wall -ansi -pedantic

# CLEANING
clean:
	rm -rf ./objects/*.o *~ ./build/simple_make
