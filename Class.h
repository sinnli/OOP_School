//
// Created by liel on 03/01/2021.
//

#ifndef UNTITLED_CLASS_H
#define UNTITLED_CLASS_H
#include "Pupil.h"
#include <vector>
#include "Teacher.h"
using namespace std;

class Class {
    char nameOfLayer;
    int numOfClass;
    vector<Pupil*> PoinToStuInClass; //use of composition
    int numStudClass;
    Teacher* educator; //use of conposition
public:
    Class();
    Class(char nameLayer, int numClass,vector<Pupil*> PointToStud, int numStudInClass, Teacher* educator);
    ~Class();

    //operator +=
    //operator []
    Pupil &operator[]( int i )const;


};

#endif //UNTITLED_CLASS_H
