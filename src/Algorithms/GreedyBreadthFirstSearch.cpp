#include <iostream>
#include <bitset>
#include "../../include/Algorithms/GreedyBreadthFirstSearch.h"

bool CompareGBFS::operator()(Node &n1, Node &n2) {
    if (n1.getHeuristicValue() != n2.getHeuristicValue())
        return n1.getHeuristicValue() > n2.getHeuristicValue();
    else if (n1.getCost() != n2.getCost())
        return n1.getCost() < n2.getCost();
    else
        return n1.getIndex() < n2.getIndex();
}

void GreedyBreadthFirstSearch::run(State initialState) {
    this->startTimer();

    if (initialState.isGoal()){
        this->stopTimer();
        this->setInitialHeuristic(Node::heuristic(initialState));
        return;
    }

    Node n(initialState, 0);
    this->open;
    this->open.push(n);
    this->closed = {};

    this->logGeneratedNode(n.getHeuristicValue());
    this->setInitialHeuristic(n.getHeuristicValue());

    while (!this->open.empty()){
        Node n = this->open.top();
        this->open.pop();

        if (closed.find(n.getState().value) == closed.end()){
            this->closed.insert(n.getState().value);
            if (n.getState().isGoal()){
                this->stopTimer();
                this->setSolutionLength(n.getCost());
                return;
            }

            this->increaseExpandedNodes();
            for (State nextState : n.getState().successorStates()){
                Node nextNode(nextState, n.getCost() + 1);
                this->open.push(nextNode);
                this->logGeneratedNode(nextNode.getHeuristicValue());
            }
        }
    }
    this->stopTimer();
}