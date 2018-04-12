#include "bubble.h"



bubble::bubble()
{
}

bubble::bubble(int *arr, int arrsize)
{
	workingarray = new int[arrsize];
	for (int i = 0; i < arrsize; i++) {
		workingarray[i] = arr[i];	
	}
	state = 0;
	count = 0;
	size = arrsize;
	prefix = 0;
	suffix = 0;
}



int bubble::step() {
	//Swap return 1
	//No change return 0
	//Completed return 2
	
	count++;
	int temp;
	if (workingarray[prefix] > workingarray[suffix]) {
		temp = workingarray[prefix];
		workingarray[prefix] = workingarray[suffix];
		workingarray[suffix] = temp;
		
		state = 1;
		return 1; //Swap
	}

	suffix++;

	if (suffix >= size) {
		prefix++;
		suffix = prefix + 1;
	}

	if (prefix >= size - 1) {
		state = 2;
		return 2; //Completed
	}


	state = 0;
	return 0; //No change

}


bubble::~bubble()
{
}
