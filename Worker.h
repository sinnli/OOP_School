


#ifndef WORKER_H
#define WORKER_H

#include "Person.h"
#include <string.h>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;


class Worker : public Person {

private :
	double tch_exp_time;
    double mng_exp_time;

protected:
	int basis;

public:
	Worker();
	Worker(string frt_name , string lst_name ,double tch_exp_time,double mng_exp_time);
	Worker(const Worker& obj);
	virtual double Get_Sallary();     // pure virtual function  // returns the sallary of the worker
	virtual void Print_Details();
    double Get_TchExp_Time();
    double Get_MngExp_Time();
	virtual void Get_Max();
    void Set_MngExp_Time(double mng_time);
    void Set_TchExp_Time(double tch_time);
	~Worker();

};

#endif