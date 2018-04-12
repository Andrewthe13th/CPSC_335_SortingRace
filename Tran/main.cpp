#include <iostream>
#include <string>
#include <sstream>
#include "racemngr.h"

#define SIZE 12
using namespace std;



int main() {
	int arr[SIZE] = {12,11,10,9,8,7,6,5,4,3,2,1};

	racemngr RM = racemngr(arr, SIZE);

	return 0;
}
