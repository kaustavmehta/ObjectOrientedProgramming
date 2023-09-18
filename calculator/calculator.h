/*
// HEADER FILE //
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

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <iostream>
#include <vector>
#include <cmath>

class Calculator {

    public:

        // Method to add two numbers
        double add();

        // Method to subtract two numbers
        double subtract();

        // Method to multiple two numbers
        double multiply();

        // Method to divide two numbers
        double divide();

        // Method to find the remainder between two numbers
        double modulus();

        // Method to find the square root of a number
        double sqroot();

        // Method to square a number
        double square();

        // Method to raise a number x to the power y
        double power();

        // Method to find the natural logarithm of a number
        double natlog();

        // Method to find the base-10 log of a number
        double logarithm();

        // Method to check if input is double
        bool check(std::string);
};

#endif