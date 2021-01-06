//
// Created by liel on 03/01/2021.
//

#include "Pupil.h"
#include "Class.h"
#include <iostream>
using namespace std;

Pupil::Pupil(){
}

void Pupil::printStudent(){
    /*
     * prints details of student
     * also grades, average
     * is or is not topStudent
     */
    cout<<"The details of the student are:"<<endl;
    //this->printPeople(); //needs to be written in father class People.
    cout<<"The grades of the student are:"<<endl;
    for (int i = 0; i<this->arrayGrades.size();i++){ //maybe names of subjects needs to be added
        cout<<arrayGrades[i]<<" ,";
    }
    //cout<<"In class "<< this->nameLayer<<this->numClass<<"."<<endl;
    //if (this->topStudent()== true){
      //  cout<<"The student is a top student."<<endl;
    //}
    //else{
      //  cout<<"The student is not a top student."<<endl;
    //}
    //cout<<"The grades average is: "<<this->gradeaverage()<<endl;
    return;
};
double Pupil::gradeaverage() { //how exact this number should be ?
    double sum=0,n = this->arrayGrades.size();
    for (int j=0;j<n;j++){
        sum+= this->arrayGrades[j];
    }
    return (sum/n);
}
bool Pupil::topStudent() {
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

int main(){

    return 0;
}