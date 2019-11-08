//
//  SpockOperation.hpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 08/11/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#ifndef SpockOperation_hpp
#define SpockOperation_hpp

#include <stdio.h>
#include "Operation.hpp"

class SpockOperation: public Operation {
    
    SpockOperation();
    
    virtual void printOperation();
    
    virtual void printShortOperation();
    
    virtual OperationResult result(Operation op);
        
};

#endif /* SpockOperation_hpp */
