#include <string>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
#include "raceMgr.cpp"

using namespace std;

int main(int argc, char *argv[]){
    
    string arr1;
    for (int i = 1; i < argc; i++){
        arr1 += argv[ i ];
        arr1 += " ";
    }

    raceMgr race(arr1, argc);
    cout << "Race Start: ";

    for (int i = 0; i < arr1.size(); i++)	{
		cout << arr1[i] << ", ";
	}
	cout << endl;

    while(//both algos have not finished/){
        race.step();
        }
    race.winner();
}