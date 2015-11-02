//Los Angeles Valley College
//CSIT 839
//Spring 2014
//Steve Mario Correa
//Assignment 4
//This program displays a menu which permits the user three choices: (1) add a student to the waiting list (by name and amount of the "contribution"; (2) view a list of the students, by name and amount of contribution, in the order stated above; or (3) exit the program.
#include "tree.h"
#include <iostream>
PersonRec::PersonRec(std::string sNameToSet, int nBribeToSet, PersonRec* lChildToSet, PersonRec* rChildToSet) {
	sName = sNameToSet;
	nBribe = nBribeToSet;
	lChild = lChildToSet;
	rChild = rChildToSet;
}
PersonRec::~PersonRec() {
	if(lChild != NULL)
		lChild = NULL;
	if(rChild != NULL)
		rChild = NULL;
}
CTree::CTree() {
	root = NULL;
}
CTree::~CTree() {
	if(root != NULL) {
		PersonRec** personrecToDelete = &root;
		bool bHaveDeletedRoot = false;
		do {
			if((*personrecToDelete)->rChild == NULL) {
				delete (*personrecToDelete);
				(*personrecToDelete) = NULL;
				if(personrecToDelete == &root)
					bHaveDeletedRoot = true;
				else
					personrecToDelete = &root; //Start over
			} else {
				personrecToDelete = &(*personrecToDelete)->rChild;
			}
		} while(bHaveDeletedRoot == false);
	}
}
void CTree::ViewList() {
	if(root == NULL) {
		std::cout << "\nList is empty\n";
	} else {
		PersonRec* personrecToShow = root;
		int nPlaceInLine = 1;
		std::cout << "\n# Name Contribution\n";
		std::cout << "=======================================\n\n";
		do {
			std::cout << nPlaceInLine << " ";
			std::cout << personrecToShow->sName << " $";
			std::cout << personrecToShow->nBribe << "\n";
			personrecToShow = personrecToShow->rChild;
			nPlaceInLine++;
		} while(personrecToShow != NULL);
	}
}
void CTree::AddToList() {
	std::string sNameOfAddition;
	int nBribeOfAddition;
	std::cout << "Enter the person's name: ";
	getline(std::cin, sNameOfAddition);
	std::cout << "Enter the person's contribution: ";
	std::cin >> nBribeOfAddition;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if(root == NULL) {
		root = new PersonRec(sNameOfAddition, nBribeOfAddition, NULL, NULL);
	} else {
		bool bPlacedAdditionInList = false;
		bool bBribeAmountWasAlreadyAccepted = false;
		PersonRec** personrecAdditionMightPlaceInFrontOf = &root;
		PersonRec** lChildLast = &(*personrecAdditionMightPlaceInFrontOf)->lChild;
		do {
			if((*personrecAdditionMightPlaceInFrontOf) == NULL) {
				PersonRec* temp = new PersonRec(sNameOfAddition, nBribeOfAddition, (*lChildLast), NULL);
				(*personrecAdditionMightPlaceInFrontOf) = temp;
				bPlacedAdditionInList = true;
			} else {
				if((*personrecAdditionMightPlaceInFrontOf)->nBribe < nBribeOfAddition) {
					PersonRec* temp = new PersonRec(sNameOfAddition, nBribeOfAddition, (*personrecAdditionMightPlaceInFrontOf)->lChild, (*personrecAdditionMightPlaceInFrontOf));
					(*personrecAdditionMightPlaceInFrontOf)->lChild = temp;
					(*personrecAdditionMightPlaceInFrontOf) = temp;
					bPlacedAdditionInList = true;
				} else if((*personrecAdditionMightPlaceInFrontOf)->nBribe == nBribeOfAddition) {
						bBribeAmountWasAlreadyAccepted = true;
				} else {
					lChildLast = &(*personrecAdditionMightPlaceInFrontOf)->lChild;
					personrecAdditionMightPlaceInFrontOf = &(*personrecAdditionMightPlaceInFrontOf)->rChild;
				}
			}
		} while(bPlacedAdditionInList == false && bBribeAmountWasAlreadyAccepted == false);
	}
}