//
// Created by liel on 03/01/2021.
//

#include "School.h"
#include "Worker.h"
#include "Layer.h"
#include "Pupil.h"
using namespace std;

School* School::oneSchool = NULL; //the static pointer
//need for static method ->only one school
School& School::theOneSchool() {
    if (oneSchool==NULL){
        //the school was not created yet
        int numLayer;
        vector<Layer *> layer;
        vector<Pupil *> pupil;
        vector<Worker *> worker;
        oneSchool = new School(numLayer,layer,pupil,worker);
        return *oneSchool;
    }
    else { //school already ones inited
        return *oneSchool;
    }
}
School::School(int numLayer, vector<Layer *> layer, vector<Pupil *> pupil, vector<Worker *> worker) {
    this->PointLayers = layer;
    this->PointPupil = pupil;
    this->PointWorker = worker;
    this->numOfLayers = numLayer;
}

School::~School() {
    delete oneSchool;
}

void School::menu() {
    int state;
    while (1) {
        std::cout << "To add new pupil to school -> enter 1" << std::endl;
        std::cout << "To add new Teacher to school -> enter 2" << std::endl;
        std::cout << "To add new Tutor to school -> enter 3" << std::endl;
        std::cout << "To add new manager to school -> enter 4" << std::endl;
        std::cout << "To add new secretary to school -> enter 5" << std::endl;
        std::cout << "Print out person details -> enter 6" << std::endl;
        std::cout << "Print out outstanding people -> enter 7" << std::endl;
        std::cout << "Print out tutor's class -> enter 8" << std::endl;
        std::cout << "Highest paid worker -> enter 9 " << std::endl;
        std::cout <<"Exit ->enter 10"<<endl;
        std::cin >> state;
        if (state == 1) {       // add new pupil
            Pupil p;
            //this->PointPupil.push_back(*)
        }
        if (state == 2) {    // delete client from data-base
            char id_arr[10];
            std::cout << "To delete client enter his id number: " << std::endl;
            std::cin >> id_arr;
            String id_to_remove(id_arr);
            Client client_to_remove = data_base.GetClientid(id_to_remove);
            data_base -= client_to_remove;
        }
        if (state == 3) {
            cout << data_base << endl;      // cout << overloading // should print all clients details and the number of clients in data base//

        }
        if (state == 4) {          // return the mtching list for specific client//
            char id_arr[10];
            std::cout << "To find matches for a client enter his id number: " << std::endl;
            std::cin >> id_arr;
            String match_client(id_arr);
            data_base.printsMatchingClient(match_client);
        }
        if (state == 5) {                    // exit the menu
            this->~Menu();       // check if needed
            break;
        }
        if ((state != 3) & (state != 4) & (state != 2) & (state != 1) & (state != 5)){
            std::cout << "Error:The Input given was incorrect" << std::endl;
            mainMenu();
        }
    }
}

Pupil add_pupil(){
    cout<<"Please enter the first name of the student:"<<endl;
    string frs_name;
    cin>>frs_name; //verifying string is needed
    cin.ignore();
    cout<<"Please enter the last name of the student:"<<endl;
    string lst_name;
    cin>>lst_name; //verifying string is needed
    cin.ignore();
    cout<<"Please enter the layer of the student(can be only one char between 'a' and 'f')."<<endl;
    char letterLayer;
    cin>>letterLayer; //verifying char between 'a' and 'f'.
    cin.ignore();
    cout<<"Please enter number of class(can be only number between 1 and 3)."<<endl;
    int numClass;
    cin>>numClass; //verifiyin required
    cin.ignore();
    cout<<"Please enter the grades of the Student. (After each grade press enter. \n"
          "As you finish please enter 101)\n"
          "All the grades are between 0 and 100."<<endl;
    vector<int> grades;
    int grd;



}