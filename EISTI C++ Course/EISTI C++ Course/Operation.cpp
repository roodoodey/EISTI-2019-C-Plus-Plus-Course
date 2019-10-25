//
//  Operation.cpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 25/10/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#include "Operation.hpp"
// Have to include iostream to be able to use cout
#include <iostream>
#include <time.h>

/*
 Static methods
 */

OperationType Operation::operationType(std::string opTypeString) {
    
    if (opTypeString == "r" || opTypeString == "R") {
        return OperationTypeRock;
    } else if (opTypeString == "p" || opTypeString == "P") {
        return OperationTypePaper;
    } else if (opTypeString == "s" || opTypeString == "S") {
        return OperationTypeScissors;
    } else if (opTypeString == "l" || opTypeString == "L") {
        return OperationTypeLizard;
    } else if (opTypeString == "sp" || opTypeString == "Sp" || opTypeString == "SP") {
        return OperationTypeSpock;
    }
    
    return OperationTypeUnknown;
}

OperationType Operation::randOperationType() {
    
    srand( time(NULL) );
    
    OperationType operations[5] = { OperationTypeRock, OperationTypePaper, OperationTypeScissors, OperationTypeLizard, OperationTypeSpock};
    
    int randIndex = rand() % 5;
    
    return operations[randIndex];
    
}

Operation Operation::randOperation() {
    
    return Operation( Operation::randOperationType() );
}

/*
 Constructors
 */

Operation::Operation(std::string opString) {
    this->type = Operation::operationType(opString);
}

Operation::Operation(OperationType type) {
    this->type = type;
}

/*
 Member functions
 */
void Operation::printOperation() {
    
    using namespace std;
    
    if (type == OperationTypeRock) {
        cout << "Rock";
    } else if (type == OperationTypePaper) {
        cout << "Paper";
    } else if (type == OperationTypeScissors) {
        cout << "Scissors";
    } else if (type == OperationTypeLizard) {
        cout << "Lizard";
    } else if (type == OperationTypeSpock) {
        cout << "Spock";
    } else if (type == OperationTypeUnknown) {
        cout << "Unknown";
    }
    
}

void Operation::printShortOperation() {
    
    using namespace std;
    
    if (type == OperationTypeRock) {
        cout << "(r/R)";
    } else if (type == OperationTypePaper) {
        cout << "(p/P))";
    } else if (type == OperationTypeScissors) {
        cout << "(s/S)";
    } else if (type == OperationTypeLizard) {
        cout << "(l/L)";
    } else if (type == OperationTypeSpock) {
        cout << "(sp/Sp/SP)";
    }
    
}

void Operation::printResult(Operation op) {
    
    using namespace std;
    
    OperationResult res = won(op);
    if (res == OperationResultWon) {
        cout << "You won! Yayyy!" << endl;
    } else if (res == OperationResultLost) {
        cout << "You Lost! Better luck next time :)" << endl;
    } else if (res == OperationResultTie) {
        cout << "It's a tie!" << endl;
    }
    
}

OperationResult Operation::won(Operation op) {
    
    if (type == OperationTypeUnknown || op.type == OperationTypeUnknown) {
        // We should thrown an error
        throw std::invalid_argument( "Cannot compare an unkown operation with" );
    }
    
    if (type == op.type) {
        return OperationResultTie;
    }
    
    // Only check which each type oses against.
    if (type == OperationTypeRock) {
        
        if (op.type == OperationTypeSpock || op.type == OperationTypePaper) {
            return OperationResultLost;
        }
        
    } else if (type == OperationTypePaper) {
        
        if (op.type == OperationTypeScissors || op.type == OperationTypeLizard) {
            
            return OperationResultLost;
        }
        
    } else if (type == OperationTypeScissors) {
        
        if (op.type == OperationTypeRock || op.type == OperationTypeSpock) {
            
            return OperationResultLost;
        }
        
    } else if (type == OperationTypeLizard) {
        
        if (op.type == OperationTypeScissors || op.type == OperationTypeRock) {
            
            return OperationResultLost;
        }
        
    } else if (type == OperationTypeSpock) {
        
        if (op.type == OperationTypePaper || op.type == OperationTypeLizard) {
            
            return OperationResultLost;
        }
        
    }
    
    return OperationResultWon;
}
