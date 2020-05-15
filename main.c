#include "linkedlist.h"

Status is_equal_void(Element element_1, Element element_2){
  return (int) element_1 == (int) element_2 ? Success : Failure;
}

int main()
{
  List_ptr pList = create_list();
  Status status;
  add_to_list(pList, (Element) 10);
  add_to_start(pList, (Element) 20);
  insert_at(pList, (Element) 30, 0);
  insert_at(pList, (Element) 40, 0);

  status = clear_list(pList);
  if(status == Success) printf("DONE\n");
  else printf("NOT DONE\n");

  display_number_linked_list(pList);
  return 0;
}
