//
//  SpockOperation.cpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 08/11/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#include "SpockOperation.hpp"
#include <iostream>

SpockOperation::SpockOperation() {
    
    type = OperationTypeSpock;
    
}

void SpockOperation::printOperation() {
    std::cout << "Spock";
}

void SpockOperation::printShortOperation() {
    std::cout << "(sp/SP)";
}

OperationResult SpockOperation::result(Operation opponentOp) {
    
    OperationType t = opponentOp.getType();
    
    if (t == OperationTypeSpock) {
        return OperationResultTie;
    } else if (t == OperationTypePaper || t == OperationTypeLizard) {
        return OperationResultLost;
    }
    
    return OperationResultWon;
}
