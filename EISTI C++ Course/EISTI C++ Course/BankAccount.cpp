//
//  BankAccount.cpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 04/12/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#include "BankAccount.hpp"
#include <iostream>
#include <math.h>

using namespace std;

BankAccount::BankAccount() {
    this->amount = 0;
    this->interests = 0;
}

BankAccount::BankAccount(long int amount, int interests) {
    this->amount = amount;
    this->interests = interests;
}

long int BankAccount::getAmount() {
    
    return amount;
}

void BankAccount::setAmount(long int amount) {
    this->amount = amount;
}

int BankAccount::getInterests() {
    
    return interests;
}

void BankAccount::setInterests(int interests) {
    this->interests = interests;
}

double BankAccount::getRate() {
    
    double rate = amount / 100.0 * (double)interests / 100.0;
    return floor(rate);
    
}

void BankAccount::update() {
    
    amount += getRate();
    
}
