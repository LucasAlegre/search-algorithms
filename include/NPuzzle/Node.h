#ifndef NODE_H
#define NODE_H

#include "./State.h"

class Node {
    
public:
    Node(State state, int cost) : state(state), cost(cost) { this->heuristicValue = heuristic(this->state); }
    const State& getState() const { return state; }
    const int getCost() const { return cost; }
    const int getHeuristicValue() const { return heuristicValue; }
    static int heuristic(State state);

private:
    State state;
    int cost;
    int heuristicValue;
};

#endif