#include "bubble.h"
using namespace std;

//The Race Mgr will keep track of which algorithms are still running, so as to be able to keep calling their step() methods. It will also keep track of how many turns it took for each algorithm to finish (to be done).
//The Race Mgr should be a class, as should each algorithm. When all the algorithms are done, the Race Mgr will print out how many turns it took for each algorithm
class racemngr
{
protected:
	bubble bubbleAl;
    int *arr;
    
public:
	racemngr(int *arr, int n);
	racemngr();

	~racemngr();

	void printArray(int *a, int b);
};

