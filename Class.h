//
// Created by liel on 03/01/2021.
//

#ifndef UNTITLED_CLASS_H
#define UNTITLED_CLASS_H
#include <vector>
#include "Teacher.h"
//#include <memory>
using namespace std;
class Pupil;

class Class {
    char nameOfLayer;
    int numOfClass;
    vector<Pupil*> PoinToStuInClass; //use of composition
    int numStudClass;
    Teacher* educator; //use of conposition
public:
    Class();
    Class(char nameLayer, int numClass,const vector<Pupil*> PointToStud, int numStudInClass, Teacher* educator);
    ~Class();
    Class& operator+=(Pupil* pupil);//adds stud to Vector of students
    Pupil &operator[]( int i )const; //returns student at given index of Vector

};

#endif //UNTITLED_CLASS_H
