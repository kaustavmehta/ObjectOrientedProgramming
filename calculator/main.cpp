/*
// MAIN CPP FILE //
Author: Kaustav Mehta
Date: 12 Sept 2023
Simple calculator program for the COMP412 Object Oriented Programming Class. This program accepts a 
character input to determine which math function the user would like to execute. The focus has been on 
using the <cmath> header definition and documentation to write this program as an instance of calling an external
library to perform functions. 

However, if I could improve this program, I would go about it in two ways:
(1) A pure string input where functions are declared in a human-readable way and order execution follows BODMAS. 
eg: 1+2 - log10(2) ^ 4 -> subtract(power(log10(2), 4), add(1,2))

(2) Try out intrinsics and macros that utilize SSE/AVX instructions such as FMA (Fused Multiply Add).
No reason to do this other than pure interest and because I think it is cool and I want to know how to point
the compiler into using a vectorized instruction (if it doesn't auto-optimize on -O2 already). This comes at the
cost of portability, but almost all modern x86 CPUs in the last 20 years have SSE at minimum. However, hypothetically,
if I were to use an AVX2 instruction for a certain math function, how would I enable the core logic to still work
using the bare minimum instruction set? i.e., if AVX2 is found, use explicit instrinsics; if not, use the lowest
instruction set level generic-x86_64_v1 to execute the same function. Would I have to write code to handle this internally,
or would the code just indicate options to the compiler?
*/

#include "calculator.h"

// Main driver code to accept user input for calculator function and passing control to those functions.
int main() {
    // To store choice of user input to the calculator. 
    // Can be expanded to a string for more a more realistic calculator operation.
    char operation;
    double result;
    
    Calculator calc; // Instantiate Calculator object

    std::cout << "Enter an operation (+, -, *, /, %, ^, r, e, l, n, h(help)): ";
    
    std::cin >> operation; // Accept user input

    switch (operation) {
        case '+':
            result = calc.add();
            std::cout << "Result (addition): " << result << std::endl;
            break;
        case '-':
            result = calc.subtract();
            std::cout << "Result (subtraction): " << result << std::endl;
            break;
        case '*':
            result = calc.multiply();
            std::cout << "Result (multiplication): " << result << std::endl;
            break;
        case '/':
            result = calc.divide();
            std::cout << "Result (division): " << result << std::endl;
            break;
        case '%':
            result = calc.modulus();
            std::cout << "Result (modulus): " << result << std::endl;
            break;
        case '^':
            result = calc.square();
            std::cout << "Result (square): " << result << std::endl;
            break;
        case 'r':
            result = calc.sqroot();
            std::cout << "Result (square root): " << result << std::endl;
            break;
        case 'e':
            result = calc.power();
            std::cout << "Result (exponent): " << result << std::endl;
            break;
        case 'l':
            result = calc.logarithm();
            std::cout << "Result (logarithm): " << result << std::endl;
            break;
        case 'n':
            result = calc.natlog();
            std::cout << "Result (natural logarithm): " << result << std::endl;
            break;
        case 'h':
            std::cout << "+ (addition(x, y))" << std::endl;
            std::cout << "- (subtraction(x, y))" << std::endl;
            std::cout << "* (multiplication(x, y))" << std::endl;
            std::cout << "/ (division(x, y))" << std::endl;
            std::cout << "% (modulus(x, y))" << std::endl;
            std::cout << "^ (square(x))" << std::endl;
            std::cout << "r (squareroot(x))" << std::endl;
            std::cout << "e (raise x to the power y)" << std::endl;
            std::cout << "l (log-10(x))" << std::endl;
            std::cout << "n (log-e(x))" << std::endl;
            break;
        default:
            std::cout << "Invalid operation!" << std::endl;
            break;
    }

    return 0;
}