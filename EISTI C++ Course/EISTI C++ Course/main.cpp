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


int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout << "Number of arguments: " << argc << endl;
    
    for (int i = 0; i < argc; i++) {
        const char *value = argv[i];
        cout << "Value at index: " << i << " is: " << value << endl;
    }
    
    return 0;
}
