using namespace std;

class racemgr
{
public:
	racemgr(int *arr, int n);
	racemgr();
	void step();
	void printArray(int *a, int b);
	void winner();
	~racemgr();

private:
	int aSize;
	int bubbleCount;
	int mergeCount;
};
