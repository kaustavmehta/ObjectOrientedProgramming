#include "calculator.h"

#include <iostream>

using namespace std;

int main() {
    char operation;
    double num1, num2;
    double result;
    Calculator calc;

    cout << "Enter an operation (+, -, *, /, %, ^, r, e, l, n): ";
    cin >> operation;

    switch (operation) {
        case '+':
            result = calc.add();
            cout << "Result (addition): " << result << endl;
            break;
        case '-':
            result = calc.subtract();
            cout << "Result (subtraction): " << result << endl;
            break;
        case '*':
            result = calc.multiply();
            cout << "Result (multiplication): " << result << endl;
            break;
        case '/':
            result = calc.divide();
            cout << "Result (division): " << result << endl;
            break;
        case '%':
            result = calc.modulus();
            cout << "Result (modulus): " << result << endl;
            break;
        case '^':
            result = calc.square();
            cout << "Result (square): " << result << endl;
            break;
        case 'r':
            result = calc.sqroot();
            cout << "Result (square root): " << result << endl;
            break;
        case 'e':
            result = calc.power();
            cout << "Result (exponent): " << result << endl;
            break;
        case 'l':
            result = calc.logarithm();
            cout << "Result (logarithm): " << result << endl;
            break;
        case 'n':
            result = calc.natlog();
            cout << "Result (natural logarithm): " << result << endl;
            break;
        default:
            cout << "Invalid operation!" << endl;
            break;
    }

    return 0;
}