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

bool playAgain();
void printRules();
Operation userOperation();
Operation computerOperation();
Result won(Operation operationOne, Operation operationTwo);
void printOp(Operation op);
void printResult(Result result);
void printRoundResult(Result result, Operation userOp, Operation computerOp, int roundResult, int playerWon, int computerWon, int numTies);
double percentage(double valueOne, double valueTwo);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // Initialize the random generator
    srand(time(NULL));

    int roundNumber = 1;
    
    int playerWon = 0;
    int computerWon = 0;
    int numTies = 0;
    
    // print the rules at the beginning
    printRules();
    
    do {
        
        Operation userOp = userOperation();
        Operation computerOp = computerOperation();
        
        // Checks if the user won
        Result userWon = won(userOp, computerOp);
        if (userWon == Tie) {
            numTies++;
        } else if (userWon == Won) {
            playerWon++;
        } else if (userWon == Lost) {
            computerWon++;
        }
        
        cout << endl;
        printRoundResult(userWon, userOp, computerOp, roundNumber, playerWon, computerWon, numTies);
        
        roundNumber++;
        
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
    
    Operation availableOperations[3] = { Rock, Paper, Scissor };
    
    // Gives a random value from 0 - 2
    int randomIndex = rand() % 3;
    
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

void printRoundResult(Result result, Operation userOp, Operation computerOp, int roundNumber, int playerWon, int computerWon, int numTies) {
    
    cout << "Round number: " << roundNumber << endl;
    printOp(userOp);
    cout << " vs. ";
    printOp(computerOp);
    cout << ". ";
    printResult(result);
    cout << endl;
    
    // Print stats with other functions.
    cout << "The user win percentage: " << percentage(playerWon, roundNumber) << "%" << endl;
    cout << "The computer win percentage: " << percentage(computerWon, roundNumber) << "%" << endl;
    cout << "Number of ties: " << percentage(numTies, roundNumber) << "%" << endl;
    
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

double percentage(double valueOne, double valueTwo) {
    
    return valueOne / valueTwo * 100;
}
