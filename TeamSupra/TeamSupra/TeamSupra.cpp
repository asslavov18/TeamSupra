#include <iostream>
#include<vector>
#include "DataTypes.h"
#include "Methods.h"
#include "ChangingDataFunctions.h"
using namespace std;

void showMenuOptions()
{
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
        return false;
    }
    return true;
}

int main()
{
    while (Menu())
    {
        ;
    }
}