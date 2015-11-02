//Los Angeles Valley College
//CSIT 839
//Spring 2014
//Steve Mario Correa
//Assignment 5
//This program displays a menu which permits the user three choices: (1) add a student to the waiting list (by name and amount of the "contribution"; (2) view a list of the students, by name and amount of contribution, in the order stated above; or (3) exit the program.
#include "tree.h"
#include <cstdlib>
#include <iostream>
int displayMenu();
void processChoice(int, CTree&);
int main() {
	int num;
	CTree ct;

	do {
		num = displayMenu();
		processChoice(num, ct);
	} while(num != 3);

	return 0;
}
int displayMenu() {
	int choice;

	std::cout << "\nMenu\n";
	std::cout << "==============================\n\n";
	std::cout << "1. Add student to waiting list\n";
	std::cout << "2. View waiting list\n";
	std::cout << "3. Exit program\n\n";
	std::cout << "Please enter choice: ";
	std::cin >> choice;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return choice;
}
void processChoice(int choice, CTree& myTree) {
	switch(choice) {
		case 1: myTree.AddToList(); break;
		case 2: myTree.ViewList(); break;
	}
}