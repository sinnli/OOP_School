/* Assignment: 3
Author: Itay Mizikov, ID: 315541615
Author: Liel Sinn, ID: 209195155
 */



#include "Secretary.h"


Secretary::Secretary(std::string frt_name, std::string lst_name, string office_plc, double mng_exp_time,
	int num_of_kids) : AdministrationPersonal(frt_name, lst_name, office_plc, mng_exp_time),Worker(frt_name,lst_name,0,mng_exp_time) {

	this->num_of_kids = num_of_kids;
}

Secretary::~Secretary() {
	std::cout << "Deleted secretary" << endl;
}


double Secretary::Get_Sallary() {
	return (this->basis + (200 * this->num_of_kids));
}

bool Secretary::Top_Person() {
	
	if (this->Get_MngExp_Time() > 10) {
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
	std::cout << "Secretary's expreince: " << this->Get_MngExp_Time() << endl;
	std::cout << "Top Secretary: ";
	if (this->top_person == true) {
		std::cout << "Yes !! " << endl;
	}
	else {
		std::cout << " No " << endl;
	}
}
