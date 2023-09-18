/*
// HEADER DEFINITION FILE //
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
#include <stdexcept>
#include <cassert>

// Add two numbers
double Calculator::add(){
    double num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    return num1 + num2;
}

// Subtract two numbers
double Calculator::subtract(){
    double num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    return num1 - num2;
}

// Multiply two numbers
double Calculator::multiply(){
    double num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    return num1 * num2;
}

// Divide two numbers, if second number is not zero.
double Calculator::divide(){
    double num1, num2;

    std::cout << "Enter two numbers (dividend, divisor): ";
    std::cin >> num1 >> num2;

    assert(num2 != 0); // Check for division by zero
    // Catch exception where user enters a zero divisor
    if (num2 == 0){
        throw std::invalid_argument("Division by zero is not allowed!");
    }

    return num1 / num2;
};

// Divide two numbers and return remainder, if second number is not zero.
double Calculator::modulus(){
    double num1, num2;

    std::cout << "Enter two numbers (dividend, divisor): ";
    std::cin >> num1 >> num2;

    assert(num2 != 0); // Check for division by zero
    // Catch exception where user enters a zero divisor
    if (num2 == 0){
        throw std::invalid_argument("Division by zero is not allowed!");
    }

    return fmod(num1, num2);
};

// Square the given number (x^2)
double Calculator::square(){
    double num;
    
    std::cout << "Enter a number: ";
    std::cin >> num;
    
    return num * num;
};

// Given base, exponent, return base^exponent.
double Calculator::power(){
    double num1, num2;
    
    std::cout << "Enter two numbers (base, exponent): ";
    std::cin >> num1 >> num2;

    return pow(num1, num2);
};

// Square root of a given non-negative number.
double Calculator::sqroot(){
    double num;

    std::cout << "Enter a number: ";
    std::cin >> num;
    
    assert(num >= 0); // Check for non-negative input to square root
    // Catch if input number is negative. Throw an exception is true.
    if (num < 0){
        throw std::invalid_argument("Square root of a negative number!");
    }

    return sqrt(num);
};

// Natural log/log-e of a given number.
double Calculator::natlog(){
    double num;

    std::cout << "Enter a number (non-zero and non-negative): ";
    std::cin >> num;
    
    assert(num > 0); // Check for non-zero, non-negative input to logarithm
    // Catch if input number is zero and throw an exception.
    if (num == 0){
        throw std::invalid_argument("Logarithm of zero is not allowed!");
    } 
    // Catch if input number is negative and throw an exception.
    else if (num < 0){
        throw std::invalid_argument("Logarithm of a negative number is not allowed!");
    }

    return log(num);
};

// Log-10 of a given non-negative and non-zero number.
double Calculator::logarithm(){
    double num;

    std::cout << "Enter a number (non-zero and non-negative): ";
    std::cin >> num;
    
    assert(num > 0); // Check for non-zero, non-negative input to logarithm
    // Catch if input number is zero and throw an exception.
    if (num == 0){
        throw std::invalid_argument("Logarithm of zero is not allowed!");
    } 
    // Catch if input number is negative and throw an exception.
    else if (num < 0){
        throw std::invalid_argument("Logarithm of a negative number is not allowed!");
    }

    return log10(num);
};