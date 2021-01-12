//
// Created by liel on 03/01/2021.
//
#include <iostream>
#include "School.h"
#include "Worker.h"
#include "Layer.h"
#include "Pupil.h"
#include "Teacher.h"
#include "Class.h"
#include "Tutor.h"
#include "Secretary.h"
#include "VecAnalyser.h"


using namespace std;

School* School::oneSchool = NULL; //the static pointer
//need for static method ->only one school
School* School::theOneSchool() {
    if (oneSchool==NULL){
        //the school was not created yet
        int numLayer;
        vector<Layer *> layer;
        vector<Pupil *> pupil;
        vector<Worker *> worker;
        oneSchool = new School(numLayer,layer,pupil,worker);
        return oneSchool;
    }
    else { //school already ones inited
        return oneSchool;
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
            Pupil* pnewP = creatingPupil();
            //add new layer if needed
            char layerLet = pnewP->getLayer();
            //returns true if layer exist in vector of layer
            int layerIndex = this->lookForLayer(layerLet);
            if (layerIndex==-1){
                //this layer does not exist yet
                this->newLayerAdd_pupil(pnewP,layerLet);
            }
            else{ //the layer exist
                //add to class
                Class* theClass = this->PointLayers[layerIndex]->getClass(pnewP->getClassnum());
                if (NULL == theClass){  //there is no such class yet
                    //create class
                    this->newClassAdd(pnewP,layerLet);
                }
                else{
                    //add to given class
                    theClass->addToClass(pnewP);
                }
            }
        }
        if (state == 2) {    // add new teacher to school
            Teacher* pnewT = creatingTeacher(); //the creation of teacher
        }
        if (state == 3) { //adds new tutor
            creatingTutor();
        }
        if (state == 4) {          // adds manager

        }
        if (state == 5) { //adds new secretary
            creatingSecretary(); //is also added to workers pointer vector of school
        }
        if (state == 6){//prints person details
            cout<<"All people at school with their details:"<<endl;
            cout<<"The Pupil at the school with their details:"<<endl;
            for(int i = 0;i<this->PointPupil.size();i++){
                this->PointPupil[i]->Print_Details();
            }
            cout<<"The Workers at the school with their details:"<<endl;
            for(int i = 0;i<this->PointWorker.size();i++){
                this->PointWorker[i]->Print_Details();
            }
        }
        if (state == 7){ //prints out standing people
            cout<<"All outstanding people at school:"<<endl;
            cout<<"Top students:"<<endl;
            for (int i = 0;i<this->PointPupil.size();i++){
                if (this->PointPupil[i]->Top_Person()){
                    this->PointPupil[i]->Print_Details();
                }
            }
            cout<<"Top workers:"<<endl;
            for (int i = 0;i<this->PointWorker.size();i++){
                if (this->PointWorker[i]->Top_Person()){
                    this->PointWorker[i]->Print_Details();
                }
            }
        }
        if (state == 8){ //prints out class of tutor
            this->printClassOfTutor();
        }
        if (state == 9){ //prints out highest paid worker
            VecAnalyser<Worker> vecAnObj;
            vecAnObj.SetVector(this->PointWorker);
            vecAnObj.printMax();
        }
        if (state == 10) {                    // exit the menu
            this->~School();
            break;
        }
        if ((0<state)&&(state<11)){
            std::cout << "Error:The Input given was incorrect" << std::endl;
            menu();
        }
    }
}

Pupil* School::creatingPupil(){
    cout<<"Please enter the first name of the student:"<<endl;
    string frs_name;
    cin>>frs_name; //verifying string is needed
    cin.ignore();
    cout<<"Please enter the last name of the student:"<<endl;
    string lst_name;
    cin>>lst_name; //verifying string is needed
    //needs to check if the student already exist

    cin.ignore();
    cout<<"Please enter the layer of the student(can be only one char between 'a' and 'f')."<<endl;
    char letterLayer;
    cin>>letterLayer; //verifying char between 'a' and 'f'.
    cin.ignore();
    cout<<"Please enter number of class(can be only number between 1 and 3)."<<endl;
    int numClass;
    cin>>numClass; //verifiyin required
    cin.ignore();
    cout<<"Please enter the grades of the Student. (After each grade press enter.) \n"
          "To stop please enter any character.\n"
          "All the grades are between 0 and 100."<<endl;
    vector<int> grades;
    int grd;
    while(cin>>grd){ //returns false for characters because grd is int
        //verifying the input first
        grades.push_back(grd);
    }
    Pupil newPupil = Pupil(frs_name,lst_name,letterLayer,numClass,grades);
    Pupil* pnewPupil = &newPupil;
    this->PointPupil.push_back(pnewPupil);//added to Pupil of school
    return pnewPupil;
}

int  School::lookForLayer(char letterLayer) {
    for (int i=0; i<this->PointLayers.size();i++){
        if(this->PointLayers[i]->getLayer()==letterLayer){
            return i;
        }
    }
    return -1;
}

Teacher* School::creatingTeacher() {
    Worker* pw = this->creatingWorker();
    int indexWorker  = this->lookForWorker(pw->getPerson_FirstName(),pw->getPerson_LastName());
    pw = this->workerExistAlready(indexWorker,pw); //checks if worker already exists
    vector<string> study_sbj = this->creatingStudy_Sbj(); //gets at leadt one subject to teach
    Teacher newTeacher = Teacher(pw->getPerson_FirstName(),pw->getPerson_LastName(),study_sbj,study_sbj.size(),pw->Get_Exp_Time());
    Teacher* pnewTeacher = &newTeacher;
    this->PointWorker.push_back(pnewTeacher);
    //add the teacher to Workers of school
    return pnewTeacher;
}
void School::newLayerAdd_pupil(Pupil *pnewP,char layerLet) {
    //creating new Class:
    Class* pnewClass =  this->newClassAdd(pnewP,layerLet);
    //creating new Layer:
    vector<Class *> classesInLayer;
    classesInLayer.push_back(pnewClass); //new class added to new layer
    Layer La = Layer(layerLet, classesInLayer);
    Layer *pLa = &La;
    //add to layerVector of School
    this->PointLayers.push_back(pLa);
    this->numOfLayers += 1;//adding to layers count of school
}
Class* School::newClassAdd(Pupil *pnewP,char layerLet){

    Class theNewClass = Class(layerLet,pnewP->getClassnum());
    Class* ptheNewClass = &theNewClass;
    ptheNewClass->addToClass(pnewP);
    return ptheNewClass;
}

//Tutor(string frt_name, string lst_name, vector<string> study_sbj,
// int num_subj, double tch_exp_time, char layerLet, int numClass);

Tutor* School::creatingTutor() {
    cout<<"In what layer is the new tutor ->you can enter a char between 'a' and 'f':"<<endl;
    char layerLet;
    cin>>layerLet;//verify
    cin.ignore();
    cout<<"In what class number is the new tutor to be added ->you can enter a number beween 1 and 3:"<<endl;
    int classNum;
    cin>>classNum; //verify
    Worker* pw = this->creatingWorker(); //asking for first/last name and exp_time
    int workerIndex = this->lookForWorker(pw->getPerson_FirstName(),pw->getPerson_LastName());
    pw = workerExistAlready(workerIndex,pw); //checkes if worker already exist
    vector<string> study_sbj = this->creatingStudy_Sbj(); //gets at least one subject to teach
    Tutor newTutor = Tutor(pw->getPerson_FirstName(),pw->getPerson_LastName(),
                           study_sbj,study_sbj.size(),pw->Get_Exp_Time(),layerLet,classNum);
    Tutor* pnewTutor = &newTutor;
    //check if there is already a tutor for this class
   int layerIndex = this->lookForLayer();
    if(layerIndex==-1){
        //new layer
    }
    if (layerIndex!=-1){
       //this layer exist
       if(this->PointLayers[layerIndex]->lookForClass(classNum)) {
            //there is a class like this ->there is also  a tutor
            Tutor* oldTutor  = this->PointLayers[layerIndex]->getClass(classNum)->Get_Tutor();
       }
       else{
           //open new class +add to layer vector
       }
       //set tutor
       this->PointLayers[layerIndex]->getClass(classNum)->Set_Tutor(pnewTutor);

    }
    this->PointWorker.push_back(pnewTutor);  //is also added to workers pointer vector of school
    return pnewTutor;
}
Secretary* School::creatingSecretary() {
    cout<<"Please enter the first name of the student:"<<endl;
    string frs_name;
    cin>>frs_name; //verifying string is needed
    cin.ignore();
    cout<<"Please enter the last name of the student:"<<endl;
    string lst_name;
    cin>>lst_name; //verifying string is needed
    //needs to check if the student already exist

    cin.ignore();
    cout<<"Please enter the number of his office place:"<<endl;
    string office_plc;
    cin>>office_plc; //verifying ->maybe take int and convert to string is preferd
    cin.ignore();
    cout<<"Please enter the number of years the secretary is at his job:"<<endl;
    double mng_exp_time;
    cin>>mng_exp_time; //verify
    cin.ignore();
    cout<<"Enter the number of your kids learning at this school:"<<endl;
    int num_of_kids;
    cin>>num_of_kids;//verify
    Secretary sec = Secretary(frs_name,lst_name,office_plc,mng_exp_time,num_of_kids);
    Secretary* psec = &sec;
    //adding to vector of workers
    this->PointWorker.push_back(psec);
    return psec;
}

void School::printClassOfTutor() {
    cout<<"Please enter the first name of tutor of whom the pupil of class are to be printed:"<<endl;
    string frs_name;
    cin>>frs_name; //verifying needed
    cout<<"Please enter the last name of the tutor:"<<endl;
    string lst_name;
    cin>>lst_name; //verify
    //look for tutor in workers vec
    int tutorIndex = this->lookForWorker(frs_name,lst_name);
    //this->PointWorker[tutorIndex]

}
int School::lookForWorker(string frt_name, string lst_name) {
     for (int i=0; i<this->PointWorker.size();i++){
        if ((this->PointWorker[i]->getPerson_FirstName()==frt_name)&&
        (this->PointWorker[i]->getPerson_LastName()==lst_name)){
            return i;
        }
    }
    return -1; //no such index
}
double School::verify_double(double num) {
    std::cin >> num;
    while (std::cin.fail()) {
        std::cout << "Error! Please enter a number(no letters or other characters):" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> num;
    }
    return num;
}
int  School::verify_int(int num) {
    std::cin >> num;
    while (std::cin.fail()) {
        std::cout << "Error! Please enter a number(no letters or other characters):" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> num;
    }
    return num;
}
string School::verify_string(string str) {
    std::cin >> str;
    while (std::cin.fail()) {
        std::cout << "Error! Please enter a number(no letters or other characters):" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> str;
    }
    return str;
}
Worker* creatingWorker(){ //every worker needs to begin with this creation
    cout<<"Please enter the first name of the teacher:"<<endl;
    string frs_name;
    cin>>frs_name; //verifying string is needed
    cin.ignore();
    cout<<"Please enter the last name of the teacher:"<<endl;
    string lst_name;
    cin>>lst_name; //verifying string is needed
    //needs to check if worker already exist
    double exp_time;
    cout<<"Enter the exprience time (in years):"<<endl;
    cin>>exp_time;//verify
    Worker w = Worker(frs_name,lst_name,exp_time);
    Worker *pw = &w;
    return pw;
}
Worker* School::workerExistAlready(int workerIndex,Worker* pw) {
    while (workerIndex == -1){
        cout<<"Try again this worker already exist."<<endl;
        pw = this->creatingWorker();
        workerIndex = this->lookForWorker(pw->getPerson_FirstName(),pw->getPerson_LastName());
        //checks if this worker exist already
    }
    return pw;
}
vector<string> School::creatingStudy_Sbj() {
    cout<<"Please enter in the subject the Teacher is teaching(at least one):\n"
          "Finish by entering: end "<<endl;
    vector<string> study_sbj;
    string subj;
    while (cin>>subj){
        if(subj == "end") {
            break;
        }
        else{
            study_sbj.push_back(subj);
        }
    }//check a least one subj
    if(study_sbj.empty()){
        this->creatingStudy_Sbj(); //new chance to enter subjects of teacher
    }
    return study_sbj;
}



//for turor creation good
//ask the user to add Teacher as educator(Tutor)
// Worker *w = this->creatingWorker();
//int indexWorker  = this->lookForWorker(w->getPerson_FirstName(),w->getPerson_LastName());
//w = this->workerExistAlready(indexWorker,w); //checks if worker already exists
// vector<string> study_sbj = this->creatingStudy_Sbj();
// Tutor tutorOfNewClass = Tutor(w->getPerson_FirstName(),w->getPerson_LastName(),
//    study_sbj,study_sbj.size(),w->Get_Exp_Time(),layerLet,
//   pnewP->getClassnum()); //new tutor created (ther is new in the ctor)
//Tutor* ptutorOfNewClass = &tutorOfNewClass;



//for old tutor
//using the ctor of tutor for existing class
// Class* theExistingClass = this->PointLayers[layerIndex]->getClass(classNum);
//change current turor to teacher
//Tutor* existingTutor = theExistingClass->Get_Tutor();
//Teacher convTutorToTeacher = Teacher(existingTutor->getPerson_FirstName(),existingTutor->getPerson_LastName(),
// existingTutor->Get_sturdy_sbj(),existingTutor->Get_sturdy_sbj().size(),
// existingTutor->Get_Exp_Time());
//Teacher* pTe = &convTutorToTeacher;
//needs to be deleted and

int main(){
    string F_n = "Israel",f2 = "hello",f3="alisa",f4 = "Inona",f6 = "Smith";
    string L_n = "Levi";
    string F_n1 = "Israeli";
    string L_n1 = "Levli";
    string sub[15] = {"a"};
    vector<int> gra = {100,75,90,100},gr1 = {56,100,100,100};
    vector<Pupil*> Ppupil;
    School *s = s->theOneSchool();
    s->menu();
    return 0;
}