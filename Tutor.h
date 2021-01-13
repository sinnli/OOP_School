/* Assignment: 3
Author: Itay Mizikov, ID: 315541615
Author: Liel Sinn, ID: 209195155
 */

#pragma once
#ifndef TUTOR_H
#define TUTOR_H
#include "Pupil.h"
#include "Class.h"
#include "Teacher.h"
#include <vector>

class Tutor : public virtual Teacher {

private :
	 Class* Class_m;

public:
    Tutor(string frt_name, string lst_name, vector<string> study_sbj, int num_subj, double tch_exp_time);
	double Get_Sallary();
	bool Top_Person();
	void Print_Details();
    virtual Class* Get_Class();
    void Set_to_Class(Class* Class);
    void Set_no_class();
    virtual ~Tutor();
};
#endif
