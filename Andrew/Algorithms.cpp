/*
Team Name: PAN
Paul Smith pgsmith@csu.fullerton.edu
Andrew de Fluente adelafuente3@csu.fullerton.edu
Nguyen Tran ntran272@csu.fullerton.edu

Algorithms:
    Holds the raccepositions, winner and looser and status of the running algoriths.
    Also handles prints for the algorithms that are running.
*/

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

