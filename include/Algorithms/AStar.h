#ifndef ASTAR_H
#define ASTAR_H

#include <limits.h>
#include "../NPuzzle/State.h"
#include "../NPuzzle/Node.h"
#include "./Algorithm.h"
#include <queue>
#include <unordered_set>
using namespace std;

struct CompareAStar {
    bool operator()(Node &n1, Node &n2);
};

class AStar : public Algorithm {

private:
    priority_queue<Node, vector<Node>, CompareAStar> open;
    unordered_set<uint64_t> closed;

public:
    void run(State initialState);
};



#endif