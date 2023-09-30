#include "admission_utilities.h"

// Not sure how to implement pointers or dynamic memory management since this program does not have
// any real logic to it. Since it isn't necessary, I won't use it.

// Constructor using a member list initializer. Again, we use reference to the std::string
// and std::vector<Extracurricular>, std::vector<SubjectGrade> types to prevent data
// duplication in memory.

// Update 30 September 2023:
// Updated to use pointers and dynamic memory management.

Extracurricular::Extracurricular(const std::string& _title, const std::string& _description, int _year)
            : title(_title), description(_description), year(_year) {}

SubjectGrade::SubjectGrade(const std::string& _subject, double _grade)
            : subject(_subject), grade(_grade) {}

Applicant::Applicant(const std::string& _name, int _age, int _dob, const std::string& _email,
                const std::vector<Extracurricular*>& _extracurriculars,
                const std::vector<SubjectGrade*>& _subjectGrades, int _satScore)
            : name(_name), age(_age), dob(_dob), email(_email), extracurriculars(_extracurriculars),
            subjectGrades(_subjectGrades), satScore(_satScore) {}

// Getter methods

std::string Applicant::getName() const {return name;}
int Applicant::getAge() const {return age;}
int Applicant::getDOB() const {return dob;}
std::string Applicant::getEmail() const {return email;}
std::vector<Extracurricular*> Applicant::getExtracurriculars() const {return extracurriculars;}
std::vector<SubjectGrade*> Applicant::getSubjectGrades() const {return subjectGrades;}
int Applicant::getSATScore() const {return satScore;}

// Setter methods

void Applicant::setName(const std::string& _name) {name = _name;}

void Applicant::setAge(int _age) {
            // TODO: Validation for age being a plausible value for a prospective university applicant
            age = _age;
}

void Applicant::setDOB(int _dob){
            // TODO: Validation for a valid DOB format
            // (split by [0:2] for date, [2:4] for month and [4:] for year)
            dob = _dob;
}

void Applicant::setEmail(const std::string& _email) {
            // TODO: Validation that the email address is valid. Wouldn't want to attempt it
            // given how I've seen how scary the regex expression to validate an email looks like.
            email = _email;
}

void Applicant::setExtracurriculars(const std::vector<Extracurricular*>& _extracurriculars) {
    // TODO: Validation that we don't exceed an X number of extracurricular activities.
    // Further validation that the year given ought to be validated in the Extracurricular class.
    extracurriculars = _extracurriculars;
}

void Applicant::setSubjectGrades(const std::vector<SubjectGrade*>& _subjectGrades) {
    // TODO: Validation for a minimum of (4?) subjects and a maximum X number of subjects.
    // Further validation on the grades achieved ought to be done. Currently, the function
    // associated with the SubjectGrade class will happily take any double value.
    subjectGrades = _subjectGrades;
}

void Applicant::setSATScore(int _satScore) {
    // TODO: If the applicant hasn't done SAT, maybe a value of -1 might be good to indicate
    // this. Further, an upper maximum validation of 1400 should be done.
    satScore = _satScore;
}       

// Method to display applicant's information (basically reads and prints the entire
// data structure that the Applicant class encapsulates).
void Applicant::displayInfo() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Date of Birth: " << dob << std::endl;
    std::cout << "Email: " << email << std::endl;
    
    std::cout << "Extracurriculars: " << std::endl;
    // Loop to iterate over every Extracurricular activity in the extracurriculars vector
    // and prints the encapsulating title, description and year.
    
    for (const Extracurricular* activity : extracurriculars) {
        std::cout << "- Title: " << activity->title << std::endl;
        std::cout << "  Description: " << activity->description << std::endl;
        std::cout << "  Year: " << activity->year << std::endl;
    }
    
    std::cout << "Subject Grades: ";
    // Loop to iterate over every SubjectGrade object in the subjectGrades vector and
    // and prints the encapsulating subject name and grade.
    for (const SubjectGrade* subjectGrade : subjectGrades) {
        std::cout << subjectGrade->subject << " (" << subjectGrade->grade << "%), ";
    }

    std::cout << std::endl;
    std::cout << "SAT Score: " << satScore << " /1400" << std::endl;
}