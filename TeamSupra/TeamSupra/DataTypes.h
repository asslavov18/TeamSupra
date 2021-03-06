#pragma once
#include<string>
#include<vector>
using namespace std;
struct STUDENT
{
    string name;
    string surname;
    string schoolClass;
    string role;
    string email;
    void askForData();
};
vector<STUDENT> students;


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
}




struct TEAM
{
    string name;
    string description;
    string date;
    string status;
    vector<STUDENT> students;
};
vector<TEAM> teams;


struct TEACHER
{
    string name;
    string surname;
    string email;
    vector<TEAM> teams;
};
vector<TEACHER> teachers;

struct SCHOOL
{
    string name;
    string city;
    string address;
    vector<TEACHER> teachers;
    vector<TEAM> teams;
    vector<STUDENT> students;
};