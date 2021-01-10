#include "Tutor.h"


Tutor::Tutor(string frt_name, string lst_name, vector<string> study_sbj, int num_subj, double tch_exp_time, Class* Class):
	Teacher(frt_name, lst_name, study_sbj, num_subj, tch_exp_time){

	this->Class_m = Class;
}
Tutor::Tutor(Teacher *teacher,char layerLet,int numClass) {
    //if class in layer exist ..just add class
    //layer.look for classNUM
    //else create new class
    //add to the layer.point to class vector ->not sure about that

    //this->Class_m = Class
}

double Tutor::Get_Sallary() {
	return (this->Get_Sallary()+1000);
}

bool Tutor::Top_Person() {
	
	if (this->Class_m->Top_Class() == true) {
		return true;
	}
	return false;
}

void Tutor::Print_Details() {

	Teacher::Print_Details();    // !check if its changes the salary from teacher to tutor! / 
	std::cout << "Tutor's class: " << this->Class_m->Get_nameOfLayer() << "-" << this->Class_m->Get_numOfClass() << endl;
	this->Class_m->Print_Students();      // prints tutor's students info 
}
Tutor::~Tutor() {
    cout<<"Tutor is deleted"<<endl;
}
Class* Tutor::Get_ClassPointer() {
    return this->Class_m;
}











//Teacher::Teacher(string frt_name, string lst_name, string study_sbj[15], int num_subj, double tch_exp_time) :Worker(frt_name, lst_name, tch_exp_time) {


