#pragma once
#include<string>
#include<vector>
struct STUDENT
{
    std::string name;
    std::string surname;
    std::string schoolClass;
    std::string role;
    std::string email;
};

struct TEAM
{
    std::string name;
    std::string description;
    std::string date;
    std::string status;
    std::vector<STUDENT> students;
};

struct TEACHER
{
    std::string name;
    std::string surname;
    std::string email;
    std::vector<TEAM> teams;
};

struct SCHOOL
{
    std::string name;
    std::string city;
    std::string address;
    std::vector<TEACHER> teachers;
    std::vector<TEAM> teams;
    std::vector<STUDENT> students;
};
