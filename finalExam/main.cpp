/*
Kaustav Mehta
Final Exam Submission towards COMP412 Object Oriented Programming.
6 October 2023
*/

// main.cpp
#include "Car.h"
#include <iostream>

int main() {

    try {
        // Create a Car object using dynamic memory allocation
        Car* carPtr = new Car("Red", "ABC123", 4);

        // Display car information
        carPtr->displayCarInfo();

        // Accelerate the car
        carPtr->accelerate(30);
        carPtr->displayCarInfo();

        // Brake the car
        carPtr->brake(10);
        carPtr->displayCarInfo();

        // Shift gears
        carPtr->gearShift(2);
        carPtr->displayCarInfo();

        // Deallocate memory
        delete carPtr;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
    }

    return 0;
}
