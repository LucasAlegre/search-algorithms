#ifndef ALGO_H
#define ALGO_H

#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include "../NPuzzle/State.h"

using namespace std;

class Algorithm {

private:
    unsigned int expandedNodes;
    unsigned int generatedNodes;
    unsigned int solutionLength;
    int sumHeuristic;
    int initialHeuristic;
    chrono::steady_clock::time_point startTime;
    chrono::steady_clock::time_point endTime;

public:
    Algorithm() : expandedNodes(0), solutionLength(0), generatedNodes(0), sumHeuristic(0) {};
    void increaseExpandedNodes();
    void addTotalHeuristic(int value);
    void setInitialHeuristic(int value);
    void setSolutionLength(unsigned int value);
    void startTimer();
    void stopTimer();
    double duration();
    double meanHeuristic();
    void print();

    virtual void run(State initialState) = 0;
};

#endif