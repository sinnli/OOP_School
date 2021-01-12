#pragma once
#ifndef TUTOR_H
#define TUTOR_H
#include "Pupil.h"
#include "Class.h"
#include "Teacher.h"
#include <vector>

class Tutor : public Teacher {       

private :
	 Class* Class_m;

public:
    Tutor(string frt_name, string lst_name, vector<string> study_sbj, int num_subj, double tch_exp_time, Class* Class);
    // class was created


    Tutor(string frt_name, string lst_name, vector<string> study_sbj, int num_subj, double tch_exp_time);
    // class not created

	double Get_Sallary();
	bool Top_Person();
	void Print_Details();
    void Set_Class_details(int numClass, char layerLet, const vector<Pupil*> PointToStud, int numStudInClass, Tutor* educator);
    Class* Get_Class();
    void Set_to_Class(Class* Class);
    void Set_no_class();
    virtual ~Tutor();
	Class* Get_ClassPointer();
};
#endif
