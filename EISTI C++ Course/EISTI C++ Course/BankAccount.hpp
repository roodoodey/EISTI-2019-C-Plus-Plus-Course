//
//  BankAccount.hpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 04/12/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#ifndef BankAccount_hpp
#define BankAccount_hpp

#include <stdio.h>
using namespace std;

class BankAccount {
    
public:
    
    /* Constructor **/
    BankAccount();
    
    BankAccount(long int amount, int interests);
    
    long int getAmount();
    void setAmount(long int amount);
    
    int getInterests();
    void setInterests(int interests);
    
private:
    
    /**
     @description The amount will be defined as a whole and cents will be represented as
     The first two placeholders. So a value of 1003 = 10.03 euros. 
     */
    long int amount;

    /**
     @description The interests will be defined as a percentage where 103, will be 1.03 percent
     interest rate.
     */
    int interests;
    
};

#endif /* BankAccount_hpp */
