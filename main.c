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

Element add(Element element1, Element element2 ){
  long int number1 = (long int) element1;
  long int number2 = (long int) element2;
  Element result = (Element)(number1 + number2);
  return result;
}

void print_square(Element element){
  printf("%d\n",(int) square(element));
}

int main()
{
  List_ptr pList = create_list();
  Status status;
  add_to_list(pList, (Element) 2);
  add_to_start(pList, (Element) 2);
  insert_at(pList, (Element) 3, 0);
  insert_at(pList, (Element) 4, 0);

  display_number_linked_list(remove_all_occurrences(pList, (Element) 2, &is_equal));

  display_number_linked_list(pList);
  return 0;
}
