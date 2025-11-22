/**
 * @file Loan.h
 * @brief Loan calculator class for EMI calculations
 * @author Afraz Khan
 * @date November 2025
 */

#ifndef LOAN_H
#define LOAN_H

#include <string>

/**
 * @class Loan
 * @brief A class to represent and calculate loan details
 * 
 * This class handles loan calculations including EMI (Equated Monthly Installment),
 * total payment, and total interest for a given loan amount, interest rate, and tenure.
 */
class Loan {
private:
    long double amount;     ///< Principal loan amount
    long double interest;   ///< Annual interest rate in percentage
    long int tenure;        ///< Loan tenure in months
    long double emi;        ///< Calculated EMI amount
    
public:
    /**
     * @brief Default constructor
     * Initializes all values to zero
     */
    Loan();
    
    /**
     * @brief Parameterized constructor
     * @param amt Loan amount
     * @param rate Annual interest rate (in percentage)
     * @param months Loan tenure in months
     */
    Loan(long double amt, long double rate, long int months);
    
    /**
     * @brief Set the loan amount
     * @param amt Loan amount to set
     */
    void setAmount(long double amt);
    
    /**
     * @brief Set the interest rate
     * @param rate Annual interest rate (in percentage)
     */
    void setInterest(long double rate);
    
    /**
     * @brief Set the loan tenure
     * @param months Loan tenure in months
     */
    void setTenure(long int months);
    
    /**
     * @brief Get the loan amount
     * @return Current loan amount
     */
    long double getAmount();
    
    /**
     * @brief Get the interest rate
     * @return Current annual interest rate
     */
    long double getInterest();
    
    /**
     * @brief Get the loan tenure
     * @return Current tenure in months
     */
    long int getTenure();
    
    /**
     * @brief Get the calculated EMI
     * @return Calculated EMI amount
     */
    long double getEMI();
    
    /**
     * @brief Calculate the EMI using standard formula
     * 
     * Uses the formula: EMI = [P x R x (1+R)^N]/[(1+R)^N-1]
     * where P = principal, R = monthly rate, N = tenure in months
     */
    void calculateEMI();
    
    /**
     * @brief Calculate total payment over loan period
     * @return Total amount to be paid (EMI * tenure)
     */
    long double getTotalPayment();
    
    /**
     * @brief Calculate total interest paid
     * @return Total interest amount (Total Payment - Principal)
     */
    long double getTotalInterest();
    
    /**
     * @brief Display loan details to console
     */
    void displayDetails();
};

#endif
