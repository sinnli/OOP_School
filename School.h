//
// Created by liel on 03/01/2021.
//

#ifndef UNTITLED_SCHOOL_H
#define UNTITLED_SCHOOL_H

#include <vector>


using namespace std;
class Layer; //forward declaration
class Pupil;
class Worker;
class Layer;
class Teacher;
class Class;
class Tutor;
class Secretary;
template <typename T>
class VecAnalyser;

class School{
    int numOfLayers = 0;
    int numOFManager = 0;
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
    static School* theOneSchool(); //single School is being created
    void menu(); //prints out the management menu of the school
    int lookForLayer(char letterLayer);
    int lookForWorker(string frt_name,string lst_name);
    void newLayerAdd_pupil(Pupil* pnewP, char layerLet);
    Class* newClassAdd(Pupil *pnewP,char layerLet);
    Tutor* creatingTutor();
    Pupil* creatingPupil();
    Teacher* creatingTeacher();
    Secretary* creatingSecretary();
    void printClassOfTutor();
    double verify_double(double num);
    int verify_int(int num);
    string verify_string(string str);
    Worker* creatingWorker();
    Worker* workerExistAlready(int workerIndex,Worker* pw);
    vector<string> creatingStudy_Sbj();


    //creatingManager(); //use int num of Manager

};

#endif //UNTITLED_SCHOOL_H
