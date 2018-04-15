/*
Team Name: PAN
Paul Smith pgsmith@csu.fullerton.edu
Andrew de Fluente adelafuente3@csu.fullerton.edu
Nguyen Tran ntran272@csu.fullerton.edu

BubbleSort:
    Creates an instance of bubblesort and has function to run the algorithm one step at 
    a time.
*/


#include "BubbleSort.h"

/* BubbleSort Implementation */
BubbleSort::BubbleSort(const vector<int>& a)
{
	// set initial status
	Bstatus = BubbleSortingStatus::NoSwap;
	prefix = 0;
	suffix = 1;
	ID = "B";

	// copy list
	int i = 0;
	for (auto &x : a)
	{
		list.push_back(x);
		//cout << x << " ";
	}
	//cout << endl;
}

/*
Return false when Bubble sort has finished else
*/
void BubbleSort::step()
{
	// check if sorting has finished one pass
	if (suffix >= static_cast<int>(list.size()))
	{
		// FINISHED SORTING, tell race mgr that algorithm has finished
		if (Bstatus == BubbleSortingStatus::NoSwap)
			Astatus = Algorithm::AlgorithmStatus::FinishedSorting;
		else // next pass
		{
			prefix = 0;
			suffix = 1;
			Bstatus = BubbleSortingStatus::NoSwap;
			step();
		}
	}
	else // suffix and prefix are both valid
	{
		// Compare the left element with the right
		if (list[prefix] > list[suffix])
		{
			// do a swap
			int tmp = list[prefix];
			list[prefix] = list[suffix];
			list[suffix] = tmp;

			// bubble sort still need to do another round of swapping
			Bstatus = BubbleSortingStatus::Swapped;

			// tell race manager that algorithm is swapping
			Astatus = Algorithm::AlgorithmStatus::Swapping;
		}
		else
			Astatus = Algorithm::AlgorithmStatus::Unsorted;


		// increment the prefix and suffix
		prefix++;
		suffix++;
	}
}
