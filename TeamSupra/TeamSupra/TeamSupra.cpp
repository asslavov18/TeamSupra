#include <iostream>
#include<vector>
#include<conio.h>
#include <fstream>
#include "DataTypes.h"
#include "Methods.h"
#include "ChangingDataFunctions.h"
using namespace std;

void showMenuOptions()
{
    //clears the console
    system("cls");
    cout << "------------WELCOME TO TEAM SUPRA'S PROJECT------------" << endl;
    cout << "Select an option" << endl;
    cout << "1. Add a student" << endl;
    cout << "2. Remove a student" << endl;
    cout << "3. Show all students" << endl;
    cout << "4. Add a team" << endl;
    cout << "5. Add a teacher" << endl;
    cout << "0. Leave the program" << endl;
}


bool Menu()
{
    int choice;
    showMenuOptions();
    cin >> choice;
    //We call the corresponding function for the choice
    if (choice == 1)
    {
        system("cls");
        addStudent();
    }
    else if (choice == 2)
    {
        system("cls");
        removeStudentByEmail();
    }
    else if (choice == 3)
    {
        system("cls");
        showAllStudents();
        pressAnyKey();
    }
    else if (choice == 4)
    {
        system("cls");
        addTeam();
    }
    else if (choice == 5)
    {
        system("cls");
        addTeacher();
    }
    else if (choice == 0)
    {
        cout << "Have a nice day." << endl;
        return false;
    }
    else
    {
        cout << "Input a valid choice!" << endl;
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