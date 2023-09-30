#ifndef ADMISSION_UTILITIES_H_
#define ADMISSION_UTILITIES_H_

#include <iostream>
#include <string>
#include <vector>

// Not sure how to implement pointers or dynamic memory management since this program does not have
// any real logic to it. Since it isn't necessary, I won't use it.

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
        Extracurricular(const std::string& _title, const std::string& _description, int _year);
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

        SubjectGrade(const std::string& _subject, double _grade);
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
                const std::vector<SubjectGrade>& _subjectGrades, int _satScore);
        
        // Getter methods
        std::string getName() const;

        int getAge() const;

        int getDOB() const;

        std::string getEmail() const;

        std::vector<Extracurricular> getExtracurriculars() const;

        std::vector<SubjectGrade> getSubjectGrades() const;

        int getSATScore() const;

        // Setter methods
        void setName(const std::string& _name);

        void setAge(int _age);

        void setDOB(int _dob);

        void setEmail(const std::string& _email);

        void setExtracurriculars(const std::vector<Extracurricular>& _extracurriculars);

        void setSubjectGrades(const std::vector<SubjectGrade>& _subjectGrades);

        void setSATScore(int _satScore);       

        // Method to display applicant's information (basically reads and prints the entire
        // data structure that the Applicant class encapsulates).
        void displayInfo() const;
};

#endif