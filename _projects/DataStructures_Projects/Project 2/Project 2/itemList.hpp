//
//  itemList.hpp
//  Project 2: Inheritance and Polymorphism


#ifndef itemList_hpp
#define itemList_hpp
#include "ClothingList.h"
#include <stdio.h>

#endif /* itemList_hpp */
class itemList{
private:
    item* ptrhead;
    item* ptrend;
    item* ptr;
public:
    itemList();
    void createitem(string,double,string);
   void displayitems();
    int getnumberofcart();
    void cartlist();
    void sort();
};
void itemList::sort(){
    item *temphead = ptrhead;
    string tempname;
    string tempupc;
    double tempprice;
    int counter = 0;
    while (temphead)
    {
        temphead = temphead->getnextitem();
        counter++;
    }
    temphead = ptrhead;
    
    for (int j=0; j<counter; j++)
    {
        while (temphead->getnextitem())
        {
            if (temphead->getprice() > temphead->getnextitem()->getprice())
            {
                tempname = temphead->getname();
                temphead->setname(temphead->getnextitem()->getname());
                temphead->getnextitem()->setname(tempname);
                
                tempprice = temphead->getprice();
                temphead->setprice(temphead->getnextitem()->getprice());
                temphead->getnextitem()->setprice(tempprice);
                
                tempupc = temphead->getupc();
                temphead->setname(temphead->getnextitem()->getupc());
                temphead->getnextitem()->setupc(tempupc);
            }
            temphead = temphead->getnextitem();
        }
        temphead = ptrhead;
    }
}
itemList::itemList(){
    ptrhead = NULL;
    ptrend = NULL;
}
void itemList::createitem(string name2, double price2, string upc2){
    item *temp= new item(name2,price2,upc2);
    temp->setname(name2);
    temp->setprice(price2);
    temp->setupc(upc2);
    if(ptrhead==NULL)
    {
        temp->setnextitem(NULL);
        ptrhead=temp;
        ptrend=temp;
        temp=NULL;
    }
    else
    {
        ptrend->setnextitem(temp);
        ptrend=temp;
    }
}
int itemList::getnumberofcart(){
    int i=0;
    item *temp = new item;
    temp = ptrhead;
    while(temp!=NULL)
    {
        temp = temp->getnextitem();
        i++;
    }
    return i;
}
void itemList::cartlist(){
    ofstream myfile ("CartList.txt");
    if (myfile.is_open())
    {
    item *temp = new item;
    temp = ptrhead;
    int x=1;
        myfile << getnumberofcart();
    while(temp!=NULL)
    {
      myfile << temp->getinfoformated();
        temp = temp->getnextitem();
    }
        myfile.close();
}
}
void itemList::displayitems(){
    item *temp = new item;
    temp = ptrhead;
    int x=1;
    cout<<endl;
    cout<<"-----cart list-----";
    cout<<endl;
    while(temp!=NULL)
    {
        cout <<x<<": ";
        temp->getinfo();
        cout<<endl;
        temp = temp->getnextitem();
        x++;
    }
    
}
