/*
 ============================================================================
 Name        : DoubleLinkedList.h
 Author      : Gustavo Marques (2020)
 Version     : 0.1
 Copyright   : 
 Description : Dynamic DoublY linked list written in C
 ============================================================================
 */
#ifndef _H_LIST
#define _H_LIST

/* CONSTANTS */
#define LIST_OK     0
#define LIST_ERROR  -1

/*
 ============================================================================
  DATA STRUCT
 ============================================================================
*/

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


/*
 ============================================================================
  PROTOTYPES
 ============================================================================
*/
int listInit(sList * plist);
void List(sList * plist);
void Put(sList * plist, int value);
void Get(sList * plist, int value);
void Clear(sList * plist);
void Remove(sList * plist, int value);
void GetFirst(sList * plist);
void GetLast(sList * plist);
void Sort(sList * plist);

#endif
/*END OF FILE*/