#include "linkedlist.h"

Status is_equal_void(Element element_1, Element element_2){
  return (int) element_1 == (int) element_2 ? Success : Failure;
}

int main()
{
  List_ptr pList = create_list();
  Element element = malloc(sizeof(element));
  Element removed_element;
  element = (Element) 10;

  add_to_list(pList, element);

  element = (Element) 20;
  add_to_start(pList, element);

  element = (Element) 30;
  insert_at(pList, element, 0);

  element = (Element) 40;
  insert_at(pList, element, 0);

  removed_element = remove_first_occurrence(pList, (Element) 30, &is_equal_void);
  if(removed_element == NULL) printf("Element is not present\n");
  else printf("Removed element %d\n", (int) removed_element);

  display_number_linked_list(pList);
  return 0;
}
