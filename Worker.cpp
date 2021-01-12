#include "Worker.h"


Worker::Worker(): exp_time(-1){}        // defualt Ctor


Worker::Worker(string frt_name, string lst_name, double tch_exp_time, double mng_exp_time){ //Worker::Worker(string frt_name, string lst_name, double exp_time):Person(frt_name, lst_name) {     // first Ctor

    this->mng_exp_time = mng_exp_time;
    this->tch_exp_time = tch_exp_time;
    this->basis = 25;
}


Worker::~Worker() {
    cout<<"deleting Worker"<<endl;
}
double Worker::Get_MngExp_Time() {
    return this->mng_exp_time;
}

double Worker::Get_TchExp_Time() {
    return this->tch_exp_time;
}

double Worker::Get_Sallary(){
    double default_sal = 0;
    return default_sal;
}


void Worker::Set_MngExp_Time(double mng_time) {
    this->mng_exp_time = mng_time;
}

void Worker::Set_TchExp_Time(double tch_time) {
    this->tch_exp_time = tch_time;
}


void Worker::Print_Details(){
    return;
}
void Worker::Get_Max() {
    this->Get_Sallary();
    return;
}





