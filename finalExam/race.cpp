/*
Kaustav Mehta
Final Exam Submission towards COMP412 Object Oriented Programming.
6 October 2023
*/

// race.cpp
#include "Car.h"
#include <vector>

int main() {
    
    // Create an array of Car objects
    std::vector<Car> cars;
    
    // Create four cars with corresponding colors and plate numbers.
    cars.push_back(Car("Red", "ABC123", 4));
    cars.push_back(Car("Blue", "XYZ456", 2));
    cars.push_back(Car("Green", "DEF789", 4));
    cars.push_back(Car("Yellow", "GHI101", 4));

    // Simulate a racing scenario using a loop
    // Print out a car's trajectory across the race, car by car.
    for (Car& car : cars) {

        std::cout << "-----" << std::endl;

        car.displayCarInfo();
        car.accelerate(30);
        car.displayCarInfo();
        car.brake(10);
        car.displayCarInfo();
    
    }

    return 0;
}
