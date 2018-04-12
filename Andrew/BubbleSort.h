#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "Algorithms.h"

class BubbleSort : public Algorithm {
public:
	BubbleSort() {};
	BubbleSort(const vector<int>& a);
	virtual void step() override;

	// status codes
	enum class BubbleSortingStatus { NoSwap, Swapped };
private:
	BubbleSortingStatus Bstatus;
	int prefix;
	int suffix;
};

#endif
