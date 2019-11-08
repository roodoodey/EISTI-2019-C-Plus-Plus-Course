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

/*
 In this program we will look at input and multiway if, else if,
 and else statements. We will simulate a shop where the reducation
 a buyer gets depends on the amount he shops for.
 */

void printList(vector<int> vec);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> intList;
    
    cout << "the list is initialized empty, so its size is: " << intList.size() << endl;
    
    intList.push_back(7);
    intList.push_back(5);
    intList.push_back(3);
    
    cout << "After initialization" << endl;
    printList(intList);
    
    // Inserts the value -10 at index 1
    intList.insert(intList.begin() + 1, -10);
    
    cout << "After inster" << endl;
    printList(intList);
    
    // Removes the value at index 0
    intList.erase(intList.begin());
    
    cout << "After erase" << endl;
    printList(intList);
    
    intList.push_back(-20);
    // Will remove the indexes from 0 to 2
    intList.erase(intList.begin(), intList.begin() + 2);
    
    cout << "after range erase" << endl;
    printList(intList);
    
    
    
    return 0;
}

void printList(vector<int> vec) {
    
    for (int i = 0; i < vec.size(); i++) {
        
        cout << "value at index: " << i << " is: " << vec[i] << endl;
        
    }
    
}
