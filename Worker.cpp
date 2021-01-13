#include "Worker.h"
#include "Class.h"

//Worker::Worker() :tch_exp_time(-1) ,mng_exp_time(-1){}        // defualt Ctor
Worker::Worker(const Worker &obj):Person(obj.first_name, obj.last_name) {
    this->tch_exp_time = obj.tch_exp_time;
    this->mng_exp_time = obj.mng_exp_time;
    this->first_name = obj.first_name;
    this->last_name = obj.last_name;
}

Worker::Worker(string frt_name, string lst_name, double tch_exp_time=0, double mng_exp_time=0):
Person(frt_name, lst_name) {     // first Ctor

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


Class* Worker::Get_Class() {
    return NULL;
}


