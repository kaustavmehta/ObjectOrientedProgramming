#ifndef grading_utilities.h
#define grading_utilities.h

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
        Student(const std::string& _studentName, int _id): name(_studentName), studentId(_id) {}

        // Setter for adding a subject and its corresponding grade to their respective subjects and grades vectors.
        // Looked up the C++ equivalent of Python's list.append() function and found the std::vector::push_back function:
        // Reference for the function used: https://cplusplus.com/reference/vector/vector/push_back/
        // We pass a reference to the string as the function's parameter to prevent duplication of data in memory.
        void addGrade(const std::string& _subject, double _grade) {
            
            subjects.push_back(_subject);
            grades.push_back(_grade);

        }

        // Function to calculate a simple grade average (out of 100). We iterate over every grade in grades and return
        // the average as being the sum of the grades divided by the size of the grades vector.
        // Reference for the function used: https://cplusplus.com/reference/vector/vector/empty/
        double calculateAverageGrade() const {
            // If grades is an empty vector, we will run into a division by zero exception/error. This condition checking
            // should take care of the case where the empty vector results in a zero denominator, and instead we directly
            // return a double value of 0.0.
            if (grades.empty()) {
                return 0.0;
            }

            double sum = 0.0; // Initialize variable

            for (double grade : grades) {
                sum += grade;
            }
            
            return sum / grades.size(); // Calculate and return the average
        }

        // Simple function to print out the contents of the Student object.
        void displayInfo() const {

            std::cout << "Student Name: " << name << std::endl;
            std::cout << "Student ID: " << studentId << std::endl;

            // If the grades vector is empty, we won't have any computation to do, so we take care of this case
            // and directly jump to the else condition where we state that no grades are available.
            if (!grades.empty()) {

                std::cout << "Subject-wise Grades:" << std::endl;
                
                // std::vector::size() returns a type of size_t, so to compare the size, we initialize i as a size_t.
                // Alternatively, we could convert size_t to an integer.
                for (size_t i = 0; i < subjects.size(); ++i) {
                    // Since the subjects and grades vector are of the same size, we can be assured that one index corresponds
                    // correctly to a (subject, grade) combination.
                    std::cout << " - " << subjects[i] << ": " << grades[i] << std::endl;
                }
                
                std::cout << "  -- Average Grade: " << calculateAverageGrade() << std::endl;
            } 
            
            else {
                std::cout << "No grades available." << std::endl;
            }
        }
};


#endif