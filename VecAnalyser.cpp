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
bool VecAnalyser<T>::outOfRange(int index) {
    string Error;
    Error.append("No Student at given index ")
    Error.append(to_string(index)); //converst int to string
    Error.append(". The range of the vector is 0 to ");
    Error.append(this->data.size());
    Error.append(".");
    try {
        if (!(0 <= i <= this->data.size())) {
            throw (Error);
        }
        return true;
    }
    catch (string Error) {
        cout << Error << endl; //not sure if string needs to be printed
        return false;
    }
    return false;
}

template<typename T>
T VecAnalyser<T>::returnIndex(int i) const {
    try {
        this->
        }
        else{
            throw (i);
        }
    }
    catch (int  i) {
        cout<< "No Student at given index "<<i<<". The range of the vector is 0 to "<<this->data.size()<<'.'<<endl;
    }
    return (*this->data[i]); //returns Pupil or Worker in given index
}

template<typename T>
void VecAnalyser<T>::swap(int index_1,int index_2){


    T temp;
    temp = this->data[index_1];
    this->data[index_1] = this->data[index_2];
    this->data[index_2] = temp;

}

template<typename T>