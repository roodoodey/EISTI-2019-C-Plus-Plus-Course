//
//  RockOperation.cpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 08/11/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#include "RockOperation.hpp"
#include <iostream>

RockOperation::RockOperation() {
    
    type = OperationTypeRock;
    
}

void RockOperation::printOperation() {
    std::cout << "Rock";
}

void RockOperation::printShortOperation() {
    std::cout << "(r/R)";
}

OperationResult RockOperation::result(Operation opponentOp) {
    
    OperationType t = opponentOp.getType();
    
    if (t == OperationTypeRock) {
        return OperationResultTie;
    } else if (t == OperationTypePaper || t == OperationTypePaper) {
        return OperationResultLost;
    }
    
    return OperationResultWon;
}
