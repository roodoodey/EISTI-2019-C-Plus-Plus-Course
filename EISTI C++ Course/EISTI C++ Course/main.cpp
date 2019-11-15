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
    
    //int array[3] = { 1, 2, 3};
    
    int *array;
    cout << "How many items in your list?" << endl;
    
    int arraySize;
    cin >> arraySize;
    
    array = new int[arraySize];
    
    for (int i = 0; i < arraySize; i++) {
        int input;
        cout << "input item at index " << i;
        cin >> input;
        array[i] = input;
    }
    
    delete [] array;
    
    array = new int[arraySize];
    
    
    return 0;
}

void printList(int *array, int size) {
    
    
    
}
