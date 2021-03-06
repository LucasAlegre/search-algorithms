#ifndef GBFS_H
#define GBFS_H

#include <unordered_set>
#include <stack>
#include "../NPuzzle/State.h"
#include "../NPuzzle/Node.h"
#include "./Algorithm.h"

using namespace std;

class GreedyBreadthFirstSearch : public Algorithm {

private:
    stack<Node> open;
    unordered_set<uint64_t> closed;

public:
    void run(State initialState);
};

#endif