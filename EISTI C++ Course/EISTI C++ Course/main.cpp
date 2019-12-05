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
    
    BankAccount accountTwo = BankAccount(1000, 200);
    
    cout << "second account: " << accountTwo.getAmount() << " interests: " << accountTwo.getInterest() << endl;
    
    cout << "second account interest rate is: " << accountTwo.getRate() << endl;
    
    accountTwo.update();
    
    cout << "Second account after intest update: " << accountTwo.getAmount() << endl;
    
    return 0;
}
