# c_challenges
A small prompt to interact with a double linked list. The commands accepted are:
* put <number>
* remove <position>
* get <position>
* clear
* getfirst
* getlast
* sort
* list
* exit

## Compiling
Depends only on ansi compiler. There is a makefile to build easier.

To build this repository:
``
$ make all
``

To clean:
``
$ make clean
``

## Running

To run:
```
$ make run
```

Some examples:
```
prompt> put 3
3 
prompt> put 7
3 7 
prompt> put 2
3 7 2 
prompt> list
3 7 2 
prompt> remove 2
7
3 2 
prompt> put 9
3 2 9 
prompt> sort
2 3 9 
prompt> exit
```
