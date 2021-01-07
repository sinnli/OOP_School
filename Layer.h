//
// Created by liel on 03/01/2021.
//

#ifndef UNTITLED_LAYER_H
#define UNTITLED_LAYER_H

#include <vector>
//#include <memory>
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
};

#endif //UNTITLED_LAYER_H
