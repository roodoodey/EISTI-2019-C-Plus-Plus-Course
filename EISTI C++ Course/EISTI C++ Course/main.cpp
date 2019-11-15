//
//  main.cpp
//  EISTI C++ Course
//
//  Created by Mathieu MBP 13 on 17/10/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool isPrime(int value);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout << "This program checks whether a given value is a prime number." << endl;
    cout << "Input your number: ";
    
    int number;
    cin >> number;
    
    if (isPrime(number)) {
        cout << "The number " << number << " is a prime number" << endl;
    } else {
        cout << "The number is not a prime number";
    }
    
    
    
    return 0;
}

bool isPrime(int value) {
    
    int minValue = sqrt(value);

    for (int i = 2; i < minValue; i++) {
        // If we find a value which can divide our value
        // we then know it is not a prime number
        if (value % i == 0) {
            return false;
        }
    }
    
    // If no value up to sqrt(value) can divide our number
    // we know that the numbe ris a prime number.
    return true;
}
