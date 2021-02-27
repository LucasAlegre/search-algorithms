#include <iostream>
#include <math.h>

#include "../../include/NPuzzle/Node.h"
#include "../../include/NPuzzle/State.h"

int Node::heuristic(State state){
    uint64_t mask = 15; // 1111
    uint8_t k = 0;
    int heuristic = 0;
    for(int i = 0; i < State::sideDim; i++){
        for(int j = 0; j < State::sideDim; j++){
            uint64_t valueMasked = state.value & mask;
            int value = valueMasked >> 4*k;
            if (value != 0)
                heuristic += abs(i - (value / State::sideDim)) + abs(j - (value % State::sideDim));
            k++;
            mask = mask << 4;
        }
    }
    return heuristic;
}