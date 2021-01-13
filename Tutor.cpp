/* Assignment: 3
Author: Itay Mizikov, ID: 315541615
Author: Liel Sinn, ID: 209195155
 */


#include "Tutor.h"


Tutor::Tutor(string frt_name, string lst_name, vector<string> study_sbj, int num_subj, double tch_exp_time):
Teacher(frt_name,lst_name,study_sbj,num_subj,tch_exp_time),Worker(frt_name,lst_name,tch_exp_time,0){
    this->Class_m;//empty
}



Class* Tutor::Get_Class() {
    return this->Class_m;
}

void Tutor::Set_to_Class(Class* Class) {

    this->Class_m = Class;
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

void Tutor::Set_no_class() {
    this->Class_m = NULL;
}










//Teacher::Teacher(string frt_name, string lst_name, string study_sbj[15], int num_subj, double tch_exp_time) :Worker(frt_name, lst_name, tch_exp_time) {


