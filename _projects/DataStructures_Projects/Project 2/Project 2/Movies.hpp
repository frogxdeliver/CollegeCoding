//Movies header file w/implementation
//Movies is derived class of Item
#ifndef Movies_hpp
#define Movies_hpp

#include <stdio.h>
#include <iostream>
#include "ElectronicsList.h"
#endif /* Movies_hpp */
using namespace std;
class Movie: public item //class Movie,public Item
{
private:
	
	float rating;
	int copy;
	int year;
	string title;
	string format;//dvd,digital,vhs
	string director;
    Movie* nextMovie;

public:
    void moviemenu();
	 //Movie:Item();
	  Movie();
	 /*
	 getter functions pull data from private members
	 setter functions assign values to private members
	 setters used here cuz data will be read from separate file
	 file will be like record that can't be changed by customer,so
	 setters restrict data change
	 */
    Movie(string,double,string,float,int,int,string,string,string);
	 void setRating(float);
	 void Numcopies(int);
	 void setYear(int);
	 void setTitle(string);
	 void setFormat(string);
	 void setDirector(string);
     string getFormat();
    float getRating();
    int getNumcopies();
    int getYear();
    string getTitle();
    string  getDirector();
    Movie* getnextMovie();
    void setNextMovie(Movie* );
    void getinfo();
};
//---------------------------------------------------------------------------//
//class declerations my dood
void Movie::setNextMovie(Movie* movi){
    nextMovie = movi;
}
Movie* Movie::getnextMovie(){
    return nextMovie;
}
Movie::Movie()
{
item();
 title=" ";
format=" ";
 director=" ";
rating=0.0;
 copy=0;
 year=0;
    nextMovie = NULL;
}
Movie::Movie(string name2,double price2,string upc2,float rating2,int copys2 ,int year2 ,string title2 ,string format2 ,string director2 ){
    item(name2,price2,upc2);
     title=title2;
     format=format2;
     director=director2;
     rating=rating2;
     copy=copys2;
     year=year2;
    nextMovie = NULL;
}
void Movie::setYear(int y)
{
year=y;
}
void Movie::setRating(float r)
{
rating=r;
}
void Movie::setTitle(string t)
{
title = t;
}
void Movie::setFormat(string f)
{
format = f;
}
void Movie::setDirector(string d)
{
director = d;
}
void Movie::Numcopies(int c)
{
copy=c;
}
string Movie::getFormat(){
    return format;
}
float Movie::getRating(){
    return rating;
}
int Movie::getNumcopies(){
    return copy;
}
int Movie::getYear(){
    return year;
}
string Movie::getTitle(){
    return title;
}
string  Movie::getDirector(){
    return director;
}
void Movie::getinfo(){
    cout<<"Name: "<<getname()<<" Price: "<< getprice()<<"$ Upc: "<< getupc()<<" Raiting: "<<rating<<" Copys: "<<copy<<" Release year: "<<year<<" Title: "<<title<<" Format: "<<format<<" Director: "<<director<<endl;
}
//---------------------------------------------------------------------------//
//end class decleration
