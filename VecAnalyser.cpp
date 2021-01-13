/* Assignment: 3
Author: Itay Mizikov, ID: 315541615
Author: Liel Sinn, ID: 209195155
 */
//not to submit
#include "VecAnalyser.h"
#include "Person.h"
#include <iostream>
#include <string.h>
#include "Worker.h"
#include "Pupil.h"
#include <typeinfo>


/*
template<typename T>
VecAnalyser<T>::VecAnalyser(vector<T*> data) {
    this->data = data; //the vector
}
*/
/*
template<typename T>
VecAnalyser<T>::VecAnalyser() {
}
  */
/*
template<typename T>
void VecAnalyser<T>::SetVector(vector<T *> the_data) {
    this->data = the_data;
}
 */
/*
template<typename T>
VecAnalyser<T>::~VecAnalyser() {
    delete[] this->data; //maybe more needed
}
*/
/*
template<typename T>
bool VecAnalyser<T>::inRange(int index) {

    if (!(0 <= index <= this->data.size())) {
        return false; //index out of range
    }
    return true; //index in range
}
 */
/*
template<typename T>
T VecAnalyser<T>::returnIndex(int i) const {
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
}
*/
/*
template<typename T>
void VecAnalyser<T>::swap(int index_1,int index_2){

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
}
*/
/*
template<typename T>
void VecAnalyser<T>::printElement(int index) {
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

}
 */
/*
template <typename T>
void VecAnalyser<T> ::printAll() {
    for(int i = 0;i<this->data.size();i++) {
        this->data[i].printDetails;
    }
    return;
}
  */
/*
template <typename T>
void VecAnalyser<T>::printMax() {
    if (typeid(*(this->data)).name()== typeid(Worker).name()){ //vector of workers->look for highest salary
        this->maxWorker();
    }
    else{
        this->maxPupil(); //vector of pupils looks for highest average
    }
    return;
}
 */

/*

template <typename T>
void VecAnalyser<T>::maxWorker() {
    double max[2] = {0,0}; //at the beginning max[0] = salary, max[1] = index with max salary
    for(int i = 0;i<this->data.size();i++) {
        if (this->data[i].Get_Sallary > max[0]){
            max[0] = this->data[i].Get_Sallary; //current highest salary
            max[1] = i; //the index of the person
        }
    }
    this->data[max[1]].print.Details; //printing out the worker with highest salary
    return;
}
  */
/*
template <typename T>
void VecAnalyser<T>::maxPupil() {
    double max[2] = {0,0}; //at the beginning max[0] = grade average, max[1] = index with max salary
    for(int i = 0;i<this->data.size();i++) {
        if (this->data[i].gradeaverage > max[0]){
            max[0] = this->data[i].Get_Sallary; //current highest grade average
            max[1] = i; //the index of the person
        }
    }
    this->data[max[1]].print.Details; //printing out the worker with highest grade average
    return;
}
template <typename T>
bool VecAnalyser<T>::indexIsManager(int index) {
    string Error = "No Person at given index ";
    Error += std::to_string(index); //converts int to string
    Error.append(". The range of the vector is 0 to ");
    Error.append(this->data.size());
    Error.append(".");

    try{
        if (this->inRange(index)){
            //there is such index
            if  (typeid(*(this->data)).name()== typeid(Worker).name()) { //the vector of Workers
                // since the manager can't be in the pupil vector
                //look for manager
                //if (typeid(*(this->data[index]).name() == typeid(Manager).name()){
                // there is only a single manager->single person of this type
                return true;
                //}
            }
            return false;
        }
        throw Error;
    }
    catch (string Error) {
        cout<< Error;
    }
}

*/