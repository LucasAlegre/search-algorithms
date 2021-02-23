#ifndef NODE_H
#define NODE_H

#include "./State.h"

class Node {
    
public:
    Node(State state, int cost) : state{state}, cost(cost) { this->heuristic_value = heuristic(state); }
    const State& getState() const { return state; }
    const int getCost() const { return cost; }
    const int getHeuristicValue() const { return cost; }
    static int heuristic(State state);

private:
    State state;
    int cost;
    int heuristic_value;
};

#endif