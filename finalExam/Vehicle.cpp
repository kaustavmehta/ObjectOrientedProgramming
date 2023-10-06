/*
Kaustav Mehta
Final Exam Submission towards COMP412 Object Oriented Programming.
6 October 2023
*/

// Vehicle.cpp
#include "Vehicle.h"
#include <iostream>

// Constructor
Vehicle::Vehicle(const std::string& color, const std::string& licensePlate)
    : color_(color), licensePlate_(licensePlate), speed_(0), gear_(0) {}

// Member function to accelerate any vehicle.
void Vehicle::accelerate(int speedIncrement) {
    speed_ += speedIncrement;
}

// Member function to deaccelerate any vehicle.
void Vehicle::brake(int speedDecrement) {
    if (speed_ >= speedDecrement) {
        speed_ -= speedDecrement;
    } else {
        speed_ = 0;
    }
}

// Member function to shift gears in any vehicle.
void Vehicle::gearShift(int newGear) {
    gear_ = newGear;
}

// Common vehicle properties that can be shown with this base class' display member function.
void Vehicle::displayInfo() const {
    std::cout << "Color: " << color_ << " | "
    << "License Plate: " << licensePlate_ << " | "
    << "Speed: " << speed_ << " mph" << " | "
    << "Gear: " << gear_;
}
