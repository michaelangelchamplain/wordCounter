/*
Michael Angel
PA6
*/
#include "doublyLinkedList.h"
#include "word.h"


#include <iostream>
#include <algorithm>

#include <string>
using namespace std;

//Helper functions

/* Pre: Any string that contains alpha characters
*  Post: A string that is made up of all lowercase letters
*  Purpose: To convert a word to all lowercase letters
*********************************************************/
string toLowerCase( string word )
{
	string lowerCase;

	return lowerCase;
}

/* Pre: A string that contains alpha characters or punctuation
*  Post: A string without punctuation
*  Purpose: To remove all punctuation from a word
*********************************************************/
string removePunctuation( string word )
{
	string removedPunct;

	return removedPunct;
}

string removeCapsAndPunct( string word )
{
	char puncts[] = { '"', '\'', '(', ')', '!', '?', '%', '$', '#', ';', ':' };   
	int length = word.length();

	for( int i = 0; i < length; i++ )
	{
		word.erase( remove( word.begin(), word.end(), puncts[i] ), word.end() );
	}

	cout << "Testing remove punct: " << word << endl;

	length = word.length();

	for( int j = 0; j < length; j++ )
	{
		if( word[j] >= 65 && word[j] <= 90 )
		{
			word[j] = word[j] += 32;
		}
	}

	cout << "Testing remove caps: " << word << endl;


	return word;
}

/* Pre: A linked list of Words
*  Post: An alphabetically sorted linked list of words
*  Purpose: To make an alphabetically sorted linked list
*********************************************************/
Word sortAlphabetically( Word wordLL )
{
	return wordLL;
}




void main()
{
	string testWord = "Mike's";

	removeCapsAndPunct( testWord );

	system("pause");
}