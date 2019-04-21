//Classes.cpp
//Project 1


#ifndef Classes_cpp
#define Classes_cpp

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
#endif /* classes_hpp */
class classes{
private:
    string name;
    double grade;
    classes* next;
public:
    classes();
    classes(string,double,classes*);
    string getname();
    double getgrade();
    void setname(string);
    void setgrade(double);
    void setnext(classes*);
    classes* getnext();
    void getinfo();
};
classes::classes(){
    name ="";
    grade = 0;
    next = NULL;
}
classes::classes(string name2,double grade2,classes* CL){
    name = name2;
    grade = grade2;
    next = CL;
}
string classes::getname(){
    return name;
}
double classes::getgrade(){
    return grade;
}
void classes::setname(string inn){
    name = inn;
}
void classes::setgrade(double gg){
    grade = gg;
}
void classes::setnext(classes* ne){
    next = ne;
}
classes* classes::getnext(){
    return next;
}
void classes::getinfo(){
    cout << "Class: "<<name;
    cout<< "\tGrade: "<<grade;
}
