/* Assignment: 3
Author: Itay Mizikov, ID: 315541615
Author: Liel Sinn, ID: 209195155
 */
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

//like another ctor
void Class::Set_Class_details(int numClass, char layerLet, const vector<Pupil *> PointToStud, int numStudInClass,
                              Tutor *educator) {
    this->numOfClass = numClass;
    this->nameOfLayer = layerLet;
    this->PoinToStuInClass = PointToStud;
    this->numStudClass = numStudInClass;
    this->educator = educator;

}
Tutor* Class::Get_Tutor() {
    return this->educator;
}
Class::Class(char nameLayer, int numClass) {
    this->nameOfLayer = nameLayer;
    this->PoinToStuInClass; //empty
    this->educator; //empty
    this->numOfClass = numClass;
    this->numStudClass = 0; //empty
}
void Class::addToClass(Pupil *pupil) {
    this->PoinToStuInClass.push_back(pupil);
    this->numStudClass+=1;
}
void Class::Set_Tutor(Tutor* tutor) {
    this->educator = tutor;
    return ;
}
vector<Pupil*> Class::Get_PointToPupilInClass() {
    return this->PoinToStuInClass;
}
void Class::Print_Class_avg() {    // prints class average score

    int num_stu = this->numStudClass;
    double avrg = 0;
    for (int i = 0; i < num_stu; i++) {
        avrg =+ this->PoinToStuInClass[i]->gradeaverage();
    }
    avrg = avrg / num_stu;
    std::cout << "Average score of Class " << this->nameOfLayer << "-" << this->numOfClass << ": " << avrg << endl;
}