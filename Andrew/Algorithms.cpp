#include "Algorithms.h"


/* Algorithm Implementation */

int Algorithm::getListElement(int element)
{
	if( element > static_cast<int>(list.size()) )
	{
		return list[element];
	}
	else
		return -1;
}

void Algorithm::printList()
{
	cout << ID << ": [";
	for (int i = 0; i < ( (static_cast<int>( list.size()))-1 ) ; i++)
	{
		cout << list[i] << ", ";
	}
	cout << list.back() << "]" << endl;
}

