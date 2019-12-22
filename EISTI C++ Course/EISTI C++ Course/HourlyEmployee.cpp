//
//  HourlyEmployee.cpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 22/12/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#include "HourlyEmployee.hpp"
#include <iostream>

HourlyEmployee::HourlyEmployee() : EmployeeBase() {
    updateNetSalary(0, 0);
}

HourlyEmployee::HourlyEmployee(string theName, string theCompanyId, double theHours, double theRate) : EmployeeBase(theName, theCompanyId) {
    setHours(theHours);
    setRate(theRate);
    updateNetSalary(hours, rate);
}

double HourlyEmployee::getRate() const {
    
    return rate;
}

double HourlyEmployee::getHours() const {
    
    return hours;
}

void HourlyEmployee::setRate(double theRate) {
    rate = theRate;
    updateNetSalary(hours, rate);
}

void HourlyEmployee::setHours(double theHours) {
    hours = theHours;
    updateNetSalary(hours, rate);
}

void HourlyEmployee::updateNetSalary(double theHours, double theRate) {
    
    setNetSalary(hours * rate);
    
}

void HourlyEmployee::printPaycheck() {
    
    this->EmployeeBase::printPaycheck();
    cout << "For number of hours: " << getHours() << " at the rate of: " << getRate() << endl;
    
}
