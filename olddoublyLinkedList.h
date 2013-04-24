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


using namespace std;

template <class T>
class DoublyLinkedList
{
   private:
      T                   mData;
      DoublyLinkedList<T> *mPrevious;
      DoublyLinkedList<T> *mNext;

   public:
      DoublyLinkedList();
      DoublyLinkedList(T data);
      ~DoublyLinkedList();
   
      T                   getData();
      DoublyLinkedList<T> *getNext();
      DoublyLinkedList<T> *getPrevious();

      void setData(T data);
   
      void display();
      void insert(T data);
      bool isExist(T searchKey);
      void remove(T searchKey);

      bool operator<(T rhs);
      friend bool operator<(T lhs, DoublyLinkedList<T> rhs);

      bool operator>(T rhs);
      friend bool operator>(T lhs, DoublyLinkedList<T> rhs);

      bool operator==(T rhs);
      friend bool operator==(T lhs, DoublyLinkedList<T> rhs);

      bool operator!=(T rhs);
      friend bool operator!=(T lhs, DoublyLinkedList<T> rhs);

      friend ostream& operator<<(ostream &outputStream, DoublyLinkedList<T> obj);
};


/********** Constructors **********/

/*      Pre:  None
 *     Post:  The next and previous pointers are initialized to NULL
 *  Purpose:  Default constructor
******************************************************************************/
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	mNext = NULL;
	mPrevious = NULL;
}


/*      Pre:  A data used to initialized a new node
 *     Post:  The next and previous pointers are initialized to NULL, and the
 *            data is initialized to the specified value
 *  Purpose:  Constructor
******************************************************************************/
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(T data)
{
	mNext = NULL;
	mPrevious = NULL;
	mData = data;
}


/********** Deconstructors **********/

/*      Pre:  The dummy node for the doubly linked list must be instantiated
 *     Post:  A node is removed
 *  Purpose:  Deconstructor
******************************************************************************/
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	DoublyLinkedList<T> *temp = mNext;

	while( temp != NULL )
	{
		mNext = temp->mNext;
		temp->mNext = NULL;
		delete temp;

		temp = mNext;
	}
}


/********** Accessors **********/

/*      Pre:  The node is instantiated
 *     Post:  The data stored in the node is returned
 *  Purpose:  To retrieve the value stored in a node
******************************************************************************/
template <class T>
T DoublyLinkedList<T>::getData()
{
	return mData;
}


/*      Pre:  The node is instantiated
 *     Post:  The next pointer of the node is returned
 *  Purpose:  To retrieve the location of the next node
******************************************************************************/
template <class T>
DoublyLinkedList<T> *DoublyLinkedList<T>::getNext()
{
	return mNext;
}


/*      Pre:  The node is instantiated
 *     Post:  The previous pointer of the node is returned
 *  Purpose:  To retrieve the location of the previous node
******************************************************************************/
template <class T>
DoublyLinkedList<T> *DoublyLinkedList<T>::getPrevious()
{
	return mPrevious;
}


/********** Mutator **********/

/*      Pre:  The node is instantiated and the new data
 *     Post:  The data stored in the node is updated
 *  Purpose:  To replace the value of the data stored in a node
******************************************************************************/

template <class T>
void DoublyLinkedList<T>::setData(T data)
{
	mData = data;
}


/********** Others **********/

/*      Pre:  The dummy node is instantiated
 *     Post:  The data of the nodes in the doubly linked list is displayed on
 *            the screen
 *  Purpose:  To display all data stored in the doubly linked list
******************************************************************************/   
template <class T>
void DoublyLinkedList<T>::display()
{
	DoublyLinkedList<T> *temp = mNext;

	while( temp != NULL )
	{
		cout << temp->getData() << endl;

		temp = temp->getNext();
	}
}


/*      Pre:  The dummy node is instantiated and the new value is available
 *     Post:  The new node is added onto the doubly linked list in ascending
 *            order.  For example, if the new data is B, then it must be added
 *            in between A and C
 *  Purpose:  To add a new node onto the doubly linked list
******************************************************************************/
template <class T>
void DoublyLinkedList<T>::insert(T data)
{
	DoublyLinkedList<T> *temp, *prev;
	DoublyLinkedList<T> *insert = new DoublyLinkedList( data );

	if( getNext() == NULL )
	{
		mNext = insert;
		prev = mNext;
	}

	else
	{
		temp = mNext;
		prev = temp;

		while( temp != NULL && temp->getData() < data )
		{
			prev = temp;
			temp = temp->getNext();
		}

		if( temp == getNext() )
		{
			insert->mNext = getNext();
			mNext = insert;

			insert->mPrevious = prev;

			if( prev == NULL )
			{
				insert->mPrevious = prev->mPrevious;
			}
		}

		else
		{
			prev->mNext = insert;
			insert->mNext = temp;

			insert->mPrevious = prev;
		}
	}
}


/*      Pre:  The dummy node is instantiated and the searchkey is provided
 *     Post:  True is the given value exists in the doubly linked list, 
 *            otherwise false
 *  Purpose:  To validate if a given value exists in the doubly linked list
******************************************************************************/
template <class T>
bool DoublyLinkedList<T>::isExist(T searchKey)
{
	bool isExist = false;
	DoublyLinkedList<T> *temp = getNext();

	while( temp != NULL )
	{
		if( temp->getData() == searchKey )
		{
			isExist = true;

			break;
		}

		temp = temp->getNext();
	}

	return isExist;
}


/*      Pre:  The dummy node is instantiated and the searchkey is provided
 *     Post:  If the given searchKey exists in the doubly linked list, it is
 *            removed from the list
 *  Purpose:  To remove a given value from the doubly linked list.  If there
 *            is multiple occurances of the given value, only the first 
 *            occurrance is removed
******************************************************************************/
template <class T>
void DoublyLinkedList<T>::remove(T searchKey)
{
	if( isExist( searchKey ) == false )
	{
		return;
	}

	DoublyLinkedList<T> *temp = getNext();
	DoublyLinkedList<T> *prev = getNext();

	while( temp->getData() != searchKey )
	{
		prev = temp;

		temp = temp->getNext();
	}

	if( temp == getNext() )
	{
		mNext = temp->getNext();
		
		temp->mNext = NULL;
	}

	else if( temp->getNext() == NULL )
	{
		prev->mNext = NULL;
	}

	else
	{
		prev->mNext = temp->getNext();

		temp->mNext = NULL;
	}

	delete temp; /**/
}


/********** Overloading Operators **********/

/*      Pre:  A T value for comparison
 *     Post:  True if the value stored in the current node is less than the
 *            specified value
 *  Purpose:  To perform the less than operator for DoublyLinkedList < T
******************************************************************************/
template <class T>
bool DoublyLinkedList<T>::operator<(T rhs)
{
	return mData < rhs;
}


/*      Pre:  A T value for comparison
 *     Post:  True if the specified value is less than the value stored in the 
 *            current node
 *  Purpose:  To perform the less than operator for T < DoublyLinkedList
******************************************************************************/
template <class T>
bool operator<(T lhs, DoublyLinkedList<T> rhs)
{
	return mData < rhs;
}


/*      Pre:  A T value for comparison
 *     Post:  True if the value stored in the current node is greater than the
 *            specified value
 *  Purpose:  To perform the less than operator for DoublyLinkedList > T
******************************************************************************/
template <class T>
bool DoublyLinkedList<T>::operator>(T rhs)
{
	return lhs < rhs.getData();
}


/*      Pre:  A T value for comparison
 *     Post:  True if the specified value is greater than the value stored in the 
 *            current node
 *  Purpose:  To perform the greater than operator for T > DoublyLinkedList
******************************************************************************/
template <class T>
bool operator>(T lhs, DoublyLinkedList<T> rhs)
{
	return lhs < rhs.getData();
}


/*      Pre:  A T value for comparison
 *     Post:  True if the value stored in the current node is equal than the
 *            specified value
 *  Purpose:  To perform the less than operator for DoublyLinkedList == T
******************************************************************************/
template <class T>
bool DoublyLinkedList<T>::operator==(T rhs)
{
	return getData() == rhs;
}


/*      Pre:  A T value for comparison
 *     Post:  True if the specified value is equal than the value stored in the 
 *            current node
 *  Purpose:  To perform the greater than operator for T == DoublyLinkedList
******************************************************************************/
template <class T>
bool operator==(T lhs, DoublyLinkedList<T> rhs)
{
	return getData() == rhs;
}


/*      Pre:  A T value for comparison
 *     Post:  True if the value stored in the current node is not equal than
 *            the specified value
 *  Purpose:  To perform the less than operator for DoublyLinkedList != T
******************************************************************************/
template <class T>
bool DoublyLinkedList<T>::operator!=(T rhs)
{
	return getData() != rhs;
}


/*      Pre:  A T value for comparison
 *     Post:  True if the specified value is not equal than the value stored in 
 *            the current node
 *  Purpose:  To perform the greater than operator for T != DoublyLinkedList
******************************************************************************/
template <class T>
bool operator!=(T lhs, DoublyLinkedList<T> rhs)
{
	return lhs != rhs.getData();
}


/*      Pre:  A output stream and a node
 *     Post:  Output the information stored in the node to the specified 
 *            output stream 
 *  Purpose:  To perform outputStream << DoublyLinkedList
******************************************************************************/
template <class T>
ostream& operator<<(ostream &outputStream, DoublyLinkedList<T> obj)
{
	outputStream < obj.getData();
	return outputStream;
}

#endif