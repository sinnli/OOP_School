#include "Person.h"

class Worker : public Person {

private :
	double exp_time;    
	//double tch_exp_time;

protected:
	int basis;

public:
	Worker();
	Worker(string frt_name , string lst_name , double exp_time);
	Worker(const Worker& obj);
	virtual double Get_Sallary() = 0;     // pure virtual function  // returns the sallary of the worker 
	//virtual void Print_Details() = 0;
	double Get_Exp_Time();
	~Worker();

};

