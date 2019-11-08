//
//  LizardOperation.cpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 08/11/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#include "LizardOperation.hpp"
#include <iostream>

LizardOperation::LizardOperation() {
    
    type = OperationTypeLizard;
    
}

void LizardOperation::printOperation() {
    std::cout << "Spock";
}

void LizardOperation::printShortOperation() {
    std::cout << "(sp/SP)";
}

OperationResult LizardOperation::result(Operation opponentOp) {
    
    OperationType t = opponentOp.getType();
    
    if (t == OperationTypeSpock) {
        return OperationResultTie;
    } else if (t == OperationTypePaper || t == OperationTypeLizard) {
        return OperationResultLost;
    }
    
    return OperationResultWon;
}
