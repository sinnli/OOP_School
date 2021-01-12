#include "AdministrationPersonal.h"

AdministrationPersonal::AdministrationPersonal():Worker() {
    this->office_plc = "00000";
}


AdministrationPersonal::AdministrationPersonal(std::string frt_name, std::string lst_name, string office_plc,
                                               double mng_exp_time) : Worker(frt_name, lst_name,0, mng_exp_time)
{
    this->office_plc = office_plc;
}


AdministrationPersonal::~AdministrationPersonal() {
    std::cout << "Deleted administration personal" << endl;
}

string AdministrationPersonal::Get_office_plc() {
    return this->office_plc;
}


void AdministrationPersonal::Set_office_plc(string office_plc) {
    this->office_plc = office_plc;
}