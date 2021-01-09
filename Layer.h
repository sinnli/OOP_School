//
// Created by liel on 03/01/2021.
//

#ifndef UNTITLED_LAYER_H
#define UNTITLED_LAYER_H

#include <vector>
#include <iostream>
using namespace std;

class Class;

class Layer{
    char nameLayer;
    vector<Class*> classesOfLayerPointer; //use of composition
    //not sure if counts as Class**
    //the vector can at most 3 pointers
public:
    Layer(); //default c-tor
    Layer(char nameLayer,const vector<Class*> classesInLayer);
    ~Layer();
    Class &operator[]( int i )const; //getting class at given index of the vector
    void setLayerVec(Class* PClass); //adds class to layer
    bool lookForClass(Class* PClass); //looks for class in vector by given class*
    bool lookForClass(int classNum); //looks for class in vector by given classnum
    char getLayer();
    Class* getClass(int classNum);
};

#endif //UNTITLED_LAYER_H
