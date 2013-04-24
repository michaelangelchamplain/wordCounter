/* ***  Given to you by:  Wei Kian Chen
     *  Completed by:     Michael Angel
     *  Class:            CSI 281
     *  Date Assigned:    2/8/13
     *  Date Due:    2/13/13
     *
     *  Description:
     *      This class is template class for a doubly linked list
     *
     *  Certification of Authenticity:	
     *     I certify that this assignment is entirely my own work.
     **********************************************************************/

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <fstream>
#include "word.h"
using namespace std;

class DoublyLinkedList
{
   private:
      string mData;
	  int mCount;
      DoublyLinkedList *mPrevious;
      DoublyLinkedList *mNext;

   public:
      DoublyLinkedList();
      DoublyLinkedList(string data);
      ~DoublyLinkedList();
   
      string getData();
	  int getCount();
      DoublyLinkedList *getNext();
      DoublyLinkedList *getPrevious();

      void setData(string data);
   
      void display();
      void insert(string data);
};
#endif