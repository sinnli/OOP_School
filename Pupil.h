/* Assignment: 1
Author1: Israel Israeli,
ID: 01234567
Author2: Learsi Learsi,
ID: 7654321
*/

#ifndef UNTITLED_PUPIL_H
#define UNTITLED_PUPIL_H

#include <vector>
#include "Class.h"
using namespace std;

class Person;

class Pupil : public Person {
    vector<int> arrayGrades;//i dont know how many grades
    char* nameLayer;
    int numClass;
    Class pupilClass; //use of composition
protected:

public:
    Pupil();//default c-tor
    Pupil(char* nameLayer,int numClass,vector<int> Grades,Class pupilClass);
    ~Pupil();
    //getter/setter
    double gradeaverage(); //how excact this average should be ?
    bool topStudent(); //average over 85, no subject under 65
    void printStudent();
};

#endif //UNTITLED_PUPIL_H
