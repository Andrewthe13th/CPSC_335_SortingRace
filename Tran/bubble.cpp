#include "bubble.h"
#include <iostream>
using namespace std;

/*
	Function Step
	Check prefix and suffix 
	if arr[prefix] > arr[suffix], swap and return 1;
	else no change, return 2;
	if completed, return 0;
*/
int bubble::step(int prefix, int suffix)
{
	//completed
	if (prefix == size - 1 && suffix == size)
		return 0;

	//swap
	if (arr[prefix] > arr[suffix])
	{
		int tmp = arr[prefix];
		arr[prefix] = arr[suffix];
		arr[suffix] = tmp;

		return 1;
	}

	//no change
	return 2;
}


/*
	print out states
*/
void bubble::printState() {
	//cout << "State" << endl;
	int i;
	for (i = 0; i < size; i++)
	{
        if(i == size - 1){
            cout << arr[i];
        }else{
            cout << arr[i] << ",";
        }
	}
	cout << "]";
	cout << endl;

}

/*
	Perform bubble sorts
*/
int * bubble::perform()
{
    int callCount = 0;
    
	for (prefix = 0; prefix < size; prefix++) {
		for (suffix = prefix + 1; suffix < size; suffix++) {
				callCount++;
				int stepret = step(prefix,suffix);

				if (stepret == 1){
                    cout << "#" << callCount << ",B: [";
                    printState();
                    
//                    for(int i = 0; i <size;i++){
//                    }
                    
				}
		}
	}

	cout << "Bubble sort took " << callCount << " turns" << endl;
	return arr;
}



bubble::~bubble()
{
}

bubble::bubble() {}

bubble::bubble(int *b, int f)
{
	arr = b;
    copy = b;
	size = f;
}
