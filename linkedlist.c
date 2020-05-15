#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void display_number_linked_list(List_ptr pList){
  Node_ptr p_walk = pList->first;
  while (p_walk != NULL)
  {
    printf("%d ", (int) p_walk->element);
    p_walk = p_walk->next;
  }
  printf("\n");
}

List_ptr create_list(void){
  List_ptr pList = malloc(sizeof(LinkedList));
  pList->first = NULL;
  pList->last = NULL;
  pList->length = 0;
  return pList;
}

Node_ptr create_Node(Element element){
  Node_ptr node = malloc(sizeof(Node));
  node->element = element;
  node->next = NULL;
  return node;
}

Status add_to_list(List_ptr pList, Element element){
  Node_ptr new_node = create_Node(element);
  if(pList->first == NULL){
    pList->first = new_node;
  }else
  {
    pList->last->next = new_node;
  }
  pList->last = new_node;
  pList->length++;
  return Success;
}

