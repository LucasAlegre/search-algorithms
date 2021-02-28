#include "../../include/Algorithms/IDAStar.h"

int IDAStar::fLimitedSearch(Node& node, int& recLimit){
    if (node.f() > this->fLimit){
        recLimit = node.f();
        return -1;
    }
    if (node.getState().isGoal()) {
        return node.getCost();
    }
    int nextLimit = INT_MAX;
    this->increaseExpandedNodes();
    for(State nextState : node.getState().successorStates()){
        Node newNode(nextState, node.getCost() + 1);
        this->logGeneratedNode(newNode.getHeuristicValue());
        int thisRecLimit;
        int solutionCost = fLimitedSearch(newNode, thisRecLimit);
        if (solutionCost != -1){
            return solutionCost;
        }
        nextLimit = min(nextLimit, thisRecLimit);
    }
    recLimit = nextLimit;
    return -1;
}

void IDAStar::run(State initialState) {
    this->startTimer();

    Node n(initialState, 0);
    this->logGeneratedNode(n.getHeuristicValue());
    this->setInitialHeuristic(n.getHeuristicValue());
    
    this->fLimit = n.getHeuristicValue();
    while (this->fLimit < INT_MAX) {
        this->logGeneratedNode(n.getHeuristicValue());
        int recLimit;
        int solution = fLimitedSearch(n, recLimit);
        this->fLimit = recLimit;
        if (solution != -1) {
            this->stopTimer();
            this->setSolutionLength(solution);
            return;
        }
    }
    this->stopTimer();
}