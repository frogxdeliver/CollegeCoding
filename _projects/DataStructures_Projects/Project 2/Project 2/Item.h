#ifndef Item_h
#define Item_h
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#endif
using namespace std;
//wow the item class its the default class for everything to depend apawn
//it holds the 3 basic items that every product needs for a store
class item{
private:
    //@define name holds the name of the product being sold
    string name;
     //@define price holds the amount the product cost
    double price;
     //@define upc holds the UPC number used to disigwish products
    string upc;
    item* nextitem;
public:
    item();
    item(string,double,string);
    string getname();
    double getprice();
    void setname(string);
    void setprice(double);
    string getupc();
    void setupc(string);
    void setnextitem(item*);
    item* getnextitem();
    void getinfo();
    item* makeitem();
    string getinfoformated();
};

item::item(){
    //default constuctor
    name = "";
    price = 0;
    upc = "";
}
item::item(string nameh,double pricei,string upc2){
    //overloaded constructor
    name = nameh;
    price = pricei;
    upc  = upc2;
    price = 0;
}
void item::setnextitem(item* next){
    //returns nothing @paramators is an item list
    nextitem = next;
}
item* item::getnextitem(){
    return nextitem;
}
string item::getname(){
    return name;
}
double item::getprice(){
    return price;
}
void item::setname(string name2){
    name = name2;
}
void item::setprice(double price2){
    price = price2;
}
void item::setupc(string upc2){
    upc = upc2;
}
string item::getupc(){
    return upc;
}
void item::getinfo(){
    cout<<"Name: "<<getname()<<" Price: "<< getprice()<<"$ UPC: "<< getupc();
}
string item::getinfoformated(){
    std::ostringstream sstream;
    sstream << price;
    std::string varAsString = sstream.str();

    return (" "+name+" "+varAsString+" "+upc+"");
}
item* item::makeitem(){
    item* temp = new item();
    temp->setname(name);
    temp->setupc(upc);
    temp->setprice(price);
    temp->nextitem = NULL;
    return temp;
}
