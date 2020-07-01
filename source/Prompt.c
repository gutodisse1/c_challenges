/*
 ============================================================================
 Name        : Prompt.c
 Author      : Gustavo Marques 
 Version     : 0.1
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoubleLinkedList.c"

void print_entry(char *entry) {
	printf("You entered: %s\n", entry);
}

int main( void ) {
	char input[201];
	char *token;

	sList list;
	sNode * tmpNode;
	DoubleLinkedInit(&list);

	while(1) {
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		}
		token = strtok(input, " ");

		if (strncmp(input, "put", 3) == 0) {
			int value;
			token = strtok(NULL, " ");
			value = atoi(token);
			tmpNode = newNode(value);

			DoubleLinkedAddHead(&list, tmpNode);
			List(&list);
		}

		if (strncmp(input, "get", 3) == 0) {
			int value;
			token = strtok(NULL, " ");
			value = atoi(token);
			printf("%d\n", Get(&list, value));
		}

		if (strncmp(input, "remove", 6) == 0) {
			int value;
			token = strtok(NULL, " ");
			value = atoi(token);
			printf("%d\n", Remove(&list, value));
			/*List(&list);*/
		}

		if (strncmp(input, "clear\n", 5) == 0) {
			Clear(&list);
		}

		if (strncmp(input, "first\n", 5) == 0) {
			printf("%d\n", GetFirst(&list));
		}

		if (strncmp(input, "last\n", 5) == 0) {
			printf("%d\n", GetLast(&list));
		}

		if (strncmp(input, "list\n", 5) == 0) {
			List(&list);
		}

		if (strncmp(input, "exit\n", 5) == 0) {
			break;
		}
	}
	

	return EXIT_SUCCESS;
}
