/*
Christopher Markieta
OOP344A
July 28, 2013
*/

#include "DoublyLinkedList.h"
#include "serialization.h"

int main(void)
{
  DoublyLinkedList list;  // Original list
  DoublyLinkedList list2; // Loaded list

  list.pushBack(1);
  list.pushBack(2);
  list.pushBack(3);

  serialization(&list); // Write to file

  load(&list2);         // Load from file

  list.pushBack(4);     // Modify original to show difference
  
  std::cout << "Original list:" << std::endl;

  while(!list.isEmpty())
  {
    std::cout << " <- " << list.getValue() << " -> ";
    list.popFront();
  }

  std::cout << std::endl << "Loaded list:" << std::endl;

  while(!list2.isEmpty())
  {
    std::cout << " <- " << list2.getValue() << " -> ";
    list2.popFront();
  }

  getchar(); // System pause

  return 0;
}