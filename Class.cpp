//
// Created by liel on 03/01/2021.
//

#include "Class.h"
using namespace std;

Class::Class(char nameLayer, int numClass, vector<Pupil *> PointToStud, int numStudInClass, Teacher *educator) {
    this->nameOfLayer = nameLayer;
    this->PoinToStuInClass = PointToStud;
    this->educator = educator;
    this->numOfClass = numClass;
    this->numStudClass = numStudInClass;
}
Class::Class() { //default ctor
    this->nameOfLayer = 'a';
    this->PoinToStuInClass; //is Null if empty
    //this->educator = *Teacher(); ->is there a default c-tor for teacher?
    this->numOfClass = 0;
    this->numStudClass = 0;
}
Class::~Class() {
    //delete[] PoinToStuInClass; maybe later requaried
    cout<<"Class been deleted"<<endl;
}
Pupil & Class ::operator[]( int i )const{
    try {
        if (0 <= i <= this->PoinToStuInClass.size()) {
            //index is in vector
            return (*this->PoinToStuInClass[i]); //returns Pupil in given index
        }
        else{
            throw (i);
        }
    }
    catch (int  i) {
        cout<< "No Student at given index."<<endl;
    }
    //Pupil stud;
    //return stud; //default Pupil
}
