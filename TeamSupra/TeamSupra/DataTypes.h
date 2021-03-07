#pragma once
#include<string>
#include<vector>
using namespace std;

struct STUDENT
{
    int id;
    string name;
    string surname;
    string schoolClass;
    string role;
    string email;
    void askForData();
};


vector<STUDENT> students = {
{0, "Michael", "Watts", "10V", "front end", "michawatts@gmail.com" },
{1, "Zachary", "Dennis", "12B", "back end", "zachdennis@hotmail.com" },
{2, "Kawhi", "Leonard", "11A", "scrum master", "kawhleonard@yahoo.com" },
{3, "Susan", "Hamilton", "11G", "qa", "susahamilton@outlook.com" },
{4, "Herman", "Howell", "9A", "scrum master", "hermhowell@outlook.com" },
{5, "Harriet", "Mccoy", "12V", "front end", "harrmccoy@gmail.com" },
{6, "Angelina", "Cook", "10B", "back end", "angecook@outlook.com" },
};;




struct TEAM
{
    string name;
    string description;
    string date;
    string status;
    vector<STUDENT> members;
    void askForData();
};

vector<TEAM> teams = {
{ "KKB", "A cool team", "22/11/2020", "in use",
    {
        students[0],
        students[1],
        students[3],
        students[5],
    }
} };




struct TEACHER
{
    string name;
    string surname;
    string email;
    vector<TEAM> taughtTeams;
    void askForData();
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