/*
Michael Angel
PA6
*/
#include "doublyLinkedList.h"
#include "TimerSystem.h"

#include <iomanip>
#include <iostream>
#include <fstream>
#include <algorithm>

#include <string>
using namespace std;

string toLowerCase( string word );
string removePunctuation( string word );
string removeCapsAndPunct( string word );
void displayForward(DoublyLinkedList *ptr);


void main()
{
	TimerSystem timer;
	double timerTime;
	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(16);

	srand(unsigned(time(NULL)));

	

	string word;
	string textFile;
	DoublyLinkedList *wordList;
	wordList = new DoublyLinkedList;
	
	cout << "Name of file (sans .txt): ";
	cin >> textFile;
	cout << endl;
	textFile += ".txt";

	ifstream inFile( textFile );//Get
	
	timer.startClock();//Time to polulate the list and calculate it.
	while( inFile.good() )
	{
		inFile >> word;
		word = removeCapsAndPunct( word );
		if( word != "" )
		{
			wordList->insert(word);
		}
		
		word = "";
	}
	timerTime = timer.getTime();//The number of times each word as been used has been calculated 
								//and its in alphabetical order

	displayForward(wordList);

	
	cout << endl << "Time to do these operations: " << timerTime << endl << endl;
	system("pause");
}

//Helper functions

/* Pre: Any string that contains alpha characters
*  Post: A string that is made up of all lowercase letters
*  Purpose: To convert a word to all lowercase letters
*********************************************************/
string toLowerCase( string word )
{
	int length = word.length();

	for( int j = 0; j < length; j++ )
	{
		if( word[j] >= 65 && word[j] <= 90 )
		{
			word[j] += 32;
		}
	}

	//cout << "Testing remove caps: " << word << endl;
	
	return word;
}

/* Pre: A string that contains alpha characters or punctuation
*  Post: A string without punctuation
*  Purpose: To remove all punctuation from a word
*********************************************************/
string removePunctuation( string word )
{
	char puncts[] = { '"', '\'', '(', ')', '[', ']', '{', '}', ':', ';', ',', '.', '<', '>', '?', '/', '\\',
					  '|', '`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '-', '_', '=', '+'};   
	int arraySize = sizeof( puncts )/sizeof(puncts[0]);

	for( int i = 0; i < arraySize; i++ )
	{
		word.erase( remove( word.begin(), word.end(), puncts[i] ), word.end() );
	}

	//cout << "Testing remove punct: " << word << endl;

	return word;
}

string removeCapsAndPunct( string word )
{
	word = removePunctuation( word );

	word = toLowerCase( word );

	return word;
}

void displayForward(DoublyLinkedList *ptr)
{
   DoublyLinkedList *tmp;

   tmp = ptr;
   tmp = tmp->getNext();

   cout << "Word List (Alphabetical and Enumerated): " << endl << endl;

   while (tmp != NULL)
   {
      cout << tmp->getData() << " - " << tmp->getCount() << endl;
      tmp = tmp->getNext();
   }
}