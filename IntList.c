/**
 *  Integer LIST ADT : public interface
 *
 *  COMP220: Assignment 2
 *  Author:  Keaton Armstrong
 *  Date:    Feb. 8, 2018
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "IntList.h"
//function prototypes
node* createNode (int value);

/*
 * Constructor - return a new, empty list 
 * POST:  ilistLen(list) == 0
 */
IntList ilistNew( )
{
  IntList list = {NULL,NULL,0};
  return list;
}

node* createNode (int value)
{
  node* node = malloc(sizeof(node));
  node->data = value;
  node->next = NULL;
  return node;
}

/*
 * Destructor - remove all data and free all memory associated with the list 
 * POST: ilistLen(list) == 0
 */
 void ilistDelete( IntList *list )
 {
   node* p = list->head;
  
    printf("\n");
  
    while(p != NULL){
      
      p = p->next;
      free(list->head);
      list->head = p;
    }    
    list->head = NULL;
    list->tail =NULL;
    list->len = 0;
 }


/*
 * Print a text representation of this list on STDOUT
 */
void ilistPrint( IntList list )
{
  node* p = list.head;
  
  while(p != NULL){
    if (p == list.head) {
      printf("h");
    }
    
    printf("[%d]\n", p->data);
    
    if (p == list.tail) {
      printf("t");
    }
    p = p->next;
  }
  printf("\n");
}

/*
 * Return the number of items in the list
 */
int ilistLen( IntList list )
{
  return list.len;
}

/*
 * Return the item at the given index from the list 
 * PRE: 0<=at && at<ilistLen(list)
 */
int ilistGet( IntList list, int at )
{
  node* p = list.head;
  
  int index = 0;
  
  while(p != NULL){
    if (index == at){
      return p->data;
    }
    p = p->next;
    index++;
  }
}


/*
 * Return the number of times the given item occurs in the list 
 */
int ilistCount( IntList list, int item )
{
  node* p = list.head;
  
  int count = 0;
  
  while(p != NULL){
    if(p->data == item){
      count++;
    }
    p = p->next;
  }
  return count;
}

/*
 * Search the list for the given item
 * RETURN: the position, pos, such that ilistGet(list, pos)==item OR -1 if the item is not found
 */
int ilistFind( IntList list, int item )
{
  node* p = list.head;
  int i = 0;
  
  while (p != NULL){
    if (p->data == item){
      return i;
    }
    else{
      p = p->next;
      i++;
    }
  }
  return -1;
}


/*
 * Append the given item to the list 
 * POST: ilistGet( ilistLen(list)-1 ) == item
 */
void ilistAppend( IntList *list, int item )
{
  
  if(ilistLen(*list) == 0){
    list->head = createNode(item);
  }
  else{
    
      node* p = list->head;

      while(p->next != NULL){
        p = p->next;
      }
      p->next = createNode(item);
      list->tail = p->next;
  }
  list->len++;
}

/*
 * Insert the given item into the list at the given location
 * POST: length of list is increased by one, and ilistGet( list, at ) == item
 */


void ilistInsert( IntList *list, int at, int item )
{
  
  node* newNode = createNode(item);

  node* p = list->head;
  
  int i = 0;
  
  while(i <= at-1){ 
    if( i == at-1){
      newNode->next = p->next;
      p->next = newNode;
      list->len++;
    }    
    p = p->next;
    i++;
  }
}

/*
 * Remove the given item at the given location from the  list 
 * POST: length of list is reduced by one, item at given location has been removed.
 */
void ilistRemove( IntList *list, int at )
{
  node* p = list->head;
  
  int i = 0;
  while(i < at-1){ 
    p = p->next;
    i++;
  }
  printf("%d\n",i);
  printf("%d",p->data);
  
  p->next = p->next->next;
  list->len--;
}

/*
 * Append all items from list2 to list1 
 * POST: length of list1 increased by size of list2 and all items from list2 are appended to list1.
 */
void ilistJoin( IntList *list1, IntList list2 )
{
  node* p = list2.head;
  
  while(p != NULL){
    ilistAppend(list1,p->data);
    p = p->next;
  }
}

/*
 * Reverse the order of items in the list
 * POST: items in the list are in reversed order (e.g., first item is now last and visa versa)
 */
void ilistReverse( IntList *list )
{
  node* curNode = list->head;
  node* nextNode = NULL;
  node* prevNode = NULL;
  
  list->tail = curNode;

  while(curNode != NULL){
    nextNode = curNode->next;
    curNode->next = prevNode;
    prevNode = curNode;
    curNode = nextNode;
  }
  
  list->head = prevNode;
}

/*
 * Return a "deep copy" of the list, with it's own, independent set of data.
 * Challenge Exercise:  NOT required for assignment - add your own tests to test driver.
 */
IntList ilistCopy( IntList list );