//Author: Drew
//11/26/17
#include <cstdlib>
#include <iostream>
#include"Grid.h"
using namespace std;

int main(int argc, char *argv[])
{
    Grid game;
    bool in, won;
    int col;
    cout <<game.view();
    do
    {
         cout <<"Player A, enter a column: ";
         cin >> col;
         in = game.insert('A', col);  
         if (!in)
            break; 
         cout <<game.view();
         won = game.win('A');
         system("CLS");
         if (won)
         {
            cout <<game.view();
            cout <<"Player A won!\n";
         }
         else
         {
             cout <<game.view();
             cout <<"Player B, enter a column: ";
             cin >> col;
             in = game.insert('B', col);
             if (!in)
                break;
             system("CLS");
             cout <<game.view();
             won = game.win('B');
             if (won)
                cout <<"Player B won!\n";
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
