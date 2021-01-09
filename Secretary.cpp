#include "Secretary.h"
#include <vector>

Secretary::Secretary():AdministrationPersonal() {
	this->num_of_kids = 0;
}


Secretary::Secretary(std::string frt_name, std::string lst_name, string office_plc, double mng_exp_time,
	int num_of_kids) : AdministrationPersonal(frt_name, lst_name, office_plc, mng_exp_time) {

	this->num_of_kids = num_of_kids;
}

Secretary::~Secretary() {
	std::cout << "Deleted secretary" << endl;
}


double Secretary::Get_Sallary() {
	return (this->basis + (200 * this->num_of_kids));
}

bool Secretary::Top_Person() {
	
	if (this->Get_Exp_Time() > 10) {
		return true; 
	}
	return false; 
}

void Secretary::Print_Details() {

	std::cout << "This person profession is: " << "Secretary" << endl;      
	std::cout << "Full name: " << this->getPerson_FirstName() << " " << this->getPerson_LastName() << endl;
	std::cout << "Secretary office: " << this->Get_office_plc() << endl;
	std::cout << "Secretary's sallary: " << this->Get_Sallary() << endl;
	std::cout << "Number of kids in school: " << this->num_of_kids << endl;
	std::cout << "Secretary's expreince: " << this->Get_Exp_Time() << endl;
	std::cout << "Top Secretary: ";
	if (this->top_person == true) {
		std::cout << "Yes !! " << endl;
	}
	else {
		std::cout << " No " << endl;
	}
}

int main() {
	
	string F_n = "Israel", f2 = "hello", f3 = "alisa", f4 = "Inona", f6 = "Smith";
	string L_n = "Levi";
	string F_n1 = "Israeli";
	string L_n1 = "Levli";
	vector <string> subj = { "math","biology" };
	vector<int> gra = { 100,75,90,100 }, gr1 = { 56,100,100,100 };
	vector<Pupil*> Ppupil;
	Teacher t1(F_n1, L_n1, subj, 2, 12.30);
	Teacher* Pt1;
	Pt1 = &t1;
	Class C1('a', 0, Ppupil, 30, Pt1);
	Pupil p2 = Pupil(f2, f3, 'a', 1, gr1, C1);
	Pupil p1 = Pupil(F_n, L_n, 'a', 1, gra, C1);
	//vector <string> students = { "ron", "bob", "lily" };
	t1.Print_Details();
	


}

//Pupil::Pupil(string frt_name, string lst_name, char letterLayer, int numClass, vector<int> Grades, Class pupilClass) :
//Person(frt_name, lst_name)

//Class::Class(char nameLayer, int numClass, const vector<Pupil*> PointToStud, int numStudInClass,Teacher* educator) {

//Teacher::Teacher(std::string frt_name, std::string lst_name, vector<string> study_sbj, int num_subj,
//double tch_exp_time) : Worker(frt_name, lst_name, tch_exp_time){

//Worker::Worker(string frt_name, string lst_name, double exp_time):Person(frt_name, lst_name) {
