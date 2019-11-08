//
//  PaperOperation.hpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 08/11/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#ifndef PaperOperation_hpp
#define PaperOperation_hpp

#include <stdio.h>
#include "Operation.hpp"

class PaperOperation: public Operation {
    
    PaperOperation();
    
    virtual void printOperation();
    
    virtual void printShortOperation();
    
    virtual OperationResult result(Operation op);
        
};

#endif /* PaperOperation_hpp */
