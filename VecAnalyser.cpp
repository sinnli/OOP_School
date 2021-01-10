//
// Created by liel on 10/01/2021.
//

#include "VecAnalyser.h"

template<typename T>
VecAnalyser<T>::VecAnalyser(vector<T*> data) {
    this->data = data; //the vector
}

template<typename T>
VecAnalyser<T>::~VecAnalyser<T>() {
    delete[] this->data; //maybe more needed
}

template<typename T>
bool VecAnalyser<T>::inRange(int index) {

    if (!(0 <= i <= this->data.size())) {
        return false; //index out of range
    }
    return true; //index in range
}

template<typename T>
T VecAnalyser<T>::returnIndex(int i) const {
    string Error = "No Student at given index ";
    Error += std::to_string(i); //converts int to string
    Error.append(". The range of the vector is 0 to ");
    Error.append(this->data.size());
    Error.append(".");

    try{
        if (this->inRange(i)){
            //there is such index
            return (*this->data[i]);
        }
        throw Error;
    }
    catch (string Error) {
        cout<< Error;
    }
}

template<typename T>
void VecAnalyser<T>::swap(int index_1,int index_2){

    string Error = "No Student at given index: ";
    if (!(this->inRange(index_1))) { //index not in range
        Error += std::to_string(index_1); //converts int to string
    }
    if (!((this->inRange(index_1))&&(this->inRange(index_2)))){//index not in range
        Error += string(" and "); //both indexes are out of range
    }
    if (!(this->inRange(index_2))) {//index not in range
        Error += std::to_string(index_2); //converts int to string
    }
    Error += std::to_string(i); //converts int to string
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

template<typename T>
void VecAnalyser<T>::printElement(int index) {
    string Error = "No Student at given index ";
    Error += std::to_string(index); //converts int to string
    Error.append(". The range of the vector is 0 to ");
    Error.append(this->data.size());
    Error.append(".");

    try{
        if (this->inRange(index)){
            //there is such index
            return (*this->data[index]);
        }
        throw Error;
    }
    catch (string Error) {
        cout<< Error;
    }

}