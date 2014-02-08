/*
Christopher Markieta
OOP344A
July 28, 2013
*/

#include <fstream>

void serialization(DoublyLinkedList* list)
{
  int i;
  int value;

  std::fstream data("Data.txt", std::fstream::out | std::fstream::binary);

  list->goFront();

  for(i = list->getSize() - 1; i; i--)
  {
    value = list->getValue();
    data.write((const char*)&value, sizeof(value));
    list->goNext();
  }

  value = list->getValue();
  data.write((const char*)&value, sizeof(value));

  list->goFront();

  data.close();
}

void load(DoublyLinkedList* list)
{
  int i;

  std::fstream data("Data.txt", std::fstream::in | std::fstream::binary);

  list->goFront();

  while(data.read((char*)&i, sizeof(i)))
  {
    list->pushBack(i);
  }

  data.close();
}