#include "Recursion.h"
#include <iostream>
#include <stdexcept>                // std::invalid_argument
using namespace std;

// ============================ Q1 / Q2 ============================
void countdown(int n)
{
    cout << "Entering countdown(" << n << "), stack level " << n << endl;
    if (n <= 0) {
        cout << "Base case reached!" << endl;
        return;                     // base case: no further call
    }
    cout << n << " ";               // work BEFORE the recursive call
    countdown(n - 1);               // recursive call: one level deeper
    cout << "Exiting countdown(" << n << ")" << endl;   // work AFTER
}

void buggyCountdown(int n)
{
    cout << n << " ";
    buggyCountdown(n - 1);          // no base case: never stops
}

void fixedCountdown(int n)
{
    if (n <= 0)                     // base case
        return;
    cout << n << " ";
    fixedCountdown(n - 1);
}

// ============================ Q3 / Q4 ============================
void tailPrint(int n)
{
    if (n <= 0)
        return;
    cout << n << " ";               // print first ...
    tailPrint(n - 1);               // ... the call is the LAST action
}

void nonTailPrint(int n)
{
    if (n <= 0)
        return;
    nonTailPrint(n - 1);            // call first ...
    cout << n << " ";               // ... printing waits on the stack
}

int tailSum(int n, int accumulator)
{
    if (n == 0)
        return accumulator;         // the answer is already complete
    return tailSum(n - 1, accumulator + n);   // nothing pending
}

int nonTailSum(int n)
{
    if (n == 0)
        return 0;
    return n + nonTailSum(n - 1);   // the "+ n" waits for the result
}

// ============================ Q5 ============================
long long factorial(int n)
{
    if (n < 0)
        throw invalid_argument("Factorial of negative number is undefined");
    if (n == 0 || n == 1)
        return 1;                   // base case
    return n * factorial(n - 1);    // pending multiplication
}

long long factorialTail(int n, long long acc)
{
    if (n <= 1)
        return acc;
    return factorialTail(n - 1, n * acc);
}

// ============================ Q6 ============================
double power(double base, int exponent, int& calls)
{
    calls++;
    if (exponent == 0) return 1;                            // base case 1
    if (exponent == 1) return base;                         // base case 2
    if (exponent < 0) return 1 / power(base, -exponent, calls);
    return base * power(base, exponent - 1, calls);         // one less
}

double fastPower(double base, int exponent, int& calls)
{
    calls++;
    if (exponent == 0) return 1;
    if (exponent < 0) return 1 / fastPower(base, -exponent, calls);
    double half = fastPower(base, exponent / 2, calls);     // halve it
    if (exponent % 2 == 0)
        return half * half;
    return half * half * base;                              // odd: x base
}

// ============================ Q7 ============================
bool isEven(int n)
{
    if (n < 0) n = -n;
    if (n == 0) return true;        // base case
    return isOdd(n - 1);            // calls the OTHER function
}

bool isOdd(int n)
{
    if (n < 0) n = -n;
    if (n == 0) return false;       // base case
    return isEven(n - 1);
}

// ============================ Q9 ============================
void parseExpression(const string& expr, int& index)
{
    cout << "Entering parseExpression at index " << index << endl;
    while (index < (int)expr.length() && expr[index] != ')') {
        if (isdigit(expr[index])) {
            parseOperand(expr, index);
        }
        else if (expr[index] == '+' || expr[index] == '*' ||
            expr[index] == '-') {
            cout << "Operator: " << expr[index] << endl;
            index++;
        }
        else if (expr[index] == '(') {
            parseOperand(expr, index);          // indirect recursion
        }
        else {
            index++;                            // skip spaces etc.
        }
    }
    if (index < (int)expr.length() && expr[index] == ')') {
        cout << "Closing parenthesis at index " << index << endl;
        index++;                                // move past ')'
    }
    cout << "Exiting parseExpression at index " << index << endl;
}

void parseOperand(const string& expr, int& index)
{
    if (isdigit(expr[index])) {
        cout << "Operand: " << expr[index] << endl;
        index++;
    }
    else if (expr[index] == '(') {
        cout << "Opening parenthesis at index " << index << endl;
        index++;                                // skip '('
        parseExpression(expr, index);           // indirect recursion
    }
}

// ============================ Q10 ============================
long long fib(int n, long long& calls)
{
    calls++;
    if (n <= 1)
        return n;                   // fib(0) = 0, fib(1) = 1
    return fib(n - 1, calls) + fib(n - 2, calls);   // TWO calls: tree
}

long long fibIter(int n)
{
    long long a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        long long next = a + b;
        a = b;
        b = next;
    }
    return a;
}
