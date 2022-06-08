//
//  student.h
//  C867PA
//
//  Created by Dallas Merck on 8/19/21.
//

#ifndef student_h
#define student_h
#include "degree.h"
#include <string>
#include <iostream>

using namespace std;

class Student {

public:
    
    const static int NUMCOURSES = 3;
    
    
    
    ~Student(); //Deconstructor
    
    Student(string aStudentID, string aFirstName, string aLastName, string aEmailAddress, int aAge, int aDaysToComplete[], DegreeProgram aDegreeProgram); //Full constructor
    
    //Getters
    string GetStudentID();
    string GetFirstName();
    string GetLastName();
    string GetEmailAddress();
    int GetAge();
    int *GetDaysToComplete();
    DegreeProgram GetDegreeProgram();
    
    //Setters
    void SetStudentID(string aStudentID);
    void SetFirstName(string aFirstName);
    void SetLastName(string aLastName);
    void SetEmailAddress(string aEmailAddress);
    void SetAge(int aAge);
    void SetDaysToComplete(int aDaysToComplete[]);
    void SetDegreeProgram(DegreeProgram degreeProgram);
    void print();
    
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    DegreeProgram degreeProgram;
    int daysToComplete[NUMCOURSES];

};


#endif /* student_h */
