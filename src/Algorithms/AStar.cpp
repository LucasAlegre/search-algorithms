#include "../../include/Algorithms/AStar.h"

bool Comparef::operator()(Node N1, Node N2)
{
    return N1.f() > N2.f();
}

void AStar::run(State initialState)
{
    this->startTimer();

    if (initialState.isGoal())
    {
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

    while (!this->open.empty())
    {
        Node n = this->open.top();
        this->open.pop();
        this->increaseExpandedNodes();
        this->logGeneratedNode(n.getHeuristicValue());
        if (closed.find(n.getState().value) == closed.end())
        {
            this->closed.insert(n.getState().value);
            if (n.getState().isGoal())
            {
                this->stopTimer();
                this->setSolutionLength(n.getCost() + 1);
                return;
            }
            for (State nextState : n.getState().successorStates())
            {
                Node nextNode(nextState, n.getCost() + 1);
                this->open.push(nextNode);
            }
        }
    }
    this->stopTimer();
}