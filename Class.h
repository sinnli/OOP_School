//
// Created by liel on 03/01/2021.
//

#ifndef UNTITLED_CLASS_H
#define UNTITLED_CLASS_H
#include <vector>
#include <iostream>
using namespace std;


class Pupil;
class Tutor;

class Class {
    char nameOfLayer;
    int numOfClass;
    vector<Pupil*> PoinToStuInClass; //use of composition
    int numStudClass;
    Tutor* educator; //use of conposition
public:
    Class();
    Class(char nameLayer, int numClass,const vector<Pupil*> PointToStud, int numStudInClass, Tutor* educator);
    Class(char nameLayer, int numClass); //just open a new class
    ~Class();
    Class& operator+=(Pupil* pupil);//adds stud to Vector of students
    void addToClass(Pupil* pupil);
    Pupil &operator[]( int i )const; //returns student at given index of Vector
    void plusOne_numStudClass();
    int Get_numStudClass();
    bool Top_Class();
    int Get_numOfClass();
    char Get_nameOfLayer();
    void Print_Students();
    void Set_Class_details(int numClass, char layerLet, const vector<Pupil*> PointToStud, int numStudInClass, Tutor* educator);
    Tutor* Get_Tutor();
    void Set_Tutor(Tutor* tutor); //and returns the current one


};

#endif //UNTITLED_CLASS_H
