//
//  MovieList.hpp
//  Project 2: Inheritance and Polymorphism
//

#ifndef MovieList_hpp
#define MovieList_hpp
#include"Movies.hpp"
#include <stdio.h>

#endif /* MovieList_hpp */
class MovieList{
private:
    Movie* ptrhead;
    Movie* ptrend;
    Movie* ptr;
public:
    MovieList();
    void createmovie(string,double,string,float,int,int,string,string,string);
   void displaymovies();
    Movie* searchname(string);
    Movie* searchupc(string);
    Movie* searchprice(double);
    Movie* searchfromnumber(int);
};
MovieList::MovieList(){
    ptrhead = NULL;
    ptrend = NULL;
}
void MovieList::createmovie(string name2,double price2,string upc2,float rating2,int copys2 ,int year2 ,string title2 ,string format2 ,string director2 ){
    Movie *temp= new Movie(name2,price2,upc2,rating2,copys2,year2,title2,format2,director2);
    temp->setname(name2);
    temp->setprice(price2);
    temp->setupc(upc2);
    temp->setRating(rating2);
    temp->setYear(year2);
    temp->setTitle(title2);
    temp->setFormat(format2);
    temp->setDirector(director2);
    if(ptrhead==NULL)
    {
        ptrhead=temp;
        ptrend=temp;
        temp=NULL;
    }
    else
    {
        ptrend->setNextMovie(temp);
        ptrend=temp;
    }
}
void MovieList::displaymovies(){
    Movie *temp = new Movie;
    temp = ptrhead;
    cout<<endl;
    cout<<"-----Movie list-----";
    cout<<endl;
    int x =1;
    while(temp!=NULL)
    {
        cout <<x<<": ";
        temp->getinfo();
        cout<<endl;
        temp = temp->getnextMovie();
        x++;
    }
}
Movie* MovieList::searchname(string name){
    {
        while (ptrhead != NULL)
        {
            if (ptrhead->getname() == name)
            {
                return ptrhead;
            }
            ptrhead = ptrhead->getnextMovie();
        }
    }
    return NULL;
}
Movie* MovieList::searchupc(string name){
    {
        while (ptrhead != NULL)
        {
            if (ptrhead->getupc() == name)
            {
                return ptrhead;
            }
            ptrhead = ptrhead->getnextMovie();
        }
    }
    return NULL;
}
Movie* MovieList::searchprice(double name){
    {
        while (ptrhead != NULL)
        {
            if (ptrhead->getprice() == name)
            {
                return ptrhead;
            }
            ptrhead = ptrhead->getnextMovie();
        }
    }
    return NULL;
}
Movie* MovieList::searchfromnumber(int y){
    int x =1;
    while (ptrhead != NULL)
    {
        if (x==y)
        {
            return ptrhead;
        }
        ptrhead = ptrhead->getnextMovie();
        x++;
    }
    
    return NULL;

}
