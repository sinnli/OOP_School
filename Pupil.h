/* Assignment: 3
Author: Itay Mizikov, ID: 315541615
Author: Liel Sinn, ID: 209195155
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
public:
    Pupil();//default c-tor
    Pupil(string frt_name , string lst_name ,char letterLayer,int numClass,vector<int> Grades);
    virtual ~Pupil();
    double gradeaverage(); //how excact this average should be ?
    virtual void Print_Details();
    virtual bool Top_Person() ;//average over 85, no subject under 65
    char getLayer()const;
    int getClassnum()const;
    virtual void Get_Max();

};

#endif //UNTITLED_PUPIL_H
