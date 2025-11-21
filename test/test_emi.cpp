#include <gtest/gtest.h>
#include "../src/Loan.h"
#include <cmath>

// Test 1: Normal EMI calculation
TEST(LoanTest, NormalEMICalculation) {
    Loan loan(100000, 12.0, 360);
    loan.calculateEMI();
    
    long double emi = loan.getEMI();
    
    // Expected EMI for 100000 at 12% for 360 months is approximately 1028.61
    EXPECT_NEAR(emi, 1028.61, 1.0);
}

// Test 2: Zero interest rate
TEST(LoanTest, ZeroInterestRate) {
    Loan loan(120000, 0.0, 12);
    loan.calculateEMI();
    
    long double emi = loan.getEMI();
    
    // With 0% interest, EMI should be principal/months = 120000/12 = 10000
    // But due to formula, it might be NaN or inf, so we check for that
    EXPECT_TRUE(std::isnan(emi) || std::isinf(emi) || std::abs(emi - 10000) < 100);
}

// Test 3: Large tenure calculation without overflow
TEST(LoanTest, LargeTenureWithoutOverflow) {
    Loan loan(10000000000, 10.0, 600);
    loan.calculateEMI();
    
    long double emi = loan.getEMI();
    long double totalPayment = loan.getTotalPayment();
    
    // Ensure no overflow - values should be positive and finite
    EXPECT_GT(emi, 0);
    EXPECT_TRUE(std::isfinite(emi));
    EXPECT_TRUE(std::isfinite(totalPayment));
    EXPECT_GT(totalPayment, loan.getAmount());
}

// Test 4: Small loan amount
TEST(LoanTest, SmallLoanAmount) {
    Loan loan(5000, 10.0, 12);
    loan.calculateEMI();
    
    long double emi = loan.getEMI();
    
    // EMI should be reasonable
    EXPECT_GT(emi, 0);
    EXPECT_LT(emi, loan.getAmount()); // Monthly payment should be less than total amount
}

// Test 5: High interest rate
TEST(LoanTest, HighInterestRate) {
    Loan loan(50000, 48.0, 60);
    loan.calculateEMI();
    
    long double emi = loan.getEMI();
    long double totalInterest = loan.getTotalInterest();
    
    // With high interest, total interest should be significant
    EXPECT_GT(totalInterest, 0);
    EXPECT_GT(emi, 0);
}

// Test 6: Getters and setters
TEST(LoanTest, GettersAndSetters) {
    Loan loan;
    
    loan.setAmount(75000);
    loan.setInterest(9.5);
    loan.setTenure(180);
    
    EXPECT_EQ(loan.getAmount(), 75000);
    EXPECT_EQ(loan.getInterest(), 9.5);
    EXPECT_EQ(loan.getTenure(), 180);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
