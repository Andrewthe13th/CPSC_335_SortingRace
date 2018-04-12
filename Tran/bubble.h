class bubble
{
public:
	int * perform();
	void printState();
	int step(int a , int b);
    int *getArray() { return copy;}
    int getState();
    
	bubble(int *b, int f);
	bubble();
	~bubble();

protected:
	int state;
	int *arr, prefix, suffix, size, s, *copy;

};

