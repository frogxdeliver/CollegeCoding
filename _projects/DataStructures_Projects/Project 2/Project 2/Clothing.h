//Clothing.h

#ifndef Clothing_h
#define Clothing_h
#include<iostream>
#include "Item.h"
using namespace std;

class Clothing: public item
{
	private:
		string type; // pants, shirts, sleepwear, accessories
		string gender; // man, women
		string sizePants; //Large, medium, small (for shirts)
		int sizeL; //length
		int sizeW; //width
		int quantity; //amount of clothing left
    Clothing* nextclothing;
	public:
    Clothing();
    Clothing(string n,double p ,string u,string t,string g,string s,int l,int w,int q);
		void print();
		void setClothingType(string newClothing);
		void setGender(string newG);
		void setSize(int newL, int newW);
		void setSize(string newSize);
		void setQuantity(int newQ);
		void printInfo();
		void printInfo(string newClothing, string newG, string newSize, int newQ);
		void printInfo(string newClothing, string newG, int newL, int newW, int newQ);
		string getClothingType();
		string getGender();
		string getSize();
		int getSizeL();
		int getSizeW();
		int getQuantity();
    Clothing* getnextclothing();
    void setnextClothing(Clothing*);
    
		
};
Clothing::Clothing(){
    item();
    type = "";
    gender = "";
    sizePants = "";
    sizeL = 0;
    sizeW = 0;
    quantity = 0;
    nextclothing = NULL;
}
Clothing::Clothing(string n,double p ,string u,string t,string g,string s,int l,int w,int q){
    item(n,p,u);
    type = t;
    gender = g;
    sizePants = s;
    sizeL = l;
    sizeW = w;
    quantity = q;
    nextclothing = NULL;
}
//setters
Clothing* Clothing::getnextclothing(){
    return nextclothing;
}
void Clothing::setnextClothing(Clothing *h){
    nextclothing = h;
}
void Clothing::setClothingType(string newClothing){
	type = newClothing;
}
void Clothing::setGender(string newG){
	gender = newG;
}
void Clothing::setSize(string newSize){
	sizePants = newSize;
}
void Clothing::setSize(int newL, int newW){
	sizeL = newL;
	sizeW = newW;
}
void Clothing::setQuantity(int newQ){
	quantity = newQ;
}

//getters
string Clothing::getClothingType(){
	return type;
}
string Clothing::getGender(){
	return gender;
}
string Clothing::getSize(){
	return sizePants;
}
int Clothing::getSizeL(){
	return sizeL;
}
int Clothing::getSizeW(){
	return sizeW;
}
int Clothing::getQuantity(){
	return quantity;
}

//print
void Clothing::printInfo(){
    cout << "Type of Clothing: " << type<< ", For: " << gender<< ", Length: " << sizeL<< ", Width: " << sizeW
    << ", Quantity: " << quantity << "\n";
}
	
#endif //Clothing_h
