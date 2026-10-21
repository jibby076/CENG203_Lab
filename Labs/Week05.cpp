#include "Labs.h"
#include "../Recursion/Recursion.h"
#include "../LinkedList/LinkedList.h"
#include <iostream>
#include <iomanip>                  // setprecision
#include <stdexcept>                // invalid_argument
using namespace std;

void runWeek05()
{
    cout << "--- Week 5: Recursion and Stack Tracing ---" << endl;
    cout << boolalpha;

    // ---------- Q1: countdown trace ----------
    cout << "[Q1]" << endl;
    countdown(3);

    // ---------- Q2: infinite recursion ----------
    // buggyCountdown(3);           // Q2: uncomment, run, comment again
    cout << "[Q2] fixedCountdown: ";
    fixedCountdown(3);
    cout << endl;

    // ---------- Q3: tail vs non-tail print ----------
    cout << "[Q3] tailPrint(3):    ";  tailPrint(3);     cout << endl;
    cout << "[Q3] nonTailPrint(3): ";  nonTailPrint(3);  cout << endl;

    // ---------- Q4: tail vs non-tail sum ----------
    cout << "[Q4] tailSum(5, 0) = " << tailSum(5, 0)
        << "   nonTailSum(5) = " << nonTailSum(5) << endl;

    // ---------- Q5: factorial ----------
    try {
        cout << "[Q5] factorial(5) = " << factorial(5)
            << "   factorial(0) = " << factorial(0) << endl;
        cout << "[Q5] factorial(20) = " << factorial(20) << endl;
        cout << "[Q5] factorialTail(4, 1) = " << factorialTail(4, 1)
            << endl;
        cout << "[Q5] calling factorial(-3) ..." << endl;
        long long bad = factorial(-3);          // throws: next line skipped
        cout << "[Q5] factorial(-3) = " << bad << endl;
    }
    catch (const invalid_argument& e) {
        cout << "[Q5] Error: " << e.what() << endl;
    }

    // ---------- Q6: power ----------
    int calls = 0;
    cout << fixed << setprecision(3);
    cout << "[Q6] power(2, 3) = " << power(2, 3, calls)
        << "   power(2, -3) = " << power(2, -3, calls)
        << "   power(5, 0) = " << power(5, 0, calls) << endl;
    calls = 0;
    cout << "[Q6] power(2, 10) = " << power(2, 10, calls)
        << "  calls = " << calls << endl;
    calls = 0;
    cout << "[Q6] fastPower(2, 10) = " << fastPower(2, 10, calls)
        << "  calls = " << calls << endl;
    calls = 0;
    cout << "[Q6] fastPower(2, 100) calls = ";
    fastPower(2, 100, calls);
    cout << calls << endl;
    cout << defaultfloat;

    // ---------- Q7: isEven / isOdd ----------
    cout << "[Q7] isEven(4) = " << isEven(4)
        << "   isOdd(4) = " << isOdd(4) << endl;
    cout << "[Q7] isEven(7) = " << isEven(7)
        << "   isOdd(-3) = " << isOdd(-3) << endl;

    // ---------- Q8: linked list, recursive ----------
    LinkedList list;
    list.insertAtFront(4);  list.insertAtFront(3);
    list.insertAtFront(2);  list.insertAtFront(1);          // 1 2 3 4
    cout << "[Q8] ";  list.display();
    cout << "[Q8] backward: ";  list.displayBackward();
    list.reverse();
    cout << "[Q8] reversed: ";  list.display();

    // ---------- Q9: expression parser ----------
    string expr = "2+(3*(4+5))";
    int index = 0;
    cout << "[Q9] parsing " << expr << endl;
    parseExpression(expr, index);

    // ---------- Q10: tree recursion ----------
    for (int n : { 5, 10, 20, 25 }) {
        long long fibCalls = 0;
        long long value = fib(n, fibCalls);
        cout << "[Q10] fib(" << n << ") = " << value
            << "  calls = " << fibCalls
            << "  fibIter = " << fibIter(n) << endl;
    }
}
