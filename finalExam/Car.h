/*
Kaustav Mehta
Final Exam Submission towards COMP412 Object Oriented Programming.
6 October 2023
*/

// Car.h
#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {

public:
    // Constructor
    Car(const std::string& color, const std::string& licensePlate, int numDoors);

    // Member function to display car information, including the number of doors
    void displayCarInfo() const;

private:
    int numDoors_;

};

#endif // CAR_H
