//
// Created by liel on 03/01/2021.
//

#ifndef UNTITLED_CLASS_H
#define UNTITLED_CLASS_H
#include "Pupil.h"
#include <vector>
using namespace std;

class Class {
    char nameOfLayer;
    int numOfClass;
    vector<Pupil*> PoinToStuInClass; //use of composition
    int numStudClass;
    //Teacher* educator; //use of conposition
public:
    Class();
    ~Class();

    //operator +=
    //operator []
    Pupil &operator[]( int i );


};

#endif //UNTITLED_CLASS_H
