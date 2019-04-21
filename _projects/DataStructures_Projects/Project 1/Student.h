//Student.h
#ifndef STUDENT_H
#define STUDENT_H


class StudentList
{
	private:
		struct node{
			string stuLName, stuFName, stuID;
			node* next;
		};
		typedef struct node* nodePtr;
		
		nodePtr head;
		nodePtr curr;
		nodePtr temp;
	public:
		StudentList();
		void AddNode (string stuLName, string stuFName, string stuID);
		void DeleteNode(string delStu);
		void PrintList();
};
#endif // Student_H
