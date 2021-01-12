//
// Created by liel on 12/01/2021.
//

#include "Manager.h"
Manager::Manager(string frt_name, string lst_name, string office_plc,double mng_exp_time,
                 vector<string> study_sbj, int num_subj, double tch_exp_time)
{
    this->AdministrationPersonal::first_name = frt_name;
    this->Teacher::first_name = frt_name;
    this->AdministrationPersonal::last_name = lst_name;
    this->Teacher::last_name = lst_name;
    this->AdministrationPersonal::Set_office_plc(office_plc);
    this->Worker::Set_MngExp_Time(mng_exp_time);
    this->Worker::Set_TchExp_Time(tch_exp_time);
    this->num_subj = num_subj;
    this->study_sbj = study_sbj;

}

Manager* Manager::Get_Manager() {
    if (manager == NULL) {
        //manager = new Manager;
        std::cout << "there is no active manager" << endl;
    }
    else{
        std::cout << "School already has a manager" << endl;
        return manager;
    }
}

double Manager::Get_Sallary() {

    double tch_sallary = Teacher::Get_Sallary();
    if (this->Worker::Get_TchExp_Time() == 0) {
        tch_sallary = 0;
    }
    double mng_sallary = (2 * this->Worker::basis) + (500 * this->Worker::Get_MngExp_Time());
    return (tch_sallary + mng_sallary);

}

bool Manager::Top_Person() {

    if (this->Worker::Get_MngExp_Time() > 3) {
        return true;
    }
    return false;
}

void Manager::Print_Details() {

    std::cout << "Manager's full name: " << this->Worker::getPerson_FirstName() << " " << this->Worker::getPerson_LastName() << endl;
    this->Print_Subjects();
    std::cout << "Manager's sallary: " << this->Get_Sallary() << endl;
    std::cout << "Manager's managment expreince: " << this->Worker::Get_MngExp_Time() << endl;

    if (this->Worker::Get_TchExp_Time() != 0) {
        std::cout << "Manager's teaching expreince: " << this->Worker::Get_TchExp_Time() << endl;
    }

    std::cout << "Top Manager: ";
    if (this->Top_Person() == true) {
        std::cout << "Yes !! " << endl;
    }
    else {
        std::cout << " No " << endl;
    }

}

