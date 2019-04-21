#ifndef SWAP_H
#define SWAP_H
#include "Item.h"
using namespace std;

class Swap : public Item {
	public:

	    Swap() : Item(1, "This is used to swap the top two pieces of a column.") {
    	};

    	void use(Grid *g) {
        	system("CLS");
        	cout << g->view();
        	cout << "In which column would you like to swap pieces? > ";
        	cin >> col;
        	system("CLS");
        	temp1 = g -> removeTop(col);
        	temp2 = g -> removeTop(col);
        	g -> insert(temp1,col);
        	g -> insert(temp2,col);
        	//cout << g -> view(); ANGERY
    	}
	private:
    	int col;
    	char temp1;
    	char temp2;
};



#endif /* SWAP_H */

