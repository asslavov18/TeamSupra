#include <iostream>
#include<vector>
#include "DataTypes.h"
#include "ChangingDataFunctions.h"
using namespace std;
int main()
{
    addStudent();
    removeStudentByEmail();
    cout << students.empty();
}