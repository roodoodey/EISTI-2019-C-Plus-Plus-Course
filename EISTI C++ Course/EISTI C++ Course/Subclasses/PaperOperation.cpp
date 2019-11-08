//
//  PaperOperation.cpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 08/11/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#include "PaperOperation.hpp"
#include <iostream>

PaperOperation::PaperOperation() {
    
    type = OperationTypePaper;
    
}

void PaperOperation::printOperation() {
    std::cout << "Paper";
}

void PaperOperation::printShortOperation() {
    std::cout << "(p/P)";
}

OperationResult PaperOperation::result(Operation opponentOp) {
    
    OperationType t = opponentOp.getType();
    
    if (t == OperationTypePaper) {
        return OperationResultTie;
    } else if (t == OperationTypeScissors || t == OperationTypeLizard) {
        return OperationResultLost;
    }
    
    return OperationResultWon;
}
