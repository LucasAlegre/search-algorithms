#include <iostream>
#include <string.h>
#include <sstream>
#include "include/Algorithms/BreadthFirstSearch.h"

using namespace std;

vector<string> split(string input, string delimiter)
{
    vector<string> jogos;

    size_t pos = 0;
    std::string token;
    while ((pos = input.find(delimiter)) != std::string::npos) {
        token = input.substr(0, pos);
        input.erase(0, pos + delimiter.length());
        jogos.push_back(token);
    }
    jogos.push_back(input);
    return jogos;
}


int main(int argc, char** argv) {

    vector<int> game;
    vector<State> games;
    //State state(vector<int>({0,1,2,3,4,5,6,7,8}));///S*
    ///State state(game);////S0

    int i = 2;

    string input ="";


    for(int i=2; i<argc; i++)
    {
        input =argv[i];
        if(input.find(",") == string::npos)
        {
            game.push_back(stoi(input));
        }
        else
        {
            input = input.substr(0,input.size()-1);
            game.push_back(stoi(input));
            games.push_back(game);
            game.clear();
        }
        
    }
    if(!game.empty())
        games.push_back(game);
    if(strcmp(argv[1],"-bfs")==0)
    {
        for(int i = 0; i<games.size(); i++)
        {
            BreadthFirstSearch bfs = BreadthFirstSearch();
            bfs.run(games[i]);
            bfs.print();    
        }
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