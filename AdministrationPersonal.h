#ifndef ADMINISTRATIONPERSONAL_H
#define ADMINISTRATIONPERSONAL_H

#include "Person.h"
#include "Worker.h"
#include <iostream>
#include <string.h>
#include <vector>

class AdministrationPersonal : public Worker{

private:
	string office_plc; 

public:
	AdministrationPersonal();
	AdministrationPersonal(std::string frt_name, std::string lst_name,string office_plc, double mng_exp_time);
	~AdministrationPersonal();
	virtual double Get_Sallary() = 0;     // pure virtual function        // already appears in Worker class 
	virtual bool Top_Person() = 0;        // pure virtual function        // already appears in Worker class 
	virtual void Print_Details() = 0;     // pure virtual function        // already appears in Worker class 
	string Get_office_plc();
};
#endif
