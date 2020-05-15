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

  Element removed_element = remove_from_start(pList);
  if(removed_element == NULL) printf("List is empty\n");
  else printf("Removed the first element %d\n", (int) removed_element);

  removed_element = remove_from_end(pList);
  if(removed_element == NULL) printf("List is empty\n");
  else printf("Removed the last element %d\n", (int) removed_element);

  display_number_linked_list(pList);
  return 0;
}
