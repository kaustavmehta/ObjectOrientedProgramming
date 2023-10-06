/*
Kaustav Mehta
Final Exam Submission towards COMP412 Object Oriented Programming.
6 October 2023
*/

// Car.cpp

#include "Car.h"
#include <iostream>

// Constructor
Car::Car(const std::string& color, const std::string& licensePlate, int numDoors)
    : Vehicle(color, licensePlate), numDoors_(numDoors) {}

// Member function to display the information stored in the Car object.
void Car::displayCarInfo() const {

    displayInfo(); // Call the base class method to display common vehicle information
    std::cout << " | Number of Doors: " << numDoors_ << std::endl;

}
