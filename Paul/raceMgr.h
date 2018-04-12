#include "bubble.h"
using namespace std;

class racemgr
{
public:
	racemgr(int *arr, int n);
	racemgr();
    bubble bubbleAlgo;
	void step();
	void printArray(int *a, int b);
	void winner();
	~racemgr();

private:
	int aSize;
	int bubbleCount;
	int mergeCount;
};
