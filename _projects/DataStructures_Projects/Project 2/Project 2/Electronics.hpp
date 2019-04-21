#ifndef Electronics_hpp
#define Electronics_hpp

#include <stdio.h>
#include "itemList.hpp"
/* Electronics_hpp */
#endif
using namespace std;

class Electronics : public item{
private:
    string brandName;
    string modelNum;
    string type;
    Electronics* next;
public:
    Electronics();
    Electronics(string,double,string,string,string,string);
    void setType(string t);
    void setbrandName(string m);
    void setmodelNum(string b);
    string gettype();
    string getmodelNum();
    string getbrandName();
    void printItem();
    Electronics* getnextelectronic();
    void setnextelectronic(Electronics*);
    
    
};
Electronics* Electronics::getnextelectronic(){
    return next;
}
void Electronics::setnextelectronic(Electronics* next2){
    next = next2;
}
Electronics::Electronics()
{
    item();
    type="";
}
Electronics::Electronics(string name2,double price2 ,string upc2,string brand2,string model2,string type2){
    item(name2,price2,upc2);
    
    brandName = brand2;
    modelNum = model2;
    type = type2;

}
void Electronics::setType(string t)
{
    type = t;
}
void Electronics::setmodelNum(string m)
{
    modelNum = m;
}
void Electronics::setbrandName(string b)
{
    brandName = b;
}
string Electronics::getbrandName()
{
    return brandName;
}
string Electronics::getmodelNum()
{
    return modelNum;
}
string Electronics::gettype()
{
    return type;
}
void Electronics::printItem()
{
    getinfo();
    cout <<"Type: "<<type<<endl
    <<"Model Number: "<<modelNum<<endl
    <<"Brand: "<<brandName<<endl;
}
