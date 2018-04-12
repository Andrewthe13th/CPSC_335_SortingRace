#ifndef RACEMGR_H
#define RACEMGR_H

#include "MergeSort.h"
#include "BubbleSort.h"

class RaceMgr {
public:
	RaceMgr() {};
	RaceMgr(std::vector<int> a);
	void run();
	void printWinner();
	void printSwap() {};\
private:
	BubbleSort* bubble;
	MergeSort* merge;
	int count;
	int winnerCount;
	int loserCount;
};

#endif
