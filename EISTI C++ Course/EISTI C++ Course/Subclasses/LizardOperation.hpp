//
//  LizardOperation.hpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 08/11/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#ifndef LizardOperation_hpp
#define LizardOperation_hpp

#include <stdio.h>
#include "Operation.hpp"

class LizardOperation: public Operation {
    
    LizardOperation();
    
    virtual void printOperation();
    
    virtual void printShortOperation();
    
    virtual OperationResult result(Operation op);
        
};

#endif /* LizardOperation_hpp */
