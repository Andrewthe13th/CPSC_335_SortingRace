#include "RaceMgr.h"
#include <vector>
#include <math.h>

int main(int argc, char *argv[])
{
	// Testing BubbleSort
	vector<int> list = { 8,7,6,5,4,3,2,1 };

	/*BubbleSort bubble(list);

	while (bubble.getStatus() != Algorithm::AlgorithmStatus::FinishedSorting)
	{
		bubble.printList();
		bubble.step();
	}

	cout << "FINISHED SORTING" << endl;
	bubble.printList();*/

	MergeSort merge(list);

	while (merge.getStatus() != Algorithm::AlgorithmStatus::FinishedSorting)
	{
		merge.printList();
		merge.step();
	}

	cout << "FINISHED SORTING" << endl;
	merge.printList();

	system("PAUSE");
	return 0;
}