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
#include "Manager.h"

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
    for (int i = 0; i < this->PointLayers.size(); ++i) {
        for (int j = 0;j<this->PointLayers[i]->getClassOfLayer().size();j++){
            delete this->PointLayers[i]->getClassOfLayer()[j];
        }
        delete this->PointLayers[i];
    }
    for (int i = 0; i < this->PointWorker.size(); ++i) {
        delete this->PointWorker[i];
    }
    for (int i = 0; i < this->PointPupil.size(); ++i) {
        delete this->PointPupil[i];
    }
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
            char layerLet = pnewP->getLayer();  //returns true if layer exist in vector of layer
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
                    this->newClassAdd_pupil(pnewP,layerLet);
                }
                else{
                    //add to given class
                    theClass->addToClass(pnewP);
                }
            }
        }
        if (state == 2) {    // add new teacher to school
            this->creatingTeacher(); //the creation of teacher
        }
        if (state == 3) { //adds new tutor
            this->creatingTutor();
        }
        if (state == 4) {          // adds manager
            if(this->numOFManager == 0){
                this->creatingManager();
            }
            else{
                cout<<"Error! You can add only a single manger."<<endl;
            }
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
        if ((state<1)||(state>10)){
            std::cout << "Error:The Input given was incorrect" << std::endl;
        }
        menu();
    }
}

Pupil* School::creatingPupil(){
    cout<<"Please enter the first name of the student:"<<endl;
    string frs_name ;
    cin>>frs_name;
    while (cin.fail()) {
        cout << "Error! Please enter a string:" << std::endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> frs_name;
    }
    cout<<"Please enter the last name of the student:"<<endl;
    string lst_name ;
    cin>>lst_name;
    while (cin.fail()) {
        cout << "Error! Please enter a string:" << std::endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> lst_name;
    }
    cout<<"Please enter the layer of the student(can be only one char between 'a' and 'f')."<<endl;
    char letterLayer = this->verify_layLetter(letterLayer); //verifying getting a char between 'a' and 'f'.
    cout<<"Please enter number of class(can be only number between 1 and 3)."<<endl;
    int numClass = this->verify_classNum(numClass);
    cout<<"Please enter the grades of the Student. (After each grade press enter.) \n"
          "To stop please enter 101.\n"
          "All the grades are between 0 and 100."<<endl;
    vector<int> grades;
    int grd;

    while (cin>>grd) {
        while ((cin.fail()) || (grd < 0) || (grd > 101)) { //returns false for characters because grd is int
            cout << "Error! Please enter a number between 0 and 100:" << std::endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> grd;
            //verifying the input first
        }
        if (grd == 101) {
            break;
        }
        grades.push_back(grd);
    }
    Pupil* newPupil = new Pupil(frs_name,lst_name,letterLayer,numClass,grades); //pupil created
    //checks if there is a person like this existing in school
    int workerIndex = this->lookForWorker(frs_name,lst_name);
    int pupilIndex = this->lookForPupil(frs_name,lst_name);
    while ((workerIndex!=-1)||(pupilIndex!=-1)){
        cout<<"Error! This worker exists already.Try again:"<<endl;
        this->creatingPupil();
    }
    this->PointPupil.push_back(newPupil);//added to Pupil of school
    return newPupil;
}

Pupil* School::pupilExistAlready(int pupilIndex,Pupil* pPupil) {
    while (pupilIndex == -1){
        cout<<"Try again this pupil already exist."<<endl;
        pPupil = this->creatingPupil();
        pupilIndex = this->lookForWorker(pPupil->getPerson_FirstName(),pPupil->getPerson_LastName());
        //checks if this pupil exist already
    }
    return pPupil;
}

int  School::lookForLayer(char letterLayer) {
    for (int i=0; i<this->PointLayers.size();i++){
        if(this->PointLayers[i]->getLayer()==letterLayer){
            return i;
        }
    }
    return -1;
}

int School::lookForPupil(string frs_name, string lst_name) {
    for (int i=0; i<this->PointPupil.size();i++){
        if ((this->PointPupil[i]->getPerson_FirstName()==frs_name)&&
            (this->PointPupil[i]->getPerson_LastName()==lst_name)){
            return i;
        }
    }
    return -1; //no such index
}

Teacher* School::creatingTeacher() {
    cout<<"Please enter the first name of the teacher:"<<endl;
    string frs_name;
    cin >> frs_name;
    while (cin.fail()) {
        cout << "Error! Please enter a string:" << std::endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> frs_name;
    }
    cout<<"Please enter the last name of the teacher:"<<endl;
    string lst_name;
    cin>> lst_name;
    while (cin.fail()) {
        cout << "Error! Please enter a string:" << std::endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> lst_name;
    }
    int workerIndex = this->lookForWorker(frs_name,lst_name);
    int pupilIndex = this->lookForPupil(frs_name,lst_name);
    while ((workerIndex!=-1)||(pupilIndex!=-1)){
        cout<<"Error! This worker exists already.Try again:"<<endl;
        this->creatingTeacher();
    }
    cout<<"Please enter the of years of experience as Teacher:"<<endl;
    double tchExp_time;
    std::cin >> tchExp_time;
    while (std::cin.fail()) {
        std::cout << "Error! Please enter a number(no letters or other characters):" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> tchExp_time;
    }
    vector<string> study_sbj = this->creatingStudy_Sbj(); //gets at leadt one subject to teach
    Teacher* newTeacher = new Teacher(frs_name,lst_name,
                                      study_sbj,study_sbj.size(),tchExp_time);

    this->PointWorker.push_back(newTeacher);
    //add the teacher to Workers of school
     return newTeacher;
}

void School::newLayerAdd_pupil(Pupil *pnewP,char layerLet) {
    //creating new Class:
    Class* pnewClass =  this->newClassAdd_pupil(pnewP,layerLet);
    //creating new Layer:
    vector<Class *> classesInLayer;
    classesInLayer.push_back(pnewClass); //new class added to new layer
    Layer* La = new Layer(layerLet, classesInLayer);
    //add to layerVector of School
    this->PointLayers.push_back(La);
    this->numOfLayers += 1;//adding to layers count of school
}
void School::newLayerAdd_tutor(Tutor *pnewT, char layerLet,int classNum) {
    //creating new Class:
    Class* pnewClass =  this->newClassAdd_tutor(pnewT,layerLet,classNum);
    //creating new Layer:
    vector<Class *> classesInLayer;
    classesInLayer.push_back(pnewClass); //new class added to new layer
    Layer* La = new Layer(layerLet, classesInLayer);
    //add to layerVector of School
    this->PointLayers.push_back(La);
    this->numOfLayers += 1;//adding to layers count of school
}
Class* School::newClassAdd_pupil(Pupil *pnewP,char layerLet){
    Class* theNewClass = new Class(layerLet,pnewP->getClassnum());
    theNewClass->addToClass(pnewP);//add student to new class
    return theNewClass;
}
Class* School::newClassAdd_tutor(Tutor *pnewT, char layerlet,int classNum) {
    Class* theNewClass = new Class(layerlet,classNum);
    theNewClass->Set_Tutor(pnewT);
    pnewT->Set_to_Class(theNewClass);
    return theNewClass;
}

Tutor* School::creatingTutor() {
    cout<<"In what layer is the new tutor ->you can enter a char between 'a' and 'f':"<<endl;
    char layerLet = verify_layLetter(layerLet);
    cout<<"In what class number is the new tutor to be added ->you can enter a number beween 1 and 3:"<<endl;
    int classNum = verify_classNum(classNum);
    cout<<"Please enter the first name of the tutor:"<<endl;
    string frs_name;
    cin >> frs_name;
    while (cin.fail()) {
        cout << "Error! Please enter a string:" << std::endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> frs_name;
    }
    cout<<"Please enter the last name of the tutor:"<<endl;
    string lst_name;
    cin >> lst_name;
    while (cin.fail()) {
        cout << "Error! Please enter a string:" << std::endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> frs_name;
    }
    cout<<"Please enter the of years of experience as tutor:"<<endl;
    double tchExp_time = verify_double(tchExp_time);
    //checks if there is a person like this existing in school
    int workerIndex = this->lookForWorker(frs_name,lst_name);
    int pupilIndex = this->lookForPupil(frs_name,lst_name);
    while ((workerIndex!=-1)||(pupilIndex!=-1)){
        cout<<"Error! This worker exists already.Try again:"<<endl;
        this->creatingTutor();
    }
    vector<string> study_sbj = this->creatingStudy_Sbj(); //gets at least one subject to teach
    Tutor* newTutor = new Tutor(frs_name,lst_name,
                           study_sbj,study_sbj.size(),tchExp_time);
    //check if there is already a tutor for this class
   int layerIndex = this->lookForLayer(layerLet);
    if(layerIndex==-1){
        //new layer
    }
    if (layerIndex!=-1){
       //this layer exist
       if(this->PointLayers[layerIndex]->lookForClass(classNum)) {
            //there is a class like this ->there may be also  a tutor ->checkkkeee
            Tutor* oldTutor  = this->PointLayers[layerIndex]->getClass(classNum)->Get_Tutor();
            oldTutor->Set_no_class(); //now a tutor of no class
           //set tutor
           this->PointLayers[layerIndex]->getClass(classNum)->Set_Tutor(newTutor); //the tutor was set in class
           newTutor->Set_to_Class(this->PointLayers[layerIndex]->getClass(classNum)); //the tutor has a class
       }
       else{
           //open new class +add to layer vector
           this->newClassAdd_tutor(newTutor,layerLet,classNum); //only new class and adding of tutor to class
       }

    }
    else{
        //there is no layer ->also no class
        this->newLayerAdd_tutor(newTutor,layerLet,classNum);
    }
    this->PointWorker.push_back(newTutor);  //is also added to workers pointer vector of school
    return newTutor;
}
Manager* School::creatingManager() {
    this->numOFManager = 1; //only a single manager can be created
    Manager *m = m->Get_Manager();

    cout<<"Please enter the first name of the secretary:"<<endl;
    string frs_name;
    cin >> frs_name;
    while (cin.fail()) {
        cout << "Error! Please enter a string:" << std::endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> frs_name;
    }
    cout<<"Please enter the last name of the secretary:"<<endl;
    string lst_name;
    cin >> lst_name;
    while (cin.fail()) {
        cout << "Error! Please enter a string:" << std::endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> lst_name;
    }
    //checks if there is a person like this existing in school
    int workerIndex = this->lookForWorker(frs_name,lst_name);
    int pupilIndex = this->lookForPupil(frs_name,lst_name);
    while ((workerIndex!=-1)||(pupilIndex!=-1)){
        cout<<"Error! This worker exists already.Try again:"<<endl;
        this->creatingManager();
    }
    cout<<"Please enter the number of his office place:"<<endl;
    int  Noffice_plc = verify_int(Noffice_plc);
    string office_plc = to_string(Noffice_plc);
    cout<<"Please enter the number of years of experience in administration:"<<endl;
    double mng_exp_time = verify_double(mng_exp_time);
    cout<<"Please enter the number of years of experience in teaching:"<<endl;
    double tch_exp_time = verify_double(tch_exp_time);
    vector<string> study_sbj = this->creatingStudy_Sbj(); //gets at least one subject to teach
    //adding to vector of worker
    this->PointWorker.push_back(m);
    m->Set_Details(frs_name,lst_name,office_plc,mng_exp_time,study_sbj,tch_exp_time);
    return m;
}

Secretary* School::creatingSecretary() {
    cout<<"Please enter the first name of the secretary:"<<endl;
    string frs_name;
    cin >> frs_name;
    while (cin.fail()) {
        cout << "Error! Please enter a string:" << std::endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> frs_name;
    }
    cout<<"Please enter the last name of the secretary:"<<endl;
    string lst_name;
    cin >> lst_name;
    while (cin.fail()) {
        cout << "Error! Please enter a string:" << std::endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> lst_name;
    }
    //checks if there is a person like this existing in school
    int workerIndex = this->lookForWorker(frs_name,lst_name);
    int pupilIndex = this->lookForPupil(frs_name,lst_name);
    while ((workerIndex!=-1)||(pupilIndex!=-1)){
        cout<<"Error! This worker exists already.Try again:"<<endl;
        this->creatingSecretary();
    }
    cout<<"Please enter the number of his office place:"<<endl;
    int  Noffice_plc = verify_int(Noffice_plc);
    string office_plc = to_string(Noffice_plc);
    cout<<"Please enter the number of years the secretary is at his job:"<<endl;
    double mng_exp_time = verify_double(mng_exp_time);
    cout<<"Enter the number of your kids learning at this school:"<<endl;
    int num_of_kids = verify_int(num_of_kids);
    Secretary* sec = new Secretary(frs_name,lst_name,office_plc,mng_exp_time,num_of_kids);
    //adding to vector of workers
    this->PointWorker.push_back(sec);
    return sec;
}

void School::printClassOfTutor() {
    cout<<"Please enter the first name of tutor of whom the pupil of class are to be printed:"<<endl;
    string frs_name = verify_string(frs_name);
    cout<<"Please enter the last name of the tutor:"<<endl;
    string lst_name = verify_string(lst_name);
    //look for tutor in workers vec +checks if there is a person like this existing in school
    int workerIndex = this->lookForWorker(frs_name,lst_name);
    while ((workerIndex ==-1)){
        cout<<"Error! There is no tutor with this name.\n"
              "Try again:"<<endl;
        this->printClassOfTutor();
    }
    cout<<"The class of the tutor is in class number: "<< this->PointWorker[workerIndex]->Get_Class()->Get_numOfClass()
    <<"\n and the class is in layer is: "<<this->PointWorker[workerIndex]->Get_Class()->Get_nameOfLayer()<<endl;
    cout<<"The class average is:"<<endl;
    //here class average
    cout<<"The pupils in class are:"<<endl;
    vector<Pupil*> puplOfClass = this->PointWorker[workerIndex]->Get_Class()->Get_PointToPupilInClass();
    for (int i = 0; i < puplOfClass.size(); ++i) {
        puplOfClass[i]->Print_Details(); //printing each pupil of class with its details
    }
   cout<<"The outstanding pupils in class are:"<<endl;
    for (int i = 0; i < puplOfClass.size(); ++i) {
        if (puplOfClass[i]->Top_Person()==true){
            puplOfClass[i]->Print_Details(); //printing each pupil of class with its details
            //with or without details ?
        }
    }
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

int School::verify_classNum(int classNum) {
    std::cin >> classNum;
    while ((std::cin.fail())||(classNum<1)||(classNum>3)) {
        std::cout << "Error! Please enter a number(between 1 and 3):" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> classNum;
    }
    return classNum;
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
char School::verify_layLetter(char layLetter) {
    std::cin >> layLetter;
    while ((std::cin.fail())||(layLetter<'a')||(layLetter>'f')) {
        std::cout << "Error! Please enter a char between 'a' and 'f':" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> layLetter;
    }
    return layLetter;
}
string School::verify_string(string str) {
    cin >> str;
    while (cin.fail()) {
       cout << "Error! Please enter a string:" << std::endl;
       cin.clear();
       cin.ignore(256, '\n');
       cin >> str;
    }
    return  str;
}
Worker* School::creatingWorker(){ //every worker needs to begin with this creation
    cout<<"Please enter the first name of the teacher:"<<endl;
    string frs_name;
    cin >> frs_name;
    while (cin.fail()) {
        cout << "Error! Please enter a string:" << std::endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> frs_name;
    }
    cout<<"Please enter the last name of the teacher:"<<endl;
    string lst_name;
    cin >> lst_name;
    while (cin.fail()) {
        cout << "Error! Please enter a string:" << std::endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> frs_name;
    }
    Worker* w =  new Worker(frs_name,lst_name,0,0);
    return w;
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
        cout<<"You need to enter a least one subject."<<endl;
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