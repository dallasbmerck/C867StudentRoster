//
//  roster.cpp
//  C867PA
//
//  Created by Dallas Merck on 8/19/21.
//

#include <stdio.h>
#include "student.h"
#include "roster.h"
#include <iostream>
#include <string>

using namespace std;




void Roster::parseStudentID(string data){
    
    size_t rhs = data.find(",");
    string studentID = data.substr(0, rhs);
    
    size_t lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string firstName = data.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string lastName = data.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string emailAddress = data.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int age = stoi(data.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int daysInCourse1 = stoi(data.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int daysInCourse2 = stoi(data.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int daysInCourse3 = stoi(data.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string strDegree = data.substr(lhs, rhs - lhs);
    
    DegreeProgram degreeProgram = DegreeProgram::SECURITY;
    if (strDegree == "SECURITY"){
        degreeProgram = SECURITY;
        }
    else if (strDegree == "NETWORK") {
        degreeProgram = NETWORK;
    }
    else if (strDegree == "SOFTWARE") {
        degreeProgram = SOFTWARE;
    }

    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2,  daysInCourse3, degreeProgram);
}


    Roster::~Roster() {
    for (int i = 0; i < lastStudentIndex; i++) {
        delete this->classRosterArray[i];
    }
    }
    

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
    int days[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[lastStudentIndex++] = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeprogram);
    }


void Roster::remove(string studentID){
    bool studentIDFound = false;
    for (int i = 0; i < lastStudentIndex; i++) {
        if (this->classRosterArray[i]->GetStudentID() == studentID) {
            studentIDFound = true;
            delete this->classRosterArray[i];
            for (int j = i; j < lastStudentIndex - 1; j++) {
            this->classRosterArray[j] = this->classRosterArray[j + 1];
            }
            
            lastStudentIndex--;
            cout << "Successfully removed student from roster. " << studentID << endl;
        }
    }
    
        if (!studentIDFound) {
            cout << "Error! Student with the ID: " << studentID << " not found." << endl << endl;
        }
}

void Roster::printAll(){
    for (int i = 0; i < this->lastStudentIndex; i++) {
        (this->classRosterArray)[i]->print();
       }
}
    
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < lastStudentIndex; i++) {
        if (classRosterArray[i]->GetStudentID() == studentID) {
            cout << "Student ID " << classRosterArray[i]->GetStudentID() << ": ";
            int *day = classRosterArray[i]->GetDaysToComplete();
            cout << "Average number of days in three courses: " << (day[0] + day[1] + day[2]) / 3.0 << endl;
            return;
        }
    }
}

void Roster::printInvalidEmails() {
    cout << "Displaying invalid email addresses:" << endl << endl;
    bool invalidEmailFound = false;
    for (int i = 0; i < lastStudentIndex; i++) {
        string iStudentEmail = classRosterArray[i]->GetEmailAddress();
        if (!(iStudentEmail.find(' ') == string::npos) ||
           (iStudentEmail.find('@') == string::npos) ||
            (iStudentEmail.find('.') == string::npos)) {
            invalidEmailFound = true;
            cout << iStudentEmail;
            cout << endl;
        }
    }
    cout << endl;
    if (!invalidEmailFound) {
        cout << "No invalid email addresses found." << endl;
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < lastStudentIndex; i++) {
        if (this->classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
            this->classRosterArray[i]->print();
        }
    }
}
