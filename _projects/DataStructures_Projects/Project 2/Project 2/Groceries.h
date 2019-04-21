//this is Groceries header and implementation
//derived class of Item
#include<iostream>
#include "MovieList.hpp"
using namespace std;

class Groceries: public item//, public Item
{
private:
	string type;//type of food
	string expiration;//expiration date
	int calorie;
	int quantity;
    Groceries* NextGroceries;
public:
	Groceries();
    Groceries(string,double,string,string,string,int,int);
	void setFoodtype(string);//choice between fresh,canned,and frozen
    string getFoodtype();
	void setExpiration(string);//expiration date
    string getExpiration();
	void setCalories(int);
    int getCalories();
	void setQuantity(int);
	int getQuantity();
    void setNextGroceries(Groceries* );
    Groceries* getNextGroceries();
    void displayGroceries();
   void getinfo();
};
// Groceries header implementation

Groceries::Groceries()
{
    item();
string type="";
string expiration="";
int calorie=0;
int quantity=0;
}
Groceries::Groceries(string n,double p,string up,string ty,string exper,int call,int quan){
    item(n,p,up);
    type = ty;
    expiration = exper;
    calorie = call;
    quantity = quan;
    NextGroceries = NULL;
}
void Groceries::setFoodtype(string f)
{
type=f;
}
string Groceries::getFoodtype()
{
return type;
}
void Groceries::setExpiration(string e)
{
expiration=e;
}
string Groceries::getExpiration()
{
return expiration;
}
void Groceries::setCalories(int c)
{
calorie=c;
}
int Groceries::getCalories()
{
return calorie;
}
void Groceries::setQuantity(int q)
{
quantity=q;
}
int Groceries::getQuantity()
{
return quantity;
}
void Groceries::setNextGroceries(Groceries* next){
    NextGroceries = next;
}
Groceries* Groceries::getNextGroceries(){
    return NextGroceries;
}
void Groceries::getinfo(){
    cout<<"Name: "<<getname()<<" Price: "<< getprice()<<"$ Upc: "<< getupc()<<" type: "<<type<<" experation date: "<<expiration<<" calories: "<<calorie<<" quantiy: "<<quantity<<endl;
}





