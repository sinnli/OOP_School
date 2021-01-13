/* Assignment: 3
Author: Itay Mizikov, ID: 315541615
Author: Liel Sinn, ID: 209195155
 */
#ifndef UNTITLED_CLASS_H
#define UNTITLED_CLASS_H
#include <vector>
#include <iostream>
using namespace std;


class Pupil;
class Tutor;

class Class {
    char nameOfLayer;
    int numOfClass;
    vector<Pupil*> PoinToStuInClass; //use of composition
    int numStudClass;
    Tutor* educator; //use of conposition
public:
    Class();
    Class(char nameLayer, int numClass,const vector<Pupil*> PointToStud, int numStudInClass, Tutor* educator);
    Class(char nameLayer, int numClass); //just open a new class
    virtual ~Class();
    void addToClass(Pupil* pupil);
    Pupil &operator[]( int i )const; //returns student at given index of Vector
    bool Top_Class();
    int Get_numOfClass();
    char Get_nameOfLayer();
    void Print_Students();
    void Set_Class_details(int numClass, char layerLet, const vector<Pupil*> PointToStud, int numStudInClass, Tutor* educator);
    Tutor* Get_Tutor();
    void Set_Tutor(Tutor* tutor); //and returns the current one
    vector<Pupil*> Get_PointToPupilInClass();
    void Print_Class_avg();


};

#endif //UNTITLED_CLASS_H
