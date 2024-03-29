/* Assignment: 3
Author: Itay Mizikov, ID: 315541615
Author: Liel Sinn, ID: 209195155
 */

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Person
{
private:

protected:
	string first_name;
	string last_name;
	bool top_person;

public:
	Person(const string frt_name, const string lst_name);
	Person(const Person& obj);
	string getPerson_FirstName() const;
	string getPerson_LastName() const;
	void Set_Top_Person();
    void printPeople();
	virtual void Print_Details() = 0;
	virtual bool Top_Person() ;
	virtual double Get_Max();
	virtual ~Person();

};
#endif
