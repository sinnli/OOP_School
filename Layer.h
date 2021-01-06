//
// Created by liel on 03/01/2021.
//

#ifndef UNTITLED_LAYER_H
#define UNTITLED_LAYER_H

#include "Class.h"
#include <vector>
using namespace std;

class Layer{
    char* nameLayer;
    vector<Class*> classesOfLayerPointer; //use of composition
    //not sure if counts as Class**
    //the vector can at most 3 pointers
public:
    Layer();
    ~Layer();
    //copy ctor
    //what is the 4 present of compiler ?
    //operator []
    Class* &operator[]( int i );
};

#endif //UNTITLED_LAYER_H
