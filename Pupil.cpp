//
// Created by liel on 03/01/2021.
//

#include "Pupil.h"
#include "Person.h"
#include "Class.h"
#include <iostream>
using namespace std;

Pupil::Pupil(){ //default c-tor
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
int main(){
    string F_n = "Israel",f2 = "hello",f3="alisa",f4 = "Inona",f6 = "Smith";
    string L_n = "Levi";
    string F_n1 = "Israeli";
    string L_n1 = "Levli";
    string sub[15] = {"a"};
    vector<int> gra = {100,75,90,100},gr1 = {56,100,100,100};
    vector<Pupil*> Ppupil;
  /*  Teacher t1  = Teacher(F_n1,L_n1,sub,15,12.30);
    Teacher *Pt1;
    Pt1 = &t1;
    Class C1('a',0,Ppupil,30,Pt1);
    Pupil p2 = Pupil(f2,f3,'a',1,gr1,C1);
    Pupil p1= Pupil(F_n,L_n,'a',1,gra,C1);
    p1.Top_Person();
    p1.gradeaverage();
    //p1.Print_Details();
    //p2.Print_Details();
    Pupil *Pp1,*Pp2;
    Pp1 = &p1;
    Pp2 = &p2;
    C1 += Pp1;
    C1 += Pp2;
    C1[0].Print_Details();
    C1[1].Print_Details();

*/
    return 0;
}