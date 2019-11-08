//
//  RockOperation.hpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 08/11/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#ifndef RockOperation_hpp
#define RockOperation_hpp

#include <stdio.h>
#include "Operation.hpp"

class RockOperation: public Operation {
    
    RockOperation();
    
    virtual void printOperation();
    
    virtual void printShortOperation();
    
    virtual OperationResult result(Operation op);
        
};

#endif /* RockOperation_hpp */
