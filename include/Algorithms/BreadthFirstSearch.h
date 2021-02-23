#ifndef BFS_H
#define BFS_H

#include <unordered_set>
#include <queue>
#include "../NPuzzle/State.h"
#include "../NPuzzle/Node.h"
#include "../NPuzzle/Output.h"


using namespace std;

class BreadthFirstSearch {

private:
    queue<Node> open;
    unordered_set<uint64_t> closed;

public:
    Output run(State initialState);
};

#endif