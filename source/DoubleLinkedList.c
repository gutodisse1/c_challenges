/*
 ============================================================================
 Name        : DoubleLinkedList.c
 Author      : Gustavo Marques (2020)
 Version     : 0.1
 Copyright   : 
 Description : Dynamic DoublY linked list written in C
 ============================================================================
 */
#include "DoubleLinkedList.h"
#include <stdio.h>   /* printf, free */
#include <stdlib.h>  /* printf, free */

/*
 ============================================================================
  NODES FUNCTIONS
 ============================================================================
*/

/*
 * TODO: ADD ERROR HANDLINGs
 */
sNode * newNode(int value){
    sNode * newNode;
    newNode = (sNode *) malloc(sizeof(sNode));
    newNode->value = value;

    return newNode;
}


/*
 ============================================================================
  LIST FUNCTIONS
 ============================================================================
*/

/* INIT */
int listInit(sList * plist){
    if(plist == NULL){
        return LIST_ERROR;
    }
    
    plist->head = NULL;
    plist->tail = NULL;
    plist->count = 0;

    return LIST_OK;
}

int listAddHead(sList * plist, sNode * newNode){
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

int listAddTail(sList * plist, sNode * newNode){
    if(plist == NULL || newNode == NULL){
        return LIST_ERROR;
    }

    if(plist->count == 0){
        plist->head = newNode;
        plist->tail = newNode;
    } else {
        plist->tail->next = newNode;
        newNode->next = NULL;
        newNode->prev = plist->tail;
        plist->tail = newNode;
    }
    plist->count = plist->count + 1; 
    return LIST_OK;
}

sNode * GetNode(sList * plist, int value){
    int i;
    sNode * tmpNode = plist->head;

    /*
     * TODO: CHANGE TO WHILE STATMENT
     */
    for(i=0; i<plist->count; i++){
        if( value == i+1){
            return tmpNode;
        };
        tmpNode = tmpNode->next;  
    }
    return 0;
}


/*
 ============================================================================
  PROMPT COMMANDS
 ============================================================================
*/
void List(sList * plist){
    sNode * tmpNode = plist->head;
    if(plist == NULL || tmpNode == NULL){
        return;
    }
    
    while(tmpNode){
        printf("%d ", tmpNode->value );
        tmpNode = tmpNode->next;
    };
    printf("\n");
}

void Put(sList * plist, int value){
	sNode * tmpNode;
    tmpNode = newNode(value);
    listAddTail(plist, tmpNode);
    List(plist);
}

void Get(sList * plist, int value){
    sNode * tmpNode = GetNode(plist, value);
    if(tmpNode)
    {
        printf("%d\n", tmpNode->value);
    }
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

void Remove(sList * plist, int value){
    sNode * nextNode;
    sNode * prevNode;
    
    sNode * tmpNode = GetNode(plist, value);
    if(tmpNode)
    {
        printf("%d\n", tmpNode->value);
        nextNode = tmpNode->next;
        prevNode = tmpNode->prev;

        if(tmpNode == plist->head && tmpNode == plist->tail)
        {
            plist->head = NULL;
            plist->tail = NULL;
        } else if( tmpNode == plist->head ){ /* HEAD */
            plist->head = nextNode;
            nextNode->prev = NULL;
        } else if( tmpNode == plist->tail ){ /* TAIL */
            plist->tail = prevNode;
            prevNode->next = NULL;
        } else if( tmpNode != plist->head 
                    && tmpNode != plist->tail ){
            nextNode->prev = prevNode;
            prevNode->next = nextNode;
        }
    
        plist->count = plist->count - 1;
        free(tmpNode);
    }
    
}

void GetFirst(sList * plist){
    sNode * tmpNode = plist->tail;
    if(tmpNode){
        printf("%d\n", tmpNode->value);
    }
}

void GetLast(sList * plist){
    sNode * tmpNode = plist->head;
    if(tmpNode){
        printf("%d\n", tmpNode->value);
    }
}

void swapeNodes(sNode * a, sNode * b){
    int tmp = a->value;
    a->value = b->value;
    b->value = tmp;
}

/*
 *  CAN BE IMPROVED 
 *   WITH BETTER SORT METHOD
 */
void Sort(sList * plist){
    sNode * node;
    sNode * nextNode;
    int changes = 1;

    while(changes){
        changes = 0;

        nextNode = plist->head;
        while(nextNode){
            node        = nextNode;        
            nextNode    = nextNode->next;
            if( nextNode && 
                node->value > nextNode->value){
                changes = 1;
                swapeNodes(node, nextNode);
            }
        }       
    };
    List(plist); 
}

/*END OF FILE*/