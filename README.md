# Legacy Loan Calculator - 2009

A refactored C++ loan/EMI calculator with input validation, overflow protection, and comprehensive testing.

## Features

- ✅ EMI (Equated Monthly Installment) calculation
- ✅ Input validation for all parameters
- ✅ Overflow protection using `long double`
- ✅ Configuration file support
- ✅ Comprehensive unit tests with GoogleTest
- ✅ Full Doxygen documentation

## Project Structure
```
legacy-calc-2009/
├── src/
│   ├── main.cpp       # Main entry point
│   ├── Loan.h         # Loan class header
│   ├── Loan.cpp       # Loan class implementation
│   ├── Config.h       # Configuration parser header
│   └── Config.cpp     # Configuration parser implementation
├── test/
│   └── test_emi.cpp   # Unit tests (GoogleTest)
├── docs/
│   └── html/          # Generated Doxygen documentation
├── config.txt         # Configuration file
├── Makefile.simple    # Build configuration
├── Doxyfile           # Doxygen configuration
└── README.md          # This file
```

## Building the Project

### Prerequisites
- g++ compiler with C++11 support
- make
- GoogleTest (for running tests)
- Doxygen (for generating documentation)

### Install Dependencies (Ubuntu/Debian)
```bash
sudo apt-get update
sudo apt-get install g++ make libgtest-dev doxygen
```

### Compile
```bash
make -f Makefile.simple
```

### Run
```bash
./calc -cp -a 100000 -i 12 -n 360
```

## Usage

### Calculate EMI (Monthly Payment)
```bash
./calc -cp -a <amount> -i <interest_rate> -n <tenure_months>
```

### Examples
```bash
# Calculate EMI for 100,000 at 12% for 30 years (360 months)
./calc -cp -a 100000 -i 12 -n 360

# Calculate EMI for 50,000 at 10% for 5 years (60 months)
./calc -cp -a 50000 -i 10 -n 60

# Get help
./calc -h
```

### Command-line Options
- `-cp` : Calculate monthly payment (EMI)
- `-a <amount>` : Loan amount (must be >= 1000)
- `-i <rate>` : Annual interest rate in % (0.01 - 50.0)
- `-n <months>` : Loan tenure in months (1 - 600)
- `-h, --help` : Display help message

## Configuration File

The `config.txt` file contains validation limits and default values:

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

## Running Tests

All unit tests use GoogleTest framework:

```bash
make -f Makefile.simple test
```

### Test Coverage
- Normal EMI calculation
- Edge cases (zero interest, small amounts)
- Large values without overflow
- High interest rates
- Getters and setters validation

## Generating Documentation

Generate HTML documentation using Doxygen:

```bash
make -f Makefile.simple docs
```

Documentation will be available at `docs/html/index.html`

## Bug Fixes

### 1. Input Validation ✅
- Added validation for negative values
- Implemented min/max limits from config file
- Proper error messages for invalid inputs

### 2. Integer Overflow Protection ✅
- Changed from `float` and `int` to `long double` and `long int`
- Used `powl()` for high-precision calculations
- Tested with very large values (10 billion+)

### 3. Removed Hardcoded Values ✅
- Created `config.txt` for configuration
- Implemented `Config` class to read settings
- All validation limits now configurable

## Development Timeline

- **Nov 18, 2025**: Initial setup and structure
- **Nov 19, 2025**: Input validation and overflow fixes
- **Nov 20, 2025**: Configuration file support
- **Nov 21, 2025**: Unit tests with GoogleTest
- **Nov 22, 2025**: Doxygen documentation
- **Nov 23, 2025**: Final polish and cleanup

## Author
**Afraz Khan**  
GitHub: [@theafrazkhan](https://github.com/theafrazkhan)

## Assignment
Software Engineering Assignment 2  
Instructor: Engr. Muhammad Umer Haroon  
Date: November 2025

## License
Educational use only - Software Engineering Course Project
