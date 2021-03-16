#pragma once
#include <conio.h>
#include <fstream>
#include <iostream>
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
    cout << "Current available teams:\n\n";
    for (size_t i = 0; i < teams.size(); i++)
    {
        cout <<"Team name: "<< teams[i].name << endl;
    }
}

void showAllTeams()
{
    cout << "Current available teams:\n\n";
    for (size_t i = 0; i < teams.size(); i++)
    {
        
        cout << " Team name: " << teams[i].name << endl;
        cout << " Description: " << teams[i].description << endl;
        cout << " Date of setup: " << teams[i].date << endl;
        cout << " Status: " << teams[i].status << endl;
        cout << "\n Members: " << endl;
        for (size_t j = 0; j < teams[i].members.size(); j++)
        {
            teams[i].members[j].showStudent();
            if (j != teams[i].members.size() - 1)
            {
                cout << "------------------------------------" << endl;
            }
        }
        cout << "_________________________________________\n" << endl;
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

void ReadFromStudentFile()
{
    ifstream readFile;
    string line;

    readFile.open("StudentsFile.txt", ios::out);

    if (readFile.is_open())
    {
        while (!readFile.eof())
        {
            getline(readFile, line);
            cout << line << endl;
        }
    }
    readFile.close();
}

void ReadFromTeacherFile()
{
    ifstream readFile;
    string line;

    readFile.open("TeachersFile.txt", ios::out);

    if (readFile.is_open())
    {
        while (!readFile.eof())
        {
            getline(readFile, line);
            cout << line << endl;
        }
    }
    readFile.close();
}

bool checkValidId(int id)
{
    return (id >= 0 && id <= students[students.size() - 1].id);
}

void deleteLineFromStudentFile()
{
    int n;
    const char* file_name = ("StudentsFile.txt");
    ifstream is(file_name);
    ofstream ofs;

    ReadFromStudentFile();

    cout << endl;
    cout << "Enter line of the student you want to delete : ";
    cin >> n; 
    cout << endl;

    ofs.open("temp.txt", ios::out);

    char c;
    int lineNum = 1;
    while (is.get(c))
    {
        // if a newline character 
        if (c == '\n')
        {
            lineNum++;
        }

        // file content not to be deleted 
        if (lineNum != n)
        {
            ofs << c;
        }
    }

    ofs.close();
    is.close();

    // remove the original file 
    remove(file_name);
    // rename the file 
    rename("temp.txt", file_name);

    cout << "File after deletion :\n " << endl;
    ReadFromStudentFile();
}

void deleteLineFromTeacherFile()
{
    int n;
    const char* file_name = ("TeachersFile.txt");
    ifstream is(file_name);
    ofstream ofs;

    ReadFromTeacherFile();

    cout << endl;
    cout << "Enter line of the teacher you want to delete : ";
    cin >> n;
    cout << endl;

    ofs.open("temp.txt", ios::out);

    char c;
    int lineNum = 1;
    while (is.get(c))
    {
        // if a newline character 
        if (c == '\n')
        {
            lineNum++;
        }

        // file content not to be deleted 
        if (lineNum != n)
        {
            ofs << c;
        }
    }

    ofs.close();
    is.close();

    // remove the original file 
    remove(file_name);
    // rename the file 
    rename("temp.txt", file_name);

    cout << "File after deletion :\n " << endl;
    ReadFromTeacherFile();
}



void StudentMenuOptions()
{
    int choice;
    cout << "Enter your choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        system("cls");
        addStudent();
        break;

    case 2:
        system("cls");
        removeStudentByEmail();
        break;

    case 3:
        system("cls");
        deleteLineFromStudentFile();
        pressAnyKey();
        break;

    case 4:
        system("cls");
        showAllStudents();
        pressAnyKey();
        break;

    case 5:
        system("cls");
        cout << "List of Students:\n";
        ReadFromStudentFile();
        pressAnyKey();
        break;

    default:
        cout << "Input a valid choice!" << endl;
        break;
    }
}

void TeacherMenuOptions()
{
    int choice;
    cout << "Enter your choice : ";
    cin >> choice;

    switch(choice)
    {
    case 1:
        system("cls");
        addTeacher();
        break;
        
    case 2:

        system("cls");
        cout << "List of Teachers:\n";
        ReadFromTeacherFile();
        pressAnyKey();
        break;

    case 3:
        system("cls");
        deleteLineFromTeacherFile();
        pressAnyKey();
        break;

    default:
        cout << "Input a valid choice!" << endl;
        break;
    }
}

void TeamsMenuOptions()
{
    int choice;
    cout << "Enter your choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        system("cls");
        addTeam();
        break;
    case 2:

        system("cls");
        showAllTeams();
        pressAnyKey();
        break;

    case 3:
        system("cls");

        pressAnyKey();
        break;

    default:
        cout << "Input a valid choice!" << endl;
        break;
    }
}