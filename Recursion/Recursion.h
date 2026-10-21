#pragma once
#include <string>

// Week 5: recursive functions. Free functions, no class.
// Every function has a base case (stop) and a recursive case (call).

// ---- Q1 / Q2: tracing the call stack ----
void countdown(int n);                      // prints Entering / Exiting
void buggyCountdown(int n);                 // Q2: NO base case - crashes!
void fixedCountdown(int n);                 // Q2: 3 2 1

// ---- Q3 / Q4: tail vs non-tail ----
void tailPrint(int n);                      // 3 2 1  (work BEFORE call)
void nonTailPrint(int n);                   // 1 2 3  (work AFTER call)
int  tailSum(int n, int accumulator);       // tailSum(5, 0) = 15
int  nonTailSum(int n);                     // nonTailSum(5) = 15

// ---- Q5: factorial ----
long long factorial(int n);                 // throws std::invalid_argument
long long factorialTail(int n, long long acc);   // factorialTail(4, 1) = 24

// ---- Q6: power ----
double power(double base, int exponent, int& calls);      // linear
double fastPower(double base, int exponent, int& calls);  // squaring

// ---- Q7: indirect (mutual) recursion ----
bool isEven(int n);
bool isOdd(int n);

// ---- Q9: indirect recursion - expression parser ----
void parseExpression(const std::string& expr, int& index);
void parseOperand(const std::string& expr, int& index);

// ---- Q10: tree recursion ----
long long fib(int n, long long& calls);     // naive, counts its calls
long long fibIter(int n);                   // loop version
