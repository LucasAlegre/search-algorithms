#include "../../include/Algorithms/IterativeDeepening.h"

bool IterativeDeepening::depthLimitedSearch(State& initialState, int depthLimit){
    if (initialState.isGoal()) {
        return true;
    }
    if (depthLimit > 0) {
        this->increaseExpandedNodes();
        for (State nextState : initialState.successorStates()){
            bool solution = depthLimitedSearch(nextState, depthLimit - 1);
            if (solution) {
                return true;
            }
        }
    }
    return false;
}

void IterativeDeepening::run(State initialState) {
    this->startTimer();
    this->setInitialHeuristic(Node::heuristic(initialState));

    for(int depth = 0; depth < this->maxDepth; depth++){
        bool solution = depthLimitedSearch(initialState, depth);
        if(solution) {
            this->stopTimer();
            this->setSolutionLength(depth);
            return;
        }
    }
    this->stopTimer();
}