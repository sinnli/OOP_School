#ifndef SECRETARY_H
#define SECRETARY_H
#include "AdministrationPersonal.h"
#include "Class.h"
#include "Pupil.h"
#include "Teacher.h"

class Secretary: public AdministrationPersonal{

private:
	int num_of_kids; 

public:
	Secretary();
	Secretary(std::string frt_name, std::string lst_name, string office_plc, double mng_exp_time, int num_of_kids);
	virtual ~Secretary();
	double Get_Sallary();
	bool Top_Person();
	void Print_Details();
};
#endif
