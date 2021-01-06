#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

#ifndef PERSON_H
#define PERSON_H


class Person
{
private:

protected:
	string first_name;
	string last_name;
	bool top_person;

public:
	//Person();
	Person(const string frt_name, const string lst_name);
	Person(const Person& obj);
	string getPerson_FirstName() const;
	string getPerson_LastName() const;
	void Set_Top_Person();
	virtual void Print_Details() = 0;
	virtual bool Top_Person() ;
	~Person();

};
#endif
