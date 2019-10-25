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


void Operation::outputOperation() {
    
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
    }
    
}

void Operation::outputShortOperation() {
    
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

OperationResult Operation::won(Operation op) {
    
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
        
        
        
    } else if (type == OperationTypeLizard) {
        
        
        
    } else if (type == OperationTypeSpock) {
        
        
        
    }
    
    return OperationResultWon;
}
