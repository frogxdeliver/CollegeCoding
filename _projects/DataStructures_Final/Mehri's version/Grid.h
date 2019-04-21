//Grid.h
//Author: Drew
//11/26/17

#include<string>
using namespace std;
#ifndef GRID_H
#define GRID_H
class Grid
{
      public:
          Grid();
          bool insert(char player, int col);
          bool win(char player);
          string view();
      private:
          char matrix[6][7];
          int rowCount[7];  //row count of the same letter in each column
};

Grid::Grid()
{
     for(int row = 0; row < 6; row++)
         for (int col = 0; col < 7; col++)
              matrix[row][col] = 'E'; 
     for (int i = 0; i < 7; i++)
         rowCount[i] = 0;       
}

bool Grid::win(char player) 
{
     int count = 0;
     //scan vertical
     
     for (int col = 0; col < 7; col++)
     {
         for (int row = 0; row < 6; row++)
                 if (matrix[row][col] == player)
                    count++;
                 else
                 if (count >= 4)
                    return true;
                 else
                     count = 0;           
     }
     
     
	 count = 0; //reset 
     //scan horizontally
     for (int row = 0; row<6; row++)
     {
		for(int col = 0; col<7; col++)
			if(matrix[row][col] == player)
				count++;
			else if (count>=4)
				return true;
			else
				count = 0;
		
	}
	
	count = 0;
     //scan in diagonals.
     //scan right
     for(int row = 6; row>0; row--){
		for(int col =7; col>0; col--)
			for (int z = 0; z<=row && z<=col; z++)
				if(matrix[row-z][col-z] == player)
					count++;
				else if (count>=4)
					return true;
				else
	      			count = 0;
			
			
	}
	
	
	//scan left
	for(int i = 6; i>0; i--){
		for(int j = 0; j<7; j++)
			for (int z = 0; z<=i && z<=7-4; z++)
				if(matrix[i-z][j+z] == player)
					count+=1;
				else if (count>= 4)
					return true;
				else
					count = 0;
		
	}
     
    
    return false;
}
bool Grid::insert(char player, int col)
{
     if (matrix[0][col -1] != 'E')  //check if column is full
        return false;
     else
     
         for (int row = 5; row >= 0; row--)
             if (matrix[row][col -1] == 'E')
             {
                matrix[row][col -1] = player;
                return true;
             }
}
string Grid::view()
{
     string str;
     
     for (int row = 0; row < 6; row++)
     {
         for (int col = 0; col < 7; col++)
         {
             str += " |X| ";
             str += matrix[row][col];
         }
             
         str += " |X|\n";
     }
     str += " _____________________________________________\n";
     str += " |X| 1 |X| 2 |X| 3 |X| 4 |X| 5 |X| 6 |X| 7 |X|\n";
     return str;
}

#endif
