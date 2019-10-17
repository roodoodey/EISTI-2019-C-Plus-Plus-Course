//
//  main.cpp
//  EISTI C++ Course
//
//  Created by Mathieu MBP 13 on 17/10/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 In this program we will look at input and multiway if, else if,
 and else statements. We will simulate a shop where the reducation
 a buyer gets depends on the amount he shops for.
 */


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    // Spending in euros, no cents allowed.
    int spending;
    // The points the user gets based on their spending.
    int pointsGained;
    // The price reducation the user gets
    double reduction;
    
    cin >> spending;
    
    if (spending < 10) {
        // If spending is less than 10 euros the user gets no price reduction.
        
    } else if (spending >= 10 && spending <= 30) {
        // If spending is 10 or more euros but less than or equal to 30 euros
        // the user gets a 10% reduction.
    } else {
        // If the user spends more than 30 euros they get a 20% reduction.
        
    }
    
    cout << "The user spent: " << spending << endl;
    cout << "He got a reduction worth: " << reduction << endl;
    cout << "And gained " << pointsGained << " points" << endl;
    
    return 0;
}
