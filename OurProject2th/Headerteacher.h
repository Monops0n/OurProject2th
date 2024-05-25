//#pragma once
//
//#include <iostream>
//#include <fstream>
//#include <string>
//#include<locale>
//#include <sstream>
//#include<stdlib.h>
//#include<vector>
//#include<iomanip>
//#include <algorithm>
//#include<Windows.h>
//using namespace std;
//
//struct Topics
//{
//    string Cycles = "Циклы"; //4+13
//    string Array = "Массивы";//5+13
//    string String = "Строки";//6+13
//    string Recursion = "Рекурсия";//7+13
//    string Struct = "Структуры";//8+13
//    string Files = "Файлы";//9+13
//    string Address = "Адреса и указатели";//10+13
//    string Dinamic = "Динамическая память";//11+13
//    string Final = "Итоговый тест";//12+13
//    string Average = "Средний балл";//13
//};
//
//struct Student_1
//{
//    string Login, Password, FIO, Cycles, Arrays, Strings,
//        Recursion, Structs, Files, Address, Dinamic, Final, Average;
//};
//
//
////ВОПРОСЫ
//struct Question
//{
//    string question;
//    string answers[4];//строки ответов "   a) break"
//    int countAnswers;
//    string trueAnswer;//правильный ответ"a"
//};
//struct Title
//{
//    string title;
//    string countQuestions;
//    Question questions[20];
//};
//struct Student
//{
//    string login, password, FI, cycles, array, stringa, recursion, structure, files, address, dinamic, final, average;
//};
//
//void clearFile(string name);
//void writeQuestionsInFile(Title* titles, int countTitle);
//void writeInformationInFile(Student* students, int count, string name);
//int parsingFileForTitles(Title* titles);
//int chooseTitle(Title* titles, int count);
//void changeNumberofQuestions(Title* titles, int countQuestions, int numTitle);
//void deleteQuestion(Title* titles, int numTitle, int countTitles);
//void addQuestion(Title* titles, int numTitle, int countTitles);
//void editQuestion(Title* titles, int numTitle, int countTitles);
//void editQuestions();
//int fillStudentsData(Student* students);
//void addStudent(Student* students, int& count);
//void deleteStudent(Student* students, int& count);
//void addAndDeleteStudents();
//void replaceSubstring(string& str, const string& from, const string& to);
//void editProgress();
//int Choise_Topic();
//int Choise_Mark();
//void Output_All_Topics(vector<Student_1> Students);
//void Output_Specific_Topic(vector<Student_1> Students);
//void Filter(vector<Student_1> Students);
//void Sorted(vector<Student_1> Students);
//int Teacher_chek();
//void Menu_Students(vector<Student_1> Students);