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
    
    BankAccount account = BankAccount();
    
    cout << "account balance is " << account.getAmount() << endl;
    
    long int amount;
    int cents;
    double interests;
    
    cout << "Amount: ";
    cin >> amount;
    
    cout << "Cents: ";
    cin >> cents;
    
    cout << "Interests: ";
    cin >> interests;
    
    BankAccount accountTwo = BankAccount(amount, cents, interests);
    cout << "My account is " << accountTwo.getAmount() << endl;
    
    return 0;
}
