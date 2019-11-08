//
//  ScissorOperation.cpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 08/11/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#include "ScissorOperation.hpp"
#include <iostream>

ScissorOperation::ScissorOperation() {
    
    type = OperationTypeScissors;
    
}

void ScissorOperation::printOperation() {
    std::cout << "Scissor";
}

void ScissorOperation::printShortOperation() {
    std::cout << "(s/S)";
}

OperationResult ScissorOperation::result(Operation opponentOp) {
    
    OperationType t = opponentOp.getType();
    
    if (t == OperationTypeScissors) {
        return OperationResultTie;
    } else if (t == OperationTypeRock || t == OperationTypeSpock) {
        return OperationResultLost;
    }
    
    return OperationResultWon;
}
