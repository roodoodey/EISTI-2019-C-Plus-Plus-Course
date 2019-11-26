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

// Takes a vector as a parameter by value. When a vector is passed by value all of the elements are copied to a new array which is passed to the function.
void printList(vector<int> vec);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // Creates an instance of a vector list. By default it is created empty and calls the constructor on vector behind the scenes
    vector<int> intList;
    // The statement below is essentially what happens in the statement above behind the scenes. The reason this is possible is because vector has a default empty constructor.
    // If the class did not have a default empty constructor it would fail.
    vector<int> otherList = vector<int>();
    
    // Both list are empty because when they are created they hold no value.
    cout << "the list is initialized empty, so its size is: " << intList.size() << endl;
    
    // We add 7 to the back of the list. The list should contain 7.
    intList.push_back(7);
    // We add 5 to the back of the list. The list should contain 7, 5.
    intList.push_back(5);
    // We add 3 to the back of the list. The list should contain 7, 5, 3.
    intList.push_back(3);
    
    cout << "After initialization" << endl;
    // The list should print 7, 5, 3.
    printList(intList);
    
    // We use the insert method to add an element at a specific index. We use the begin() method of the list to tell it that we want to start at the beginning of the list, that is index 0, and add 1 to the index. So we are inserting the value -10 at index 1 of the list.
    intList.insert(intList.begin() + 1, -10);
    
    cout << "After inster" << endl;
    // Our list should contain 7, -10, 5, 3
    printList(intList);
    
    // The erase method removes an element at a given index. We used the begin() method on the vector to indicate we want to remove the element at index 0. This will remove the value 7 from the list.
    intList.erase(intList.begin());
    
    cout << "After erase" << endl;
    // Our list should contain -10, 5, 3
    printList(intList);
    
    // We add -20 to the back of our list
    // Our list should contain -10, 5, 3, -20
    intList.push_back(-20);
    
    // Removes the values from index [0,2[ where the second value is the upper bound of the range. So in this method we remove values for indexes 0 and 1.
    intList.erase(intList.begin(), intList.begin() + 2);
    
    cout << "after range erase" << endl;
    // Our list should contain 3, -20.
    printList(intList);
    
    
    
    return 0;
}

void printList(vector<int> vec) {
    
    // TUse the size method on the vector list which will send back the size of the array which represents the number of values in the list.
    for (int i = 0; i < vec.size(); i++) {
        
        // We use the [] subscript to print the value.
        cout << "value at index: " << i << " is: " << vec[i] << endl;
        
    }
    
}
