//
//  LoadHelper.hpp
//  Project 2: Inheritance and Polymorphism

//XCODE 4 LYFE XCODE 4 LYFE XCODE 4 LYFE XCODE 4 LYFE XCODE 4 LYFE XCODE 4 LYFE XCODE 4 LYFE XCODE 4 LYFE XCODE 4 LYFE XCODE 4 LYFE XCODE 4 LYFE XCODE 4 LYFE XCODE 4 LYFE XCODE 4 LYFE XCODE 4 LYFE XCODE 4 LYFE XCODE 4 LYFE XCODE 4 LYFE
//
#ifndef LoadHelper_hpp
#define LoadHelper_hpp
#include<iostream>
#include <stdio.h>
#include <fstream>
//when we are pulling the files if we ever encounter an error
//we have to call the system to stop becuase this is the one thing that cannot fail
//---------------------------------pull-movies Declaration--------------------------------------
//in this method we pull the information from the file assiated with the method and add to a list
MovieList* pullmovies(){
    MovieList *movies = new MovieList();
    ifstream inFile;
    int x=0;
    int y;
    string name2;
    double price2;
    string upc2;
    float rating2;
    int copys2;
    int year2;
    string title2;
    string format2;
    string director2;
    inFile.open("movielist.txt");
    if (!inFile) {
        exit(1);   // call system to stop
    }
    inFile >> x;
    for( int y = 0;y<x;y++){
        inFile >> name2;
        inFile >> price2;
        inFile >> upc2;
        inFile >> rating2;
        inFile >> copys2;
        inFile >> year2;
        inFile >> title2;
        inFile >> format2;
        inFile >> director2;
        //
        movies->createmovie( name2,  price2,  upc2,  rating2,  copys2,  year2,  title2,  format2,  director2);
    }
    return movies;
}
//---------------------------------pull-groceries Declaration--------------------------------------
//in this method we pull the information from the file assiated with the method and add to a list
GroceriesList* pullgroceries(){
    GroceriesList *gro = new GroceriesList();
    ifstream inFile;
    int x=0;
    int y;
    string name2;
    double price2;
    string upc2;
    string type2;//type of food
    string expiration2;//expiration date
    int calorie2;
    int quantity2;
    inFile.open("grocerielist.txt");
    if (!inFile) {
        exit(1);   // call system to stop
    }
    inFile >> x;
    for( int y = 0;y<x;y++){
        inFile >> name2;
        inFile >> price2;
        inFile >> upc2;
        inFile >> type2;
        inFile >> expiration2;
        inFile >> calorie2;
        inFile >> quantity2;
        gro->createGroceries(name2, price2, upc2, type2, expiration2, calorie2, quantity2);
    }
    return gro;
}
//---------------------------------pull-Clothing Declaration--------------------------------------
//in this method we pull the information from the file assiated with the method and add to a list
ClothingList* pullClothing(){
    ClothingList *gro = new ClothingList();
    ifstream inFile;
    int x=0;
    int y;
    string name2;
    double price2;
    string upc2;
    string type; // pants, shirts, sleepwear, accessories
    string gender; // man, women
    string sizePants; //Large, medium, small (for shirts)
    int sizeL; //length
    int sizeW; //width
    int quantity;
    inFile.open("ClothingList.txt");
    if (!inFile) {
        exit(1);   // call system to stop
    }
    inFile >> x;
    for( int y = 0;y<x;y++){
        inFile >> name2;
        inFile >> price2;
        inFile >> upc2;
        inFile >> type;
        inFile >> gender;
        inFile >> sizePants;
        inFile >> sizeL;
        inFile >> sizeW;
        inFile >> quantity;
        gro->CreateClothing(name2, price2, upc2, type, gender, sizePants, sizeL, sizeW, quantity);
    }
    return gro;
}//---------------------------------pull-electronics Declaration--------------------------------------
//in this method we pull the information from the file assiated with the method and add to a list
ElectronicsList* pulleletronics(){
    ElectronicsList *gro = new ElectronicsList();
    ifstream inFile;
    int x=0;
    int y;
    string name2;
    double price2;
    string upc2;
    string brandName;
    string modelNum;
    string type;
    inFile.open("ElectronicsList.txt");
    if (!inFile) {
        exit(1);   // call system to stop
    }
    inFile >> x;
    for( int y = 0;y<x;y++){
        inFile >> name2;
        inFile >> price2;
        inFile >> upc2;
        inFile >> brandName;
        inFile >> modelNum;
        inFile >> type;
        gro->createelectronic( name2,  price2,  upc2,  brandName,  modelNum,  type);
    }
    return gro;
}
//---------------------------------pull-cart Declaration--------------------------------------
//when we first start up the program we grab the contents of the users cart from storage
itemList* pullCart(){
    itemList *gro = new itemList();
    ifstream inFile;
    int x=0;
    int y;
    string name2;
    double price2;
    string upc2;
    inFile.open("CartList.txt");
    if (!inFile) {
        //if the file fails to load we quit the program becuase something is wrong xD
        exit(1);   // call system to stop
    }
    inFile >> x;
    for( int y = 0;y<x;y++){
        inFile >> name2;
        inFile >> price2;
        inFile >> upc2;
        
        gro->createitem(name2, price2, upc2);
    }
    return gro;

}

//---------------------------------save-cart Declaration--------------------------------------
//in this method we save the contents of the users cart every time a new item is added
void SaveCart(itemList* cart){
    if( remove( "CartList.txt" ) != 0 ){
        //delete the old cart file before remaking to avoid diffucatly saving
    }else{
        //pass off to ItemList for the saving of the list
         cart->cartlist();
}
}

#endif /* LoadHelper_hpp */
