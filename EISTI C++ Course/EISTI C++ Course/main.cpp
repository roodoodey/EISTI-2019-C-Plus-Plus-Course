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
 An Enumerator which identifies which operation we used.
 */
typedef enum {
    // Rock defaults to value 0
    Rock,
    // Paper defaults to value 1
    Paper,
    // Scissor defaults to value 2, etc.
    Scissor,
    Lizard,
    Spock
} Operation;

/**
 An enumerator which identifies the result of two operations.
 */
typedef enum {
    // Won defaults to 0
    Won,
    // Tie is set to 3
    Tie=3,
    // Lost is set to 4, because Lost is set to 3.
    Lost
} Result;

/**
 A recursive method which asks the user after each round whether they want to play again.
 It returns true if they want to play again and false if they do not. I
 
 It is a recursive method which keeps calling itself until there is a valid input from the user.
 */
bool playAgain();
/**
 Uses cout to print the rules of the game in the console to the user on startup.
 */
void printRules();

/**
 Asks the user which operation they want to use. If they use an unrecognized operation, it will recursively
 ask the user for an input until they give a valid one.
 */
Operation userOperation();

/**
 This method creates a list of all of the operations, and then picks on operation at random
 for the computer which is then returned.
 */
Operation computerOperation();

/**
 This method takes in two operations, and gives back the result based on the first operation.
 It sends the result based on the first operation. So if operation one is a scissor and operation
 two is a rock, the result will be Lost.
 */
Result won(Operation operationOne, Operation operationTwo);

/**
 This method uses cout to print the name of the operatino to the console. So operation
 Rock prints Rock to the console.
 */
void printOp(Operation op);

/**
 This method uses cout to print a message based on the result.
 */
void printResult(Result result);

/**
 Prints the result of the round with the minimal statistics.
 */
void printRoundResult(Result result, Operation userOp, Operation computerOp, int roundResult, int playerWon, int computerWon, int numTies);

/**
 Calculates the percentage of value one divided by value two.
 */
double percentage(double valueOne, double valueTwo);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // Initialize the random generator
    srand(time(NULL));
    
    // We start with round Number One
    int roundNumber = 1;
    
    // Variables for our statistics
    int playerWon = 0;
    int computerWon = 0;
    int numTies = 0;
    
    // print the rules at the beginning
    printRules();
    
    // Runs the do while loop until the player does not want to play anymore
    do {
        
        // Get the user operation from console input
        Operation userOp = userOperation();
        
        // Get the computer operation at random
        Operation computerOp = computerOperation();
        
        // Checks if the user won
        Result userWon = won(userOp, computerOp);
        
        // Increment the statistics based on the result
        if (userWon == Tie) {
            numTies++;
        } else if (userWon == Won) {
            playerWon++;
        } else if (userWon == Lost) {
            computerWon++;
        }
        
        // Added an end line to make the console output clearer
        cout << endl;
        
        // Print the round result, with the statistics to the user.
        printRoundResult(userWon, userOp, computerOp, roundNumber, playerWon, computerWon, numTies);
        
        // Increment the round number at the end.
        roundNumber++;
        
        // We ask the player if he wants to play again or not.
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
