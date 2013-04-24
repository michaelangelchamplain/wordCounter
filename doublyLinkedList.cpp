#include "doublyLinkedList.h"

/********** Constructors **********/

/*      Pre:  None
 *     Post:  The next and previous pointers are initialized to NULL
 *  Purpose:  Default constructor
******************************************************************************/
DoublyLinkedList::DoublyLinkedList()
{
	mNext = NULL;
	mPrevious = NULL;
}


/*      Pre:  A data used to initialized a new node
 *     Post:  The next and previous pointers are initialized to NULL, and the
 *            data is initialized to the specified value
 *  Purpose:  Constructor
******************************************************************************/
DoublyLinkedList::DoublyLinkedList(string data)
{
	mNext = NULL;
	mPrevious = NULL;
	mData = data;
	mCount = 1;
}


/********** Deconstructors **********/

/*      Pre:  The dummy node for the doubly linked list must be instantiated
 *     Post:  A node is removed
 *  Purpose:  Deconstructor
******************************************************************************/
DoublyLinkedList::~DoublyLinkedList()
{
	DoublyLinkedList *temp = mNext;

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
int DoublyLinkedList::getCount()
{
	return mCount;
}


/*      Pre:  The node is instantiated
 *     Post:  The data stored in the node is returned
 *  Purpose:  To retrieve the value stored in a node
******************************************************************************/
string DoublyLinkedList::getData()
{
	return mData;
}


/*      Pre:  The node is instantiated
 *     Post:  The next pointer of the node is returned
 *  Purpose:  To retrieve the location of the next node
******************************************************************************/
DoublyLinkedList *DoublyLinkedList::getNext()
{
	return mNext;
}


/*      Pre:  The node is instantiated
 *     Post:  The previous pointer of the node is returned
 *  Purpose:  To retrieve the location of the previous node
******************************************************************************/
DoublyLinkedList *DoublyLinkedList::getPrevious()
{
	return mPrevious;
}


/********** Mutator **********/

/*      Pre:  The node is instantiated and the new data
 *     Post:  The data stored in the node is updated
 *  Purpose:  To replace the value of the data stored in a node
******************************************************************************/
void DoublyLinkedList::setData(string data)
{
	mData = data;
}


/********** Others **********/

/*      Pre:  The dummy node is instantiated
 *     Post:  The data of the nodes in the doubly linked list is displayed on
 *            the screen
 *  Purpose:  To display all data stored in the doubly linked list
******************************************************************************/   
void DoublyLinkedList::display()
{
	DoublyLinkedList *temp = mNext;

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
void DoublyLinkedList::insert(string data)
{
	DoublyLinkedList *temp, *prev;
	DoublyLinkedList *insert = new DoublyLinkedList( data );

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

		if( prev->getData() == data )
		{
			prev->mCount++;
		}

		else if( temp != NULL && temp->getData() == data )
		{
			temp->mCount++;
		}

		else if( temp == getNext() )
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