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
void userChoice(int &userNum);
void runMenu(pet &aPet, pet pList[P_LIST], int &pListSize, int &userChoice);
//PROTOTYPES in menu
void addPet(pet &aPet, pet pList[P_LIST], int &pListSize);
void interactPet();
void displayPet(pet pList[], int pListSize);
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
	int userNum = 0;
	welcome();
	
	while(userNum != 7)
		runMenu(aPet, pList, pListSize, userNum);
	return 0;
}

//DEFINITIONS

//This function will welcome the user and explain the program
//It takes no input and displays text
void welcome()
{
	cout << "Welcome. This program will allow you to create, care for, and store your virtual pets!" << endl;
	cout << "Please guard your heart closely, for these pets will steal it!" << endl;	
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
	cout << endl << endl << "Menu - enter number 1-7 to proceed:" << endl;
	cout << "1.	Enter a new pet" << endl;
	cout << "2.	Play with or care for pet" << endl;
	cout << "3.	Display all pets" << endl;
	cout << "4.	Display pets by ability" << endl;
	cout << "5.	Save existing pets to file (append)" << endl;
	cout << "6.	Load from existing file" << endl;
	cout << "7.	Quit" << endl;

}

//This function takes userChoice in the form of an integer and sends it to runMenu()
//to select the appropriate menu option. Takes only valid menu options (1-7);
//takes integer and returns it to runMenu()
void userChoice(int &userChoice)
{
	cout << "Choose: ";
	cin >> userChoice;
	cin.ignore(100,'\n');

	while(userChoice < 1 || userChoice > 7)
	{
		cout << "Error! Please enter a number between 1 and 7!" << endl;
		cout << "Choose: ";
		cin >> userChoice;
		cin.ignore(100, '\n');
	}

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
void runMenu(pet &aPet, pet pList[P_LIST], int &pListSize, int &userNum)
{
	displayMenu();
	userChoice(userNum);
	switch(userNum)
	{
		case 1:
			addPet(aPet, pList, pListSize);
			break;
		case 2:
			//interactPet();
			break;
		case 3:
			displayPet(pList, pListSize);
			break;
		case 4:
			//displayBy();
			break;
		case 5:
			savePets(aPet, pList, pListSize);
			break;
		case 6:
			loadPets(aPet, pList, pListSize);
			break;
		case 7:
			cout << endl;
			cout << "Come back soon!" << endl;
			return;
	}
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
	
	cout << "Weight of pet: ";
	cin >> aPet.pSize;
	cin.ignore(100,'\n');

	//Add this pet to pList
	petList(aPet, pList, pListSize);

}
void interactPet()
{

}
void displayPet(pet pList[], int pListSize)
{
	for(int i = 0; i < pListSize; ++i)
	{
		cout << "\n Pet #" << i << endl;
		cout << '\t' << pList[i].pName << endl;
		cout << '\t' << pList[i].pAbility << endl;
		cout << '\t' << pList[i].pDesc << endl;
		cout << '\t' << pList[i].pSize << endl;
		
	}
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

	if(!outfile)
		{
			cout << "Error when opening file! Save cannot proceed." << endl;
		}
	else{
			cout << "Save in progress..." << endl;
			cout << "Save complete!" << endl;

						
			for(int i = 0; i < pListSize;++i)
			{
				outfile << pList[i].pName << '|' << pList[i].pAbility << '|' << pList[i].pDesc << '|'
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

	if(!infile)
	{
		cout << "Error when loading from file! Load cannot proceed." << endl;
	}
	else
	{
		pListSize = 0;
		infile.get(pList[pListSize].pName, P_LIST, '|');
		infile.ignore(100,'|');
		
		while(!infile.eof() && pListSize < P_LIST)
		{
			infile.get(pList[pListSize].pAbility, P_ABILITY, '|');
			infile.ignore(100,'|');
			
			infile.get(pList[pListSize].pDesc, P_DESC, '|');
			infile.ignore(100,'|');
			
			infile >> pList[pListSize].pSize;
			infile.ignore(100,'\n');
			pListSize++;

			infile.get(pList[pListSize].pName, P_LIST, '|');
			infile.ignore(100,'|');
		}
	}


}

