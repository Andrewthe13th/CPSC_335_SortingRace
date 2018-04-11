#include "raceMgr.h"
//#include "bubble"
//#include "merge"
#include <iostream>

using namespace std;

racemgr::racemgr(int *arr, int n)
{
	bubbleAlgo = bubble(arr, n);
	mergeAlgo  = merge(arr, n);
}

racemgr::racemgr() {

}

void racemgr::step()
{
	//0: No Change / starting state
	//1: Swap made
	//2: Finished

	int bubbleState = bubbleAlgo.getState();
	int mergeState  = mergeAlgo.getState();

	if (bubbleState != 2){
		bubbleAlgo.step();
		bubbleCount++
		bubbleState = bubbleAlgo.getState();
	}
	
	if (mergeState != 2){
		mergeAlgo.step();
		mergeCount++
		mergeState = mergeAlgo.getState();
	}

	if (bubbleState == 1){
		int * bubblePt = bubbleAlgo.getPointer();
		cout << "#" << bubbleCount << "B: [";
		printArray(bubblePt, aSize);
		cout << "]";
	}

	if (mergeState == 1){
		int * mergePt = mergeAlgo.getPointer();
		cout << "#" << mergeCount << "M: [";
		printArray(mergePt, aSize);
		cout << "]";
	}
}

void racemgr::winner(){
	if (bubbleCount > mergeCount)
		cout << "The winner is bubble" << endl;
	else{
		cout << "The winner is merge" << endl;
	}

	int * winPt = bubbleAlgo.getPointer();
	printArray(winPt, aSize);

	winPt = mergeAlgo.getpointer();
}

void racemgr::printArray(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ", ";
	}
	cout << endl;
}