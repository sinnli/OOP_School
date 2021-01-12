//
// Created by liel on 12/01/2021.
//

#ifndef UNTITLED_MANAGER_H
#define UNTITLED_MANAGER_H
#pragma once
#ifndef MANAGER_H
#define MANAGER_H
class Teacher;
class AdministrationPersonal;
class Class;
class Worker;
#include "Teacher.h"
#include "AdministrationPersonal.h"
#include "Class.h"
#include "Worker.h"

class Manager: public virtual AdministrationPersonal, public virtual Teacher {

private:
    static Manager* manager;
    Manager(string frt_name, string lst_name, string office_plc, double mng_exp_time, vector<string> study_sbj, int num_subj, double tch_exp_time);


public:
    static Manager* Get_Manager() ;
    double Get_Sallary();
    bool Top_Person();
    void Print_Details();
    virtual ~Manager();

};
#endif


#endif //UNTITLED_MANAGER_H
