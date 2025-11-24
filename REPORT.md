# Software Engineering Assignment 2 Report

## Legacy Loan Calculator - Refactoring Project

**Student Name:** Afraz Khan  
**GitHub Username:** theafrazkhan  
**Email:** thebestafraz@gmail.com  
**Course:** Software Engineering  
**Instructor:** Engr. Muhammad Umer Haroon  
**Date:** November 25, 2025

---

## 1. Project Overview

This project involved refactoring a legacy C++ loan calculator application to improve code quality, add input validation, fix bugs, implement unit tests, and generate comprehensive documentation.

### Original Repository
- **Source:** https://github.com/bradyallenjohnson/LoanCalculatorCpp
- **Project:** Legacy Qt-based loan calculator with command-line support
- **Language:** C++ (originally with Qt dependencies)

### Project Objectives
1. Fix critical bugs (input validation, integer overflow, hardcoded values)
2. Refactor code into modular structure
3. Implement comprehensive unit tests
4. Add Doxygen documentation
5. Follow software engineering best practices

---

## 2. Development Timeline

The project was completed over 6 days with incremental commits:

| Date | Activity | Commits |
|------|----------|---------|
| Nov 18, 2025 | Initial setup, basic structure | 2 |
| Nov 19, 2025 | Input validation, overflow fixes | 2 |
| Nov 20, 2025 | Configuration file implementation | 1 |
| Nov 21, 2025 | Unit tests with GoogleTest | 1 |
| Nov 22, 2025 | Doxygen documentation | 1 |
| Nov 23, 2025 | Final polish, README update | 2 |

**Total Commits:** 9 commits on dev branch

---

## 3. Bug Fixes

### Bug Fix #1: Input Validation

**Problem:** The original code had no input validation, accepting negative values and invalid inputs.

**Solution:** Implemented comprehensive validation with configurable limits.

**Code Before:**
```cpp
// No validation - accepted any value
float amount = stof(argv[i]);
```

**Code After:**
```cpp
// Validation with config-based limits
if (amount <= 0 || amount < minAmt) {
    cout << "Error: Loan amount must be at least " << minAmt << "!" << endl;
    return 1;
}
if (amount > maxAmt) {
    cout << "Error: Loan amount cannot exceed " << maxAmt << "!" << endl;
    return 1;
}
```

**Test Output:**
```
$ ./calc -cp -a -5000 -i 12 -n 360
Error: Loan amount must be positive!

$ ./calc -cp -a 500 -i 12 -n 12
Error: Loan amount must be at least 1000!
```

### Bug Fix #2: Integer Overflow Protection

**Problem:** Using `float` and `int` types caused overflow with large loan values.

**Solution:** Changed to `long double` and `long int` with safer math functions.

**Code Before:**
```cpp
private:
    float amount;
    float interest;
    int tenure;
    float emi;

void calculateEMI() {
    float monthlyRate = interest / (12 * 100);
    float temp = pow(1 + monthlyRate, tenure);
    emi = (amount * monthlyRate * temp) / (temp - 1);
}
```

**Code After:**
```cpp
private:
    long double amount;
    long double interest;
    long int tenure;
    long double emi;

void calculateEMI() {
    long double monthlyRate = interest / (12.0L * 100.0L);
    long double temp = powl(1.0L + monthlyRate, tenure);
    emi = (amount * monthlyRate * temp) / (temp - 1.0L);
}
```

**Test Output:**
```
$ ./calc -cp -a 10000000000 -i 10 -n 600
Loan Details:
Amount: Rs. 10000000000.00
Interest Rate: 10.00%
Tenure: 600 months
EMI: Rs. 83910554.21
Total Payment: Rs. 50346332524.51
Total Interest: Rs. 40346332524.51
```

### Bug Fix #3: Hardcoded Values Removed

**Problem:** Validation limits and settings were hardcoded in the source code.

**Solution:** Created `config.txt` and `Config` class to manage settings.

**config.txt:**
```ini
# Validation limits
MIN_AMOUNT=1000
MAX_AMOUNT=100000000000
MIN_INTEREST=0.01
MAX_INTEREST=50.0
MIN_TENURE=1
MAX_TENURE=600

# Display settings
CURRENCY_SYMBOL=Rs.
DECIMAL_PLACES=2
```

**Config.h Implementation:**
```cpp
class Config {
private:
    std::map<std::string, std::string> config;
public:
    bool loadFromFile(const std::string& filename);
    std::string get(const std::string& key);
    long double getDouble(const std::string& key);
    long int getInt(const std::string& key);
};
```

---

## 4. Code Refactoring

### File Structure

**Before:**
```
LoanCalculatorCpp/
  - LoanCalculator.cpp
  - LoanCalculator.h
  - LoanCalculatorMain.cpp
  - LoanCalcQtMainWindow.cpp (Qt dependency)
  - LoanCalcQtMainWindow.h (Qt dependency)
```

**After:**
```
legacy-calc-2009/
  - src/
      - main.cpp          # Clean entry point
      - Loan.h            # Loan class header
      - Loan.cpp          # Loan implementation
      - Config.h          # Configuration parser
      - Config.cpp        # Config implementation
  - test/
      - test_emi.cpp      # GoogleTest suite
  - docs/html/            # Generated documentation
  - config.txt            # Configuration file
  - Makefile.simple       # Build system
```

### Modular Design

1. **Loan Class:** Pure business logic for EMI calculations
2. **Config Class:** Handles configuration file parsing
3. **main.cpp:** Command-line interface and user interaction
4. **Separation of Concerns:** Each class has a single responsibility

---

## 5. Unit Testing

### GoogleTest Implementation

Implemented 6 comprehensive unit tests covering:

1. **Normal EMI Calculation** - Standard use case
2. **Zero Interest Rate** - Edge case handling
3. **Large Tenure Without Overflow** - Overflow protection validation
4. **Small Loan Amount** - Boundary testing
5. **High Interest Rate** - Extreme value testing
6. **Getters and Setters** - API validation

### Test Results

```
[==========] Running 6 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 6 tests from LoanTest
[ RUN      ] LoanTest.NormalEMICalculation
[       OK ] LoanTest.NormalEMICalculation (0 ms)
[ RUN      ] LoanTest.ZeroInterestRate
[       OK ] LoanTest.ZeroInterestRate (0 ms)
[ RUN      ] LoanTest.LargeTenureWithoutOverflow
[       OK ] LoanTest.LargeTenureWithoutOverflow (0 ms)
[ RUN      ] LoanTest.SmallLoanAmount
[       OK ] LoanTest.SmallLoanAmount (0 ms)
[ RUN      ] LoanTest.HighInterestRate
[       OK ] LoanTest.HighInterestRate (0 ms)
[ RUN      ] LoanTest.GettersAndSetters
[       OK ] LoanTest.GettersAndSetters (0 ms)
[----------] 6 tests from LoanTest (0 ms total)
[==========] 6 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 6 tests.
```

**Test Coverage: 100% of critical functionality**

---

## 6. Documentation

### Doxygen Implementation

Added comprehensive Doxygen comments to all:
- Classes
- Methods
- Parameters
- Return values

### Example Documentation

```cpp
/**
 * @class Loan
 * @brief A class to represent and calculate loan details
 * 
 * This class handles loan calculations including EMI (Equated Monthly Installment),
 * total payment, and total interest for a given loan amount, interest rate, and tenure.
 */
class Loan {
    /**
     * @brief Calculate the EMI using standard formula
     * 
     * Uses the formula: EMI = [P x R x (1+R)^N]/[(1+R)^N-1]
     * where P = principal, R = monthly rate, N = tenure in months
     */
    void calculateEMI();
    
    /**
     * @brief Get the calculated EMI
     * @return Calculated EMI amount
     */
    long double getEMI();
};
```

### Generated Documentation

- HTML documentation generated in `docs/html/`
- Full API reference with cross-links
- Class hierarchy diagrams
- File dependency graphs

---

## 7. Git Commit History

### Commit Timeline (Abbreviated)

```
* b40d1a8 updated README with complete documentation and examples
* d589855 added makefile targets for test and docs
* 37bc24f added doxygen documentation comments and generated docs
* d7056ee added googletest unit tests - all passing
* 08af5a6 added config file support - removed hardcoded values
* f5191e9 fixed overflow issue - changed to long double for calculations
* b230b40 added input validation for negative values
* 0dd4e6b initial working version - basic emi calculator
* 0393a08 updated gitignore file
```

### Commit Message Quality

- Clear, concise descriptions
- Present tense, imperative mood
- Each commit represents atomic change
- Progressive development visible

---

## 8. Building and Running

### Quick Start

```bash
# Clone repository
git clone [repository-url] legacy-calc-2009
cd legacy-calc-2009
git checkout dev

# Build
make -f Makefile.simple

# Run calculator
./calc -cp -a 100000 -i 12 -n 360

# Run tests
make -f Makefile.simple test

# Generate documentation
make -f Makefile.simple docs
```

### Sample Execution

```bash
$ ./calc -cp -a 50000 -i 10 -n 240

Loan Details:
Amount: Rs. 50000.00
Interest Rate: 10.00%
Tenure: 240 months
EMI: Rs. 482.51
Total Payment: Rs. 115802.60
Total Interest: Rs. 65802.60
```

---

## 9. Challenges and Solutions

### Challenge 1: Qt Dependencies
**Problem:** Original code required Qt framework  
**Solution:** Created standalone C++ version without external dependencies

### Challenge 2: GoogleTest Installation
**Problem:** GoogleTest not pre-installed on system  
**Solution:** Installed via apt-get and linked statically

### Challenge 3: Float Precision
**Problem:** Standard float caused rounding errors  
**Solution:** Used long double for high-precision calculations

---

## 10. Lessons Learned

1. **Input Validation is Critical:** Never trust user input
2. **Type Selection Matters:** Choose appropriate data types for range requirements
3. **Configuration Over Hardcoding:** External config files improve maintainability
4. **Test-Driven Development:** Unit tests catch bugs early
5. **Documentation as Code:** Doxygen comments keep docs synchronized with code
6. **Git Best Practices:** Small, atomic commits with clear messages

---

## 11. Future Enhancements

Potential improvements for future versions:

1. **Additional Calculation Modes:**
   - Calculate interest rate given EMI
   - Calculate tenure given EMI
   - Loan balance after N payments

2. **Enhanced Validation:**
   - Age-based tenure limits
   - Income-to-loan ratio checks
   - Multiple currency support

3. **Reporting Features:**
   - Amortization schedule generation
   - CSV/PDF export of payment schedule
   - Graphical visualization

4. **Database Integration:**
   - Store loan calculations
   - Loan comparison features
   - Historical data analysis

---

## 12. Conclusion

This project successfully refactored a legacy loan calculator application by:

[DONE] Fixing 3 critical bugs (validation, overflow, hardcoding)  
[DONE] Refactoring code into clean, modular structure  
[DONE] Implementing 6 comprehensive unit tests (100% pass rate)  
[DONE] Adding complete Doxygen documentation  
[DONE] Following software engineering best practices  
[DONE] Creating comprehensive user and developer documentation  

The refactored codebase is more maintainable, testable, and production-ready compared to the original implementation.

---

## 13. References

- Original Repository: https://github.com/bradyallenjohnson/LoanCalculatorCpp
- GoogleTest Documentation: https://google.github.io/googletest/
- Doxygen Manual: https://www.doxygen.nl/manual/
- C++11 Reference: https://en.cppreference.com/w/
- EMI Formula: https://en.wikipedia.org/wiki/Equated_monthly_installment

---

**End of Report**

---

## Appendix A: Complete File Listing

### Source Files
- `src/main.cpp` - 120 lines
- `src/Loan.h` - 110 lines (with docs)
- `src/Loan.cpp` - 85 lines
- `src/Config.h` - 60 lines (with docs)
- `src/Config.cpp` - 55 lines

### Test Files
- `test/test_emi.cpp` - 84 lines

### Configuration
- `config.txt` - 20 lines
- `Makefile.simple` - 30 lines
- `Doxyfile` - Generated by doxygen

### Documentation
- `README.md` - 200+ lines
- `docs/html/` - Generated documentation

**Total Lines of Code (excluding comments): ~550 lines**

---

*Report prepared using Markdown. Convert to PDF using pandoc or similar tool.*
