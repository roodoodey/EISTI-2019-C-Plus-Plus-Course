//
//  EmployeeBase.hpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 22/12/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#ifndef EmployeeBase_hpp
#define EmployeeBase_hpp

#include <stdio.h>
#include <string>

using namespace std;

class EmployeeBase {
    
public:
    EmployeeBase();
    EmployeeBase(string theName, string theCompanyId);
    
    string getName() const;
    string getCompanyId() const;
    double getNetSalary() const;
    
    void setName(string theName);
    void setCompanyId(string theCompanyId);
    void setNetSalary(double theSalary);
    void printPaycheck();
    
private:
    string name;
    string companyId;
    double netSalary;
};

#endif /* EmployeeBase_hpp */
