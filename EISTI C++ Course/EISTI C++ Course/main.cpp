//
//  main.cpp
//  EISTI C++ Course
//
//  Created by Mathieu MBP 13 on 17/10/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#include <iostream>
#include <math.h>
#include "EmployeeBase.hpp"
#include "HourlyEmployee.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    EmployeeBase example = EmployeeBase("Julius Cesar", "019493894");
    example.printPaycheck();
    
    HourlyEmployee ender = HourlyEmployee("Andrew Wiggin", "0384958302", 120, 30);
    ender.printPaycheck();
    
    // Ender2
    EmployeeBase ender2 = ender;
    ender2.printPaycheck();
    
    return 0;
}
