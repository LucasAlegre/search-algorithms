#include <iostream>
#include <string.h>
#include "include/Algorithms/BreadthFirstSearch.h"

using namespace std;

int main(int argc, char** argv) {

    vector<int> game;
    vector<State> games;
    //State state(vector<int>({0,1,2,3,4,5,6,7,8}));///S*
    ///State state(game);////S0

    int i = 2;

    while(i<argc)
    {
        game.push_back(stoi(argv[i]));
        i++;
    }
    
    games.push_back(game);

    cout << games[0].value << endl;


    /*
    vector<string> input;
    while(i<argc)
    {
        input.push_back(argv[i]);
        i++;
    }

    i =0;
    while(i<argc)
    {
        if(input[i].find(',')!=string::npos)
        {
            input[i].
            game.push_back(stoi(argv[i]));
            games.push_back(game);
            vector<int> game;
        }
        else{
            game.push_back(stoi(argv[i]));
        }
        i++;
    }
    */
    

    if(strcmp(argv[1],"-bfs")==0)
    {
        BreadthFirstSearch bfs = BreadthFirstSearch();
        bfs.run(games[0]);
        bfs.print();
    }
    else if(strcmp(argv[1],"-idfs")==0)
    {
        ///function
    }
    else if(strcmp(argv[1],"-astar")==0)
    {
        ///function
    }
    else if(strcmp(argv[1],"-idastar")==0)
    {
        ///function
    }
    else if(strcmp(argv[1],"-gbfs")==0)
    {
        ///function
    }
    return 0;
}