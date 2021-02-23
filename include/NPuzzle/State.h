#ifndef STATE_H
#define STATE_H

#include <vector>
#include <cstdint>

using namespace std;

struct State {
    /***
     *   Each tile is represented by 4 bits in the 64 bits value
     * 
     **/
    uint64_t value;
    uint8_t blankPos;
    uint8_t parentBlankPos;

    static short nPuzzle;
    static short sideDim;
    static uint64_t goalState;

    State(uint64_t value, uint64_t blankPos, uint8_t parentBlankPos) : value(value), blankPos(blankPos), parentBlankPos(parentBlankPos) {};
    State(vector<int> pos);
    bool isGoal() const;
    vector<State> successorStates() const;
    State move(uint8_t movePos) const;
    void print() const;
};

#endif