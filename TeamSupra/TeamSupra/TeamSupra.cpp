#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>
#include "DataTypes.h"
#include "Methods.h"
#include "ChangingDataFunctions.h"
#include "Menus.h"

using namespace std;

bool Menu()
{
    int choice;
    showMenuOptions();
    cout << "\nSelect an option: ";
    cin >> choice;

    //We call the corresponding function for the choice

    switch (choice)
    {
    case 1:
        system("cls"); 
        showStudentMenu();
        StudentMenuOptions();
        break;

    case 2:
        system("cls"); 
        showTeacherMenu();
        TeacherMenuOptions();
        break;

    case 3:
        system("cls"); 
        showTeamMenu();
        TeamsMenuOptions();
        break;

    case 0:
        cout << "\nHave a nice day!" << endl;
        return false;
        break;

    default: 
        cout << "Input a valid choice!" << endl; 
        break;
    }

    //If the choice is not 0 or invalid the Menu function is called again

    return true;
}

int main()
{
    //We leave the while only when 0 is entered and false is returned

    while (Menu())
    {
        ;
    }
}