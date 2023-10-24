#include "HSubject.h"

void HSubject::printS(string ky)
{
	// find the key in the hash table
	int hashVal = search(ky);
	if (hashVal == -1) // if the key is not found in the hash table
	{
	    cout << "ERROR" << endl;
	    return;
	}

	cout << "Subject " << ky << " " << arr[hashVal].data.size() << " topics: \n";
	if (arr[hashVal].flag == full)
	{
	    // create an interator that will traverse through the data segment in the located key
		for (list<string>:: iterator it = arr[hashVal].data.begin(); it != arr[hashVal].data.end(); it++)
		{
		    // print each one to the screen
			cout << *it << " ";
		}
		cout << endl;
	}
	return;
}

void HSubject::printN(string ky, int N)
{
	int hashVal = search(ky);
	if (hashVal == -1) {
	    cout << "ERROR\n";
	    return;
	}
	
	if (arr[hashVal].flag == full)
	{
	    // create an iterator which will traverse through the data segment in the key found
		list<string>::iterator it;
		int count = N;
		for (it = arr[hashVal].data.begin(); it != arr[hashVal].data.end(); it++)
		{
			cout << *it << " ";
			count--;
			if (count == 0)
			{
				break;
			}
		}
		cout << endl;
	}
	return;
}

void HSubject::print()
{
    cout << "All subjects and titles: " << endl;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].flag == full)
		{
			cout << arr[i].key << ": ";
			for (list<string>:: iterator it = arr[i].data.begin(); it != arr[i].data.end(); it++)
			{
				cout << *it << " ";
			}
			cout << endl;
		}
	}
}

void HSubject::startNewTable()
{
    // make each entry in the hash table empty
	for (int i = 0; i < size; i++)
	{
		arr[i].flag = empty;
	}
}

void HSubject::addSubjectAndTitle(string s, string t)
{
    // create a list of dtrings
	list<string>* discussion = entryData(s);
	// if there is nothing in discussion yet
	if (discussion == NULL)
	{
		list<string> newList; // create a new list
		newList.push_front(t); // move the title to the front of the list
		add(s, newList); // add it using the hash function
		return;
	}
	else
	{
		discussion->push_front(t); // push it to the front of the list
		return;
	}
}
