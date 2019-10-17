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
    
    // Spending in euros, no cents allowed.
    double spending;
    // The points the user gets based on their spending. They get 1 point for each
    // euro they spend.
    int pointsGained = 0;
    // The price reducation the user gets
    double reduction;
    
    // To make the outpout show a dot and 2 fractional characters
    // for doubles
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(2);
    
    cout << "Input how much you are willing to spend: ";
    
    cin >> spending;
    
    if (spending < 10) {
        // If spending is less than 10 euros the user gets no price reduction.
        // We need to set the reduction variable to 0 so it has some value.
        reduction = 0;
    } else if (spending >= 10 && spending <= 30) {
        // If spending is 10 or more euros but less than or equal to 30 euros
        // the user gets a 10% reduction.
        reduction = spending * 0.1;
    } else {
        // If the user spends more than 30 euros they get a 20% reduction.
        reduction = spending * 0.2;
    }
    
    // By default int is rounded so we need to use a floor method to calculate the
    // number of points the user gained
    pointsGained += floor(spending);
    
    
    cout << "The user spent: " << spending << endl;
    cout << "He got a reduction worth: " << reduction << endl;
    cout << "The user paid: " << spending - reduction << endl;
    cout << "And gained " << pointsGained << " points" << endl;
    
    return 0;
}
