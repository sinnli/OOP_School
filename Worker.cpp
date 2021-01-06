#include "Worker.h"


//Worker::Worker(): exp_time(-1){}        // defualt Ctor 


Worker::Worker(string frt_name, string lst_name, double exp_time):Person(frt_name, lst_name) {     // first Ctor

	this->exp_time = exp_time;
	this->basis = 25; 
}
Worker::~Worker() {
    cout<<"deleting Worker"<<endl;
}

double Worker::Get_Exp_Time() {
	return this->exp_time;
}







