//Austin Huerta's program 3 for CS162
//on 11/01/23
//

#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;
const int P_NAME = 30;
const int P_ABILITY = 30;
const int P_DESC = 200;
const int P_STATE = 50;
const int P_LIST = 20;
//A struct containing information about a single pet!
struct pet
{
	char pName[P_NAME];
	char pAbility[P_ABILITY];
	char pDesc[P_DESC];
	char pState[P_STATE];
	int pSize = 0; //size in kilograms
				
};

//PROTOTYPES
void welcome();
void petList(pet &aPet, pet pList[P_LIST], int &pListSize);
//PROTOTYPES to run menu
void displayMenu();
void userChoice();
void runMenu();
//PROTOTYPES in menu
void addPet(pet &aPet, pet pList[P_LIST], int &pListSiz);
void interactPet();
void displayPet();
void displayBy();
void savePets(pet &aPet, pet pList[P_LIST], int &pListSize);
void loadPets(pet &aPet, pet pList[P_LIST], int &pListSize);
//main() will declare and maintain variables such as an array of pets, as well as call
//higher level functions such as welcome, functions to run menu, and maybe open file.
int main()
{
	pet aPet; // an object of struct pet
	pet pList[P_LIST];			
	int pListSize = 0;;
	welcome();
	addPet(aPet,pList,pListSize);
	

	cout << pList[0].pName << endl;
	cout << pList[0].pAbility << endl;
	savePets(aPet, pList, pListSize);
	return 0;
}

//DEFINITIONS

//This function will welcome the user and explain the program
//It takes no input and displays text
void welcome()
{

}
//This function is called to manage the array of pets, pList, as well as track the size
//of the array(20) and ensure array is not over cap.
//It takes input pet aPet, pList, pListSize
//it updates pList and pListSize by reference in main.

void petList(pet &aPet, pet pList[P_LIST], int &pListSize)
{
	if(pListSize < P_LIST)
	{
		pList[pListSize] = aPet;
		pListSize++;
	}
}

//This function displays to the user a list of options to allow them to interact with
//userChoice() and runMenu() functions.
//No input
//prints text to user
void displayMenu()
{

}

//This function takes userChoice in the form of an integer and sends it to runMenu()
//to select the appropriate menu option. Takes only valid menu options (1-7);
//takes integer and returns it to runMenu()
void userChoice()
{

}
//This function is the backbone of the user's interaction with this program
//it takes their choice as integer input from userChoice and selects from 7 options:
//1.	Enter a new pet
//2.	Play with or care for pet
//3.	Display all pets
//4.	Display pets by ability
//5.	Save existing pets to file (append)
//6.	Load from existing file
//7.	Quit
//input includes int choice from userChoice and various other flags to keep things running
//smoothly
//no direct output
void runMenu()
{

}

//IN MENU

//This function allows the user to create a pet. Takes input and loads struct pet 
//with the given input
//takes string inputs and outputs members of struct by reference
void addPet(pet &aPet, pet pList[P_LIST], int &pListSize)
{
	/*
	char pName[P_NAME];
	char pAbility[P_ABILITY];
	char pDesc[P_DESC];
	char pState[P_STATE];
	int pSize = 0; //size in kilograms
	*/
	cout << "Name your pet: ";
	cin.get(aPet.pName, P_NAME, '\n');
	cin.ignore(100,'\n');

	cout << "Give your pet an ability: ";
	cin.get(aPet.pAbility, P_ABILITY, '\n');
	cin.ignore(100,'\n');

	cout <<  "Describe your pet: ";
	cin.get(aPet.pDesc, P_DESC, '\n');
	cin.ignore(100, '\n');

	cout << "pet state test";
	cin.get(aPet.pState, P_STATE, '\n');
	cin.ignore(100, '\n');

	//Add this pet to pList
	petList(aPet, pList, pListSize);

}
void interactPet()
{

}
void displayPet()
{

}
void displayBy()
{

}
//This function will save the user’s current pets contained in pList to the external data file. The data file will be appended
//using ios :: app, and separated by ‘|’. Each line will contain ‘\n’ at the end of each line.
//Each line will represent a single pet entry!
//This function will take pet A pet, pList and pListSize as input and file output will be the output
void savePets(pet &aPet, pet pList[P_LIST], int &pListSize)
{
	ofstream outfile;
	outfile.open("virtual_pet.txt");

	if(outfile)
		{
			cout << "File opened " << endl;
			for(int i = 0; i < pListSize;++i)
			{
				cout << "write [i]"
					 << endl;
				outfile << pList[i].pName << '|' << pList[i].pAbility << '|' << pList[i].pDesc << '|' << pList[i].pState << '|'
					<< pList[i].pSize << '\n';
			}
		}
	outfile.close();
}
	/*
	char pName[P_NAME];
	char pAbility[P_ABILITY];
	char pDesc[P_DESC];
	char pState[P_STATE];
	int pSize = 0; //size in kilograms
	*/
void loadPets(pet &aPet, pet pList[P_LIST], int &pListSize)
{
	ifstream infile;
	infile.open("virtual_pet.txt");

	if(infile)
	{
		infile.get();
		infile.ignore(100,'|');
	}


}

