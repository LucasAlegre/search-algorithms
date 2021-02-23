#include <iostream>
#include "include/Algorithms/BreadthFirstSearch.h"

using namespace std;

int main(int argc, char** argv) {
    State state(vector<int>({5,0,2,6,4,8,1,7,3}));
    //State state(vector<int>({0,1,2,3,4,5,6,7,8}));
    //cout << state.value << endl;

    BreadthFirstSearch bfs = BreadthFirstSearch();

    Output output = bfs.run(state);
    output.print();

    return 0;
}