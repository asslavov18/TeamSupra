#pragma once
#include <iostream>
#include <conio.h>
#include <fstream>
#include "DataTypes.h"
#include "ChangingDataFunctions.h"

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
    cin.ignore();
    getline(cin, role);
    cout << "Input email: ";
    cin >> email;
    id = students[students.size() - 1].id + 1;

    addStudentToFile();
}

void STUDENT::showStudent()
{
    cout << "  Name: " << name << " " << surname << endl;
    cout << "  Grade: " << schoolClass << endl;
    cout << "  Role: " << role << endl;
    cout << "  Email: " << email << endl;
}

void STUDENT::addStudentToFile()
{
    ofstream outputFile;
    //using ios::app to set the stream's position indicator to the end of the stream before each output operation.
    outputFile.open("StudentsFile.txt", ios::app); 

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
    cin.ignore();
    getline(cin, description);
    cout << "Input date of setup: ";
    cin >> date;
    status = "In use";
    showAllStudents();
    cout << "Which students do you want to add in your team(by id) enter -1 to stop: ";
    
    //we need to be cautious of the user entering a single id
    //more than one time
    bool valid;
    int id = 0, used[100] = { 0 };
    while (id != -1)
    {
        cin >> id;
        valid=checkValidId(id);
        if (!valid&&id!=-1)
        {
            cout << "Enter valid id!" << endl;
            continue;
        }

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

    addTeacherToFile();
    taughtTeams = searchTeamsByNames();
}

void TEACHER::addTeacherToFile()
{
    ofstream outputFile;
    //using ios::app to set the stream's position indicator to the end of the stream before each output operation.
    outputFile.open("TeachersFile.txt", ios::app);

    if (outputFile.is_open())
    {
        outputFile << name << " " << surname << " | " << email <<endl;
        outputFile.close();
    }
}