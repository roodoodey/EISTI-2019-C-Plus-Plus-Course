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

// We send back the point for the array which we created dynamically.
int *readArray(int arraySize);

// We send the pointer to the array location to the method and its size. We cannot know
// The size of the list as it is a point, therefore we need to pass it size as a parameter as well.
void printArray(int *array, int arraySize);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout << "How many items will be in your list?" << endl;
    
    // Ask the user for the size of the array
    int arraySize;
    cin >> arraySize;
    
    // Creates an array dynamically of size `arraySize` and asks the user to input every single record.
    int *array = readArray( arraySize );
    printArray(array, arraySize);
    
    // Since we allocated the memory dynamically we also need to delete it.
    // And the array will point to nothing.
    delete [] array;
    
    return 0;
}

// We send the pointer to the array location to the method and its size. We cannot know
// The size of the list as it is a point, therefore we need to pass it size as a parameter as well.
void printArray(int *array, int arraySize) {
    
    for (int i = 0; i < arraySize; i++) {
        // Get the value of the list at index i;
        cout << array[i] << ", ";
    }
    
}

// We send back the point for the array which we created dynamically.
int *readArray(int arraySize) {
    
    // Dynamically create a list of size `arraySize` of type int.
    int *array = new int[arraySize];
    
    // Ask the user for the value of every single record of the list and add it to the list.
    for (int i = 0; i < arraySize; i++) {
        int input;
        cout << "input item at index " << i;
        cin >> input;
        array[i] = input;
    }
    
    // Send back the pointer to the array location.
    return array;
}
