all:    sort_race

sort_race:  Source.o RaceMgr.o MergeSort.o BubbleSort.o Algorithms.o
	g++ -std=c++11 Source.o RaceMgr.o MergeSort.o BubbleSort.o Algorithms.o -o sort_race

Source.o:   Source.cpp
	g++ -std=c++11 -g -c Source.cpp 

RaceMgr.o:  RaceMgr.h MergeSort.h BubbleSort.h
	g++ -std=c++11 -g -c RaceMgr.cpp
	
MergeSort.o:    MergeSort.h Algorithms.h
	g++ -std=c++11 -g -c MergeSort.cpp

BubbleSort.o: BubbleSort.h Algorithms.h
	g++ -std=c++11 -g -c BubbleSort.cpp

Algorithms.o: Algorithms.h
	g++ -std=c++11 -g -c Algorithms.cpp


clean:
	rm -rf *.o
