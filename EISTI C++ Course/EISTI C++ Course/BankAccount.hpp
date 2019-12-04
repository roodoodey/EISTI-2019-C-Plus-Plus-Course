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
    
    BankAccount(long int amount, int cents, double interests);
    
    long int getAmount();
    void setAmount(long int amount);
    
    int getCents();
    void setCents(int cents);
    
    double getInterests();
    void setInterests(double interests);
    
private:
    
    long int amount;
    int cents;

    double interests;
    
};

#endif /* BankAccount_hpp */
