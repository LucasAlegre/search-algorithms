#include <iostream>
#include <bitset>

#include "../../include/NPuzzle/State.h"

short State::nPuzzle;
short State::sideDim;
uint64_t State::goalState;

State::State(vector<int> pos){
    this->value = 0;
    for(int i = pos.size() - 1; i >= 0; i--){
        this->value = this->value << 4;
        this->value = this->value | pos[i];
        if(pos[i] == 0){
            this->blankPos = i;
            this->parentBlankPos = i;
        }
    }
    State::nPuzzle = pos.size() - 1;
    if(State::nPuzzle == 8){
        State::goalState = 36344967696U;  // 0 1 2 3 4 5 7 8
        State::sideDim = 3;
    }
    else if(State::nPuzzle == 15){
        State::goalState = 18364758544493064720U;  // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
        State::sideDim = 4;
    }
    else{
        cout << "Invalid input." << endl;
        exit(-1);
    }
}

uint8_t State::valueAt(uint8_t i, uint8_t j) const {
    uint64_t mask = 15;
    auto moves = (4*(i*State::sideDim + j));
    mask = mask << moves; 
    return (this->value & mask) >> moves;   // I miss Neander and Ceasar
}

bool State::isGoal() const {
    return this->value == State::goalState;
}

vector<State> State::successorStates() const {
    vector<State> nextStates;

    // Order: up, left, right, down
    if(this->blankPos >= State::sideDim) {  // Move up
        uint8_t movePos = this->blankPos - State::sideDim;
        if(movePos != this->parentBlankPos) {
            State newState = this->move(movePos);
            nextStates.push_back(newState);
        }
    }
    if(this->blankPos % State::sideDim != 0) {  // Move left
        uint8_t movePos = this->blankPos - 1;
        if(movePos != this->parentBlankPos) {
            State newState = this->move(movePos);
            nextStates.push_back(newState);
        }
    }
    if((this->blankPos+1) % State::sideDim != 0) {  // Move right
        uint8_t movePos = this->blankPos + 1;
        if(movePos != this->parentBlankPos) {
            State newState = this->move(movePos);
            nextStates.push_back(newState);
        }
    }
    if(this->blankPos < State::sideDim*(State::sideDim - 1)) {  // Move down
        uint8_t movePos = this->blankPos + State::sideDim;
        if(movePos != this->parentBlankPos) {
            State newState = this->move(movePos);
            nextStates.push_back(newState);
        }
    }
    return nextStates;
}

State State::move(uint8_t movePos) const {
    uint64_t mask = 15;
    mask = mask << 4*movePos;
    uint64_t onlyValueToMove = this->value & mask;
    uint64_t stateValueWithoutMovedValue = this->value & ~mask;
    if (movePos > this->blankPos){
        onlyValueToMove = onlyValueToMove >> (4 * (movePos - this->blankPos));
    }
    else {
        onlyValueToMove = onlyValueToMove << (4 * (this->blankPos - movePos));
    }
    return State(stateValueWithoutMovedValue | onlyValueToMove, movePos, this->blankPos);
}

void State::print() const {
    string puzzle = "";
    for (int i = 0; i < State::sideDim; i++){
        for (int j = 0; j < State::sideDim; j++){
            auto tile = this->valueAt(i, j);
            puzzle += to_string(tile) + " "; 
        }
        puzzle += "\n";
    }
    cout << puzzle << endl;
}