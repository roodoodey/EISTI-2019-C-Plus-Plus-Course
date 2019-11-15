//
//  main.cpp
//  EISTI C++ Course
//
//  Created by Mathieu MBP 13 on 17/10/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//


#include <iostream>
#include <math.h>
#include "stdlib.h"

using namespace std;

class User {
    
public:
        
    virtual string getFullName() { return firstName + lastName; };
    
    void setFirstName(string name);
    void setLastName(string name);
    
private:
    
protected:
    string firstName;
    string lastName;
    string email;
    
};

class Student: public User {
    
    string getFullName() { return firstName + middleName + lastName; };
    
protected:
    string middleName;
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    
    return 0;
}
