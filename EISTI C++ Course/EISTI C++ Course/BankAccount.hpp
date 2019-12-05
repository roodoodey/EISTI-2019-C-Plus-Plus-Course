//
//  BankAccount.hpp
//  EISTI C++ Course
//
//  Created by Mathieu Skulason on 05/12/2019.
//  Copyright © 2019 Mathieu MBP 13. All rights reserved.
//

#ifndef BankAccount_hpp
#define BankAccount_hpp

#include <stdio.h>
#include <iostream>
#include <string>

class BankAccount {
    
public:
    
    BankAccount();
    BankAccount(std::string name, long int amount, long int interest);
    
    std::string getName();
    void setName(std::string name);
    
    long int getAmount();
    void setAmount(long int amount);
    
    long int getInterest();
    void setInterest(long int interest);
    
    /**
     Will return the interests for the given year. Will be done with the same decimal context as the amount. That is 1002 = 10.02 euros.
     */
    long int getRate();
    
    /**
     Will use the get rate function to calculate the interest rate and add it to the bank amount.
     */
    void update();
    
    /**
     @description This method will output the name of the bank account and the balance as well as interest rate.
     */
    void output(std::ostream &stream);
    
    /**
    @description Output the percentage by using the static outputEuros method.
    */
    void outputEuros(std::ostream &stream);
    
    /**
     @description Output the percentage by using the static outputPercentage method.
     */
    void outputPercentage(std::ostream &stream);
    
    /**
     @description Takes in an amount of type 1030 which will be pretty printed as 10.30 euros to be more readily readable by the user.
     */
    static void outputEuros(long int amount, std::ostream &stream);
    
    /**
    @description Takes in a percentage of type 1030 which will be pretty printed as 10.30 % to be more readily readable by the user.
    */
    static void outputPercentage(long int percentage, std::ostream &stream);
    
private:
    
    /**
     @description Name of the account;
     */
    std::string name;
    
    /**
     @description 1003 = 10.03 euros
     */
    long int amount;
    
    /**
     @description 123 = 1.23%
     */
    long int interest;
    
};

#endif /* BankAccount_hpp */
