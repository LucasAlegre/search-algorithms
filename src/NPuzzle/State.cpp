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
        State::goalState = 36344967696;
        State::sideDim = 3;
    }
    else if(State::nPuzzle == 15){
        State::goalState = 81985529216486895;
        State::sideDim = 4;
    }
    else{
        cout << "Invalid input." << endl;
        exit(-1);
    }
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
    uint64_t k = 0;
    uint64_t mask = 15;
    for (int i = 0; i < State::sideDim; i++){
        for (int j = 0; j < State::sideDim; j++){
            uint64_t tile = (this->value & (mask << 4*k));   // I miss Neander and Ceasar
            tile = tile >> 4*k;
            puzzle += to_string(tile) + " "; 
            k++;
        }
        puzzle += "\n";
    }
    cout << puzzle << endl;
}