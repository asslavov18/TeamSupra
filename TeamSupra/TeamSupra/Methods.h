#pragma once
#include<iostream>
#include<conio.h>
#include <fstream>
#include"DataTypes.h"
#include"ChangingDataFunctions.h"
using namespace std;
//used to fill a STUDENT variable with data
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
    AddStudentToFile();
}

void STUDENT::AddStudentToFile()
{
    ofstream outputFile;
    outputFile.open("StudentsFile.txt", ios::app); //using ios::app to not overwtite the iformation

    if (outputFile.is_open())
    {
        outputFile << name << " " << surname << " | " << schoolClass << " | " << role << " | " << email << endl;
        outputFile.close();
    }
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
    //we need to be cautious of the user entering a single id
    //more than one time
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
    AddTeacherToFile();
    taughtTeams = searchTeamsByNames();
}

void TEACHER::AddTeacherToFile()
{
    ofstream outputFile;
    outputFile.open("TeachersFile.txt", ios::app); //using ios::app to not overwtite the iformation

    if (outputFile.is_open())
    {
        outputFile << name << " " << surname << " | " << email <<endl;
        outputFile.close();
    }
}