#include "../../include/Algorithms/Algorithm.h"

void Algorithm::increaseExpandedNodes(){
    this->expandedNodes++;
}

void Algorithm::addTotalHeuristic(int value){
    this->sumHeuristic += value;
}

void Algorithm::setInitialHeuristic(int value) {
    this->initialHeuristic = value;
}

void Algorithm::setSolutionLength(unsigned int value) {
    this->solutionLength = value;
}

void Algorithm::startTimer() {
    this->startTime = chrono::steady_clock::now();
}

void Algorithm::stopTimer() {
    this->endTime = chrono::steady_clock::now();
}

double Algorithm::duration() {  // In seconds
    return chrono::duration_cast<std::chrono::microseconds>(this->endTime - this->startTime).count() / 1000000.0;
}

double Algorithm::meanHeuristic() {
    if (this->generatedNodes > 0){
        return double(this->sumHeuristic) / this->generatedNodes; 
    }
    else {
        return 0;
    }
}

void Algorithm::print() {
    string result = to_string(this->expandedNodes) + ",";
    result += to_string(this->solutionLength) + ',';
    result += to_string(this->duration()) + ',';
    result += to_string(this->meanHeuristic()) + ',';
    result += to_string(this->initialHeuristic);
    cout << result << endl;
}