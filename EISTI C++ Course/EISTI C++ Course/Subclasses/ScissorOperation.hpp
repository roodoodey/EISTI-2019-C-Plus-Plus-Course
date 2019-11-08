//
//  ScissorOperation.hpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 08/11/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#ifndef ScissorOperation_hpp
#define ScissorOperation_hpp

#include <stdio.h>
#include "Operation.hpp"

class ScissorOperation: public Operation {
    
    ScissorOperation();
    
    virtual void printOperation();
    
    virtual void printShortOperation();
    
    virtual OperationResult result(Operation op);
        
};

#endif /* ScissorOperation_hpp */
