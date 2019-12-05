//
//  BankAccount.cpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 05/12/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#include "BankAccount.hpp"
#include <math.h>

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

long int BankAccount::getRate() {
    // 1000 = 10.00
    // 200 = 2.00 %
    // 10.00 * 2 = 20
    // 1020
    long int rate = floor((double)amount / 100 * (double)interest / 100);
    
    return rate;
}

void BankAccount::update() {
    
    amount += getRate();
    
}
