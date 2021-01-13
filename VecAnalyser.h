//
// Created by liel on 10/01/2021.
//

#ifndef UNTITLED_VECANALYSER_H
#define UNTITLED_VECANALYSER_H

//forward declaration
#include <vector>
using std::vector;
using namespace std;
#include <iostream>
#include <string.h>
class Worker;
class Person;
class Pupil;


template<typename T>
class VecAnalyser{
private:
    //or vector of pointer to pupil or tho workers
    vector<T*> data;
public:
    VecAnalyser(){};
   //VecAnalyser(vector<T*> data);
    virtual ~VecAnalyser(){};
    void SetVector( vector<T*> the_data)
    {this->data = the_data;};

    T returnIndex(int i)const{
        string Error = "No Person at given index ";
        Error += std::to_string(i); //converts int to string
        Error.append(". The range of the vector is 0 to ");
        Error.append(this->data.size());
        Error.append(".");

        try{
            if (this->inRange(i)){
                //there is such index
                return (this->data[i]);
            }
            throw Error;
        }
        catch (string Error) {
            cout<< Error;
        }
    }; //returns object of type T in given index
    //needs to give back error of type string
    //where explained what index was given and what is the range of index

    void swap(int index_1,int index_2){
        string Error = "No Person at given index: ";
        if (!(this->inRange(index_1))) { //index not in range
            Error += std::to_string(index_1); //converts int to string
        }
        if (!((this->inRange(index_1))&&(this->inRange(index_2)))){//index not in range
            Error += string(" and "); //both indexes are out of range
        }
        if (!(this->inRange(index_2))) {//index not in range
            Error += std::to_string(index_2); //converts int to string
        }
        Error.append(". The range of the vector is 0 to ");
        Error.append(this->data.size());
        Error.append(".");

        try {
            if ((this->inRange(index_1))&&(this->inRange(index_2))){
                //indexes given exsist
                T temp;
                temp = this->data[index_1];
                this->data[index_1] = this->data[index_2];
                this->data[index_2] = temp;
                return;
            }
            throw Error;
        }
        catch (string Error){
            cout<<Error;
        }
    };
    //swaps between two indexes with same string error

    void printElement(int index){
        string Error = "No Person at given index ";
        Error += std::to_string(index); //converts int to string
        Error.append(". The range of the vector is 0 to ");
        Error.append(this->data.size());
        Error.append(".");

        try{
            if (this->inRange(index)){
                //there is such index
                this->data[index].printDetails;
                return;
            }
            throw Error;
        }
        catch (string Error) {
            cout<< Error;
        }
    }; //prints the object at given index, with string error

    void printAll(){
        for(int i = 0;i<this->data.size();i++) {
            this->data[i].printDetails;
        }
        return;
    };//prints the whole vector<>
    void printMax(){
        if (this->data.empty()){
            cout<<"There are no people in this vector"<<endl;
            return;
        }
        return;
    };
    //prints the objects with max value(for students ->highest average
    //for workers->highest salary)

    bool indexIsManager(int index){
        string Error = "No Person at given index ";
        Error += std::to_string(index); //converts int to string
        Error.append(". The range of the vector is 0 to ");
        Error.append(this->data.size());
        Error.append(".");

        try{
            if (this->inRange(index)){
                if (this->data.empty()){ //not sure if needed
                    cout<<"There are no people in this vector"<<endl;
                    return false;
                }
                //there is such index
                if  (typeid(this->data.at(index)).name() == "Manager") { //the vector of Workers
                    //checks if object type is manager
                    return true;

                }
                return false;
            }
            throw Error;
        }
        catch (string Error) {
            cout<< Error;
        }
    }; //RTTI use typeid(*(vec)[i])

    bool inRange(int index){
        if (!(0 <= index <= this->data.size())) {
            return false; //index out of range
        }
        return true; //index in range
    };

    void max(){
        double max[2] = {0,0}; //at the beginning max[0] = salary, max[1] = index with max salary
        for(int i = 0;i<this->data.size();i++) {
            if (this->data[i]->Get_Max() > max[0]){
                max[0] = this->data[i]->Get_Max(); //current highest salary
                max[1] = i; //the index of the person
            }
        }
        this->data[max[1]]->Print_Details(); //printing out the worker with highest salary
        return;
    };

};

#endif //UNTITLED_VECANALYSER_H
