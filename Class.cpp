//
// Created by liel on 03/01/2021.
//
#include "Pupil.h"
#include "Class.h"
#include "Teacher.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Class::Class(char nameLayer, int numClass, const vector<Pupil*> PointToStud, int numStudInClass,
             Teacher *educator) {
    this->nameOfLayer = nameLayer;
    this->PoinToStuInClass = PointToStud;
    this->educator = educator;
    this->numOfClass = numClass;
    this->numStudClass = numStudInClass;
}


Class::Class() { //default ctor
    this->nameOfLayer;
    this->PoinToStuInClass; //is Null if empty
    this->educator;
    this->numOfClass;
    this->numStudClass;
}
Class::~Class() {
    //delete[] PoinToStuInClass; maybe later required
    cout<<"Class been deleted"<<endl;
}
Pupil & Class ::operator[]( int i )const
{
    if ((i >= this->PoinToStuInClass.size())||(i<0)) {
        //Vector index out of bound, exiting.
        cout<< "No Student at given index."<<endl;
        exit(0);
    }
    return (*this->PoinToStuInClass[i]); //returns Pupil in given index
}
Class& Class::operator+=(Pupil* pupil) {
    //shared_ptr<Pupil> pPupil = make_shared<Pupil>();
    this->PoinToStuInClass.push_back(pupil);
    //adding an student  in the end of the vector
    return *this;
}
