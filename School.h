//
// Created by liel on 03/01/2021.
//

#ifndef UNTITLED_SCHOOL_H
#define UNTITLED_SCHOOL_H

#include <vector>
using namespace std;
class Layer; //declaring the class here and including in cpp file
class Pupil;
class Worker;

class School{
    int numOfLayers;
    vector<Layer*> PointLayers;
    vector<Pupil*> PointPupil;
    vector<Worker*> PointWorker;
    static School* oneSchool;//must be private
    School(); //must be private
protected:
public:
    ~School();
    static int theOneSchool();
    void menu(); //prints out the managment menu of the school
};

#endif //UNTITLED_SCHOOL_H
