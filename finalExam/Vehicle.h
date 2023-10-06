/*
Kaustav Mehta
Final Exam Submission towards COMP412 Object Oriented Programming.
6 October 2023
*/

// Vehicle.h
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>

class Vehicle {
public:
    // Constructor
    Vehicle(const std::string& color, const std::string& licensePlate);

    // Member functions for vehicle functionality such accelerating, braking and shifting gears.
    void accelerate(int speedIncrement);
    void brake(int speedDecrement);
    void gearShift(int newGear);

    // Display vehicle information
    void displayInfo() const;

protected:
    std::string color_;
    std::string licensePlate_;
    int speed_;
    int gear_;
};

#endif // VEHICLE_H
