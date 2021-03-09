#ifndef GBFS_H
#define GBFS_H

#include <unordered_set>
#include <queue>
#include "../NPuzzle/State.h"
#include "../NPuzzle/Node.h"
#include "./Algorithm.h"

using namespace std;

class Compare {
    public:
        bool operator()(Node N1, Node N2);
};

class GreedyBreadthFirstSearch : public Algorithm {

private:
    priority_queue<Node, vector<Node>, Compare> open;
    unordered_set<uint64_t> closed;

public:
    void run(State initialState);
};

#endif