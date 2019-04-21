//
//  ElectronicsList.hpp
//  Project 2: Inheritance and Polymorphism


#ifndef electronicList_hpp
#define electronicList_hpp
#include "Electronics.hpp"
#include <stdio.h>

#endif /* electronicList_hpp */
class ElectronicsList{
private:
    Electronics* ptrhead;
    Electronics* ptrend;
    Electronics* ptr;
public:
    ElectronicsList();
    void createelectronic(string name2,double price2 ,string upc2,string brand2,string model2,string type2);
   void displayelectronics();
    Electronics* searchname(string);
    Electronics* searchupc(string);
    Electronics* searchprice(double);
    Electronics* searchfromnumber(int);
};
ElectronicsList::ElectronicsList(){
    ptrhead = NULL;
    ptrend = NULL;
}
void ElectronicsList::createelectronic(string name2,double price2 ,string upc2,string brand2,string model2,string type2){
    Electronics *temp= new Electronics( name2, price2 , upc2, brand2, model2, type2);
    temp->setname(name2);
    temp->setprice(price2);
    temp->setupc(upc2);
    temp->setbrandName(brand2);
    temp->setmodelNum(model2);
    temp->setType(type2);
    if(ptrhead==NULL)
    {
        ptrhead=temp;
        ptrend=temp;
        temp=NULL;
    }
    else
    {
        ptrend->setnextelectronic(temp);
        ptrend=temp;
    }
}
void ElectronicsList::displayelectronics(){
    Electronics *temp = new Electronics;
    temp = ptrhead;
    cout<<endl;
    cout<<"-----Electronics list-----";
    cout<<endl;
    int x =1;
    while(temp!=NULL)
    {
        cout <<x<<": ";
        temp->getinfo();
        cout<<endl;
        temp = temp->getnextelectronic();
        x++;
    }
}
Electronics* ElectronicsList::searchname(string name){
    {
        while (ptrhead != NULL)
        {
            if (ptrhead->getname() == name)
            {
                return ptrhead;
            }
            ptrhead = ptrhead->getnextelectronic();
        }
    }
    return NULL;
}
Electronics* ElectronicsList::searchupc(string name){
    {
        while (ptrhead != NULL)
        {
            if (ptrhead->getupc() == name)
            {
                return ptrhead;
            }
            ptrhead = ptrhead->getnextelectronic();
        }
    }
    return NULL;
}
Electronics* ElectronicsList::searchprice(double name){
    {
        while (ptrhead != NULL)
        {
            if (ptrhead->getprice() == name)
            {
                return ptrhead;
            }
            ptrhead = ptrhead->getnextelectronic();
        }
    }
    return NULL;
}
Electronics* ElectronicsList::searchfromnumber(int y){
    int x =1;
    while (ptrhead != NULL)
    {
        if (x==y)
        {
            return ptrhead;
        }
        ptrhead = ptrhead->getnextelectronic();
        x++;
    }
    
    return NULL;

}
