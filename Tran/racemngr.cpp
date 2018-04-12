#include "racemngr.h"
#include <iostream>
using namespace std;


void racemngr::printArray(int * a, int n)
{
	for (int i = 0; i < n; i++){
		if (i == n - 1) {
			cout << a[i];
		}
		else {
			cout << a[i] << ",";
		}
	}
	cout << "]";
	cout << endl;

}

racemngr::racemngr(int * arr, int n)
{
	//0: No change
	//1: swap made
	//2: Finish

	bubbleAlgo = bubble(arr, n);

	
	while (true) {
		int bubbleState = bubbleAlgo.state;
		//add mergere

		if (bubbleState != 2) {
			bubbleAlgo.step();
		}

		if (bubbleState == 1) {
			int *bubblePt = bubbleAlgo.getPointer();
			cout << "#" << bubbleAlgo.count << "B: [";
			printArray(bubblePt, n);
		}

		if (bubbleState == 2) {
			break;
		}

	}

}

racemngr::racemngr()
{
}


racemngr::~racemngr()
{
}
