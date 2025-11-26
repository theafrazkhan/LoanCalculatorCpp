/**
 * @file main.cpp
 * @brief Main entry point for loan calculator application
 * @author Afraz Khan (23P-3034), Hassan Masood (23P-3010)
 * @date November 2025
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include "Loan.h"

using namespace std;

/**
 * @brief Load configuration from file
 * @param filename Path to configuration file
 * @return Map of key-value pairs from config file
 */
map<string, string> loadConfig(const string& filename) {
    map<string, string> config;
    ifstream file(filename);
    string line;
    
    if (!file.is_open()) {
        return config; // return empty map if file cannot be opened
    }
    
    while (getline(file, line)) {
        // skip empty lines and comments
        if (line.empty() || line[0] == '#') {
            continue;
        }
        
        // parse key=value
        size_t pos = line.find('=');
        if (pos != string::npos) {
            string key = line.substr(0, pos);
            string value = line.substr(pos + 1);
            config[key] = value;
        }
    }
    
    file.close();
    return config;
}

/**
 * @brief Get double value from config map
 * @param config Configuration map
 * @param key Configuration key
 * @param defaultValue Default value if key not found
 * @return Configuration value as long double
 */
long double getConfigDouble(const map<string, string>& config, const string& key, long double defaultValue) {
    auto it = config.find(key);
    if (it != config.end()) {
        return stold(it->second);
    }
    return defaultValue;
}

/**
 * @brief Get integer value from config map
 * @param config Configuration map
 * @param key Configuration key
 * @param defaultValue Default value if key not found
 * @return Configuration value as long int
 */
long int getConfigInt(const map<string, string>& config, const string& key, long int defaultValue) {
    auto it = config.find(key);
    if (it != config.end()) {
        return stol(it->second);
    }
    return defaultValue;
}

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
    // load configuration from file
    map<string, string> config = loadConfig("config.txt");
    if (config.empty()) {
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
        // load validation limits from config file
        long double minAmt = getConfigDouble(config, "MIN_AMOUNT", 1000);
        long double maxAmt = getConfigDouble(config, "MAX_AMOUNT", 100000000000);
        long double minInt = getConfigDouble(config, "MIN_INTEREST", 0.01);
        long double maxInt = getConfigDouble(config, "MAX_INTEREST", 50.0);
        long int minTen = getConfigInt(config, "MIN_TENURE", 1);
        long int maxTen = getConfigInt(config, "MAX_TENURE", 600);
        
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
