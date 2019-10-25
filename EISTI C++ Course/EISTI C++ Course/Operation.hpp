//
//  Operation.hpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 25/10/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#ifndef Operation_hpp
#define Operation_hpp

#include <stdio.h>

typedef enum {
    OperationResultWon,
    OperationResultLost,
    OperationResultTie
} OperationResult;

typedef enum {
    OperationTypeRock,
    OperationTypePaper,
    OperationTypeScissors,
    OperationTypeLizard,
    OperationTypeSpock
} OperationType;

class Operation {
    
public:
    /*
     Checks whether the current operation wins against the passed in operation.
     */
    OperationResult won(Operation op);
    
    /*
     Prints out the name of the current operation on the format: Paper, Rock, etc.
     */
    void outputOperation();
    
    /*
     Prints out the short name of the current operation on the format: p/p for paper, r/R for Rock, etc.
     */
    void outputShortOperation();
    
    /*
     The type of operation whether it is a rock, paper, scissor.
     */
    OperationType type;
    
};

#endif /* Operation_hpp */
