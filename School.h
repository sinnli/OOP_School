//
// Created by liel on 03/01/2021.
//

#ifndef UNTITLED_SCHOOL_H
#define UNTITLED_SCHOOL_H

#include <vector>
#include <iostream>
using namespace std;
class Layer; //declaring the class here and including in cpp file
class Pupil;
class Worker;
class Layer;
class Teacher;
class School{
    int numOfLayers;
    vector<Layer*> PointLayers;
    vector<Pupil*> PointPupil;
    vector<Worker*> PointWorker;
    static School* oneSchool;//must be private
    School(int numLayer, vector<Layer*> layer, vector<Pupil*> pupil,vector<Worker*> worker); //must be private
    School();
    School(const School&);//private copy ctor
    School& operator=(const School&);//private assigment operator
protected:
public:
    ~School();
    static School& theOneSchool(); //single School is being created
    void menu(); //prints out the management menu of the school
    Pupil creatingPupil();
    bool lookForLayer(char letterLayer);
    Teacher creatingTeacher();
};

#endif //UNTITLED_SCHOOL_H
