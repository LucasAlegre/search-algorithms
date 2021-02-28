#include <iostream>
#include <cmath>

#include "../../include/NPuzzle/Node.h"
#include "../../include/NPuzzle/State.h"

int Node::f() const {
    return this->cost + this->heuristicValue;
}

int Node::heuristic(const State &state) {
    int heuristic = manhattan(state);
    if(Node::addLinearConflicts)
        heuristic += linearConflicts(state);
    return heuristic;
}

int Node::manhattan(const State &state){
    int manhattan = 0;
    for(auto i = 0; i < State::sideDim; i++){
        for(auto j = 0; j < State::sideDim; j++){
            auto value = state.valueAt(i, j);
            if (value != 0)
                manhattan += abs(i - (value / State::sideDim)) + abs(j - (value % State::sideDim));
        }
    }
    return manhattan;
}

int Node::linearConflicts(const State &state){
    int conflicts = 0;
    for (auto i = 0; i < State::sideDim; i++){
        for (auto j = 0; j < State::sideDim; j++){
            auto value = state.valueAt(i, j);
            if(value == 0)
                continue;
            
            if (j == (value % State::sideDim)){   // correct column
                for(auto r = i; r < State::sideDim; r++){
                    auto otherValue = state.valueAt(r, j);
                    if (otherValue == 0)
                        continue;
                    if (j == (otherValue % State::sideDim) && value > otherValue){   // correct column too
                        conflicts++;
                    }
                }
            }
            if(i == (value / State::sideDim)){ // correct row
                for(auto c = j; c < State::sideDim; c++){
                    auto otherValue = state.valueAt(i, c);
                    if (otherValue == 0)
                        continue;
                    if(i == (otherValue / State::sideDim) && value > otherValue) { // correct row too
                        conflicts++;
                    }
                }
            }
        }
    }
    return 2 * conflicts;
}