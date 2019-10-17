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
 and else statements with an external function which will give a grade
 based on the input value. We will then use the grade to print out different
 information based on the grade of the student with a switch statement.
 */


/***********************************
 *********** ENUMERATORS ***********
 ***********************************/

/**
 An enum is a type which holds values of type int
 in a human readable manner. In this case A=0, B=1
 etc. We can initialize A=10, and then B=11. If we
 initialize A=10, B=1, then C=2 automatically if
 we do not provide a value.
 */
enum Grade {
    A,
    B,
    C,
    D,
    F
};

/*********************************
 *********** FUNCTIONS ***********
**********************************/

/*
 Function declaration so the compiler knows this function exists.
 This function takes the first parameter points which indicates the points
 the user scored on the exam. The total points is the number of points available
 in total in the exam. Based on this we will return a Grade enumeration object
 on the scale of A-F.
 */
Grade grade(int points, int totalPoints);

/*
 Calculates the percentatge score based on the points of the student scored divided
 by the total points on the exam, multiplied by a hundred to give us a percentage but
 not a fraction.
 */
double percentage(int points, int totalPoints);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int studentPoints;
    int totalExamPoints;
    
    // To make the outpout show a dot and 2 fractional characters
    // for doubles
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(2);
    
    cout << "Student points: ";
    cin >> studentPoints;
    
    cout << "Total points available on exam: ";
    cin >> totalExamPoints;
    
    // Add a check here if the total exam points are zero.
    // As we cannot divide by zero.
    
    Grade studentGrade = grade(studentPoints, totalExamPoints);
    cout << "What is the enum value: " << studentGrade << endl;
    
    // Print different information depending on the grade of the statement
    // Switch only works with integer types and enums.
    switch (studentGrade) {
        case Grade::A:
            
            cout << "You are a great student! You got an A on the exam" << endl;
            
            // If there is no break statement which stops the current control flow
            // then it will keep outputting the statements in the next cases.
            break;
            
        case Grade::B:
            
            cout << "You are a good student! You got a B on the exam" << endl;
            
            break;
            
        case Grade::C:
            
            cout << "You can do better... You got a C on the exam" << endl;
            
            break;
            
        case Grade::D:
            
            cout << "You are not in the worst bracket... but not far." << endl;
            
        case Grade::F:
            
            cout << "You need help! ASAP." << endl;
            
            break;
            
        default:
            // Runs if it does not find any other case above.
            break;
    }
    
    cout << "Your grade was: " << grade(studentPoints, totalExamPoints) << endl;
    cout << "Your exam score was: " << studentPoints;
    cout << " for a total of: " << totalExamPoints << endl;
    
    cout << "Which makes your percentage " << percentage(studentPoints, totalExamPoints) << "%" << endl;
    
    return 0;
}

Grade grade(int points, int totalPoints) {
    
    double gradePerc = percentage(points, totalPoints);

    if (gradePerc >= 90) {
        
        return Grade::A;
    } else if (gradePerc >= 80 && gradePerc < 90) {
        
        return Grade::B;
    } else if (gradePerc >= 70 && gradePerc < 80) {
        
        return Grade::C;
    } else if (gradePerc >= 60 && gradePerc < 70) {
        
        return Grade::D;
    } else {
        
        return Grade::F;
    }
    
    // This should never execute as our control statement above ends with an else statement
    // which is run if none of the other conditions are true.
}

double percentage(int points, int totalPoints) {
    
    // Calculates the percentage score on the exam.
    double perc = (double)points / (double)totalPoints * 100;
    
    // Try removing the casting from the points. See what happens.
    // Do you know why this occurs?
    
    return perc;
}
