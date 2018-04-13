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
	ID = "M";

	//cout << "-> " << sublistSize << " " << subListCount << " " << maxComparisions << endl;

}

void MergeSort::step()
{
	
	// check if a pair of sublists can be compared among each other 
	if (currentComparision != maxComparisions)
	{
		Astatus = Algorithm::AlgorithmStatus::Unsorted;
		// if right is less than left then swap
		if (list[indexLeft + prefixLeft] > list[indexRight + prefixRight])
		{
			// swap
			Astatus = Algorithm::AlgorithmStatus::Swapping;

			////cout << list[indexLeft + prefixLeft] << " > " << list[indexRight + prefixRight] << endl << endl;
			// store value in temp array
			temp[indexLeft + prefixLeft + prefixRight] = list[indexRight + prefixRight];

			//cout << temp[indexLeft + prefixLeft + prefixRight] << " ";

			prefixRight++;

			// check if right side has less elements than normal sublist
			if ((indexRight + prefixRight) >= static_cast<int>(list.size()))
			{
				prefixRight = sublistSize;
			}

		}
		else // left is less than right
		{
			////cout << list[indexLeft + prefixLeft] << " > " << list[indexRight + prefixRight];
			temp[indexLeft + prefixLeft + prefixRight] = list[indexLeft + prefixLeft];

			//cout << temp[indexLeft + prefixLeft + prefixRight] << " ";

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
					// check if right side has less elements than normal sublist
					if (!((indexRight + prefixRight) >= static_cast<int>(list.size())))
					{
						temp[indexLeft + prefixLeft + prefixRight] = list[indexRight + prefixRight];
						//cout << temp[indexLeft + prefixLeft + prefixRight] << " ";
					}

					prefixRight++;
					
				}
			} // check right
			else if (prefixRight == sublistSize)
			{
				// push whatever is remaining on the left sublist to the temp
				while (prefixLeft != sublistSize)
				{
					// check if right side has less elements than normal sublist
					if ((indexRight + prefixRight) >= static_cast<int>(list.size()))
					{
						prefixRight = static_cast<int>(list.size()) - indexRight;
					}

					temp[indexLeft + prefixLeft + prefixRight] = list[indexLeft + prefixLeft];
					//cout << temp[indexLeft + prefixLeft + prefixRight] << " ";
					prefixLeft++;
				}
				
			}

			// Move to next comparison on the same level
			currentComparision++;
			prefixLeft = 0;
			prefixRight = 0;
			indexLeft = (2 * currentComparision)*sublistSize;
			indexRight = ((2 * currentComparision)*sublistSize) + sublistSize;
			
		}
	}
	else // no more comparisons, move on to the next level
	{
		

		// check if there is a sublist that isn't compared
		if (subListCount % 2 == 1)
		{
			// check if sublist has less elements than normal sublist
			if ((static_cast<int>(list.size()) - indexLeft) < sublistSize)
			{
				while ((indexLeft + prefixLeft) < (static_cast<int>(list.size())))
				{
					temp[indexLeft + prefixLeft] = list[indexLeft + prefixLeft];
					prefixLeft++;
				}
				prefixLeft = 0;

			}
			else
			{
				for (int i = 0; i < sublistSize; i++)
				{
					temp[indexLeft + prefixLeft + prefixRight + i] = list[indexLeft + prefixLeft + prefixRight + i];
					//cout << temp[indexLeft + prefixLeft + prefixRight + i] << " ";
				}
				//cout << "| ";
			}
		}
		// check if finished
		else if (currentComparision == 1 && maxComparisions == 1)
		{
			// check if there were an even amount of sublist
			if (subListCount % 2 == 0)
			{
				Astatus = Algorithm::AlgorithmStatus::FinishedSorting;
				// update list with Temp
				int i = 0;
				for (auto &x : list)
				{
					x = temp[i]; i++;
				}

				return;
			}
		}

		// update list with Temp
		int i = 0;
		for(auto &x : list)
		{
			x = temp[i]; i++;
		}

		currentComparision = 0;
		sublistSize = sublistSize * 2;
		subListCount = (int)(ceil(static_cast<double>(subListCount) / 2));
		maxComparisions = (static_cast<int>(subListCount)/2);
		indexLeft = 0;
		indexRight = ((2 * currentComparision)*sublistSize) + sublistSize;

		//cout << "-> " << sublistSize << " " << subListCount << " " << maxComparisions;
		//cout << endl;

		step();
	}
}

void MergeSort::printTemp()
{
	for (int i = 0; i < ( (static_cast<int>( temp.size()))-1 ) ; i++)
	{
		//cout << temp[i] << ", ";
	}
	//cout << temp.back() << "]" << endl;
}
