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

typedef struct {
    Operation userOperation;
    Operation computerOperation;
    Result userResult;
} RoundHistory;

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

/* Copies the vector passed in and prints the round number. This should probably be passed in as a pointer */
void printRoundResult(vector<RoundHistory> vec);

/**
Calculates the percentage of value one divided by value two.
*/
double percentage(double valueOne, double valueTwo);

/**
Creates a new struct with a datapoint that represents a round.
*/
RoundHistory createHistoryDataPoint(Operation userOp, Operation computerOp, Result res);

int numUserResults(vector<RoundHistory> vec, Result result);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // Initialize the random generator
    srand(time(NULL));
    
    // print the rules at the beginning
    printRules();
    
    // When declaring a vector it will use the default initializer for it
    // With an empty list of elements
    
    vector<RoundHistory> history;
    
    do {
        
        // The operation for the user
        Operation userOp = userOperation();
        
        // The operation for the computer chosen at random
        Operation computerOp = computerOperation();
        
        // Gets the result based on the operations.
        Result userWon = won(userOp, computerOp);
        
        // Create a datapoint for the new round
        RoundHistory dataPoint = createHistoryDataPoint(userOp, computerOp, userWon);
        // Adds an element at the end of the list. It handles resizing the array for us.
        // No need to copy it and play with pointers.
        history.push_back(dataPoint);
        
        cout << endl;
        
        // Prints the round result based on the history of the rounds
        printRoundResult(history);
        
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
    
    // If we get an unrecognized input we let the user know.
    cout << "Illegal input " << stringOperation << " try again." << endl;
    
    // We then call the method again until the suer puts in a valid input.
    return userOperation();
}

Operation computerOperation() {
    
    // Creates an array of size 5, with the values Rock, Paper, Scissor, Lizard, Spock as default values.
    // When we have a fixed size we do not need to use the new operator. availableOperations is a pointer
    // even though we do not have the star. All c-style arrays are pointers.
    Operation availableOperations[5] = { Rock, Paper, Scissor, Lizard, Spock };
    
    // Gives a random value from 0 - 4
    int randomIndex = rand() % 5;
    
    // Send back the value at the random index in the availableOperations array.
    return availableOperations[randomIndex];
    
}

Result won(Operation operationOne, Operation operationTwo) {
    
    // If we have the same operation we know it is a tie.
    if (operationOne == operationTwo) {
        return Tie;
    }
    
    // We only check losing cases, if none of those are met
    // We know we have a winning operation so we return
    // the Win enumerator at the end.
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

void printRoundResult(vector<RoundHistory> vec) {
    
    const RoundHistory lastRound = vec[vec.size() - 1];
    
    cout << "Round number: " << vec.size() << endl;
    printOp(lastRound.userOperation);
    cout << " vs. ";
    printOp(lastRound.computerOperation);
    cout << ". ";
    printResult(lastRound.userResult);
    cout << endl;
    
     // We print out the stats based on the history array by comparing with the appropriate results
       
    // Prints out the percentage of rounds won by the user, where the round number represents the number of rounds.
    cout << "The user win percentage: " << percentage(numUserResults(vec, Won), (int)vec.size()) << "%" << endl;
    
    // Prints out the percentage of rounds lost by the user, where the round number represents the number of rounds.
    cout << "The computer win percentage: " << percentage(numUserResults(vec, Lost), (int)vec.size()) << "%" << endl;
    
    // Prints out the percentage of rounds tied by the user, where the round number represents the number of rounds.
    cout << "Number of ties: " << percentage(numUserResults(vec, Tie), (int)vec.size()) << "%" << endl;
    
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

/**
We pass in our history array with a result to compare to and check how many such results we have for the user.
This way we can see how often the user won, lost or was tied to the computer by passing in the appropriate result.
*/
int numUserResults(vector<RoundHistory> vec, Result result) {
    
    // The counter
    int value = 0;
    
    // Loop through the history of made moves
    for (int i = 0; i < vec.size(); i++) {
        const RoundHistory point = vec[i];
        // If the comparison is met we increment the counter
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
    
    // Initializes a struct with default values which can differ between compilers.
    RoundHistory history;
    // You can initialize a history struc with the format below but the variables are declared in the same order as the struct
    // So if the order of the struct changes, then you need to change it in your entire program.
    // RoundHistory otherHistory = { userOp, computerOp, res };
    history.userOperation = userOp;
    history.computerOperation = computerOp;
    history.userResult = res;
    
    return history;
}
