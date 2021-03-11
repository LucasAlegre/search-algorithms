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
    vector<string> instances;
    size_t pos = 0;
    string token;
    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        input.erase(0, pos + delimiter.length());
        instances.push_back(token);
    }
    instances.push_back(input);
    return instances;
}

int main(int argc, char** argv) {

    vector<int> instance;
    vector<State> instances;
    string input;
    if(argc > 3) {
        for(int i = 2; i < argc; i++) {
            input = argv[i];
            if(input.find(",") == string::npos) {
                instance.push_back(stoi(input));
            }
            else {
                input = input.substr(0, input.size() - 1);
                instance.push_back(stoi(input));
                instances.push_back(instance);
                instance.clear();
            }
        }
        if(!instance.empty())
            instances.push_back(instance);
    }
    else if(argc == 3) {
        ifstream file(argv[2]);
        string line;
        while(getline(file, line)) {
            vector<string> text_input = split(line, " ");
            for(int i = 0; i < text_input.size(); i++) {
                instance.push_back(stoi(text_input[i]));
            }
            instances.push_back(instance);
            instance.clear();
        }
        file.close();
    }

    if(strcmp(argv[1],"-bfs")==0) {
        for(int i = 0; i < instances.size(); i++){
            BreadthFirstSearch bfs = BreadthFirstSearch();
            bfs.run(instances[i]);
            bfs.print();    
        }
    }
    else if(strcmp(argv[1],"-idfs")==0) {
        for(int i = 0; i < instances.size(); i++){
            IterativeDeepening idfs = IterativeDeepening();
            idfs.run(instances[i]);
            idfs.print();
        }
    }
    else if(strcmp(argv[1],"-astar")==0) {
        for(int i = 0; i < instances.size(); i++){
            AStar astar = AStar();
            astar.run(instances[i]);
            astar.print();
        }
    }
    else if(strcmp(argv[1],"-idastar")==0) {
        for(int i = 0; i < instances.size(); i++){
            IDAStar idastar = IDAStar();
            idastar.run(instances[i]);
            idastar.print();
        }
    }
    else if(strcmp(argv[1],"-gbfs")==0) {
        for(int i = 0; i < instances.size(); i++){
            GreedyBreadthFirstSearch gbfs = GreedyBreadthFirstSearch();
            gbfs.run(instances[i]);
            gbfs.print();
        }
    }
    else{ 
        cout << "Invalid algorithm." << endl;
        return -1;
    }
    return 0;
}