/*
 ============================================================================
 Name        : DoubleLinkedList.c
 Author      : Gustavo Marques (2020)
 Version     : 0.1
 Copyright   : 
 Description : Dynamic DoublY linked list written in C
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST_OK     0
#define LIST_ERROR  -1


/* DATA STRUCT */
struct Node
{
    int value;
    struct Node * prev;
    struct Node * next;
};

struct List
{
    struct Node * head;
    struct Node * tail;
    int count;
};

/* DATA TYPES */
typedef struct Node     sNode;
typedef struct List     sList;

/* INITIALLY */
int DoubleLinkedInit(sList * plist){
    if(plist == NULL){
        return LIST_ERROR;
    }
    
    plist->head = NULL;
    plist->tail = NULL;
    plist->count = 0;

    return LIST_OK;
}

int DoubleLinkedAddHead(sList * plist, sNode * newNode){
    sNode * tmpNode;
    
    if(plist == NULL || newNode == NULL){
        return LIST_ERROR;
    }

    if(plist->count == 0){
        plist->head = newNode;
        plist->tail = newNode;
    } else {
        tmpNode = plist->head;
        tmpNode->prev = newNode;
        newNode->next = tmpNode;
        plist->head   = newNode;
    }
    plist->count = plist->count + 1; 
    return LIST_OK;
}

void List(sList * plist){
    sNode * tmpNode = plist->tail;
    while(tmpNode){
        printf("%d ", tmpNode->value );
        tmpNode = tmpNode->prev;
    };
    printf("\n");
}

int Get(sList * plist, int value){
    int i;
    
    sNode * tmpNode = plist->tail;
    for(i=0; i<plist->count; i++){
        if( value == i+1){
            return tmpNode->value;
        };
        tmpNode = tmpNode->prev;  
    }
    return 0;
}

void Clear(sList * plist){
    sNode * node        = plist->tail;
    sNode * nextNode    = plist->tail;
    while(nextNode){
        node        = nextNode;        
        nextNode    = nextNode->prev;
        free(node);
    };
    plist->head  = NULL;
    plist->tail  = NULL;
    plist->count = 0;
}


/*  
 * ESTÁ COM PROBLEMA QUANDO REMOVE O CABECALHO OU O ULTIMO NÓ
 */
int Remove(sList * plist, int value){
    int i;
    int valueGot;
    sNode * nextNode;
    sNode * prevNode;
    
    sNode * tmpNode = plist->tail;

    for(i=0; i<plist->count; i++){
        if( value == i+1){
            valueGot = tmpNode->value;
            break;
        };
        tmpNode = tmpNode->prev;  
    };
    
    nextNode = tmpNode->next;
    prevNode = tmpNode->prev;

    /*head*/
    if( tmpNode == plist->head ){
        printf("HEAD");
        plist->head = nextNode;
    }
    
    /*tail*/
    if( tmpNode == plist->tail ){
        plist->tail = prevNode;
        nextNode->next = NULL;
    }
    
    if( tmpNode != plist->head && tmpNode != plist->tail ){
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
    }
   
    plist->count = plist->count - 1;
    free(tmpNode);

    return valueGot;
}

int GetFirst(sList * plist){
    sNode * tmpNode = plist->tail;
    return tmpNode->value;
}

int GetLast(sList * plist){
    sNode * tmpNode = plist->head;
    return tmpNode->value;
}


sNode * newNode(int value){
    sNode * newNode;
    newNode = (sNode *) malloc(sizeof(sNode));

    newNode->value = value;

    return newNode;
}

