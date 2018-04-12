#pragma once
#define SIZE 12
class bubble
{

protected:
	int *workingarray; //copy
	int size;
	int prefix;
	int suffix;
public:
	bubble();
	int* getPointer() { return workingarray; }
	int count;
	bubble(int *arr, int size);
	int step();
	int state;


	~bubble();
};

