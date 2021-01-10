//
// Created by liel on 10/01/2021.
//

#ifndef UNTITLED_VECANALYSER_H
#define UNTITLED_VECANALYSER_H
#include "Person.h"
#include <iostream>
#include <vector>
#include <string.h>
#include "Worker.h"
#include "Pupil.h"
#include <typeinfo>
template<typename T>
class VecAnalyser{
private:
    //or vector of pointer to pupil or tho workers
    vector<T*> data;
public:
    VecAnalyser(vector<T*> data);
    ~VecAnalyser();
    //Pupil &operator[]( int i )const
    T returnIndex(int i)const; //returns object of type T in given index
    //needs to give back error of type string
    //where explained what index was given and what is the range of index
    void swap(int index_1,int index_2);
    //swaps between two indexes with same string error
    void printElement(int index); //prints the object at given index, with string error
    void printAll();//prints the whole vector<>
    void printMax();//prints the objects with max value(for students ->highest average
    //for workers->highest salary)
    bool indexIsManager(int index); //RTTI use typeid(*(vec)[i])
    bool inRange(int index);
    void maxWorker();
    void maxPupil();

};

#endif //UNTITLED_VECANALYSER_H
