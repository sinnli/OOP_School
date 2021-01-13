/* Assignment: 3
Author: Itay Mizikov, ID: 315541615
Author: Liel Sinn, ID: 209195155
 */


#include "Person.h"


Person::Person(const string frt_name, const string lst_name) {       // Ctor to create person 
	
	this->first_name = frt_name;
	this->last_name = lst_name;
	this->top_person = false;
}


Person::Person(const Person& obj) {     // copy Ctor

	this->first_name = obj.first_name;
	this->last_name = obj.last_name;
	this->top_person = obj.top_person;
}

Person::~Person() {      // Dctor
}

string Person::getPerson_FirstName()const {
	return this->first_name;
}

string Person::getPerson_LastName() const {
	return this->last_name;
}


bool Person::Top_Person() {

	if (this->top_person == true) {
		std::cout << "this is a top person !! " << endl;      // not really needed 
		return true;
	}
	else {
		return false;
	}
}

void Person::Set_Top_Person() {
	this->top_person = true;
}

void Person::printPeople() {
    cout<<"First Name:"<<endl;
    cout<<this->first_name<<endl;
    cout<<"Last Name:"<<endl;
    cout<<this->last_name<<endl;
}

void Person::Get_Max() {
    return;
}





