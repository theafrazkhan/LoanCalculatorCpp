#ifndef LOAN_H
#define LOAN_H

#include <string>

class Loan {
private:
    long double amount;
    long double interest;
    long int tenure;  // in months
    long double emi;
    
public:
    Loan();
    Loan(long double amt, long double rate, long int months);
    
    // setters
    void setAmount(long double amt);
    void setInterest(long double rate);
    void setTenure(long int months);
    
    // getters
    long double getAmount();
    long double getInterest();
    long int getTenure();
    long double getEMI();
    
    // calculation
    void calculateEMI();
    long double getTotalPayment();
    long double getTotalInterest();
    void displayDetails();
};

#endif
