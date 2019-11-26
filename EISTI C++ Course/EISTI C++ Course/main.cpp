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

/**
 This method takes a vector by references and prints all its values to the console.
 We send the list by reference so that it is not copied to conserve memory and system load.
 */
void printList(vector<int> *vec);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // Creates a vector dynamically. Make sure to delete it at the end.
    // This vector can only contain int data types.
    vector<int> *intList = new vector<int>();
    
    cout << "the list is initialized empty, so its size is: " << intList->size() << endl;
    
    // Uses the pointer to the list to add 7 to back of the list.
    intList->push_back(7);
    // Uses the * operator to change the pointer to a value so we can add a 5 to the back of list using a dot operator which access a function ofthe class.
    (*intList).push_back(5);
    // Uses the pointer to the list to add 3 to the back of the list.
    intList->push_back(3);
    
    cout << "After initialization" << endl;
    // Should print 7, 5, 3.
    printList(intList);
    
    // Inserts the value -10 at index 1
    // We use the insert method on the list to determine an index where to add the number -10 to the list.
    // the begin() method defines the beginning of the list, which by default begins on index 0 and we add 1 to start at the first index.
    intList->insert(intList->begin() + 1, -10);
    
    cout << "After instert" << endl;
    // Should print 7, -10, 5, 3.
    printList(intList);
    
    // Removes the value at index 0
    // The earease method removes an item from a given index, we defined the begin() index which means we removed the element at index 0.
    intList->erase(intList->begin());
    
    cout << "After erase" << endl;
    // Should print -10, 5, 3.
    printList(intList);
    
    // We add -20 at the back of the list
    intList->push_back(-20);
    // The list becomes -10, 5, 3, -20
    
    // Will remove the indexes from [0,2[, where the second is the upper bound value. So it removes index 0 and 1 in this instance.
    intList->erase(intList->begin(), intList->begin() + 2);
    
    cout << "after range erase" << endl;
    // Should print 3, -20.
    printList(intList);
    
    delete intList;
    
    return 0;
}

void printList(vector<int> *vec) {
    
    vector<int> list = *vec;
    
    for (int i = 0; i < list.size(); i++) {
        
        cout << "value at index: " << i << " is: " << list[i] << endl;
        
    }
    
}
