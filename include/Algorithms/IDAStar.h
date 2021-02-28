#ifndef IDASTAR_H
#define IDASTAR_H

#include <limits.h>
#include "../NPuzzle/State.h"
#include "../NPuzzle/Node.h"
#include "./Algorithm.h"

using namespace std;

class IDAStar : public Algorithm {

private:
    int fLimit;

    int fLimitedSearch(Node &node, int &recLimit);

public:
    void run(State initialState);
};


#endif