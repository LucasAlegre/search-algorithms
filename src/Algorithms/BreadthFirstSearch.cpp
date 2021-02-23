#include <iostream>
#include <bitset>
#include "../../include/Algorithms/BreadthFirstSearch.h"
#include "../../include/NPuzzle/Output.h"

Output BreadthFirstSearch::run(State initialState) {
    Output output;
    output.startTimer();

    if (initialState.isGoal()){
        output.stopTimer();
        output.setInitialHeuristic(Node::heuristic(initialState));
        return output;
    }

    Node n(initialState, 0);
    this->open = {};
    this->open.push(n);
    this->closed = {};
    this->closed.insert(initialState.value);

    output.setInitialHeuristic(n.getHeuristicValue());

    while(!this->open.empty()){
        Node n = this->open.front();
        this->open.pop();
        output.increaseExpandedNodes();

        for(State nextState : n.getState().successorStates()){
            if (nextState.isGoal()){
                output.stopTimer();
                output.setSolutionLength(n.getCost() + 1);
                return output;
            }
            if (closed.find(nextState.value) == closed.end()){
                this->closed.insert(nextState.value);
                Node nextNode(nextState, n.getCost() + 1);
                this->open.push(nextNode);
            }
        }
    }
    output.stopTimer();
    return output;
}