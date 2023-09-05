/*
Author: Kaustav Mehta
Date: August 27 2023
This file is a solution for Q2 of the "Practical Programming using classes" assignment
for the 2023 COMP412 course at Krea University. This is a simple solution to using OOPs concepts
to bundle together data under one object. However, there is a lot of scope to improve its use:
For one, there could be a Subject class with generic public attributes that every subject at Krea
could be a derived class of. This allows for subject-specific grade calculations (such as weightages,
additional information such as component-wise grade breakdown, etc). Additionally, you could describe an
operator overload definition to "add" two subject objects such that the total grade gets added without
having to explicitly access the specific class method to get the final score.
*/

#include <iostream>
#include <string>
#include <vector>

#include <grading_utilities.h>

// Driver code
int main() {

    // Instantiate an object of Student
    Student student1("John Doe", 100);
    student1.addGrade("Math", 90.5);
    student1.addGrade("Physics", 85.0);
    student1.addGrade("English", 92.3);
    student1.displayInfo();

    // Add a line break between the two outputs.
    std::cout << std::endl;

    // Instantiate an object of Student
    Student student2("Dohn Joe", 101);
    student2.addGrade("Psychology", 98.2);
    student2.addGrade("Economics", 92.6);
    student2.addGrade("Hindi", 87.1);
    student2.displayInfo();

    std::cout << std::endl;
    return 0;
}
