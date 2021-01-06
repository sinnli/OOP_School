#include "Worker.h"


class Teacher: public Worker {

private:
	std::string study_subjects[15];      // top of 15 subjects foe each teacher 
	int num_subj;

public:
	//Teacher();
	Teacher(string frt_name, string lst_name, string study_sbj[15], int num_subj,double tch_exp_time);
	double Get_Sallary();
	bool Top_Person();
	void Print_Subjects();
	void Print_Details();
};

