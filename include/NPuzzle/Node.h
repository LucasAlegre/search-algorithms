#ifndef NODE_H
#define NODE_H

#include "./State.h"

class Node {
    
public:
    Node(State state, int cost) : state(state), cost(cost) { this->heuristicValue = heuristic(this->state); }
    const State& getState() const { return state; }
    int getCost() const { return cost; }
    int getHeuristicValue() const { return heuristicValue; }
    int f() const;
    
    static int heuristic(const State &state);
    static int manhattan(const State &state);
    static int linearConflicts(const State &state);

    static const bool addLinearConflicts = false;

private:
    State state;
    int cost;
    int heuristicValue;
};

#endif