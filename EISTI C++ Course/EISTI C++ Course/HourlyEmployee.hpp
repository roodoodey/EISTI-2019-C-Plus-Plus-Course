//
//  HourlyEmployee.hpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 22/12/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#ifndef HourlyEmployee_hpp
#define HourlyEmployee_hpp

#include <stdio.h>
#include <string>
#include "EmployeeBase.hpp"

class HourlyEmployee: public EmployeeBase {
public:
    HourlyEmployee();
    HourlyEmployee(string theName, string theCompanyId, double theHours, double theRate);
    
    double getRate() const;
    double getHours() const;
    
    void setRate(double theRate);
    void setHours(double theHours);
    // Same method base employee
    void printPaycheck();
    
private:
    
    void updateNetSalary(double theHours, double theRate);
    
    double hours;
    double rate;
    
};

#endif /* HourlyEmployee_hpp */
