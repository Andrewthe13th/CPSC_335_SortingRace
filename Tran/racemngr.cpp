#include "racemngr.h"
#include <iostream>

using namespace std;

racemngr::racemngr(int *arr, int n)
{

	bubbleAl = bubble(arr, n);
    int *a = bubbleAl.perform();
    printArray(a, n);
    
}

racemngr::racemngr() {
    
}

racemngr::~racemngr()
{
}


void racemngr::printArray(int *a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
