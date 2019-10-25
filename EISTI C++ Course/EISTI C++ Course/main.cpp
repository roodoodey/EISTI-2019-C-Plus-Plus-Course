//
//  main.cpp
//  EISTI C++ Course
//
//  Created by Mathieu MBP 13 on 17/10/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

/*
 In this program we will look at input and multiway if, else if,
 and else statements. We will simulate a shop where the reducation
 a buyer gets depends on the amount he shops for.
 */

void switchValues(int* valueOne, int& valueTwo, int valueThree);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout << "Length of the list: ";
    int length;
    cin >> length;
    
    string *arrayNames = new string[length];
    
    for (int i = 0; i < length; i++) {
        
        string name;
        
        
    }
    
    int valueOne = 0;
    int valueTwo = 0;
    /** 0xFFFFFF */
    int valueThree = 0;
    switchValues(&valueOne, valueTwo, valueThree);
    
    return 0;
}

void calcSquare(int& radius) {
    
    cin >> radius;
    
}

void switchValues(int *valueOne, int& valueTwo, int valueThree) {
    /** 0xklæjalfsæa */
    int tmpValue = *valueOne;
    *valueOne = valueTwo;
    valueTwo = tmpValue;
    
}
