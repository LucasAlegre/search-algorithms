#ifndef BFS_H
#define BFS_H

#include <unordered_set>
#include <queue>
#include "../NPuzzle/State.h"
#include "../NPuzzle/Node.h"
#include "../NPuzzle/Output.h"
#include "./Algorithm.h"

using namespace std;

class BreadthFirstSearch : public Algorithm  {

private:
    queue<Node> open;
    unordered_set<uint64_t> closed;

public:
    void run(State initialState);
};

#endif