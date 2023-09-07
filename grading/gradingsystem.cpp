#include "gradingsystem.h"

Student::Student(const std::string& _studentName, int _id): name(_studentName), studentId(_id) {}

void Student::addGrade(const std::string& _subject, double _grade) {
            
            subjects.push_back(_subject);
            grades.push_back(_grade);

        }

double Student::calculateAverageGrade() const {
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

void Student::displayInfo() const {

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