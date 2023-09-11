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

};

#endif