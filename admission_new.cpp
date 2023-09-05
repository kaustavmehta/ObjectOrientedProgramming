/* 
Author: Kaustav Mehta
Date: August 27 2023
This file is a solution for Q1 of the "Practical Programming using classes" assignment
for the 2023 COMP412 course at Krea University. The focus of this solution has been to use a limited
number of parameters that would be typical of any generic admissions process, but, a deliberate
effort has been made to use OOPs concepts to bundle together logically relevant pieces of information.
This is because, I think, a more exhaustive attempt at collecting more information would simply be
different forms of the same logic that is used here, and more time would be spent being an Admissions
Committee member rather than being a programmer.
*/

#include <iostream>
#include <string>
#include <vector>

#include <grading_utilities.h>

// Example Driver Code to demonstrate an Applicant object.
int main() {
    
    // Example extracurricular activities vector that will be passed into the applicant object.
    std::vector<Extracurricular> activities1 = {
        Extracurricular("Debate Club", "Participated in school debate competitions", 2022),
        Extracurricular("Chess Club", "Played chess at regional tournaments", 2021),
        Extracurricular("National Science Olympiad", "School Topper", 2023)
    };

    std::vector<Extracurricular> activities2 = {
        Extracurricular("Finance Club", "1st place in the Shark Tank Innovation Challenge", 2022),
        Extracurricular("Swimming", "Tamil Nadu state silver medalist", 2020),
        Extracurricular("Model United Nations", "Best Delegate", 2023)
    };

    // Example subject grades vector that will be passed into the applicant object.
    std::vector<SubjectGrade> grades1 = {SubjectGrade("Math", 90.5),
                                        SubjectGrade("Physics", 85.0),
                                        SubjectGrade("English", 92.3)};
    
    std::vector<SubjectGrade> grades2 = {SubjectGrade("Psychology", 98.2),
                                        SubjectGrade("Economics", 92.6),
                                        SubjectGrade("Hindi", 87.1)};

    // Instantiating an Applicant object.
    Applicant applicant1("John Doe", 18, 14112000, "john.doe@example.com", activities1, grades1, 1400);
    Applicant applicant2("Dohn Joe", 17, 21072001, "dohn.joe@example.com", activities2, grades2, 1285);
    
    // Print what we passed into the object.
    applicant1.displayInfo();
    applicant2.displayInfo();

    // Exit the program.
    return 0;
}
