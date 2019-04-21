//Main.cpp
//Project 1
//names: Lukas Fuller, Alan Morrison, William Wright, Sharon Blankenship, Will Varner

#include <iostream>
#include "StudentList.cpp"
using namespace std;
int main(int argc, const char * argv[]) {
    
    classlist* classe = new classlist;
    cout<<"Enter the amount of courses this university has: ";
    int len;
    cin >> len;
    for (int i = 0; i<len; i++) {
        cout<<"Enter a name for class "<<(i+1)<<": ";
        string name;
        cin >> name;
        classe->createxclass(name, NULL, NULL);
        
    }
    int stuc;
     cout<<"\nHow many students are you entering? ";
    cin>>stuc;
    studentlist* stulist = new studentlist;
    for(int i =0;i<stuc;i++){
        cout<<"Enter a first name for student "<<(i+1)<<": ";
        string fname;
        cin >> fname;
        cout<<"Enter a last name for student "<<(i+1)<<": ";
        string lname;
        cin >> lname;
        cout<<"\nHow many classes is the student taking? ";
        int classc;
        cin >> classc;
        classes* classarr[classc];
        double grades[classc];
        for(int i=0;i<classc;i++){
            int v =0;
            do{
            	string fname;
                cout<<"\nEnter the name of class "<<(i+1)<<": ";
                cin >> fname;
                v=0;
                classarr[i] = classe->findclass(fname);
                if(classarr[i]!= NULL){
                    v=1;
                }else{
                    cout<<"\nERROR the class you entered does NOT exist!"<<endl;
                }
            }while(v==0);
            cout<<"Enter the students grade for class "<<(i+1) << "(IN PERCENTAGE %): ";
            double gname;
            cin >> gname;
            grades[i] = gname;
        }
        
        
        stulist->createstudent(fname, lname, classarr, grades,classc);
        
    }
    stulist->displaystudents();
    
}
