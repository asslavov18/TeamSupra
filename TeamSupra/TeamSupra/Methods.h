#pragma once
#include<iostream>
#include"DataTypes.h"
#include"ChangingDataFunctions.h"
using namespace std;

void STUDENT::askForData()
{
    cout << "Input name: ";
    cin >> name;
    cout << "Input surname: ";
    cin >> surname;
    cout << "Input schoolClass: ";
    cin >> schoolClass;
    cout << "Input role: ";
    cin >> role;
    cout << "Input email: ";
    cin >> email;
    id = students[students.size() - 1].id + 1;
}


void TEAM::askForData()
{
    cout << "Input team name: ";
    cin >> name;
    cout << "Input description: ";
    cin >> description;
    cout << "Input date of setup: ";
    cin >> date;
    showAllStudents();
    cout << "Which students do you want to add in your team(by id) enter -1 to stop: ";
    int id = 0, used[100] = { 0 };
    while (id != -1)
    {
        cin >> id;
        if (used[id] == 0)
        {
            members.push_back(students[id]);
            used[id] = 1;
        }
    }
}

void TEACHER::askForData()
{
    string teamName;
    cout << "Input name: ";
    cin >> name;
    cout << "Input surname: ";
    cin >> surname;
    cout << "Input email: ";
    cin >> email;
    taughtTeams = searchTeamsByNames();
}