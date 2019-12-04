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
    
    long int amount;
    int interests;
    
    cout << "Amount: ";
    cin >> amount;
    
    cout << "Interests: ";
    cin >> interests;
    
    BankAccount accountTwo = BankAccount(amount, interests);
    cout << "My account is " << accountTwo.getAmount() << endl;
    
    cout << "Our rate is: " << accountTwo.getRate() << endl;
    accountTwo.update();
    cout << "Our account amount is " << accountTwo.getAmount() << endl;
    
    return 0;
}
