//
//  BankAccount.hpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 05/12/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#ifndef BankAccount_hpp
#define BankAccount_hpp

#include <stdio.h>

class BankAccount {
    
public:
    
    BankAccount();
    BankAccount(long int amount, long int interest);
    
    long int getAmount();
    void setAmount(long int amount);
    
    long int getInterest();
    void setInterest(long int interest);
    
    /**
     Will return the interests for the given year. Will be done with the same decimal context as the amount. That is 1002 = 10.02 euros.
     */
    long int getRate();
    
    /**
     Will use the get rate function to calculate the interest rate and add it to the bank amount.
     */
    void update();
    
private:
    
    /**
     @description 1003 = 10.03 euros
     */
    long int amount;
    
    /**
     @description 123 = 1.23%
     */
    long int interest;
    
};

#endif /* BankAccount_hpp */
