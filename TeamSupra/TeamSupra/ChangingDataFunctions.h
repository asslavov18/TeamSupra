#pragma once
#include<conio.h>
#include<iostream>
#include "DataTypes.h"
using namespace std;

void addStudent()
{
    STUDENT student;
    student.askForData();
    students.push_back(student);
}

void addTeam()
{
    TEAM team;
    team.askForData();
    teams.push_back(team);
}

void addTeacher()
{
    TEACHER teacher;
    teacher.askForData();
    teachers.push_back(teacher);
}



void pressAnyKey()
{
    cout << '\n' << "Press a key to continue...";
    _getch();
}

void showAllStudents()
{
    for (size_t i = 0; i < students.size(); i++)
    {
        cout << students[i].name << " " << students[i].surname << endl;
        cout << "id: " << students[i].id << endl;
        cout << "schoolClass: " << students[i].schoolClass << endl;
        cout << "role: " << students[i].role << endl;
        cout << "email: " << students[i].email << endl;
        if (i != students.size() - 1) cout << "-------------------" << endl;
    }
}

int searchByEmail()
{
    showAllStudents();
    string email;
    do
    {
        cout << endl << "Enter the email of the student that you want to delete: ";
        cin >> email;
        for (size_t i = 0; i < students.size(); i++)
        {
            if (students[i].email == email)
            {
                return i;
                break;
            }
        }
        cout << "Enter a valid email!" << endl;
    } while (1);

}

void removeStudentByEmail()
{
    string email;
    students.erase(students.begin() + searchByEmail());
}


void showAllTeamNames()
{
    for (size_t i = 0; i < teams.size(); i++)
    {
        cout << teams[i].name << endl;
    }
}

vector<TEAM> searchTeamsByNames()
{
    vector<TEAM> foundTeams;
    string teamName;
    bool found;
    showAllTeamNames();
    cout << "Enter the names of the teams you want to teach" << endl;
    do
    {
        cin >> teamName;
        found = 0;
        for (size_t i = 0; i < teams.size(); i++)
        {
            if (teams[i].name == teamName)
            {
                foundTeams.push_back(teams[i]);
                cout << "Successfully added this team" << endl << endl;
                found = 1;
            }
        }
        if (!found) cout << "Input an existing team name!" << endl << endl;
    } while (teamName != "-1");
    return foundTeams;
}