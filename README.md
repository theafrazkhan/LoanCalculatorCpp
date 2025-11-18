# Legacy Loan Calculator - 2009

A simple C++ loan/EMI calculator for calculating monthly payments, interest, and loan details.

## Project Structure
```
legacy-calc-2009/
├── src/
│   ├── main.cpp       # Main entry point
│   ├── Loan.h         # Loan class header
│   └── Loan.cpp       # Loan class implementation
├── test/
│   └── test_emi.cpp   # Unit tests
├── config.txt         # Configuration file
├── docs/              # Doxygen documentation
├── Makefile.new       # Build configuration
└── README.md          # This file
```

## Building the Project

### Prerequisites
- g++ compiler with C++11 support
- make
- GoogleTest (for running tests)
- Doxygen (for generating documentation)

### Compile
```bash
make -f Makefile.new
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

Example:
```bash
./calc -cp -a 100000 -i 12 -n 360
```

### Options
- `-cp` : Calculate monthly payment (EMI)
- `-a <amount>` : Loan amount
- `-i <rate>` : Annual interest rate (in %)
- `-n <months>` : Loan tenure in months
- `-h, --help` : Display help message

## Running Tests
```bash
make -f Makefile.new test
```

## Generating Documentation
```bash
doxygen Doxyfile
```
Documentation will be generated in the `docs/` directory.

## Author
Afraz Khan

## Assignment
Software Engineering Assignment 2 - Muhammad Umer Haroon
