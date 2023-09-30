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

// Not sure how to implement pointers or dynamic memory management since this program does not have
// any real logic to it. Since it isn't necessary, I won't use it.

#include <iostream>
#include <string>
#include <vector>

#include "admission_utilities.h"

// Example Driver Code to demonstrate an Applicant object.
int main() {
    
    // Example extracurricular activities vector that will be passed into the applicant object.
    /*
    std::vector<Extracurricular*> activities1 = {
        Extracurricular("Debate Club", "Participated in school debate competitions", 2022),
        Extracurricular("Chess Club", "Played chess at regional tournaments", 2021),
        Extracurricular("National Science Olympiad", "School Topper", 2023)
    };

    std::vector<Extracurricular*> activities2 = {
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

    */

    Extracurricular* extracurricular1 = new Extracurricular("Debate Club", "Participated in school debate competitions", 2022);
    Extracurricular* extracurricular2 = new Extracurricular("Chess Club", "Played chess at regional tournaments", 2021);
    Extracurricular* extracurricular3 = new Extracurricular("National Science Olympiad", "School Topper", 2023);

    std::vector<Extracurricular*> extracurriculars1;
    extracurriculars1.push_back(extracurricular1);
    extracurriculars1.push_back(extracurricular2);
    extracurriculars1.push_back(extracurricular3);

    Extracurricular* extracurricular4 = new Extracurricular("Finance Club", "1st place in the Shark Tank Innovation Challenge", 2022);
    Extracurricular* extracurricular5 = new Extracurricular("Swimming", "Tamil Nadu state silver medalist", 2020);
    Extracurricular* extracurricular6 = new Extracurricular("Model United Nations", "Best Delegate", 2023);

    std::vector<Extracurricular*> extracurriculars2;
    extracurriculars2.push_back(extracurricular4);
    extracurriculars2.push_back(extracurricular5);
    extracurriculars2.push_back(extracurricular6);

    SubjectGrade* subject1 = new SubjectGrade("Math", 90.5);
    SubjectGrade* subject2 = new SubjectGrade("Physics", 85.0);
    SubjectGrade* subject3 = new SubjectGrade("English", 92.3);

    std::vector<SubjectGrade*> subjects1;
    subjects1.push_back(subject1);
    subjects1.push_back(subject2);
    subjects1.push_back(subject3);

    SubjectGrade* subject4 = new SubjectGrade("Psychology", 98.2);
    SubjectGrade* subject5 = new SubjectGrade("Economics", 92.6);
    SubjectGrade* subject6 = new SubjectGrade("Hindi", 87.1);

    std::vector<SubjectGrade*> subjects2;
    subjects2.push_back(subject4);
    subjects2.push_back(subject5);
    subjects2.push_back(subject6);

    // Instantiating an Applicant object.
    Applicant applicant1("John Doe", 18, 14112000, "john.doe@example.com", extracurriculars1, subjects1, 1400);
    Applicant applicant2("Dohn Joe", 17, 21072001, "dohn.joe@example.com", extracurriculars2, subjects2, 1285);
    
    // Print what we passed into the object.
    applicant1.displayInfo();
    applicant2.displayInfo();

    // Exit the program.
    return 0;
}
