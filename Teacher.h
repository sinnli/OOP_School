#ifndef UNTITLED_TEACHER_H
#define UNTITLED_TEACHER_H

#include <string.h>
#include <vector>
#include <cstring>
#include "Worker.h"
#include "Person.h"
#include <iostream>


class Worker;
class Person;

class Teacher: public Worker {

private:
    std::string study_subjects[15];      // top of 15 subjects foe each teacher
    int num_subj;

public:
    Teacher();
    Teacher( std::string frt_name, std::string lst_name, string study_sbj[15], int num_subj,double tch_exp_time);
    double Get_Sallary();
    bool Top_Person();
    void Print_Subjects();
    void Print_Details();
    ~Teacher();
};
#endif
