//Los Angeles Valley College
//CSIT 839
//Spring 2014
//Steve Mario Correa
//Assignment 4
//This program displays a menu which permits the user three choices: (1) add a student to the waiting list (by name and amount of the "contribution"; (2) view a list of the students, by name and amount of contribution, in the order stated above; or (3) exit the program.
#ifndef PERSON_H
#define PERSON_H
#include <string>
struct PersonRec {
	//string containing person's name
	std::string sName;
	//Amount of bribe (assumed to be whole number for purpose of program)
	int nBribe;
	//Pointer to next leaf to the left (or to NULL if no leaf to the left)
	PersonRec* lChild;
	//Pointer to next leaf to the right (or to NULL if no leaf to the right)
	PersonRec* rChild;
	PersonRec(std::string, int, PersonRec*, PersonRec*);
	~PersonRec();
};
class CTree {
	private:
		PersonRec* root;
	public:
		CTree();
		~CTree();
		void ViewList();
		void AddToList();
};
#endif