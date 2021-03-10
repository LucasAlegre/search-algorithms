#include <iostream>
#include <string.h>
#include <sstream>
#include "include/Algorithms/BreadthFirstSearch.h"
#include "include/Algorithms/GreedyBreadthFirstSearch.h"
#include "include/Algorithms/IterativeDeepening.h"
#include "include/Algorithms/IDAStar.h"
#include "include/Algorithms/AStar.h"

using namespace std;

vector<string> split(string input, string delimiter) {
    vector<string> jogos;

    size_t pos = 0;
    string token;
    while ((pos = input.find(delimiter)) != string::npos) {
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
    string input;
    if(argc > 3) {
        for(int i = 2; i < argc; i++) {
            input = argv[i];
            if(input.find(",") == string::npos) {
                game.push_back(stoi(input));
            }
            else {
                input = input.substr(0, input.size() - 1);
                game.push_back(stoi(input));
                games.push_back(game);
                game.clear();
            }
        }
        if(!game.empty())
            games.push_back(game);
    }
    else if(argc == 3) {
        ifstream file(argv[2]);
        string line;
        while(getline(file, line)) {
            vector<string> text_input = split(line, " ");
            for(int i = 0; i < text_input.size(); i++) {
                game.push_back(stoi(text_input[i]));
            }
            games.push_back(game);
            game.clear();
        }
        file.close();
    }

    if(strcmp(argv[1],"-bfs")==0) {
        for(int i = 0; i < games.size(); i++){
            BreadthFirstSearch bfs = BreadthFirstSearch();
            bfs.run(games[i]);
            bfs.print();    
        }
    }
    else if(strcmp(argv[1],"-idfs")==0) {
        for(int i = 0; i < games.size(); i++){
            IterativeDeepening idfs = IterativeDeepening();
            idfs.run(games[i]);
            idfs.print();
        }
    }
    else if(strcmp(argv[1],"-astar")==0) {
        cout << "kkkk";
        for(int i = 0; i < games.size(); i++){
            AStar astar = AStar();
            astar.run(games[i]);
            astar.print();
        }
    }
    else if(strcmp(argv[1],"-idastar")==0) {
        for(int i = 0; i < games.size(); i++){
            IDAStar idastar = IDAStar();
            idastar.run(games[i]);
            idastar.print();
        }
    }
    else if(strcmp(argv[1],"-gbfs")==0) {
        for(int i = 0; i < games.size(); i++){
            GreedyBreadthFirstSearch gbfs = GreedyBreadthFirstSearch();
            gbfs.run(games[i]);
            gbfs.print();
        }
    }
    else{ 
        cout << "Invalid algorithm." << endl;
        return -1;
    }
    return 0;
}