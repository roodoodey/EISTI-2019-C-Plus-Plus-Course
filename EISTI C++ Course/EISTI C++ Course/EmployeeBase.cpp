//
//  EmployeeBase.cpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 22/12/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#include "EmployeeBase.hpp"
#include <iostream>

Employee::Employee() {
    name = "";
    companyId = "";
}

Employee::Employee(string theName, string theCompanyId, double theSalary) {
    name = theName;
    companyId = theCompanyId;
    netSalary = theSalary;
}

string Employee::getName() const {
    return name;
}

string Employee::getCompanyId() const {
    return companyId;
}

double Employee::getNetSalary() const {
    return netSalary;
}

void Employee::setName(string theName) {
    name = theName;
}

void Employee::setCompanyId(string theCompanyId) {
    companyId = theCompanyId;
}

void Employee::setNetSalary(double theSalary) {
    netSalary = theSalary;
}

void Employee::printPaycheck() {
    
    cout << "Calling print on an abstract class should never happen." << endl;
    
}
