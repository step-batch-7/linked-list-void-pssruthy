#include "linkedlist.h"

int main()
{
  List_ptr pList = create_list();
  Element element = malloc(sizeof(element));
  element = (Element) 10;

  add_to_list(pList, element);
  element = (Element) 20;
  add_to_start(pList, element);

  element = (Element) 30;
  insert_at(pList, element, 0);

  display_number_linked_list(pList);
  return 0;
}
