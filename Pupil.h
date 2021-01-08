/* Assignment: 1
Author1: Israel Israeli,
ID: 01234567
Author2: Learsi Learsi,
ID: 7654321
*/

#ifndef UNTITLED_PUPIL_H
#define UNTITLED_PUPIL_H

#include <string.h>
#include <vector>
#include <cstring>
#include "Person.h"
#include "Class.h"
#include <iostream>
using namespace std;

class Person;
class Class;

class Pupil : public Person {
    vector<int> arrayGrades;//i dont know how many grades
    char nameLayer;
    int numClass;
    //Class pupilClass; //use of composition
protected:

public:
    Pupil();//default c-tor
    Pupil(string frt_name , string lst_name ,char letterLayer,int numClass,vector<int> Grades);
    ~Pupil();

    double gradeaverage(); //how excact this average should be ?
    virtual void Print_Details();
    virtual bool Top_Person() ;//average over 85, no subject under 65
    char getLayer()const;

};

#endif //UNTITLED_PUPIL_H
