//ClassList.cpp
//Project 1

#ifndef ClassList_cpp
#define ClassList_cpp
#include "Classes.cpp"
#include <stdio.h>

#endif /* classlist_cpp */
class classlist{
private:
    classes* ptrhead;
    classes* ptrend;
    classes* ptr;
public:
    classlist();
    void createxclass(string,double,classes*);
    void displayclasses();
    void createclass(classes*);
    void createclass(classes*,double);
    classes* findclass(string);
};
classlist::classlist(){
    ptrhead = NULL;
    ptrend = NULL;
}
classes* classlist::findclass(string find){
    ptr = ptrhead;
    while(ptr->getnext()!= NULL){
        cout<<ptr->getname();
        if(ptr->getname()==find){
            return ptr;
        }else{
            ptr = ptr->getnext();
        }
    }
    if(ptr->getnext()== NULL){
        cout<<ptr->getname();
        if(ptr->getname()==find){
            return ptr;
        }
    }
    return NULL;
}
void classlist::createclass(classes* cl,double gr){
    classes* temp = new classes;
    temp->setname(cl->getname());
    temp->setgrade(gr);
    temp->setnext(NULL);
    if(ptrhead==NULL)
    {
        ptrhead=temp;
        ptrend=temp;
        temp=NULL;
    }
    else
    {
        ptrend->setnext(temp);
        ptrend=temp;
    }
}
void classlist::createclass(classes* cl){
    classes* temp = new classes;
    temp->setgrade(cl->getgrade());
    temp->setname(cl->getname());
    temp->setnext(NULL);
    if(ptrhead==NULL)
    {
        ptrhead=temp;
        ptrend=temp;
        temp=NULL;
    }
    else
    {
        ptrend->setnext(temp);
        ptrend=temp;
    }
}
void classlist::createxclass(string name, double grade, classes* cl){
    classes *temp= new classes(name,grade,cl);
    temp->setname(name);
    temp->setgrade(grade);
    temp->setnext(NULL);
    if(ptrhead==NULL)
    {
        ptrhead=temp;
        ptrend=temp;
        temp=NULL;
    }
    else
    {
        ptrend->setnext(temp);
        ptrend=temp;
    }
}
void classlist::displayclasses(){
    classes *temp = new classes;
    temp = ptrhead;
    while(temp!=NULL)
    {
        temp->getinfo();
        cout<<endl;
        temp = temp->getnext();
    }
}
