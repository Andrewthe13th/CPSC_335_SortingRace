#pragma once

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;



class Algorithm {
public:
	Algorithm() { racePosition = RacePlace::None; Astatus = AlgorithmStatus::Unsorted; };
	// stepping method that return false if algorithm is done stepping
	virtual void step() {};
	// return element in the array
	int getListElement(int element);
	void printList();

	// Algorithm status codes
	enum class AlgorithmStatus { FinishedSorting, Unsorted, Swapping };
	enum class RacePlace { None, Winner, Loser };

	AlgorithmStatus getStatus() { return Astatus; };
	RacePlace getRacePosition() { return racePosition; };
	void setRacePosition(RacePlace a) { racePosition = a; };
	string ID;

	

protected:
	RacePlace racePosition;
	AlgorithmStatus Astatus;
	// copied array
	vector<int> list;
};


#endif /* ALGORITHM_H */
