//
//  main.cpp
//  EISTI C++ Course
//
//  Created by Mathieu MBP 13 on 17/10/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
// mathieu@floweducation.io

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <vector>
#include "Operation.hpp"
using namespace std;


typedef struct {
    Operation userOperation;
    Operation computerOperation;
    OperationResult userResult;
} RoundHistory;

bool playAgain();
void printRules();
Operation userOperation();
Operation computerOperation();

/* Copies the ctor passed in and prints the round number. */
void printRoundResult(vector<RoundHistory> vec, int roundNumber);
double percentage(double valueOne, double valueTwo);

/** Creates a round History Struct element **/
RoundHistory createHistoryDataPoint(Operation userOp, Operation computerOp, OperationResult res);

int numUserResults(vector<RoundHistory> vec, OperationResult result);

int main(int argc, const char * argv[]) {
    // insert code here...

    int roundNumber = 0;
    
    // print the rules at the beginning
    printRules();
    
    // When declaring a vector it will use the default initializer for it
    // With an empty list of elements
    
    vector<RoundHistory> history;
    
    do {
        
        // Increment the round Number so we start at 1
        roundNumber++;
        
        Operation userOp = userOperation();
        Operation computerOp = Operation::s_randOperation();
        OperationResult userWon = userOp.result(computerOp);
        
        // Create a datapoint for the new round
        RoundHistory dataPoint = createHistoryDataPoint(userOp, computerOp, userWon);
        // Adds an element at the end of the list. It handles resizing the array for us.
        // No need to copy it and play with pointers.
        history.push_back(dataPoint);
        
        cout << endl;
        printRoundResult(history, roundNumber);
        
    } while ( playAgain() == true );
    
    
    
    return 0;
}

void printRules() {
    
    cout << "You are about to play rock (r/R), paper (p/P), scissors (s/S). " << endl;
    cout << "Paper wins rock, rock wins scissors and scissors win rock. " << endl;
    cout << endl;
}

bool playAgain() {
    
    cout << "Do you want to play again (y/n)? ";
    
    string character;
    cin >> character;
    // What happens if you uncomment this line? Why do we needs this?
    // hint: it has something to do with the newline character.
    // discussion here: https://stackoverflow.com/questions/5877420/c-cin-input-not-working
    cin.ignore();
    
    if (character == "y") {
        
        return true;
    } else if (character == "n") {
        
        return false;
    }
    
    cout << "Illegal input: " << character << endl;
    
    // Illegal input call the same method recursively.
    return playAgain();
}

Operation userOperation() {
    
    cout << "Choose between Rock (r/R), Paper (p/P), Scissors (s/S), Lizard (l/L), Spock (sp/Sp/SP): " << endl;
    
    string stringOperation;
    
    cin >> stringOperation;
    cin.ignore();
    
    OperationType type = Operation::s_operationType(stringOperation);
    if (type != OperationTypeUnknown) {
        return Operation(type);
    }
    
    cout << "Illegal input " << stringOperation << " try again." << endl;
    
    return userOperation();
}

void printRoundResult(vector<RoundHistory> vec, int roundNumber) {
    
    RoundHistory lastRound = vec[roundNumber - 1];
    
    cout << "Round number: " << roundNumber << endl;
    lastRound.userOperation.printOperation();
    cout << " vs. ";
    lastRound.computerOperation.printOperation();
    cout << ". ";
    lastRound.userOperation.printResult( lastRound.userResult );
    cout << endl;
    
    // Print stats with other functions.
    cout << "The user win percentage: " << percentage(numUserResults(vec, OperationResultWon), roundNumber) << "%" << endl;
    cout << "The computer win percentage: " << percentage(numUserResults(vec, OperationResultLost), roundNumber) << "%" << endl;
    cout << "Number of ties: " << percentage(numUserResults(vec, OperationResultTie), roundNumber) << "%" << endl;
    
}

int numUserResults(vector<RoundHistory> vec, OperationResult result) {
    
    int value = 0;
    
    for (int i = 0; i < vec.size(); i++) {
        const RoundHistory point = vec[i];
        if (point.userResult == result) {
            value++;
        }
    }
    
    return value;
}

double percentage(double valueOne, double valueTwo) {
    
    return valueOne / valueTwo * 100;
}

RoundHistory createHistoryDataPoint(Operation userOp, Operation computerOp, OperationResult res) {
    
    RoundHistory history;
    history.userOperation = userOp;
    history.computerOperation = computerOp;
    history.userResult = res;
    
    return history;
}
