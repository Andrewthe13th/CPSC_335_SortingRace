Class 335 - Algorithm Engineering
Project 1 - Sort Race

Team Name: PAN
Paul Smith pgsmith@csu.fullerton.edu
Andrew de Fluente adelafuente3@csu.fullerton.edu
Nguyen Tran ntran272@csu.fullerton.edu

##Intro
In this project, we follow the algorithm Bubble Sort and Merge Sort from the project guides.

##Contents
Algorithms.cpp
Algorithms.h
BubbleSort.cpp
BubbleSort.h
MergeSort.cpp
MergeSort.h
RaceMgr.cpp
RaceMgr.h
Source.cpp
README.txt
Makefile
TestRuns.txt

##Setup and Installation
linux and macos with g++:
  Use the Makefile provided with the other files
  Run command: make -f Makefile

##Sample invocation
./sort_race <numbers separated by spaces>

##Features
The program will run each algorithm one step at a time and provide a printout if there was a comparison that made a switch.
When an algorithm has finished sorting the list of numbers, the first algorithm is decided the winner and its total moves are
recorded. The second algorithm to finish is declared the looser and its total moves are recorded. When all algorithms are done
running, the algorithms final lists are printed and the Winner/Looser are printed out with their final count.

##Known Bugs
When a swap is made with merge the correct state of the array is not always printed correctly. The count and final array do print correctly.


