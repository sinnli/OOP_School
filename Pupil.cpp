/* Assignment: 3
Author: Itay Mizikov, ID: 315541615
Author: Liel Sinn, ID: 209195155
 */
#include "Pupil.h"
#include "Person.h"
#include "Class.h"
#include <iostream>
using namespace std;

Pupil::Pupil():Person("hi","hi"){ //default c-tor

    this->arrayGrades; //empty Vector
    this->nameLayer; //default value
    this->numClass;
    //this->pupilClass;
}

Pupil::Pupil(string frt_name , string lst_name ,char letterLayer, int numClass, vector<int> Grades) :
Person(frt_name, lst_name)
{
    this->nameLayer = letterLayer;
    this->arrayGrades = Grades;
    this->numClass = numClass;
    //this->pupilClass = pupilClass;
}

void Pupil::Print_Details(){
    /*
     * prints details of student
     * also grades, average
     * is or is not topStudent
     */
    cout<<"The details of the student are:"<<endl;
    this->printPeople(); //prints name of student
    cout<<"The grades of the student are:"<<endl;
    for (int i = 0; i<this->arrayGrades.size();i++){ //maybe names of subjects needs to be added
        cout<<arrayGrades[i]<<" ,";
    }
    cout<<endl;
    cout<<"In class "<< this->nameLayer<<this->numClass<<"."<<endl;
    if (this->Top_Person()== true){
        cout<<"The student is a top student."<<endl;
    }
    else{
      cout<<"The student is not a top student."<<endl;
    }
    cout<<"The grades average is: "<<this->gradeaverage()<<endl;
    return;
};
double Pupil::gradeaverage() { //how exact this number should be ?
    double sum=0,n = this->arrayGrades.size();
    for (int j=0;j<n;j++){
        sum+= this->arrayGrades[j];
    }
    return (sum/n);
}
bool Pupil::Top_Person() {
    int flag_1gradeUnder65=0;
    for (int j=0;j<this->arrayGrades.size();j++){
        if(this->arrayGrades[j]<65){
            flag_1gradeUnder65 = 1;
        }
    }
    if (this->gradeaverage()>85 & flag_1gradeUnder65==0){
        return true;
    }
    return false;
}

Pupil::~Pupil() {
    //delete[] vector.. maybe later
    cout<< "deleting Pupil"<<endl;
}

char Pupil::getLayer()const {
    return this->nameLayer; //returns char of layer the student is in
}

int Pupil::getClassnum()const{
    return this->numClass;
}
void Pupil::Get_Max() {
    this->gradeaverage();
    return;
}
