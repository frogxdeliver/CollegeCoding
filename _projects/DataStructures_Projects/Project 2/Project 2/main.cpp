//
//  main.cpp
//  Project 2: Inheritance and Polymorphism
#ifndef main_cpp
#define main_cpp

#include<iostream>
#include<fstream>
#include"grocerieList.hpp"
#include<stdio.h>
#include "LoadHelper.hpp"
#endif
using namespace std;
MovieList* pullmovies();
GroceriesList* pullgroceries();
ClothingList* pullClothing();
void moviemenu();
void mainmenu();
void top10movies();
void viewcart();
void moviesearch();
void groceriesearch();
void groceriemenu();
void ClothingSearch();
void ClothingMenu();
void ElectronicsSearch();
void ElectronicsMenu();

//---------------------------------List Declaration--------------------------------------
MovieList *movies = pullmovies();
itemList *cart = pullCart();
GroceriesList *groceriess = pullgroceries();
ClothingList *cloths = pullClothing();
ElectronicsList *electrons = pulleletronics();

int main()
{
    mainmenu();
    return 0;
}
void viewcart(){
    int selection;
    cout<<"\n Einstinzon Cart Menu";
    cout<<"\n Please Select what you would like to do with your cart";
    cout<<"\n 1 - view your cart";
    cout<<"\n 2 - clear your cart";
    cout<<"\n 3 - sort your cart";
    cout<<"\n 4 - return to main menu";
    cout<<"\n Enter selection: ";
    // read the input
    cin>>selection;
    switch(selection)
    {
        case 1 :{
            cart->displayitems();
            SaveCart(cart);
            viewcart();
        }
            break;
        case 2 :{
            cart = new itemList();
            SaveCart(cart);
            viewcart();
        }
            break;
        case 3 :{
            cart->sort();
            cart->displayitems();
            SaveCart(cart);
            viewcart();
        }
            break;
        case 4 :{
            mainmenu();
        }
            break;
        
        default : cout<<"\n Invalid selection";{
            mainmenu();
        }
    }
    cout<<"\n";
    
    
    
}
//---------------------------------main-menu Declaration--------------------------------------
void mainmenu(){
    int selection;
    cout<<"\n Einstinzon Main Menu";
    cout<<"\nPlease Select the Department That You Would like to Shop in";
    cout<<"\n 1 - Movies";
    cout<<"\n 2 - Groceries";
    cout<<"\n 3 - Clothing";
    cout<<"\n 4 - Electronics";
    cout<<"\n 5 - View Your Current cart";
    cout<<"\n 6 - exit the program";
    cout<<"\n Enter selection: ";
    // read the input
    cin>>selection;
    switch(selection)
    {
        case 1 :{
            moviemenu();
        }
            break;
        case 2 :{
            groceriemenu();
        }
            break;
        case 3 :{
            ClothingMenu();
        }
            break;
        case 4 :{
            ElectronicsMenu();
        }
            break;
        case 5:{
            viewcart();
        }break;
        default : cout<<"\n Invalid selection";{
            mainmenu();
        }
    }
    cout<<"\n";
    
    
}
//---------------------------------Movie Decleration-------------------------------------
//we have the movie menu and the movie search here
void moviemenu(){
    int selection;
    cout<<"\n Einstinzon Movie Menu";
    cout<<"\n Select an option from the list ";
    cout<<"\n 1 - search through all the movies";
    cout<<"\n 2 - view all the movies";
    cout<<"\n 3 - View Your Current cart";
    cout<<"\n 4 - return to main menu";
    cout<<"\n Enter selection: ";
    // read the input
    cin>>selection;
    switch(selection)
    {
        case 1 :{
            moviesearch();
        }
        case 2 :{
            movies->displaymovies();
            cout<<"enter the number of the movie you would like to add to cart"<<endl;
            int x;
            cin >> x;
            Movie* search = movies->searchfromnumber(x);
            if(search== NULL){
                cout<<"the movie you searched for dosent exist"<<endl;
                moviesearch();
            }else{
                search->getinfo();
                cout<<"would you like to add this movie to your cart????"<<endl;
                cout<<"1-Yes"<<endl;
                cout<<"2-no"<<endl;
                int x;
                cin>>x;
                if(x==1){
                    cart->createitem(search->getname(), search->getprice(), search->getupc());
                    moviemenu();
                }else if (x==2){
            moviemenu();
        }
            }
        }
        case 3 :{
            viewcart();
        }
        case 4 :{
            mainmenu();
        }
        default : cout<<"\n Invalid selection";{
            exit(1);
        }
    }
}
void moviesearch(){
    
    int selection;
    cout<<"\n Movie Search Menu";
    cout<<"\n Select an option from the list ";
    cout<<"\n 1 - search movies by name";
    cout<<"\n 2 - search movies by rateing";
    cout<<"\n 3 - search movies by price";
    cout<<"\n 4 - return to main menu";
    cout<<"\n Enter selection: ";
    // read the input
    cin>>selection;
    switch(selection)
    {
        case 1 :{
            cout<<"enter the name of the movie you would like to search for"<<endl;
            string name;
            cin >>name;
            Movie* search = movies->searchname(name);
            if(search== NULL){
                cout<<"the movie you searched for dosent exist"<<endl;
                moviesearch();
            }else{
                search->getinfo();
                cout<<"would you like to add this movie to your cart????"<<endl;
                cout<<"1-Yes"<<endl;
                cout<<"2-no"<<endl;
                int x;
                cin>>x;
                if(x==1){
                    cart->createitem(search->getname(), search->getprice(), search->getupc());
                    moviemenu();
                }else if (x==2){
                    cout<<"would you like to search again"<<endl;
                    cout<<"1-Yes"<<endl;
                    cout<<"2-no"<<endl;
                    int x;
                    cin>>x;
                    if(x==1){
                        moviesearch();
                    }else{
                        moviemenu();
                    }
                }else{
                    cout<<"incorrcect entrie"<<endl;
                    moviesearch();
                }
            }
        }
            break;
            
        case 2 :{
            cout<<"enter the upc of the movie you would like to search for"<<endl;
            string name;
            cin >>name;
            Movie* search = movies->searchupc(name);
            if(search== NULL){
                cout<<"the movie you searched for dosent exist"<<endl;
                moviesearch();
            }else{
                search->getinfo();
                cout<<"would you like to add this movie to your cart????"<<endl;
                cout<<"1-Yes"<<endl;
                cout<<"2-no"<<endl;
                int x;
                cin>>x;
                if(x==1){
                    cart->createitem(search->getname(), search->getprice(), search->getupc());
                    moviemenu();
                }else if (x==2){
                    cout<<"would you like to search again"<<endl;
                    cout<<"1-Yes"<<endl;
                    cout<<"2-no"<<endl;
                    int x;
                    cin>>x;
                    if(x==1){
                        moviesearch();
                    }else{
                        moviemenu();
                    }
                }else{
                    cout<<"incorrcect entrie"<<endl;
                    moviesearch();
                }
            }
        }
            break;
            
        case 3 :{
            cout<<"enter the price of the movie you would like to search for"<<endl;
            
            double name;
            cin >>name;
            Movie* search = movies->searchprice(name);
            if(search== NULL){
                cout<<"the movie you searched for dosent exist"<<endl;
                moviesearch();
            }else{
                search->getinfo();
                cout<<"would you like to add this movie to your cart????"<<endl;
                cout<<"1-Yes"<<endl;
                cout<<"2-no"<<endl;
                int x;
                cin>>x;
                if(x==1){
                    cart->createitem(search->getname(), search->getprice(), search->getupc());
                    moviemenu();
                }else if (x==2){
                    cout<<"would you like to search again"<<endl;
                    cout<<"1-Yes"<<endl;
                    cout<<"2-no"<<endl;
                    int x;
                    cin>>x;
                    if(x==1){
                        moviesearch();
                    }else{
                        moviemenu();
                    }
                }else{
                    cout<<"incorrcect entrie"<<endl;
                    moviesearch();
                }
            }
        }
            break;
            
        case 4 :{
            mainmenu();
        }
            break;
        default : cout<<"\n Invalid selection";{
            moviesearch();
        }
            
    }
    cout<<"\n";
}


//---------------------------------Grocerie Decleration-------------------------------------
void groceriemenu(){
    int selection;
    cout<<"\n Einstinzon Grocerie Menu";
    cout<<"\n Select an option from the list ";
    cout<<"\n 1 - search through all the Groceries";
    cout<<"\n 2 - view all the Groceries";
    cout<<"\n 3 - View Your Current cart";
    cout<<"\n 4 - return to main menu";
    cout<<"\n Enter selection: ";
    // read the input
    cin>>selection;
    switch(selection)
    {
        case 1 :{
            groceriesearch();
        }
            break;
            
        case 2 :{
            groceriess->displayGroceriess();
            groceriemenu();
        }
            break;
            
        case 3 :{
            viewcart();
        }
            break;
            
        case 4 :{
            mainmenu();
        }
            break;
        default : cout<<"\n Invalid selection";{
            mainmenu();
        }
    }
    
}
void groceriesearch(){
    int selection;
    cout<<"\n grocerie Search Menu";
    cout<<"\n Select an option from the list ";
    cout<<"\n 1 - search groceries by name";
    cout<<"\n 2 - search groceries by upc";
    cout<<"\n 3 - search groceries by price";
    cout<<"\n 4 - return to main menu";
    cout<<"\n Enter selection: ";
    // read the input
    cin>>selection;
    switch(selection)
    {
        case 1 :{
            cout<<"enter the name of the item you would like to search for"<<endl;
            string name;
            cin >>name;
            Groceries *search = groceriess->searchname(name);
            if(search== NULL){
                cout<<"the item you searched for dosent exist"<<endl;
                groceriesearch();
            }else{
                search->getinfo();
                cout<<"would you like to add this movie to your cart????"<<endl;
                cout<<"1-Yes"<<endl;
                cout<<"2-no"<<endl;
                int x;
                cin>>x;
                if(x==1){
                    cart->createitem(search->getname(), search->getprice(), search->getupc());
                    groceriemenu();
                }else if (x==2){
                    cout<<"would you like to search again"<<endl;
                    cout<<"1-Yes"<<endl;
                    cout<<"2-no"<<endl;
                    int x;
                    cin>>x;
                    if(x==1){
                        groceriesearch();
                    }else{
                        groceriemenu();
                    }
                }else{
                    cout<<"incorrcect entrie"<<endl;
                    groceriesearch();
                }
            }
        }
            break;
            
        case 2 :{
            cout<<"enter the upc of the item you would like to search for"<<endl;
            string name;
            cin >>name;
            Groceries* search = groceriess->searchupc(name);
            if(search== NULL){
                cout<<"the item you searched for dosent exist"<<endl;
                groceriesearch();
            }else{
                search->getinfo();
                cout<<"would you like to add this item to your cart????"<<endl;
                cout<<"1-Yes"<<endl;
                cout<<"2-no"<<endl;
                int x;
                cin>>x;
                if(x==1){
                    cart->createitem(search->getname(), search->getprice(), search->getupc());
                    groceriesearch();
                }else if (x==2){
                    cout<<"would you like to search again"<<endl;
                    cout<<"1-Yes"<<endl;
                    cout<<"2-no"<<endl;
                    int x;
                    cin>>x;
                    if(x==1){
                        groceriesearch();
                    }else{
                        groceriemenu();
                    }
                }else{
                    cout<<"incorrcect entrie"<<endl;
                    groceriesearch();
                }
            }
        }
            break;
            
        case 3 :{
            cout<<"enter the price of the item you would like to search for"<<endl;
            
            double name;
            cin >>name;
            Groceries *search = groceriess->searchprice(name);
            if(search== NULL){
                cout<<"the movie you searched for dosent exist"<<endl;
                groceriesearch();
            }else{
                search->getinfo();
                cout<<"would you like to add this item to your cart????"<<endl;
                cout<<"1-Yes"<<endl;
                cout<<"2-no"<<endl;
                int x;
                cin>>x;
                if(x==1){
                    cart->createitem(search->getname(), search->getprice(), search->getupc());
                    groceriemenu();
                }else if (x==2){
                    cout<<"would you like to search again"<<endl;
                    cout<<"1-Yes"<<endl;
                    cout<<"2-no"<<endl;
                    int x;
                    cin>>x;
                    if(x==1){
                        groceriesearch();
                    }else{
                        groceriemenu();
                    }
                }else{
                    cout<<"incorrcect entrie"<<endl;
                    groceriesearch();
                }
            }
        }
            break;
            
        case 4 :{
            mainmenu();
        }
            break;
        default : cout<<"\n Invalid selection";{
            groceriesearch();
        }
            
    }
    cout<<"\n";
}

//---------------------------------Clothing Decleration-------------------------------------
void ClothingMenu(){
    int selection;
    cout<<"\n Einstinzon Clothing Menu";
    cout<<"\n Select an option from the list ";
    cout<<"\n 1 - search through all the Clothing";
    cout<<"\n 2 - view all the Clothing";
    cout<<"\n 3 - View Your Current cart";
    cout<<"\n 4 - return to main menu";
    cout<<"\n Enter selection: ";
    // read the input
    cin>>selection;
    switch(selection)
    {
        case 1 :{
            ClothingSearch();
        }
            break;
            
        case 2 :{
            cloths->displayClothings();
            ClothingMenu();
        }
            break;
            
        case 3 :{
            viewcart();
        }
            break;
            
        case 4 :{
            mainmenu();
        }
            break;
        default : cout<<"\n Invalid selection";{
            mainmenu();
        }
    }
    cout<<"\n";
    
}
void ClothingSearch(){
    int selection;
    cout<<"\n grocerie Search Menu";
    cout<<"\n Select an option from the list ";
    cout<<"\n 1 - search groceries by name";
    cout<<"\n 2 - search groceries by upc";
    cout<<"\n 3 - search groceries by price";
    cout<<"\n 4 - return to main menu";
    cout<<"\n Enter selection: ";
    // read the input
    cin>>selection;
    switch(selection)
    {
        case 1 :{
            cout<<"enter the name of the item you would like to search for"<<endl;
            string name;
            cin >>name;
            Clothing *search = cloths->searchname(name);
            if(search== NULL){
                cout<<"the item you searched for dosent exist"<<endl;
                ClothingSearch();
            }else{
                search->getinfo();
                cout<<"would you like to add this movie to your cart????"<<endl;
                cout<<"1-Yes"<<endl;
                cout<<"2-no"<<endl;
                int x;
                cin>>x;
                if(x==1){
                    cart->createitem(search->getname(), search->getprice(), search->getupc());
                    ClothingMenu();
                }else if (x==2){
                    cout<<"would you like to search again"<<endl;
                    cout<<"1-Yes"<<endl;
                    cout<<"2-no"<<endl;
                    int x;
                    cin>>x;
                    if(x==1){
                        ClothingSearch();
                    }else{
                        ClothingMenu();
                    }
                }else{
                    cout<<"incorrcect entrie"<<endl;
                    ClothingSearch();
                }
            }
        }
            break;
            
        case 2 :{cout<<"\n search upc";
            cout<<"enter the upc of the item you would like to search for"<<endl;
            string name;
            cin >>name;
            Clothing* search = cloths->searchupc(name);
            if(search== NULL){
                cout<<"the item you searched for dosent exist"<<endl;
                ClothingSearch();
            }else{
                search->getinfo();
                cout<<"would you like to add this item to your cart????"<<endl;
                cout<<"1-Yes"<<endl;
                cout<<"2-no"<<endl;
                int x;
                cin>>x;
                if(x==1){
                    cart->createitem(search->getname(), search->getprice(), search->getupc());
                    ClothingSearch();
                }else if (x==2){
                    cout<<"would you like to search again"<<endl;
                    cout<<"1-Yes"<<endl;
                    cout<<"2-no"<<endl;
                    int x;
                    cin>>x;
                    if(x==1){
                        ClothingSearch();
                    }else{
                        ClothingMenu();
                    }
                }else{
                    cout<<"incorrcect entrie"<<endl;
                    ClothingMenu();
                }
            }
        }
            break;
            
        case 3 :{
            cout<<"enter the price of the item you would like to search for"<<endl;
            
            double name;
            cin >>name;
            Clothing *search = cloths->searchprice(name);
            if(search== NULL){
                cout<<"the movie you searched for dosent exist"<<endl;
                ClothingSearch();
            }else{
                search->getinfo();
                cout<<"would you like to add this item to your cart????"<<endl;
                cout<<"1-Yes"<<endl;
                cout<<"2-no"<<endl;
                int x;
                cin>>x;
                if(x==1){
                    cart->createitem(search->getname(), search->getprice(), search->getupc());
                    ClothingMenu();
                }else if (x==2){
                    cout<<"would you like to search again"<<endl;
                    cout<<"1-Yes"<<endl;
                    cout<<"2-no"<<endl;
                    int x;
                    cin>>x;
                    if(x==1){
                        ClothingSearch();
                    }else{
                        ClothingMenu();
                    }
                }else{
                    cout<<"incorrcect entrie"<<endl;
                    ClothingSearch();
                }
            }
        }
            break;
            
        case 4 :{
            mainmenu();
        }
            break;
        default : cout<<"\n Invalid selection";{
            ClothingSearch();
        }
            
    }
    cout<<"\n";
}

//---------------------------------Electronics Decleration-------------------------------------
void ElectronicsMenu(){
    int selection;
    cout<<"\n Einstinzon Electronics Menu";
    cout<<"\n Select an option from the list ";
    cout<<"\n 1 - search through all the Electronics";
    cout<<"\n 2 - view all the Electronics";
    cout<<"\n 3 - View Your Current cart";
    cout<<"\n 4 - return to main menu";
    cout<<"\n Enter selection: ";
    // read the input
    cin>>selection;
    switch(selection)
    {
        case 1 :{
            ElectronicsSearch();
        }
            break;
            
        case 2 :{
            electrons->displayelectronics();
            ElectronicsMenu();
        }
            break;
            
        case 3 :{
            viewcart();
        }
            break;
            
        case 4 :{
            mainmenu();
        }
            break;
        default : cout<<"\n Invalid selection";{
            mainmenu();
        }
    }
    cout<<"\n";
    
}
void ElectronicsSearch(){
    int selection;
    cout<<"\n Electronics Search Menu";
    cout<<"\n Select an option from the list ";
    cout<<"\n 1 - search Electronics by name";
    cout<<"\n 2 - search Electronics by upc";
    cout<<"\n 3 - search Electronics by price";
    cout<<"\n 4 - return to main menu";
    cout<<"\n Enter selection: ";
    // read the input
    cin>>selection;
    switch(selection)
    {
        case 1 :{
            cout<<"enter the name of the item you would like to search for"<<endl;
            string name;
            cin >>name;
            Clothing *search = cloths->searchname(name);
            if(search== NULL){
                cout<<"the item you searched for dosent exist"<<endl;
               ElectronicsSearch();
            }else{
                search->getinfo();
                cout<<"would you like to add this Item to your cart????"<<endl;
                cout<<"1-Yes"<<endl;
                cout<<"2-no"<<endl;
                int x;
                cin>>x;
                if(x==1){
                    cart->createitem(search->getname(), search->getprice(), search->getupc());
                    ElectronicsMenu();
                }else if (x==2){
                    cout<<"would you like to search again"<<endl;
                    cout<<"1-Yes"<<endl;
                    cout<<"2-no"<<endl;
                    int x;
                    cin>>x;
                    if(x==1){
                        ElectronicsSearch();
                    }else{
                        ElectronicsMenu();
                    }
                }else{
                    cout<<"incorrcect entrie"<<endl;
                    ElectronicsSearch();
                }
            }
        }
            break;
            
        case 2 :{cout<<"\n search upc";
            cout<<"enter the upc of the item you would like to search for"<<endl;
            string name;
            cin >>name;
            Clothing* search = cloths->searchupc(name);
            if(search== NULL){
                cout<<"the item you searched for dosent exist"<<endl;
                ElectronicsSearch();
            }else{
                search->getinfo();
                cout<<"would you like to add this item to your cart????"<<endl;
                cout<<"1-Yes"<<endl;
                cout<<"2-no"<<endl;
                int x;
                cin>>x;
                if(x==1){
                    cart->createitem(search->getname(), search->getprice(), search->getupc());
                    ElectronicsSearch();
                }else if (x==2){
                    cout<<"would you like to search again"<<endl;
                    cout<<"1-Yes"<<endl;
                    cout<<"2-no"<<endl;
                    int x;
                    cin>>x;
                    if(x==1){
                        ElectronicsSearch();
                    }else{
                        ElectronicsMenu();
                    }
                }else{
                    cout<<"incorrcect entrie"<<endl;
                    ElectronicsMenu();
                }
            }
        }
            break;
            
        case 3 :{
            cout<<"enter the price of the item you would like to search for"<<endl;
            
            double name;
            cin >>name;
            Clothing *search = cloths->searchprice(name);
            if(search== NULL){
                cout<<"the movie you searched for dosent exist"<<endl;
                ElectronicsSearch();
            }else{
                search->getinfo();
                cout<<"would you like to add this item to your cart????"<<endl;
                cout<<"1-Yes"<<endl;
                cout<<"2-no"<<endl;
                int x;
                cin>>x;
                if(x==1){
                    cart->createitem(search->getname(), search->getprice(), search->getupc());
                    ElectronicsMenu();
                }else if (x==2){
                    cout<<"would you like to search again"<<endl;
                    cout<<"1-Yes"<<endl;
                    cout<<"2-no"<<endl;
                    int x;
                    cin>>x;
                    if(x==1){
                        ElectronicsSearch();
                    }else{
                        ElectronicsMenu();
                    }
                }else{
                    cout<<"incorrcect entrie"<<endl;
                    ElectronicsSearch();
                }
            }
        }
            break;
            
        case 4 :{
            mainmenu();
        }
            break;
        default : cout<<"\n Invalid selection";{
           ElectronicsSearch();
       }
            
    }
    cout<<"\n";
}

