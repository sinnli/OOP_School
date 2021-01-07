//
// Created by liel on 03/01/2021.
//

#include "Layer.h"
#include <vector>
using namespace std;

Layer::Layer() {
    Class* testclass;
    //this->nameLayer = 'a';
    this->classesOfLayerPointer.push_back(testclass);
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