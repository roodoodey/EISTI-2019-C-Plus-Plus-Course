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
    name = "Checking Account";
    amount = 0;
    interest = 125;
    type = BankAccountTypeChecking;
}

BankAccount::BankAccount(std::string name, long int amount, long int interest) {
    this->name = name;
    this->amount = amount;
    this->interest = interest;
    this->type = BankAccountTypeChecking;
}

std::string BankAccount::getName() {
    
    return name;
}

void BankAccount::setName(std::string name) {
    this->name = name;
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

BankAccountType BankAccount::getType() {
    
    return type;
}

void BankAccount::setType(BankAccountType accountType) {
    type = accountType;
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

void BankAccount::output(std::ostream &stream) {
    
    stream << "Account name: " << name << " Balance: ";
    outputEuros(stream);
    stream << " Interests: ";
    outputPercentage(stream);
    stream << std::endl;
    
}

void BankAccount::outputEuros(std::ostream &stream) {
    
    BankAccount::outputEuros(amount, stream);
    
}

void BankAccount::outputPercentage(std::ostream &stream) {
    
    BankAccount::outputPercentage(interest, stream);
    
}

void BankAccount::outputEuros(long int amount, std::ostream &stream) {
    
    // The whole numbers in the euro format so this will represent 10 in 1030 value of the amount.
    long int wholeNumbers = floor( (double)amount / 100 );
    // The decimal placing of the amount so this will represent 30 in the 1030 value of the amount.
    int decimal = amount % 100;
    
    stream << wholeNumbers << "." << decimal << " Euros";
    
}

void BankAccount::outputPercentage(long int percentage, std::ostream &stream) {
    
    long int wholePercentage = floor( (double)percentage / 100 );
    int decimal = percentage % 100;
    
    stream << wholePercentage << "." << decimal << " %";
    
}

void BankAccount::outputAccountType(std::ostream &stream) {
    
    if (getType() == BankAccountTypeChecking) {
        stream << "Checking Account";
    } else if (getType() == BankAccountTypeSavings) {
        stream << "Savings Account";
    } else {
        stream << "Unrecognized Account Type";
    }
    
}
