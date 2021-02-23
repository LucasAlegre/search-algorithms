#include "../../include/NPuzzle/Output.h"

void Output::increaseExpandedNodes(){
    this->expandedNodes++;
}

void Output::addTotalHeuristic(int value){
    this->sumHeuristic += value;
}

void Output::setInitialHeuristic(int value) {
    this->initialHeuristic = value;
}

void Output::setSolutionLength(unsigned int value) {
    this->solutionLength = value;
}

void Output::startTimer() {
    this->startTime = chrono::steady_clock::now();
}

void Output::stopTimer() {
    this->endTime = chrono::steady_clock::now();
}

double Output::duration() {  // In seconds
    return chrono::duration_cast<std::chrono::microseconds>(this->endTime - this->startTime).count() / 1000000.0;
}

double Output::meanHeuristic() {
    if (this->generatedNodes > 0){
        return double(this->sumHeuristic) / this->generatedNodes; 
    }
    else {
        return 0;
    }
}

void Output::print() {
    string output = to_string(this->expandedNodes) + ",";
    output += to_string(this->solutionLength) + ',';
    output += to_string(this->duration()) + ',';
    output += to_string(this->meanHeuristic()) + ',';
    output += to_string(this->initialHeuristic);
    cout << output << endl;
}