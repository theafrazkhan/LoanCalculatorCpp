/**
 * @file main.cpp
 * @brief Main entry point for loan calculator application
 * @author Afraz Khan (23P-3034), Hassan Masood (23P-3010)
 * @date November 2025
 */

#include <iostream>
#include <string>
#include "Loan.h"
#include "Config.h"

using namespace std;

/**
 * @brief Print usage information
 * 
 * Displays command-line usage instructions for the calculator
 */
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

/**
 * @brief Main function
 * @param argc Number of command-line arguments
 * @param argv Array of command-line argument strings
 * @return 0 on success, 1 on error
 */
int main(int argc, char* argv[]) {
    // load config file
    Config config;
    if (!config.loadFromFile("config.txt")) {
        cout << "Warning: Could not load config.txt, using defaults" << endl;
    }
    
    if (argc < 2) {
        printUsage();
        return 1;
    }
    
    long double amount = 0;
    long double interestRate = 0;
    long int tenure = 0;
    bool calcPayment = false;
    
    // parse command line args
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        
        if (arg == "-cp") {
            calcPayment = true;
        }
        else if (arg == "-a" && i + 1 < argc) {
            amount = stold(argv[++i]);
        }
        else if (arg == "-i" && i + 1 < argc) {
            interestRate = stold(argv[++i]);
        }
        else if (arg == "-n" && i + 1 < argc) {
            tenure = stol(argv[++i]);
        }
        else if (arg == "-h" || arg == "--help") {
            printUsage();
            return 0;
        }
    }
    
    if (calcPayment) {
        // add basic validation
        long double minAmt = config.getDouble("MIN_AMOUNT");
        long double maxAmt = config.getDouble("MAX_AMOUNT");
        long double minInt = config.getDouble("MIN_INTEREST");
        long double maxInt = config.getDouble("MAX_INTEREST");
        long int minTen = config.getInt("MIN_TENURE");
        long int maxTen = config.getInt("MAX_TENURE");
        
        // use defaults if config not loaded
        if (minAmt == 0) minAmt = 1000;
        if (maxAmt == 0) maxAmt = 100000000000;
        if (minInt == 0) minInt = 0.01;
        if (maxInt == 0) maxInt = 50.0;
        if (minTen == 0) minTen = 1;
        if (maxTen == 0) maxTen = 600;
        
        if (amount <= 0 || amount < minAmt) {
            cout << "Error: Loan amount must be at least " << minAmt << "!" << endl;
            return 1;
        }
        if (amount > maxAmt) {
            cout << "Error: Loan amount cannot exceed " << maxAmt << "!" << endl;
            return 1;
        }
        if (interestRate < minInt) {
            cout << "Error: Interest rate must be at least " << minInt << "%!" << endl;
            return 1;
        }
        if (interestRate > maxInt) {
            cout << "Error: Interest rate cannot exceed " << maxInt << "%!" << endl;
            return 1;
        }
        if (tenure <= 0 || tenure < minTen) {
            cout << "Error: Tenure must be at least " << minTen << " months!" << endl;
            return 1;
        }
        if (tenure > maxTen) {
            cout << "Error: Tenure cannot exceed " << maxTen << " months!" << endl;
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
