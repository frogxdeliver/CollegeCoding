//
//  ClothingList.hpp
//  Project 2: Inheritance and Polymorphism


#ifndef ClothingList_hpp
#define ClothingList_hpp
#include"Clothing.h"
#include <stdio.h>

#endif /* ClothingList_hpp */
class ClothingList{
private:
    Clothing* ptrhead;
    Clothing* ptrend;
    Clothing* ptr;
public:
    ClothingList();
    void CreateClothing(string n,double p ,string u,string t,string g,string s,int l,int w,int q );
   void displayClothings();
    Clothing* searchname(string);
    Clothing* searchupc(string);
    Clothing* searchprice(double);
};
ClothingList::ClothingList(){
    ptrhead = NULL;
    ptrend = NULL;
}
void ClothingList::CreateClothing(string n,double p ,string u,string t,string g,string s,int l,int w,int q ){
    Clothing *temp= new Clothing();
    temp->setname(n);
    temp->setprice(p);
    temp->setupc(u);
    temp->setClothingType(t);
    temp->setGender(g);
    temp->setSize(l, w);
    temp->setSize(s);
    temp->setQuantity(q);
    if(ptrhead==NULL)
    {
        ptrhead=temp;
        ptrend=temp;
        temp=NULL;
    }
    else
    {
        ptrend->setnextClothing(temp);
        ptrend=temp;
    }
}
void ClothingList::displayClothings(){
    Clothing *temp = new Clothing;
    temp = ptrhead;
    cout<<endl;
    cout<<"-----Clothing list-----";
    cout<<endl;
    int x =1;
    while(temp!=NULL)
    {
        
        cout <<x<<": ";
        temp->printInfo();
        cout<<endl;
        temp = temp->getnextclothing();
        x++;
    }
}
Clothing* ClothingList::searchname(string name){
    
    {
        while (ptrhead != NULL)
        {
            if (ptrhead->getname() == name)
            {
                return ptrhead;
            }
            ptrhead = ptrhead->getnextclothing();
        }
    }
    return NULL;
}
Clothing* ClothingList::searchupc(string name){
    {
        while (ptrhead != NULL)
        {
            if (ptrhead->getupc() == name)
            {
                return ptrhead;
            }
            ptrhead = ptrhead->getnextclothing();
        }
    }
    return NULL;
}
Clothing* ClothingList::searchprice(double name){
    {
        while (ptrhead != NULL)
        {
            if (ptrhead->getprice() == name)
            {
                return ptrhead;
            }
            ptrhead = ptrhead->getnextclothing();
        }
    }
    return NULL;
}
