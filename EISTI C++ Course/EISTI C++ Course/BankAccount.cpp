//
//  BankAccount.cpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 05/12/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#include "BankAccount.hpp"

BankAccount::BankAccount() {
    amount = 0;
    interest = 125;
}

BankAccount::BankAccount(long int amount, long int interest) {
    this->amount = amount;
    this->interest = interest;
}

long int BankAccount::getAmount() {
    
    return amount;
}

void BankAccount::setAmount(long int am) {
    amount = am;
}

long int BankAccount::getInterest() {
    
    return interest;
}

void BankAccount::setInterest(long int interest) {
    this->interest = interest;
}
