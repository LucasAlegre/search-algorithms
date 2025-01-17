#include <iostream>
#include <bitset>
#include "../../include/Algorithms/BreadthFirstSearch.h"

void BreadthFirstSearch::run(State initialState) {
    this->startTimer();

    if (initialState.isGoal()){
        this->stopTimer();
        this->setInitialHeuristic(Node::heuristic(initialState));
        return;
    }

    Node n(initialState, 0);
    this->open = {};
    this->open.push(n);
    this->closed = {};
    this->closed.insert(initialState.value);

    this->setInitialHeuristic(n.getHeuristicValue());

    while(!this->open.empty()){
        Node n = this->open.front();
        this->open.pop();
        this->increaseExpandedNodes();

        for(State nextState : n.getState().successorStates()){
            if (nextState.isGoal()){
                this->stopTimer();
                this->setSolutionLength(n.getCost() + 1);
                return;
            }
            if (closed.find(nextState.value) == closed.end()){
                this->closed.insert(nextState.value);
                Node nextNode(nextState, n.getCost() + 1);
                this->open.push(nextNode);
            }
        }
    }
    this->stopTimer();
}