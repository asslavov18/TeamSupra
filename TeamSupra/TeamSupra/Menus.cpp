#include <iostream>
#include "Menus.h"

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
    cout << "||   2. Show all teachers                            ||" << endl;
    cout << "||   3. Remove teacher                               ||" << endl;
    cout << "||___________________________________________________||\n" << endl;
}

void showTeamMenu()
{
    system("cls");
    cout << "------------------WELCOME TO TEAM MENU-----------------" << endl;
    cout << "||                                                   ||" << endl;
    cout << "||   1. Add a Team                                   ||" << endl;
    cout << "||   2. Show all Teams                               ||" << endl;
    cout << "||   3. Delete Team                                  ||" << endl;
    cout << "||___________________________________________________||\n" << endl;
}

