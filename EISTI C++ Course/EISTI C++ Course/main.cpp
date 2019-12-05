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

typedef struct {
    long int amount;
    long int interests;
} StructBankAccount;

double calculsInterests(StructBankAccount acc);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    StructBankAccount structAccount;
    structAccount.amount = 0;
    structAccount.interests = 0;
    
    BankAccount account = BankAccount();
    account.setAmount(0);
    account.setInterest(1);
    
    cout << "bank account " << account.getAmount() << " interests: " << account.getInterest() << endl;
    
    return 0;
}

double calculsInterests(StructBankAccount acc) {
    
    return 0;
}
