#pragma once
#include "DataTypes.h"
#include<iostream>
using namespace std;

void addStudent()
{
    STUDENT student;
    student.askForData();
    students.push_back(student);
}

int searchByEmail()
{
    string email;
    do
    {
        cout << "Enter the email of the student that you want to delete: ";
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