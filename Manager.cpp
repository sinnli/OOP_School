/* Assignment: 3
Author: Itay Mizikov, ID: 315541615
Author: Liel Sinn, ID: 209195155
 */

#include "Manager.h"
#include "Teacher.h"
#include "AdministrationPersonal.h"
#include "Class.h"
#include "Worker.h"


Manager* Manager::manager = NULL;
Manager::Manager(string frt_name, string lst_name, string office_plc,double mng_exp_time,
                 vector<string> study_sbj, int num_subj, double tch_exp_time):
                 Worker(frt_name,lst_name,tch_exp_time,mng_exp_time),
                 Teacher(frt_name,lst_name,study_sbj,num_subj,tch_exp_time)
{
    this->AdministrationPersonal::first_name = frt_name;
    this->Teacher::first_name = frt_name;
    this->AdministrationPersonal::last_name = lst_name;
    this->Teacher::last_name = lst_name;
    this->AdministrationPersonal::Set_office_plc(office_plc);
    this->Set_MngExp_Time(mng_exp_time);
    this->Worker::Set_TchExp_Time(tch_exp_time);
    this->num_subj = num_subj;
    this->study_sbj = study_sbj;

}
Manager::~Manager() noexcept {
    delete manager;
    cout<<"Manger delete"<<endl;
}

Manager* Manager::Get_Manager() {
    if (manager == NULL) {
        //manager was not created yet
        //std::cout << "there is no manager" << endl;
        string frt_name = "first_name";
        string lst_name = "last_name";
        string office_plc = "somewhere";
        double mng_exp_time = 0;
        double tch_exp_time = 0;
        vector<string> study_sbj;//empty
        int num_subj = 0;
        manager = new Manager(frt_name,lst_name,office_plc,mng_exp_time,
                study_sbj, num_subj,tch_exp_time);
        return manager;
    }
    else{
        //std::cout << "School already has a manager" << endl;
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

void Manager::Set_Details(string frt_name, string lst_name, string office_plc, double mng_exp_time,
                          vector<string> study_sbj, double tch_exp_time) {
    this->num_subj = study_sbj.size();
    this->tch_exp_time = tch_exp_time;
    this->mng_exp_time = mng_exp_time;
    this->first_name = frt_name;
    this->last_name = lst_name;
    this->office_plc = office_plc;
    this->study_sbj = study_sbj;
}



