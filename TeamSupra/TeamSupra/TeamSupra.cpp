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
    cout << "||   1. Add a student                                ||" << endl;
    cout << "||   2. Remove a student                             ||" << endl;
    cout << "||   3. Remove student from StudentFile              ||" << endl;
    cout << "||   4. Show all students                            ||" << endl;
    cout << "||   5. Show all students from StudentFile           ||" << endl;
    cout << "||   6. Add a team                                   ||" << endl;
    cout << "||   7. Add a teacher                                ||" << endl;
    cout << "||   8. Show all Teachers                            ||" << endl;
    cout << "||   9. Delete Teacher                               ||" << endl;
    cout << "||   0. Leave the program                            ||" << endl;
    cout << "||___________________________________________________||" << endl;
}


bool Menu()
{
    int choice;
    showMenuOptions();
    cout << "\nSelect an option: ";
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
        deleteLineFromStudentFile();
        pressAnyKey();
    }
    else if (choice == 4)
    {
        system("cls");
        showAllStudents();
        pressAnyKey();
    }

    else if (choice == 5)
    {
        system("cls");
        ReadFromStudentFile();
        pressAnyKey();
    }

    else if (choice == 6)
    {
        system("cls");
        addTeam();
    }
    else if (choice == 7)
    {
        system("cls");
        addTeacher();
    }
    else if (choice == 8)
    {
        system("cls");
        ReadFromTeacherFile();
        pressAnyKey();
    }
    else if (choice == 9)
    {
        system("cls");
        deleteLineFromTeacherFile();
        pressAnyKey();
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