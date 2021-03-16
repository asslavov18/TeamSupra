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
    cout << "||                                                   ||" << endl;
    cout << "||   1. Student menu                                 ||" << endl;
    cout << "||   2. Teacher menu                                 ||" << endl;
    cout << "||   3. Team menu                                    ||" << endl;
    cout << "||   0. Leave the program                            ||" << endl;
    cout << "||___________________________________________________||" << endl;
}

void showStudentMenu()
{
    system("cls");
    cout << "----------------WELCOME TO STUDENT MENU----------------" << endl;
    cout << "||                                                   ||" << endl;
    cout << "||   1. Add a student                                ||" << endl;
    cout << "||   2. Remove a student                             ||" << endl;
    cout << "||   3. Remove student from StudentFile              ||" << endl;
    cout << "||   4. Show all students                            ||" << endl;
    cout << "||   5. Show all students from StudentFile           ||" << endl;
    cout << "||___________________________________________________||\n" << endl;
}

void showTeacherMenu()
{
    system("cls");
    cout << "----------------WELCOME TO TEACHER MENU----------------" << endl;
    cout << "||                                                   ||" << endl;
    cout << "||   1. Add a teacher                                ||" << endl;
    cout << "||   2. Sholl all teachers                           ||" << endl;
    cout << "||   3. Remove teacher from TeacherFile              ||" << endl;
    cout << "||___________________________________________________||\n" << endl;
}

void showTeamMenu()
{
    system("cls");
    cout << "------------------WELCOME TO TEAM MENU-----------------" << endl;
    cout << "||                                                   ||" << endl;
    cout << "||   1. Add a Team                                   ||" << endl;
    cout << "||___________________________________________________||\n" << endl;
}

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
        cout << "\nHave a nice day." << endl;
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