#include "Loan.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

Loan::Loan() {
    amount = 0;
    interest = 0;
    tenure = 0;
    emi = 0;
}

Loan::Loan(float amt, float rate, int months) {
    amount = amt;
    interest = rate;
    tenure = months;
    emi = 0;
}

void Loan::setAmount(float amt) {
    amount = amt;
}

void Loan::setInterest(float rate) {
    interest = rate;
}

void Loan::setTenure(int months) {
    tenure = months;
}

float Loan::getAmount() {
    return amount;
}

float Loan::getInterest() {
    return interest;
}

int Loan::getTenure() {
    return tenure;
}

float Loan::getEMI() {
    return emi;
}

void Loan::calculateEMI() {
    // EMI formula: [P x R x (1+R)^N]/[(1+R)^N-1]
    // where P = principal, R = monthly rate, N = tenure in months
    
    float monthlyRate = interest / (12 * 100);
    float temp = pow(1 + monthlyRate, tenure);
    emi = (amount * monthlyRate * temp) / (temp - 1);
}

float Loan::getTotalPayment() {
    return emi * tenure;
}

float Loan::getTotalInterest() {
    return (emi * tenure) - amount;
}

void Loan::displayDetails() {
    cout << "Loan Details:" << endl;
    cout << "Amount: Rs. " << fixed << setprecision(2) << amount << endl;
    cout << "Interest Rate: " << interest << "%" << endl;
    cout << "Tenure: " << tenure << " months" << endl;
    cout << "EMI: Rs. " << fixed << setprecision(2) << emi << endl;
    cout << "Total Payment: Rs. " << getTotalPayment() << endl;
    cout << "Total Interest: Rs. " << getTotalInterest() << endl;
}
