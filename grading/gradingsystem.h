#ifndef GRADINGSYSTEM_H_
#define GRADINGSYSTEM_H_

#include <iostream>
#include <string>
#include <vector>

// Bundles data and some logic to create a Student object.
// PARAMETERS:
//      _studentName (string): Stores the student's name.
//      _id (int): Stores the student's ID.
//      _subjects (vector <string>): A vector of strings that correspond to each subject that the student has taken.
//      _grades (vector <double>): A vector of doubles which is index-correspond to _subjects such that the double value at an index
//          corresponds to the grade achieved in the subject that corresponds to the same index at _subjects.

class Student {

    private:

        std::string name;
        int studentId;
        std::vector<std::string> subjects;
        std::vector<double> grades;

    public:
        // Constructor for the Student class using a member initializer list.
        Student(const std::string& _studentName, int _id);

        // Setter for adding a subject and its corresponding grade to their respective subjects and grades vectors.
        // Looked up the C++ equivalent of Python's list.append() function and found the std::vector::push_back function:
        // Reference for the function used: https://cplusplus.com/reference/vector/vector/push_back/
        // We pass a reference to the string as the function's parameter to prevent duplication of data in memory.
        void addGrade(const std::string& _subject, double _grade);

        // Function to calculate a simple grade average (out of 100). We iterate over every grade in grades and return
        // the average as being the sum of the grades divided by the size of the grades vector.
        // Reference for the function used: https://cplusplus.com/reference/vector/vector/empty/
        double calculateAverageGrade() const;

        // Simple function to print out the contents of the Student object.
        void displayInfo() const;
};


#endif