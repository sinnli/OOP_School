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
/*Class Layer&::operator[]( int i )  {
    if (0<=i<=2){
        if((0<=i<= this->classesOfLayerPointer.size())){
            // index is in vector
            return &(this->classesOfLayerPointer[i]); //returns the Class in given index of the array.
        }
    }
    //index in not in vector
    cout<<"No such Class in layer";
    return Class(); //returns default Class ->not sure here
}
 */