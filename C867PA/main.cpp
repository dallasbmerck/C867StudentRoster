//
//  main.cpp
//  C867PA
//
//  Created by Dallas Merck on 8/19/21.
//

#include <iostream>
#include "student.h"
#include "roster.h"

using namespace std;

int main() {

    cout << "C867 - Scripting & Programming: Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 001523951" << endl;
    cout << "Name: Dallas Merck" << endl;
    cout << endl << endl;
    
    
    static string studentData[5] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Dallas,Merck,dmerck@wgu.edu,25,15,13,11,SOFTWARE"
    };
    
    Roster classRoster;
    
    for (int i = 0; i < 5; i++) {
        classRoster.parseStudentID(studentData[i]);
    }
    cout << "Displaying all students:" << endl;
    classRoster.printAll();
    cout << endl;
    
    cout << endl << endl;
    classRoster.printInvalidEmails();
    
    cout << endl << endl;
    cout << "Students average days in courses: " << endl;
    
    classRoster.printAverageDaysInCourse("A1");
    classRoster.printAverageDaysInCourse("A2");
    classRoster.printAverageDaysInCourse("A3");
    classRoster.printAverageDaysInCourse("A4");
    classRoster.printAverageDaysInCourse("A5");
    
    cout << endl << endl;
    
    classRoster.printByDegreeProgram(SOFTWARE);
    
    cout << endl << endl;
    cout << "Removing A3" << endl << endl;
    
    classRoster.remove("A3");
    
    classRoster.printAll();

    cout << endl;
    
    classRoster.remove("A3");
    
}
