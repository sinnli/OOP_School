//
// Created by liel on 03/01/2021.
//
#include "Pupil.h"
#include "Class.h"
#include "Tutor.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Class::Class(char nameLayer, int numClass, const vector<Pupil*> PointToStud, int numStudInClass,
             Tutor *educator) {
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
int Class::Get_numStudClass() {
    return this->numStudClass;
}

bool Class::Top_Class() {     // top class if more than 50% are top students

    int cntr = 0;
    for (int i = 0; i < this->numStudClass; i++) {
        if (this->PoinToStuInClass[i]->Pupil::Top_Person() == true) {       // if (this->PoinToStuInClass[i]->Top_Person() == true)
            cntr++;
        }
    }
    if ((cntr / this->numStudClass) * 100 > 50) {
        return true;
    }
    return false;
}

int Class::Get_numOfClass() {
    return this->numOfClass;
}

char Class::Get_nameOfLayer() {
    return this->nameOfLayer;
}

void Class::Print_Students() {

    for (int i = 0; i < this->numStudClass; i++) {
        std::cout << "Students in the class are: " << endl;
        this->PoinToStuInClass[i]->Print_Details();
    }
}
void Class::plusOne_numStudClass() {
    this->numStudClass = this->numStudClass+1;
    return;
}

