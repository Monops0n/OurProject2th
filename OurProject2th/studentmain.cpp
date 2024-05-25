#include <stdlib.h>
#include <Windows.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include "Headerstudent.h"
using namespace std;
int mainstudent()
{
    string studentFile = "C:/Users/������/source/repos/OurProject2th/OurProject2th/data.txt";
    string questionFile = "C:/Users/������/source/repos/OurProject2th/OurProject2th/Tests.txt";

    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);



    Student* students = new Student[DEFAULT_SIZE];
    readFile(students, studentFile);

    int studentIndex = signInSystem(students);

    Topic* topics = new Topic[DEFAULT_SIZE];
    readFile(topics, questionFile);

    int num;
    do
    {
        cout << "+-----------------------------------------------------------------------------+" << endl
            << "|                                                                             |" << endl
            << "|                           ��� ������ �������?                               |" << endl
            << "|                                                                             |" << endl
            << "+-----------------------------------------------------------------------------+" << endl
            << "|                                                                             |" << endl
            << "|    1 - �������� �� ����                                                     |" << endl
            << "|    2 - ���� �� ����� ����                                                   |" << endl
            << "|    3 - �������� ����                                                        |" << endl
            << "|    0 - �����                                                                |" << endl
            << "|                                                                             |" << endl
            << "+-----------------------------------------------------------------------------+" << endl;
        do
        {

            scanf_s("%d", &num);
            if (num != 0 && num != 1 && num != 2 && num != 3)
            {
                printf("������� ���������� ������!\n");
            }
        } while (num != 0 && num != 1 && num != 2 && num != 3);

        switch (num)
        {
        case 0:break;
        case 1:trainingTheme(questionFile); break;
        case 2:testingOnTheTopic(topics, students, studentIndex); rewriteFileStudents(students, studentFile); break;
        case 3:finalTesting(topics, students, studentIndex); rewriteFileStudents(students, studentFile); break;
        }
    } while (num!=0);

    free(students);
    free(topics);
    delete[]topics;
    delete[]students;
    return 0;

}