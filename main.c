#include "linkedlist.h"

Status is_equal(Element element_1, Element element_2){
  return (int) element_1 == (int) element_2 ? Success : Failure;
}

Element square(Element element){
  long int number = (long int )element;
  Element result = (Element)(number * number);
  return result;
}

Status is_even(Element object){
  int number = (long int) object;
  if (number % 2 == 0) return Success;
  return Failure;
}

int main()
{
  List_ptr pList = create_list();
  Status status;
  add_to_list(pList, (Element) 1);
  add_to_start(pList, (Element) 2);
  insert_at(pList, (Element) 3, 0);
  insert_at(pList, (Element) 4, 0);

  display_number_linked_list(filter(pList, &is_even));

  display_number_linked_list(pList);
  return 0;
}
