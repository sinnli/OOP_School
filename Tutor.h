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
	Tutor(Teacher *teacher,char layerLet,int numClass);
	double Get_Sallary();
	bool Top_Person();
	void Print_Details();
	~Tutor();
	Class* Get_ClassPointer();
};
#endif
