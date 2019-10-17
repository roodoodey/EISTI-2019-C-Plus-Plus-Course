//
//  main.cpp
//  EISTI C++ Course
//
//  Created by Mathieu MBP 13 on 17/10/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;


/**
 Class enumerators are slightly different from normal enumerators.
 They are not integers and can only be compard with Operation enumerators.
 */
enum class Operation {
    Rock,
    Paper,
    Scissor
};

enum class Result {
    Won,
    Tie,
    Lost
};

bool playAgain();
void printRules();
Operation userOperation();
Operation computerOperation();
Result won(Operation operationOne, Operation operationTwo);
void printOp(Operation op);
void printResult(Result result);
void printRoundResult(Result result, Operation userOp, Operation computerOp, int playerWon, int computerWon, int numTies);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int roundNumber = 1;
    
    int playerWon = 0;
    int computerWon = 0;
    int numTies = 0;
    
    // print the rules at the beginning
    printRules();
    
    do {
        
        cout << "Round Number: " << roundNumber << endl;
        
        Operation userOp = userOperation();
        Operation computerOp = computerOperation();
        
        // Checks if the user won
        Result userWon = won(userOp, computerOp);
        if (userWon == Result::Tie) {
            numTies++;
        } else if (userWon == Result::Won) {
            playerWon++;
        } else if (userWon == Result::Lost) {
            computerWon++;
        }
        
        printRoundResult(userWon, userOp, computerOp, playerWon, computerWon, numTies);
        
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
    
    cout << "Choose between Rock (r/R), Paper (p/P) or Scissors (s/S): " << endl;
    
    string stringOperation;
    
    cin >> stringOperation;
    cin.ignore();
    
    if (stringOperation == "r" || stringOperation == "R") {
        
        return Operation::Rock;
    } else if (stringOperation == "p" || stringOperation == "P") {
        
        return Operation::Paper;
    } else if (stringOperation == "s" || stringOperation == "S") {
        
        return Operation::Scissor;
    }
    
    cout << "Illegal input " << stringOperation << " try again." << endl;
    
    return userOperation();
}

Operation computerOperation() {
    
    Operation availableOperations[3] = { Operation::Rock, Operation::Paper, Operation::Scissor };
    
    // Gives a random value from 0 - 2
    int randomIndex = arc4random_uniform(3);
    
    return availableOperations[randomIndex];
    
}

Result won(Operation operationOne, Operation operationTwo) {
    
    if (operationOne == operationTwo) {
        return Result::Tie;
    }
    
    if (operationOne == Operation::Rock) {
        if (operationTwo == Operation::Paper) {
            return Result::Won;
        }
    } else if (operationOne == Operation::Paper) {
        if (operationTwo == Operation::Scissor) {
            return Result::Won;
        }
    } else if (operationOne == Operation::Scissor) {
        if (operationTwo == Operation::Paper) {
            return Result::Won;
        }
    }
    
    // We have exhausted all posibilities so we know we win.
    return Result::Lost;
}

void printRoundResult(Result result, Operation userOp, Operation computerOp, int playerWon, int computerWon, int numTies) {
    
    printOp(userOp);
    cout << " vs. ";
    printOp(computerOp);
    cout << endl << endl;
    
    printResult(result);
    
    // Print stats with other functions.
    
}

void printResult(Result result) {
    
    if (result == Result::Won) {
        cout << "You won! Yayyy!" << endl;
    } else if (result == Result::Lost) {
        cout << "You Lost! Better luck next time :)" << endl;
    } else if (result == Result::Tie) {
        cout << "It's a tie!" << endl;
    }
    
}

void printOp(Operation op) {
    
    if (op == Operation::Rock) {
        cout << "Rock";
    } else if (op == Operation::Paper) {
        cout << "Paper";
    } else if (op == Operation::Scissor) {
        cout << "Scissor";
    }
    
}
