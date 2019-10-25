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
using namespace std;


/**
 Class enumerators are slightly different from normal enumerators.
 They are not integers and can only be compard with Operation enumerators.
 */
typedef enum {
    Rock,
    Paper,
    Scissor,
    Lizard,
    Spock
} Operation;

typedef enum {
    Won,
    Tie,
    Lost
} Result;

typedef struct {
    Operation userOperation;
    Operation computerOperation;
    Result userResult;
} RoundHistory;

bool playAgain();
void printRules();
Operation userOperation();
Operation computerOperation();
Result won(Operation operationOne, Operation operationTwo);
void printOp(Operation op);
void printResult(Result result);
void printRoundResult(RoundHistory *gameHistory, int roundNumber);
double percentage(double valueOne, double valueTwo);
RoundHistory createHistoryDataPoint(Operation userOp, Operation computerOp, Result res);
RoundHistory * createHistoryArray(RoundHistory *listToCopy, RoundHistory newDataPoint, int numValues);
int numUserResults(RoundHistory *history, Result result, int numValues);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // Initialize the random generator
    srand(time(NULL));

    int roundNumber = 0;
    
    // print the rules at the beginning
    printRules();
    RoundHistory *historyArray = nullptr;
    
    do {
        
        // Increment the round Number so we start at 1
        roundNumber++;
        
        Operation userOp = userOperation();
        Operation computerOp = computerOperation();
        Result userWon = won(userOp, computerOp);
        
        // Create a datapoint for the new round
        RoundHistory dataPoint = createHistoryDataPoint(userOp, computerOp, userWon);
        
        historyArray = createHistoryArray(historyArray, dataPoint, roundNumber);
        
        cout << endl;
        printRoundResult(historyArray, roundNumber);
        
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
    
    if (stringOperation == "r" || stringOperation == "R") {
        
        return Rock;
    } else if (stringOperation == "p" || stringOperation == "P") {
        
        return Paper;
    } else if (stringOperation == "s" || stringOperation == "S") {
        
        return Scissor;
    } else if (stringOperation == "l" || stringOperation == "L") {
        
        return Lizard;
    } else if (stringOperation == "sp" || stringOperation == "Sp" || stringOperation == "SP") {
        return Spock;
    }
    
    cout << "Illegal input " << stringOperation << " try again." << endl;
    
    return userOperation();
}

Operation computerOperation() {
    
    Operation availableOperations[5] = { Rock, Paper, Scissor, Lizard, Spock };
    
    // Gives a random value from 0 - 4
    int randomIndex = rand() % 5;
    
    return availableOperations[randomIndex];
    
}

Result won(Operation operationOne, Operation operationTwo) {
    
    if (operationOne == operationTwo) {
        return Tie;
    }
    
    if (operationOne == Rock) {
        if (operationTwo == Paper || operationTwo == Spock) {
            return Lost;
        }
    } else if (operationOne == Paper) {
        if (operationTwo == Scissor || operationTwo == Lizard) {
            return Lost;
        }
    } else if (operationOne == Scissor) {
        if (operationTwo == Rock || operationTwo == Spock) {
            return Lost;
        }
    } else if (operationOne == Lizard) {
        if (operationTwo == Rock || operationTwo == Scissor) {
            return Lost;
        }
    } else if (operationOne == Spock) {
        if (operationTwo == Paper || operationTwo == Lizard) {
            return Lost;
        }
    }
    
    // We have exhausted all posibilities so we know we win.
    return Won;
}

void printRoundResult(RoundHistory *playerHistory, int roundNumber) {
    
    const RoundHistory lastRound = playerHistory[roundNumber - 1];
    
    cout << "Round number: " << roundNumber << endl;
    printOp(lastRound.userOperation);
    cout << " vs. ";
    printOp(lastRound.computerOperation);
    cout << ". ";
    printResult(lastRound.userResult);
    cout << endl;
    
    // Print stats with other functions.
    cout << "The user win percentage: " << percentage(numUserResults(playerHistory, Won, roundNumber), roundNumber) << "%" << endl;
    cout << "The computer win percentage: " << percentage(numUserResults(playerHistory, Lost, roundNumber), roundNumber) << "%" << endl;
    cout << "Number of ties: " << percentage(numUserResults(playerHistory, Tie, roundNumber), roundNumber) << "%" << endl;
    
}

void printResult(Result result) {
    
    if (result == Won) {
        cout << "You won! Yayyy!" << endl;
    } else if (result == Lost) {
        cout << "You Lost! Better luck next time :)" << endl;
    } else if (result == Tie) {
        cout << "It's a tie!" << endl;
    }
    
}

void printOp(Operation op) {
    
    if (op == Rock) {
        cout << "Rock";
    } else if (op == Paper) {
        cout << "Paper";
    } else if (op == Scissor) {
        cout << "Scissor";
    } else if (op == Lizard) {
        cout << "Lizard";
    } else if (op == Spock) {
        cout << "Spock";
    }
    
}

int numUserResults(RoundHistory *history, Result result, int numValues) {
    
    int value = 0;
    
    for (int i = 0; i < numValues; i++) {
        const RoundHistory point = history[i];
        if (point.userResult == result) {
            value++;
        }
    }
    
    return value;
}

double percentage(double valueOne, double valueTwo) {
    
    return valueOne / valueTwo * 100;
}

RoundHistory createHistoryDataPoint(Operation userOp, Operation computerOp, Result res) {
    
    RoundHistory history;
    history.userOperation = userOp;
    history.computerOperation = computerOp;
    history.userResult = res;
    
    return history;
}

RoundHistory * createHistoryArray(RoundHistory *arrayToCopy, RoundHistory dataPoint, int numValues) {
    
    // Creates a new empty array with RoundHistory struct type with the
    // same size as the num values
    RoundHistory *list = new RoundHistory[numValues];
    
    // We first need to copy the old array into the new one so we do
    // not exceed its size and cause a SIGTERM where we access memory
    // which is not ours.
    
    // Our previous array is one shorter than the one we are adding to
    // So we need to make sure not to have an off by one error
    for (int i = 0; i < numValues - 1; i++) {
        // Copy every element in array to copy
        list[i] = arrayToCopy[i];
    }
    
    // Decrease by one as arrays are zero indexed
    // Assing the new data point.
    list[numValues - 1] = dataPoint;
    
    return list;
}
