//
//  EmployeeBase.cpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 22/12/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#include "EmployeeBase.hpp"
#include <iostream>

EmployeeBase::EmployeeBase() {
    name = "";
    companyId = "";
    netSalary = 0;
}

EmployeeBase::EmployeeBase(string theName, string theCompanyId) {
    name = theName;
    companyId = theCompanyId;
    netSalary = 0;
}

string EmployeeBase::getName() const {
    return name;
}

string EmployeeBase::getCompanyId() const {
    return companyId;
}

double EmployeeBase::getNetSalary() const {
    return netSalary;
}

void EmployeeBase::setName(string theName) {
    name = theName;
}

void EmployeeBase::setCompanyId(string theCompanyId) {
    companyId = theCompanyId;
}

void EmployeeBase::setNetSalary(double theSalary) {
    netSalary = theSalary;
}

void EmployeeBase::printPaycheck() {
    
    cout << "Pay the order for: "<< getName() << " company id: " << getCompanyId() << endl;
    cout << "Salary sum: " << getNetSalary() << "$" << endl;
    
}
