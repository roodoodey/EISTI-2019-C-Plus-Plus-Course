//
//  BankAccount.cpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 05/12/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#include "BankAccount.hpp"

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
