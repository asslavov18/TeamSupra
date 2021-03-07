#pragma once
#include<conio.h>
#include<iostream>
#include "DataTypes.h"
using namespace std;


void pressAnyKey()
{
    cout << '\n' << "Press any key to continue...";
    _getch();
}


void addStudent()
{
    STUDENT student;
    student.askForData();
    students.push_back(student);
    cout << endl << "Successfully added new student" << endl;
    pressAnyKey();
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
    //the user is asked to enter a email until they enter a valid one
    //the user with this email is then deleted in the removeStudentByEmail function
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
    //search by email returns the index of the searched student
    //we use that index to delete the said student
    students.erase(students.begin() + searchByEmail());
    cout << endl << "Successfully removed student" << endl;
    pressAnyKey();
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
    cout << "Here are the names of all existing teams:" << endl;
    showAllTeamNames();
    cout << "Enter the names of the teams you want to teach(-1 to leave)" << endl;
    //the user enters a string until they enter an existing team name
    do
    {
        cin >> teamName;
        found = 0;
        for (size_t i = 0; i < teams.size(); i++)
        {
            if (teams[i].name == teamName)
            {
                //we then add the existing team name to the vector of the teams
                //that the current teacher consults
                foundTeams.push_back(teams[i]);
                cout << "Successfully added this team" << endl;
                found = 1;
            }
        }
        if (!found) cout << "Input an existing team name!" << endl << endl;
    } while (teamName != "-1");
    return foundTeams;
}