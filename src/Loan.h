#ifndef LOAN_H
#define LOAN_H

#include <string>

class Loan {
private:
    float amount;
    float interest;
    int tenure;  // in months
    float emi;
    
public:
    Loan();
    Loan(float amt, float rate, int months);
    
    // setters
    void setAmount(float amt);
    void setInterest(float rate);
    void setTenure(int months);
    
    // getters
    float getAmount();
    float getInterest();
    int getTenure();
    float getEMI();
    
    // calculation
    void calculateEMI();
    float getTotalPayment();
    float getTotalInterest();
    void displayDetails();
};

#endif
