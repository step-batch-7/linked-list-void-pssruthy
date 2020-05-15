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

Status add_to_start(List_ptr pList, Element element){
  Node_ptr new_node = create_Node(element);
  if(pList->first == NULL){
    pList->first = new_node;
    pList->last = new_node;
  }else
  {
    new_node->next = pList->first;
    pList->first = new_node;
  }
  pList->length++;
  return Success;
}

Status insert_at(List_ptr pList, Element element, int position){
  if(position < 0 | position > pList->length) return Failure;
  if (position == 0) return add_to_start(pList, element);
  if (position == pList->length) return add_to_list(pList, element);

  Node_ptr new_node = create_Node(element);
  Node_ptr previous_node = pList->first;
  for (int count = 1; count < position; count++)
  {
   previous_node = previous_node->next;
  }
  new_node->next = previous_node->next;
  previous_node->next = new_node;
  pList->length++;
  return Success;
}

Element remove_from_start(List_ptr pList){
  Node_ptr head = pList->first;
  if (pList->first == NULL) return NULL;
  if (pList->length == 1) pList->first = pList->last = NULL;
  else pList->first = head->next;
  
  pList->length--;

  Element removed_element = head->element;
  free(head);
  return removed_element;
}
