//
//  GroceriesList.hpp
//  Project 2: Inheritance and Polymorphism


#ifndef GroceriesList_hpp
#define GroceriesList_hpp
#include"Groceries.h"
#include <stdio.h>

#endif /* GroceriesList_hpp */
class GroceriesList{
private:
    Groceries* ptrhead;
    Groceries* ptrend;
    Groceries* ptr;
public:
    GroceriesList();
    void createGroceries(string n,double p,string up,string ty,string exper,int call,int quan);
   void displayGroceriess();
    Groceries* searchname(string);
    Groceries* searchupc(string);
    Groceries* searchprice(double);
};
GroceriesList::GroceriesList(){
    ptrhead = NULL;
    ptrend = NULL;
}
void GroceriesList::createGroceries(string n,double p,string up,string ty,string exper,int call,int quan ){
    Groceries *temp= new Groceries(n,p,up,ty,exper,call,quan);
    temp->setname(n);
    temp->setprice(p);
    temp->setupc(up);
    temp->setFoodtype(ty);
    temp->setExpiration(exper);
    temp->setCalories(call);
    temp->setQuantity(quan);
    if(ptrhead==NULL)
    {
        ptrhead=temp;
        ptrend=temp;
        temp=NULL;
    }
    else
    {
        ptrend->setNextGroceries(temp);
        ptrend=temp;
    }
}
void GroceriesList::displayGroceriess(){
    Groceries *temp = new Groceries;
    temp = ptrhead;
    cout<<endl;
    cout<<"-----Groceries list-----";
    cout<<endl;
    int x =1;
    while(temp!=NULL)
    {
        
        cout <<x<<": ";
        temp->getinfo();
        cout<<endl;
        temp = temp->getNextGroceries();
        x++;
    }
    
}
Groceries* GroceriesList::searchname(string name){
    {
        while (ptrhead != NULL)
        {
            if (ptrhead->getname() == name)
            {
                
                return ptrhead;
            }
            ptrhead = ptrhead->getNextGroceries();
        }
        
    }
    return NULL;
}
Groceries* GroceriesList::searchupc(string name){
    {
        while (ptrhead != NULL)
        {
            if (ptrhead->getupc() == name)
            {
                return ptrhead;
            }
            ptrhead = ptrhead->getNextGroceries();
        }
    }
    return NULL;
}
Groceries* GroceriesList::searchprice(double name){
    {
        while (ptrhead != NULL)
        {
            if (ptrhead->getprice() == name)
            {
                return ptrhead;
            }
            ptrhead = ptrhead->getNextGroceries();
        }
    }
    return NULL;
}
