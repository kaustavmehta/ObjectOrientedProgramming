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
#include <typeinfo>
#include <string>

// Pass an input to check if it is a double through an attempted runtime-type conversion
bool Calculator::check(std::string var){
    
    double try_num;
    
    try {
        try_num = std::stod(var); // Convert var to a double
    } 
    // Check for immediately invalid inputs
    catch(const std::invalid_argument& e){
        std::cerr << "Error: Please enter valid number(s)!" << std::endl;
        return 1;
    } 
    // Check if input is within range of single-precision values
    catch(const std::out_of_range& e){
        std::cerr << "Error: Input is out of range for doubles!" << std::endl;
        return 1;
    }
    
    assert(typeid(try_num) == typeid(double)); // If we make it this far, we do a final type check

    return 0;

}

// Add two numbers
double Calculator::add(){
    std::string num1, num2;
    
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    
    assert(check(num1) == 0); // Assert that input is a double
    assert(check(num2) == 0); // Assert that input is a double
    
    return std::stod(num1) + std::stod(num2); // Convert string to double and return result
}

// Subtract two numbers
double Calculator::subtract(){
    std::string num1, num2;
    
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    
    assert(check(num1) == 0); // Assert that input is a double
    assert(check(num2) == 0); // Assert that input is a double

    return std::stod(num1) - std::stod(num2); // Convert string to double and return result
}

// Multiply two numbers
double Calculator::multiply(){
    std::string num1, num2;

    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    
    assert(check(num1) == 0); // Assert that input is a double 
    assert(check(num2) == 0); // Assert that input is a double

    return std::stod(num1) * std::stod(num2);
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

    return num1 / num2; // Convert string to double and return result
};

// Divide two numbers and return remainder, if second number is not zero.
double Calculator::modulus(){
    std::string num1, num2;

    std::cout << "Enter two numbers (dividend, divisor): ";
    std::cin >> num1 >> num2;

    assert(check(num1) == 0); // Assert that input is a double
    assert(check(num2) == 0); // Assert that input is a double

    // Catch exception where user enters a zero divisor
    if (std::stod(num2) == 0){
        throw std::invalid_argument("Division by zero is not allowed!");
    }

    return fmod(std::stod(num1), std::stod(num2)); // Convert string to double
};

// Square the given number (x^2)
double Calculator::square(){
    std::string num;
    
    std::cout << "Enter a number: ";
    std::cin >> num;
    
    assert(check(num) == 0); // Assert that input is a double

    return std::stod(num) * std::stod(num); // Convert string to double
};

// Given base, exponent, return base^exponent.
double Calculator::power(){
    std::string num1, num2;
    
    std::cout << "Enter two numbers (base, exponent): ";
    std::cin >> num1 >> num2;

    assert(check(num1) == 0); // Assert that input is a double
    assert(check(num2) == 0); // Assert that input is a double

    return pow(std::stod(num1), std::stod(num2)); // Convert string to double
};

// Square root of a given non-negative number.
double Calculator::sqroot(){
    std::string num;

    std::cout << "Enter a number: ";
    std::cin >> num;

    assert(check(num) == 0); // Assert that input is a double

    // Catch if input number is negative. Throw an exception is true.
    if (std::stod(num) < 0){
        throw std::invalid_argument("Square root of a negative number!");
    }

    return sqrt(std::stod(num)); // Convert string to double
};

// Natural log/log-e of a given number.
double Calculator::natlog(){
    std::string num;

    std::cout << "Enter a number (non-zero and non-negative): ";
    std::cin >> num;
    
    assert(check(num) == 0); // Assert that the input is a double

    // Catch if input number is zero and throw an exception.
    if (std::stod(num) == 0){
        throw std::invalid_argument("Logarithm of zero is not allowed!");
    } 
    // Catch if input number is negative and throw an exception.
    else if (std::stod(num) < 0){
        throw std::invalid_argument("Logarithm of a negative number is not allowed!");
    }

    return log(std::stod(num)); // Convert string to double
};

// Log-10 of a given non-negative and non-zero number.
double Calculator::logarithm(){
    std::string num;

    std::cout << "Enter a number (non-zero and non-negative): ";
    std::cin >> num;
    
    assert(check(num) == 0); // Assert that the input is a double

    // Catch if input number is zero and throw an exception.
    if (std::stod(num) == 0){
        throw std::invalid_argument("Logarithm of zero is not allowed!");
    } 
    // Catch if input number is negative and throw an exception.
    else if (std::stod(num) < 0){
        throw std::invalid_argument("Logarithm of a negative number is not allowed!");
    }

    return log10(std::stod(num)); // Convert string to double
};