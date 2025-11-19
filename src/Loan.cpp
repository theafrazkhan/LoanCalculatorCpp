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

Loan::Loan(long double amt, long double rate, long int months) {
    amount = amt;
    interest = rate;
    tenure = months;
    emi = 0;
}

void Loan::setAmount(long double amt) {
    amount = amt;
}

void Loan::setInterest(long double rate) {
    interest = rate;
}

void Loan::setTenure(long int months) {
    tenure = months;
}

long double Loan::getAmount() {
    return amount;
}

long double Loan::getInterest() {
    return interest;
}

long int Loan::getTenure() {
    return tenure;
}

long double Loan::getEMI() {
    return emi;
}

void Loan::calculateEMI() {
    // EMI formula: [P x R x (1+R)^N]/[(1+R)^N-1]
    // where P = principal, R = monthly rate, N = tenure in months
    
    long double monthlyRate = interest / (12.0L * 100.0L);
    long double temp = powl(1.0L + monthlyRate, tenure);
    emi = (amount * monthlyRate * temp) / (temp - 1.0L);
}

long double Loan::getTotalPayment() {
    return emi * tenure;
}

long double Loan::getTotalInterest() {
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
