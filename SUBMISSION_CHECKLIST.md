# Assignment 2 Submission Checklist

**Student:** Afraz Khan  
**Email:** thebestafraz@gmail.com  
**GitHub:** theafrazkhan

---

## ✅ Completed Tasks

- [x] Cloned repository
- [x] Created dev branch
- [x] Fixed Bug #1: Input Validation
- [x] Fixed Bug #2: Integer Overflow
- [x] Fixed Bug #3: Hardcoded Values
- [x] Added GoogleTest unit tests (6 tests)
- [x] Added Doxygen documentation
- [x] Created comprehensive README
- [x] Generated project report (REPORT.pdf)
- [x] All code compiles successfully
- [x] All tests pass (6/6)

---

## 📂 What to Submit

### Required Files:

1. **REPORT.pdf** - Main project report (246KB)
   - Location: `/home/theafrazkhan/Desktop/ise /legacy-calc-2009/REPORT.pdf`
   - Contains: Bug fixes, code snippets, test results, git history

2. **Source Code** - Either:
   - Option A: Entire repository as ZIP
   - Option B: Link to forked GitHub repository

3. **Screenshots** (already included in REPORT.pdf):
   - Git commit history
   - Test execution output
   - Code examples

---

## 🔄 Optional: Push to GitHub

If you want to create your own GitHub repository:

```bash
# Navigate to project
cd "/home/theafrazkhan/Desktop/ise /legacy-calc-2009"

# Fork the original repository on GitHub first, then:
git remote add origin https://github.com/theafrazkhan/legacy-calc-2009.git

# Push dev branch
git push -u origin dev

# Push main branch (if needed)
git checkout main
git merge dev
git push -u origin main

# Create Pull Request on GitHub
# Go to: https://github.com/theafrazkhan/legacy-calc-2009/pulls
# Click "New Pull Request"
# Select: base: main <- compare: dev
```

---

## 🧪 Quick Test Before Submission

```bash
# Navigate to project
cd "/home/theafrazkhan/Desktop/ise /legacy-calc-2009"

# Clean and rebuild
make -f Makefile.simple clean
make -f Makefile.simple

# Run tests
make -f Makefile.simple test

# Test the calculator
./calc -cp -a 100000 -i 12 -n 360

# Verify documentation
ls docs/html/index.html

# Check git log
git log --oneline --graph
```

---

## 📊 Project Statistics

| Metric | Value |
|--------|-------|
| Total Commits | 10 |
| Source Files | 5 (main.cpp, Loan.h/cpp, Config.h/cpp) |
| Test Files | 1 (test_emi.cpp) |
| Unit Tests | 6 |
| Test Pass Rate | 100% |
| Lines of Code | ~550 |
| Documentation Pages | 30+ HTML pages |
| Report Size | 246KB PDF |

---

## 🎯 Grading Criteria Met

### Bug Fixes (30%)
- ✅ Input validation with config-based limits
- ✅ Overflow protection using long double
- ✅ Externalized hardcoded values to config.txt

### Code Quality (20%)
- ✅ Clean, modular structure
- ✅ Separation of concerns
- ✅ Proper error handling
- ✅ Consistent naming conventions

### Testing (20%)
- ✅ Comprehensive GoogleTest suite
- ✅ Edge cases covered
- ✅ 100% test pass rate
- ✅ Test output documented

### Documentation (20%)
- ✅ Doxygen comments on all classes/methods
- ✅ Generated HTML documentation
- ✅ README with examples
- ✅ Inline code comments

### Version Control (10%)
- ✅ Clear commit messages
- ✅ Atomic commits
- ✅ Logical progression
- ✅ Proper branching strategy

---

## 💡 Tips for Submission

1. **Review REPORT.pdf** - Make sure all sections are complete and readable

2. **Test Everything** - Run the quick test commands above

3. **Check File Sizes** - Ensure REPORT.pdf is reasonable size (current: 246KB)

4. **Verify Commits** - All commits have proper messages and dates

5. **Documentation** - Doxygen docs are generated in `docs/html/`

6. **Clean Build** - No build artifacts in submission (use .gitignore)

---

## 📧 Submission Methods

### Method 1: Email Submission
- Attach REPORT.pdf
- Include link to GitHub repository (if pushed)
- Or attach entire project as ZIP

### Method 2: LMS Upload
- Upload REPORT.pdf to LMS
- Upload source code ZIP (if required)

### Method 3: GitHub Submission
- Fork original repository
- Push your dev branch
- Create Pull Request
- Submit PR link

---

## 🚨 Common Mistakes to Avoid

- ❌ Don't submit build artifacts (*.o, executable files)
- ❌ Don't include node_modules or similar large directories
- ❌ Don't forget to include REPORT.pdf
- ❌ Don't submit without testing first
- ❌ Don't use inappropriate commit messages

---

## ✨ Project Highlights

1. **Clean Architecture** - Modular design with clear separation
2. **Robust Testing** - 6 comprehensive unit tests
3. **Production Ready** - Proper error handling and validation
4. **Well Documented** - Both code and user documentation
5. **Professional Git History** - Clear, logical commit progression

---

## 📞 Contact Information

If you need clarification:
- **Email:** thebestafraz@gmail.com
- **GitHub:** @theafrazkhan

---

**Last Updated:** November 26, 2025  
**Status:** ✅ Ready for Submission
