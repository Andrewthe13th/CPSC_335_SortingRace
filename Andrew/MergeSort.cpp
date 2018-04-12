#include "MergeSort.h"

/* MergeSort Implementation */
MergeSort::MergeSort(const vector<int>& a)
{	
	// copy list
	for (auto &x : a)
		list.push_back(x);

	// initialize temp array
	for (int i = 0; i < static_cast<int>(list.size()); i++)
	{
		temp.push_back(0);
	}

	// set initial data
	sublistSize = 1;
	prefixLeft = 0;
	prefixRight = 0;
	currentComparision = 0;
	subListCount = static_cast<int>(list.size());
	maxComparisions = subListCount / 2;
	indexLeft = 0;
	indexRight = 1;


}

void MergeSort::step()
{
	// check if comparisons still exist for the sublist size
	cout << " Current: " << currentComparision << " Max: " << maxComparisions << endl;
	if (currentComparision != maxComparisions)
	{
		cout << "Sublist Size & Count: " << sublistSize << ", " << subListCount << endl;
		cout << "Left index & prefix: " << indexLeft << ", " << prefixLeft << " Right index & prefix: " << indexRight << ", " << prefixRight << endl << endl;
		Astatus = Algorithm::AlgorithmStatus::Unsorted;
		// if right is less than left then swap
		if (list[indexLeft + prefixLeft] > list[indexRight + prefixRight])
		{
			// store value in temp array
			temp[indexLeft + prefixLeft + prefixRight] = list[indexRight + prefixRight];
			prefixRight++;
			// swap
			Astatus = Algorithm::AlgorithmStatus::Swapping;
		}
		else // left is less than right
		{
			temp[indexLeft + prefixLeft + prefixRight] = list[indexLeft + prefixLeft];
			prefixLeft++;
		}

		// check if a sublist has been completely checked
		if (prefixLeft == sublistSize || prefixRight == sublistSize)
		{
			// check left
			if (prefixLeft == sublistSize)
			{
				// push whatever is remaining on the right sublist to the temp
				while (prefixRight != sublistSize)
				{
					temp[indexLeft + prefixLeft + prefixRight] = list[indexRight + prefixRight];
					prefixRight;
				}
			} // check right
			else if (prefixRight == sublistSize)
			{
				// push whatever is remaining on the left sublist to the temp
				while (prefixLeft != sublistSize)
				{
					temp[indexLeft + prefixLeft + prefixRight] = list[indexLeft + prefixLeft];
					prefixLeft++;
				}
			}
			// Move to next comparison on the same level
			currentComparision++;
			prefixLeft = 0;
			prefixRight = 0;
			indexLeft = (2 * currentComparision)*sublistSize;
			indexRight = ((2 * currentComparision)*sublistSize) + sublistSize;

			// check if finished
			if (currentComparision == 1 && maxComparisions == 1)
			{
				Astatus = Algorithm::AlgorithmStatus::FinishedSorting;
				for (auto &x : temp)
					cout << x << " ";
				cout << endl;
			}
		}
	}
	else // no more comparisons, move on to the next level
	{
		if (maxComparisions % 2 == 1) // odd
			maxComparisions = (maxComparisions + 1) / 2;
		else // even
			maxComparisions = maxComparisions / 2;

		currentComparision = 0;
		sublistSize = sublistSize * 2;
		subListCount = subListCount / 2;
		maxComparisions = ceil(static_cast<double>(subListCount)/2);
		indexLeft = 0;
		indexRight = ((2 * currentComparision)*sublistSize) + sublistSize;
		step();
	}
}
