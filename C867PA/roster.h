//
//  roster.h
//  C867PA
//
//  Created by Dallas Merck on 8/19/21.
//

#ifndef roster_h
#define roster_h
#include <string>

using namespace std;

class Roster {
public:

    
    ~Roster();
    
    void parseStudentID(string data);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
private:
    Student* classRosterArray[5];
    int rosterCapacity = 5;
    int lastStudentIndex = 0;

};

#endif /* roster_h */
