//
//  main.cpp
//  EISTI C++ Course
//
//  Created by Mathieu MBP 13 on 17/10/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#include <iostream>
#include <math.h>
#include "BankAccount.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    BankAccount accountTwo = BankAccount("Default Account", 1000, 200);
    
    accountTwo.output(cout);
    
    accountTwo.update();
    
    accountTwo.output(cout);
    
    return 0;
}
