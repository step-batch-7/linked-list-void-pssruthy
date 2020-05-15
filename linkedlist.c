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

Element remove_from_end(List_ptr pList){
  Node_ptr last = pList->last;
  Node_ptr p_walk =  pList->first;
  if (pList->length == 0) return NULL;
  if (pList->length == 1) pList->last = pList->first = NULL;
  else {
    for (int count = 1; count < pList->length - 1; count++)
    {
      p_walk = p_walk->next;
    }
    p_walk->next = NULL;  
    pList->last = p_walk;
  }
  Element removed_element = last->element;
  pList->length--;
  
  free(last);
  return removed_element;
}

Element remove_at(List_ptr pList, int position){
  if (position < 0 | position >= pList->length) return NULL;
  if (position == 0 ) return remove_from_start(pList);
  if (position == pList->length - 1 ) return remove_from_end(pList);
  
  Node_ptr p_walk = pList->first;
  for (int count = 0; count < position - 1; count++)
  {
    p_walk = p_walk->next;
  }
  Node_ptr node_to_remove = p_walk->next;
  p_walk->next = node_to_remove->next;
  pList->length--;

  Element removed_element = node_to_remove->element;

  free(node_to_remove);
  return removed_element;
}

Element remove_first_occurrence(List_ptr pList, Element element, Matcher matcher){
  Node_ptr p_walk = pList->first;
  int position = 0;
  while (p_walk != NULL)
  {
    if((*matcher)(element, p_walk->element) == Success){
      return remove_at(pList, position);
    }
    position++;
    p_walk = p_walk->next;
  }
  return NULL;
}
 
Status add_unique(List_ptr pList, Element element, Matcher matcher){
  Node_ptr p_walk = pList->first;
  for (int count = 0; count < pList->length; count++)
  {
    if((*matcher)(element, p_walk->element) == Success) return Failure;  
    p_walk = p_walk->next;
  }
  return add_to_list(pList, element);
}

List_ptr map(List_ptr pList, Mapper mapper){
  List_ptr mapped_list = create_list();
  Node_ptr p_walk = pList->first;

  for (int index = 0; index < pList->length; index++)
  {
    add_to_list(mapped_list, (*mapper)(p_walk->element));
    p_walk = p_walk->next;
  }
  return mapped_list;
}

List_ptr filter(List_ptr pList, Predicate predicate){
  Element filtered_list = create_list();
  Node_ptr p_walk = pList->first;
  while(p_walk != NULL)
  {
    if((*predicate)(p_walk->element) == Success){
      add_to_list(filtered_list, p_walk->element);
    }
    p_walk = p_walk->next;
  }
  return filtered_list;
}

Element reduce(List_ptr pList, Element init, Reducer reducer){
  Element context = init;
  Node_ptr p_walk = pList->first;
  while(p_walk != NULL){
    context =  (*reducer)(p_walk->element, context);
    p_walk = p_walk->next;
  }
  return context;
}

void forEach(List_ptr pList, ElementProcessor processor){
  Node_ptr p_walk = pList->first;
  while(p_walk != NULL){
    (*processor)(p_walk->element);
    p_walk = p_walk->next;
  }
}

List_ptr reverse(List_ptr pList){
  List_ptr reversed_list = create_list();
  Node_ptr p_walk = pList->first;
  while (p_walk != NULL)
  {
    add_to_start(reversed_list, p_walk->element);
    p_walk = p_walk->next;
  }
  return reversed_list;
}



Status clear_list(List_ptr pList){
  Node_ptr p_walk = pList->first;
  while (p_walk != NULL)
  {
    remove_from_start(pList);
    p_walk = p_walk->next;
  }
  return Success;
}

