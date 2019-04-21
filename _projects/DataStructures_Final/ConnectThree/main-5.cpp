//Author: Class
//11/26/17
#include <cstdlib>
#include <iostream>
#include <string>
#include"Grid.h"
#include "Boulder.h"
#include "Swap.h"
#include "Blocker.h"

using namespace std;

Grid game = Grid(6,7);
Boulder b;
Blocker blocker;
Swap s;

int storeMenu(){
	int choice;
	system("CLS");
	cout << "     Item Shop:" << endl
		 << "====================" << endl
		 << "1) Boulder" << endl
		 << "     Price: " << b.getPrice() << endl
		 << "     Description: " << b.getDes() << endl  
		 << "2) Swap" << endl
		 << "     Price: " << s.getPrice() << endl
		 << "     Description: " << s.getDes() << endl
		 << "3) Blocker" << endl
 		 << "     Price: " << blocker.getPrice() << endl
 		 << "     Description: " << blocker.getDes() << endl
		 << endl 
		 << "Enter your choice > ";
	cin >> choice;
	return choice;
}

int store(int tot){
	int choice;
	choice = storeMenu();
	switch (choice){
		case 1: 
			if (tot - b.getPrice() >= 0){
				b.use(&game);
				tot -= b.getPrice();
			} else {
				cout << "Not enough points!" << endl;
				Sleep(1000);
				system("CLS");
			}
			break;
		case 2:
            if (tot - s.getPrice() >= 0){
				s.use(&game);
				tot -= s.getPrice();
			} else {
				cout << "Not enough points!" << endl;
				Sleep(1000);
				system("CLS");
			}
			break;
		case 3:
			if(tot-blocker.getPrice() >=0 ){
				blocker.use(&game);
				tot -= blocker.getPrice();
			}else{
				cout<<"Not enough points!"<<endl;
				Sleep(1000);
				system("CLS");
			}
			break;
		default:
			break;
	}
	return tot;
}

int main()
{
    bool in, won = false;
    int at, bt;
    string choice;
    at = bt = 0;
    cout <<game.view();
    do
    {
         cout << "Player R: You have " << at << " points to spend!" << endl
		 	  << "Enter 'store' or a column number > ";
         cin >> choice;
         while (choice == "store"){
         	at = store(at);
         	cout << game.view();
         	cout << "Player R: You have " << at << " points to spend!" << endl
		 	     << "Enter 'store' or a column number > ";
         	cin >> choice;
		 }
         in = game.insert('R', atoi(choice.c_str()));  
         if (!in)
         	continue;
         cout <<game.view();
         at = at + game.win('R');
         system("CLS");
         //WIN CHECK
         if (at >= 5)
         	won = true;
         if (won)
         {
            cout <<game.view();
            cout <<"Player R won!\n";
         }
         else
         {
             cout <<game.view();
             do
             {
	            cout << "Player G: You have " << bt << " points to spend!" << endl
		 			 << "Enter 'store' or a column number > ";
         		cin >> choice;
         		while (choice == "store"){
         			bt = store(bt);
         			cout << "Player G: You have " << bt << " points to spend!" << endl
		 	     		 << "Enter 'store' or a column number > ";
         			cin >> choice;
		 		}
	            in = game.insert('G', atoi(choice.c_str()));
	         }while(!in);
             system("CLS");
             cout <<game.view();
             bt = bt + game.win('G');
            //WIN CHECK
            if (at >= 5)
         		won = true;
             if (won)
                cout <<"Player G won!\n";
             else
             {
                 system("CLS");
                 cout <<game.view();
             }
         }
         
         
    }while(!won);
    
    if (!in)
       cout <<"Game ended after column was filled!\n";

    system("PAUSE");
    return EXIT_SUCCESS;
}
