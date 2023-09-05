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

class Extracurricular {
    
    // Bundles a short title, associated description and the year when the extracurricular activity
    // was done. Each object of this class corresponds to one activity.
    // PARAMETERS:
    //      _title (string): The title of the activity.
    //      _description (string): Associated description of the activity. 
    //      _year (int): Year when the activity was done.
    
    public:
        std::string title;
        std::string description;
        int year;

        // Constructor for the class using a member initializer list for the variables.
        // We pass a reference to each string instead of making copies of the string every time.
        Extracurricular(const std::string& _title, const std::string& _description, int _year)
            : title(_title), description(_description), year(_year) {}
};

class SubjectGrade {

    // Bundles a subject and its associated grade as an object. Each object of this class
    // corresponds to one subject and its grade.
    // PARAMETERS:
    //      _subject (string): Name of the subject.
    //      _grade (double): Corresponding grade of the subject.
    
    public:
        std::string subject;
        double grade;

        SubjectGrade(const std::string& _subject, double _grade)
            : subject(_subject), grade(_grade) {}
};

class Applicant {

    // Bundles all related Applicant details into one object.
    // PARAMETERS:
    //      _name (string): Name of the applicant.
    //      _age (int): Current age of the applicant.
    //      _dob (int): Date of birth in DDMMYYYY format. [No validation is performed]
    //      _email (string): Email address of the applicant.
    //      _extracurriculars (vector <Extracurricular>): A vector consisting of as many Extracurricular
    //          objects as the number of activities. Each object contains the title, description and
    //          year of the extracurricular activity.
    //      _subjectGrades (vector <SubjectGrade>): A vector consisting of as many SubjectGrade objects
    //          as the number of subjects the applicant has registered for in their board. Each object
    //          contains the name of the subject and the associated grade.
    //      _satScore (int): For the lack of a better admissions test, we store the SAT score of the
    //          applicant. SAT scores are guaranteed to be an integer (no fractional score).

    private:
        
        int age;
        int dob;
        int satScore;
        std::string name;
        std::string email;
        std::vector<Extracurricular> extracurriculars;
        std::vector<SubjectGrade> subjectGrades;

    public:
        // Constructor using a member list initializer. Again, we use reference to the std::string
        // and std::vector<Extracurricular>, std::vector<SubjectGrade> types to prevent data
        // duplication in memory.
        Applicant(const std::string& _name, int _age, int _dob, const std::string& _email,
                const std::vector<Extracurricular>& _extracurriculars,
                const std::vector<SubjectGrade>& _subjectGrades, int _satScore)
            : name(_name), age(_age), dob(_dob), email(_email), extracurriculars(_extracurriculars),
            subjectGrades(_subjectGrades), satScore(_satScore) {}

        // Getter methods
        std::string getName() const {
            return name;
        }

        int getAge() const {
            return age;
        }

        int getDOB() const {
            return dob;
        }

        std::string getEmail() const {
            return email;
        }

        std::vector<Extracurricular> getExtracurriculars() const {
            return extracurriculars;
        }

        std::vector<SubjectGrade> getSubjectGrades() const {
            return subjectGrades;
        }

        int getSATScore() const {
            return satScore;
        }

        // Setter methods
        void setName(const std::string& _name) {
            name = _name;
        }

        void setAge(int _age) {
            // TODO: Validation for age being a plausible value for a prospective university applicant
            age = _age;
        }

        void setDOB(int _dob){
            // TODO: Validation for a valid DOB format
            // (split by [0:2] for date, [2:4] for month and [4:] for year)
            dob = _dob;
        }

        void setEmail(const std::string& _email) {
            // TODO: Validation that the email address is valid. Wouldn't want to attempt it
            // given how I've seen how scary the regex expression to validate an email looks like.
            email = _email;
        }

        void setExtracurriculars(const std::vector<Extracurricular>& _extracurriculars) {
            // TODO: Validation that we don't exceed an X number of extracurricular activities.
            // Further validation that the year given ought to be validated in the Extracurricular class.
            extracurriculars = _extracurriculars;
        }

        void setSubjectGrades(const std::vector<SubjectGrade>& _subjectGrades) {
            // TODO: Validation for a minimum of (4?) subjects and a maximum X number of subjects.
            // Further validation on the grades achieved ought to be done. Currently, the function
            // associated with the SubjectGrade class will happily take any double value.
            subjectGrades = _subjectGrades;
        }

        void setSATScore(int _satScore) {
            // TODO: If the applicant hasn't done SAT, maybe a value of -1 might be good to indicate
            // this. Further, an upper maximum validation of 1400 should be done.
            satScore = _satScore;
        }       

        // Method to display applicant's information (basically reads and prints the entire
        // data structure that the Applicant class encapsulates).
        void displayInfo() const {
            std::cout << "Name: " << name << std::endl;
            std::cout << "Age: " << age << std::endl;
            std::cout << "Date of Birth: " << dob << std::endl;
            std::cout << "Email: " << email << std::endl;
            
            std::cout << "Extracurriculars: " << std::endl;
            // Loop to iterate over every Extracurricular activity in the extracurriculars vector
            // and prints the encapsulating title, description and year.
            for (const Extracurricular& activity : extracurriculars) {
                std::cout << "- Title: " << activity.title << std::endl;
                std::cout << "  Description: " << activity.description << std::endl;
                std::cout << "  Year: " << activity.year << std::endl;
            }
            
            std::cout << "Subject Grades: ";
            // Loop to iterate over every SubjectGrade object in the subjectGrades vector and
            // and prints the encapsulating subject name and grade.
            for (const SubjectGrade& subjectGrade : subjectGrades) {
                std::cout << subjectGrade.subject << " (" << subjectGrade.grade << "%), ";
            }

            std::cout << std::endl;
            std::cout << "SAT Score: " << satScore << " /1400" << std::endl;
        }
};

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
