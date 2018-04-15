/*
Team Name: PAN
Paul Smith pgsmith@csu.fullerton.edu
Andrew de Fluente adelafuente3@csu.fullerton.edu
Nguyen Tran ntran272@csu.fullerton.edu

RaceMgr:
    Calls the algorith step funcction. Contains the logic on when to call each algorithms step() function.Call the print moves() funcction
    when moves are made and calls the printWinner() function when both algorithms are done sorting.
*/


#include "RaceMgr.h"

void RaceMgr::run()
{
	// keep running if a sorting method still hasn't finished
	/*
		There is a problem with this while loop
		removed 
		 && (merge->getStatus() != Algorithm::AlgorithmStatus::FinishedSorting


		 basically hard coded to let bubble finish
	*/
	while ((bubble->getStatus() != Algorithm::AlgorithmStatus::FinishedSorting) || (merge->getStatus() != Algorithm::AlgorithmStatus::FinishedSorting))
	{   //Increase count
		count++;

		if (bubble->getStatus() != Algorithm::AlgorithmStatus::FinishedSorting)
		{
			// run bubble sort if it hasn't finished running
			if (bubble->getStatus() != Algorithm::AlgorithmStatus::FinishedSorting)
			{
				bubble->step();

				// check if bubble has finished after this step
				if (bubble->getStatus() == Algorithm::AlgorithmStatus::FinishedSorting)
				{
					if (merge->getRacePosition() != Algorithm::RacePlace::Winner)
					{
						bubble->setRacePosition(Algorithm::RacePlace::Winner);
						winnerCount = count;
					}
					else
					{
						bubble->setRacePosition(Algorithm::RacePlace::Loser);
						loserCount = count;
					}
				}
			}
		}

		// run merge sort if it hasn't finished running
		if (merge->getStatus() != Algorithm::AlgorithmStatus::FinishedSorting)
		{
			merge->step();

			// check if merge has finished after this step
			if (merge->getStatus() == Algorithm::AlgorithmStatus::FinishedSorting)
			{
				if (bubble->getRacePosition() != Algorithm::RacePlace::Winner)
				{
					merge->setRacePosition(Algorithm::RacePlace::Winner);
					winnerCount = count;
				}
				else
				{
					bubble->setRacePosition(Algorithm::RacePlace::Loser);
					loserCount = count;
				}
			}

		}
		//Prints moves if there was a change 
		printMoves();
	}
}

void RaceMgr::printMoves()
{
    if (merge->getStatus() == Algorithm::AlgorithmStatus::Swapping){
		cout << "#" << count << ", ";
		merge->Algorithm::printList();
	}

	if (bubble->getStatus() == Algorithm::AlgorithmStatus::Swapping){
		cout << "#" << count << ", ";
		bubble->Algorithm::printList();
	}
}

void RaceMgr::printWinner()
{
	cout <<'\n' << endl;
	cout << "Final merge is: ";
	merge->printList();
	cout << "Final bubble is ";
	bubble->printList();
	if (bubble->getRacePosition() == Algorithm::RacePlace::Winner)
	{
		cout << "Winner is " << bubble->ID << " sorting method with count # " << winnerCount << endl;
		cout << "Loser is " << merge->ID << " sorting method with count # " << loserCount << endl;
	}
	else 
	{
		cout << "Winner is " << merge->ID << " sorting method with count # " << winnerCount << endl;
		cout << "Loser is " << bubble->ID << " sorting method with count # " << loserCount << endl;
	}
}

RaceMgr::RaceMgr(vector<int> a)
{
	bubble = new BubbleSort(a);
	merge = new MergeSort(a);

	count = 0;
	winnerCount = 0;
	loserCount = 0;
}
