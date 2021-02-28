#ifndef IDS_H
#define IDS_H

#include <unordered_set>
#include <queue>
#include "../NPuzzle/State.h"
#include "../NPuzzle/Node.h"
#include "./Algorithm.h"

using namespace std;

class IterativeDeepening : public Algorithm {

private:
    int maxDepth = 1000;

    bool depthLimitedSearch(State& initialState, int depthLimit);

public:
    void run(State initialState);
};


#endif