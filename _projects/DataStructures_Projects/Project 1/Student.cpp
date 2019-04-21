//Student.hpp
//Project 1

#ifndef student_cpp
#define student_cpp

#include <stdio.h>
#include "ClassList.cpp"
#endif /* Student_cpp */
class student{
public:
    student();
    student(string,string);
    void setfname(string);
    void setlname(string);
    string getfname();
    string getlastname();
    student* getnext();
    void setnext(student*);
    classlist* getclasslist();
    void getinfo();
    void setcorce(classes*);
private:
    string fname;
    string lname;
    classlist* list;
    student* next;
};
student::student(){
    fname =""; 
    lname="";
    next = NULL;
    list = new classlist;
}
student::student(string fn,string ln){
    fname = fn;
    lname = ln;
    next = NULL;
    list = new classlist;
}
void student::setfname(string fn){
    fname = fn;
}
void student::setlname(string ln ){
    lname = ln;
}
string student::getfname(){
    return fname;
}
string student::getlastname(){
    return lname;
}
student* student::getnext(){
    return next;
}
void student::setnext(student* gg){
    next = gg;
}
classlist* student::getclasslist(){
    return list;
}
void student::getinfo(){
    cout<<"Name: "<<fname <<" "<<lname
    <<endl;
    cout<<"This student is taking"<<endl;
    list->displayclasses();
}
