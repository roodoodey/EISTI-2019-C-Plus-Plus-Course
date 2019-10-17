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

bool hasQuit();

int main(int argc, const char * argv[]) {
    // insert code here...
    // This runs as long as we do not say no to continuing
    while ( hasQuit() == false ) {
        
        cout << "Here we can do some work again and again as long as we want" << endl;
        
    }
    
    return 0;
}

bool hasQuit() {
    
    cout << "Do you want to quit (y/n)? ";
    
    string character;
    cin >> character;
    // What happens if you uncomment this line? Why do we needs this?
    // hint: it has something to do with the newline character.
    // discussion here: https://stackoverflow.com/questions/5877420/c-cin-input-not-working
    cin.ignore();
    
    if (character == "y") {
        
        return true;
    } else if (character == "n") {
        
        return false;
    }
    
    cout << "Illegal input: " << character << endl;
    
    // Illegal input call the same method recursively.
    return hasQuit();
}

