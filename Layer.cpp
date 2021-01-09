//
// Created by liel on 03/01/2021.
//

#include "Layer.h"
#include <vector>
#include "Class.h"
using namespace std;

Layer::Layer() { //default c-tor
    this->nameLayer; //undefined name of Layer
    this->classesOfLayerPointer;//empty Vector
}

Layer::Layer(char nameLayer, const vector<Class *> classesInLayer) {
    if ((nameLayer>'f')||(nameLayer<'a')){
        //no such name for layer possible
        exit(0);
    }
    this->nameLayer = nameLayer;
    this->classesOfLayerPointer = classesInLayer;
}

Class & Layer ::operator[]( int i )const
{
    if ((i >= this->classesOfLayerPointer.size())||(i<0)||(i>2)) {
        //Vector index out of bound, exiting.
        cout<< "No Class at given index."<<endl;
        exit(0);
    }
    return (*this->classesOfLayerPointer[i]); //returns Pupil in given index
}

Layer::~Layer() {
    cout<<"deleting Layer"<<endl;
}

void Layer::setLayerVec(Class *PClass) {
    if (lookForClass(PClass)){
        this->classesOfLayerPointer.push_back(PClass); //adds only if does not exist
    }
    return;
}

bool Layer::lookForClass(Class* PClass){
    for (int i=0; i<this->classesOfLayerPointer.size();i++){
        if(this->classesOfLayerPointer[i]==PClass){
            return true;
        }
    }
    return false;
}
//maybe no need
bool Layer::lookForClass(int classNum){
    for (int i=0; i<this->classesOfLayerPointer.size();i++){
        if(this->classesOfLayerPointer[i]->Get_numOfClass()==classNum){
            return true;
        }
    }
    return false;
}

Class* Layer::getClass(int classNum){
    for (int i=0; i< this->classesOfLayerPointer.size();i++){
        if (this->classesOfLayerPointer[i]->Get_numOfClass()==classNum){
            return this->classesOfLayerPointer[i];
        }
    }
    return  NULL;
}

char Layer::getLayer() {
    return this->nameLayer;
}