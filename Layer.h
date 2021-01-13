/* Assignment: 3
Author: Itay Mizikov, ID: 315541615
Author: Liel Sinn, ID: 209195155
 */

#ifndef UNTITLED_LAYER_H
#define UNTITLED_LAYER_H

#include <vector>
#include <iostream>
using namespace std;

class Class;

class Layer{
    char nameLayer;
    vector<Class*> classesOfLayerPointer; //use of composition
public:
    Layer(); //default c-tor
    Layer(char nameLayer,const vector<Class*> classesInLayer);
    virtual ~Layer();
    Class &operator[]( int i )const; //getting class at given index of the vector
    bool lookForClass(Class* PClass); //looks for class in vector by given class*
    bool lookForClass(int classNum); //looks for class in vector by given classnum
    char getLayer();
    Class* getClass(int classNum);
    vector<Class*> getClassOfLayer();
};

#endif //UNTITLED_LAYER_H
