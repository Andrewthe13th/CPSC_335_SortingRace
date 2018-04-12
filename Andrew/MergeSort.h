#ifndef MERGESORT_H
#define MERGESORT_H

#include "Algorithms.h"
#include <math.h>

class MergeSort : public Algorithm {
public:
	MergeSort() {};
	MergeSort(const vector<int>& a);
	void printTemp();
	virtual void step() override;
private:
	int sublistSize;
	int prefixLeft;
	int prefixRight;
	int subListCount;
	int currentComparision;
	int maxComparisions;
	int indexLeft;
	int indexRight;
	vector<int> temp{};
};

#endif
