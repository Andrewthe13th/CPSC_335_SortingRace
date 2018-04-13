#include "RaceMgr.h"
#include <sstream>
#include <vector>
#include <string>
#include <math.h>

int main(int argc, char *argv[])
{
	string arr1;
    for (int i = 1; i < argc; i++){
        arr1 += argv[ i ];
        arr1 += " ";
    }
	stringstream iss( arr1 );
	int number;
	vector<int> list;
	while (iss >> number ){
		list.push_back( number );
	}

	RaceMgr start (list);
	cout << "Starting array is:[";
	for (int i = 0; i < ( (static_cast<int>( list.size()))-1 ) ; i++)
	{
		cout << list[i] << ", ";
	}
	cout << list.back() << "]\n" << endl;
	
	// adds check for a single element
	if (static_cast<int>(list.size()) != 1)
	{
		start.run();
		start.printWinner();
	}
	else
		cout << "List is already sorted since it contains only one element!!!\n";

	return 0;
}
