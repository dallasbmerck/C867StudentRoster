//
//  sudent.cpp
//  C867PA
//
//  Created by Dallas Merck on 8/19/21.
//

#include <stdio.h>
#include "student.h"
#include <iostream>
#include <string>

using namespace std;

int i = 0;

Student::Student(string aStudentID, string aFirstName, string aLastName, string aEmailAddress, int aAge, int aDaysToComplete[], DegreeProgram aDegreeProgram) {
    
    studentID = aStudentID;
    firstName = aFirstName;
    lastName = aLastName;
    emailAddress = aEmailAddress;
    age = aAge;
    for (i = 0; i < NUMCOURSES; i++) {
        daysToComplete[i] = aDaysToComplete[i];
    }
    degreeProgram = aDegreeProgram;
}


string Student::GetStudentID() {
    return studentID;
}

string Student::GetFirstName() {
    return firstName;
}

string Student::GetLastName() {
    return lastName;
}

string Student::GetEmailAddress() {
    return emailAddress;
}

int Student::GetAge() {
    return age;
}

int *Student::GetDaysToComplete(){
    return daysToComplete;
}

DegreeProgram Student::GetDegreeProgram() {
    return degreeProgram;
}

void Student::SetStudentID(string aStudentID) {
    studentID = aStudentID;
    return;
}

void Student::SetFirstName(string aFirstName) {
    firstName = aFirstName;
    return;
}

void Student::SetLastName(string aLastName) {
    lastName = aLastName;
    return;
}

void Student::SetEmailAddress(string aEmailAddress) {
    emailAddress = aEmailAddress;
    return;
}

void Student::SetAge(int aAge) {
    age = aAge;
    return;
}

void Student::SetDaysToComplete(int aDaysToComplete[]) {
    for (int i = 0; i < NUMCOURSES; i++) {
        daysToComplete[i] = aDaysToComplete[i];
        }
    return;
}

void Student::SetDegreeProgram(DegreeProgram aDegreeProgram) {
    degreeProgram = aDegreeProgram;
    return;
}

void Student::print() {
    cout << studentID << "\t";
    cout << "First name: " << firstName << "\t";
    cout << "Last name: " << lastName << "\t";
    cout << "Age: " << age << "\t";
    cout << "Days in courses: {";
    for (int i = 0; i < NUMCOURSES; i++){
        cout << daysToComplete[i] << " ";
    }
    cout << "}" << "\t" << "Degree program: ";
    switch(degreeProgram) {
        case SECURITY :
            cout << "SECURITY";
            break;
        case NETWORK :
            cout << "NETWORK";
            break;
        case SOFTWARE :
            cout << "SOFTWARE";
            break;
    }
    cout << endl;
    return;
}


Student::~Student() {}


