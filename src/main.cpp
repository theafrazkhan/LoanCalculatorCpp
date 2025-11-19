#include <iostream>
#include <string>
#include "Loan.h"

using namespace std;

void printUsage() {
    cout << "\nLoan/EMI Calculator" << endl;
    cout << "===================" << endl;
    cout << "\nUsage: calc -cp -a <amount> -i <interest> -n <months>" << endl;
    cout << "\nOptions:" << endl;
    cout << "  -cp         Calculate monthly payment (EMI)" << endl;
    cout << "  -a <amount> Loan amount" << endl;
    cout << "  -i <rate>   Interest rate (annual %)" << endl;
    cout << "  -n <months> Loan tenure in months" << endl;
    cout << "\nExample:" << endl;
    cout << "  ./calc -cp -a 100000 -i 12 -n 360" << endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printUsage();
        return 1;
    }
    
    float amount = 0;
    float interestRate = 0;
    int tenure = 0;
    bool calcPayment = false;
    
    // parse command line args
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        
        if (arg == "-cp") {
            calcPayment = true;
        }
        else if (arg == "-a" && i + 1 < argc) {
            amount = stof(argv[++i]);
        }
        else if (arg == "-i" && i + 1 < argc) {
            interestRate = stof(argv[++i]);
        }
        else if (arg == "-n" && i + 1 < argc) {
            tenure = stoi(argv[++i]);
        }
        else if (arg == "-h" || arg == "--help") {
            printUsage();
            return 0;
        }
    }
    
    if (calcPayment) {
        // add basic validation
        if (amount <= 0) {
            cout << "Error: Loan amount must be positive!" << endl;
            return 1;
        }
        if (interestRate < 0) {
            cout << "Error: Interest rate cannot be negative!" << endl;
            return 1;
        }
        if (tenure <= 0) {
            cout << "Error: Tenure must be positive!" << endl;
            return 1;
        }
        
        Loan loan(amount, interestRate, tenure);
        loan.calculateEMI();
        
        cout << "\n";
        loan.displayDetails();
        cout << "\n";
    }
    
    return 0;
}
