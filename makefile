# RUNNING
run:
	./build/simple_make

# COMPILE AND LINKING
all: simple_make
 
simple_make: Prompt.o DoubleLinkedList.o
	gcc -o ./build/simple_make ./objects/Prompt.o ./objects/Queue.o ./objects/Stack.o
 
Prompt.o: ./source/Prompt.c
	gcc -o ./objects/Prompt.o ./source/Prompt.c -c -W -Wall -ansi -pedantic

DoubleLinkedList.o: ./source/DoubleLinkedList.c
	gcc -o ./objects/DoubleLinkedList.o ./source/DoubleLinkedList.c  -c -W -Wall -ansi -pedantic

# CLEANING
clean:
	rm -rf ./objects/*.o *~ ./build/simple_make
