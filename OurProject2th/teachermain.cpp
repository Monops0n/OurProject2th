//#include"Headerteacher.h"
//vector<Student_1>Students;
//int mainteacher()
//{
//    setlocale(LC_ALL, "Russian");
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    string s;
//    ifstream FILE("data.txt");
//    while (getline(FILE, s))
//    {
//        Student_1 stud;
//        stud.Login = s;
//        getline(FILE, s);
//        stud.Password = s;
//        getline(FILE, s);
//        stud.FIO = s;
//        getline(FILE, s);
//        stud.Cycles = s.back();
//        getline(FILE, s);
//        stud.Arrays = s.back();
//        getline(FILE, s);
//        stud.Strings = s.back();
//        getline(FILE, s);
//        stud.Recursion = s.back();
//        getline(FILE, s);
//        stud.Structs = s.back();
//        getline(FILE, s);
//        stud.Files = s.back();
//        getline(FILE, s);
//        stud.Address = s.back();
//        getline(FILE, s);
//        stud.Dinamic = s.back();
//        getline(FILE, s);
//        stud.Final = s.back();
//        getline(FILE, s);
//        stud.Average = s.substr(s.length() - 4);
//        Students.push_back(stud);
//    }
//    FILE.close();
//    int blok = 0;
//    do
//    {
//        system("cls");
//        if (Teacher_chek())
//        {
//            cout << "\t+-----------------------------------------------------+" << endl;
//            cout << "\t|                                                     |" << endl;
//            cout << "\t|            ����� ������������� ������               |" << endl;
//            cout << "\t|                                                     |" << endl;
//            cout << "\t+-----------------------------------------------------+" << endl;
//            cout << "\t|                                                     |" << endl;
//            cout << "\t| 1 - �������������� ��������                         |" << endl;
//            cout << "\t| 2 - ������ �� ������� ���������                     |" << endl;
//            cout << "\t| 3 - �����                                           |" << endl;
//            cout << "\t|                                                     |" << endl;
//            cout << "\t+-----------------------------------------------------+" << endl << endl << endl;
//            cout << "\t";
//        }
//        else return 0;
//        do
//        {
//            cin >> blok;
//            if (blok < 1 && blok>3) cout << "�������� ����. ���������� �����..." << endl;
//        } while (blok < 1 && blok>3);
//        switch (blok)
//        {
//        case 1:
//            editQuestions();
//            Sleep(1000);
//            break;
//        case 2:
//            Menu_Students(Students);
//            break;
//        case 3:break;
//        default:cout << "�������� ����" << endl; break;
//        }
//    } while (blok != 0);
//    blok = 0;
//    return 0;
//}
#include <iostream>
#include <fstream>
#include <string>
#include<locale>
#include <sstream>
#include<stdlib.h>
#include<vector>
#include<iomanip>
#include <algorithm>
#include<Windows.h>

using namespace std;

struct Topics
{
    string Cycles = "�����"; //4+13
    string Array = "�������";//5+13
    string String = "������";//6+13
    string Recursion = "��������";//7+13
    string Struct = "���������";//8+13
    string Files = "�����";//9+13
    string Address = "������ � ���������";//10+13
    string Dinamic = "������������ ������";//11+13
    string Final = "�������� ����";//12+13
    string Average = "������� ����";//13
};

struct Student_1
{
    string Login, Password, FIO, Cycles, Arrays, Strings,
        Recursion, Structs, Files, Address, Dinamic, Final, Average;
};

vector<Student_1>Students;
//�������
struct Question
{
    string question;
    string answers[4];//������ ������� "   a) break"
    int countAnswers;
    string trueAnswer;//���������� �����"a"
};
struct Title
{
    string title;
    string countQuestions;
    Question questions[20];
};
struct Student
{
    string login, password, FI, cycles, array, stringa, recursion, structure, files, address, dinamic, final, average;
};
void clearFile(string name)
{
    ofstream file(name, std::ios_base::in | std::ios_base::out);
    file << "AA";
    file.seekp(std::ios::beg);
    file << "1";
    file.close();
}

void writeQuestionsInFile(Title* titles, int countTitle)
{
    ofstream file("Tests.txt");
    for (int i = 0; i < countTitle; i++)
    {
        file << titles[i].title << endl;
        file << titles[i].countQuestions << endl;
        for (int j = 0; j < atoi(titles[i].countQuestions.c_str()); j++)
        {
            file << titles[i].questions[j].question << endl;
            for (int k = 0; k < 4; k++)
            {
                file << titles[i].questions[j].answers[k] << endl;
            }
            file << titles[i].questions[j].trueAnswer << endl;
        }
    }
    file.close();
}

void writeInformationInFile(Student* students, int count, string name)
{
    ofstream file(name);
    for (int i = 0; i < count; i++)
    {
        file << students[i].login << endl;
        file << students[i].password << endl;
        file << students[i].FI << endl;
        file << students[i].cycles << endl;
        file << students[i].array << endl;
        file << students[i].stringa << endl;
        file << students[i].recursion << endl;
        file << students[i].structure << endl;
        file << students[i].files << endl;
        file << students[i].address << endl;
        file << students[i].dinamic << endl;
        file << students[i].final << endl;
        file << students[i].average << endl;
    }
}

int parsingFileForTitles(Title* titles)
{
    int count = 0;
    ifstream file("Tests.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            titles[count].title = line;
            getline(file, line);
            titles[count].countQuestions = line;
            int countQuestions = atoi(titles[count].countQuestions.c_str());
            for (int i = 0; i < countQuestions; i++)
            {
                getline(file, titles[count].questions[i].question);
                int countAnswers = 0;
                string temp;
                while (true) {
                    getline(file, temp);
                    if (temp[0] == '*') {
                        titles[count].questions[i].trueAnswer = temp;
                        break;
                    }
                    titles[count].questions[i].answers[countAnswers++] = temp;
                }
                titles[count].questions[i].countAnswers = countAnswers;
            }
            count++;
        }
    }
    file.close();
    return count;
}

int chooseTitle(Title* titles, int count)
{
    int numTitle;
    do
    {
        system("cls");
        cout << "�������� ���� �� ���: " << endl;
        for (int i = 0; i < count; i++)
        {
            cout << i + 1 << ") " << titles[i].title << endl;
        }
        cin >> numTitle;
        if (numTitle < 1 or numTitle > count)
        {
            cout << "������� ���������� ��������! " << endl;
        }
    } while (numTitle < 1 or numTitle > count);
    return numTitle - 1;
}

void changeNumberofQuestions(Title* titles, int countQuestions, int numTitle)
{
    for (int i = 0; i < countQuestions; i++) {
        string& question = titles[numTitle].questions[i].question;
        size_t pos = question.find(')');
        if (pos != string::npos) {
            question = to_string(i + 1) + question.substr(pos);
        }
    }
}

void deleteQuestion(Title* titles, int numTitle, int countTitles)
{
    int numQuestion;
    do
    {
        system("cls");
        cout << "����� ������ ������ �������?" << endl;
        for (int i = 0; i < atoi(titles[numTitle].countQuestions.c_str()); i++)
        {
            cout << titles[numTitle].questions[i].question << endl;
        }
        cin >> numQuestion;
        if (numQuestion < 1 or numQuestion > atoi(titles[numTitle].countQuestions.c_str()))
        {
            cout << "������� ���������� ��������! " << endl;
        }
    } while (numQuestion < 1 or numQuestion > atoi(titles[numTitle].countQuestions.c_str()));

    //�������� �������
    for (int i = numQuestion - 1; i < atoi(titles[numTitle].countQuestions.c_str()) - 1; i++)
    {
        titles[numTitle].questions[i] = titles[numTitle].questions[i + 1];
    }
    //��������� ���-�� ��������
    titles[numTitle].countQuestions = to_string(atoi(titles[numTitle].countQuestions.c_str()) - 1);
    changeNumberofQuestions(titles, atoi(titles[numTitle].countQuestions.c_str()), numTitle);
    clearFile("Tests.txt");
    writeQuestionsInFile(titles, countTitles);
}

void addQuestion(Title* titles, int numTitle, int countTitles)
{
    string alph = "abcd";
    int countQuestions = atoi(titles[numTitle].countQuestions.c_str());
    string line;
    system("cls");
    do
    {
        cout << "������� ������: " << endl;
        getchar();
        getline(cin, line);
    } while (line.find('?') == string::npos);

    titles[numTitle].questions[countQuestions].question = to_string(countQuestions + 1) + ") " + line;

    cout << "������� �������� �������: " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << alph[i] << ") ";
        getline(cin, line);
        string s, s1 = ") ";
        s = alph[i] + s1 + line;
        titles[numTitle].questions[countQuestions].answers[i] = s;
    }

    string correctAnswer;
    do
    {
        cout << "������� ���������� ����� (����� a, b, c ��� d): ";
        cin >> correctAnswer;
    } while (correctAnswer != "a" and correctAnswer != "b" and correctAnswer != "c" and correctAnswer != "d");

    titles[numTitle].questions[countQuestions].trueAnswer = "*   " + correctAnswer;
    titles[numTitle].countQuestions = to_string(countQuestions + 1);

    // ������ ������������ ������� ��� ��������
    cout << titles[numTitle].questions[countQuestions].question << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << titles[numTitle].questions[countQuestions].answers[i] << endl;
    }
    cout << titles[numTitle].questions[countQuestions].trueAnswer << endl;
    clearFile("Tests.txt");
    writeQuestionsInFile(titles, countTitles);
}

void editQuestion(Title* titles, int numTitle, int countTitles)
{
    string alph = "abcd";
    int countQuestions = atoi(titles[numTitle].countQuestions.c_str());
    string line;
    int numQuestion;
    system("cls");
    for (int i = 0; i < atoi(titles[numTitle].countQuestions.c_str()); i++)
    {
        cout << titles[numTitle].questions[i].question << endl;
    }
    do
    {
        cout << "�������� ������: " << endl;
        getchar();
        cin >> numQuestion;
        if (numQuestion < 1 or numQuestion > atoi(titles[numTitle].countQuestions.c_str()))
        {
            cout << "������� ���������� ��������! " << endl;
        }
    } while (numQuestion < 1 or numQuestion > atoi(titles[numTitle].countQuestions.c_str()));

    do
    {
        system("cls");
        cout << "������� ������: " << endl;
        getline(cin, line);
    } while (line.find('?') == string::npos);

    titles[numTitle].questions[numQuestion - 1].question = to_string(numQuestion) + ") " + line;
    cout << "������� �������� �������: " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << alph[i] << ") ";
        getline(cin, line);
        string s, s1 = ") ";
        s = alph[i] + s1 + line;
        titles[numTitle].questions[numQuestion - 1].answers[i] = s;
    }

    string correctAnswer;
    do
    {
        cout << "������� ���������� ����� (����� a, b, c ��� d): ";
        cin >> correctAnswer;
    } while (correctAnswer != "a" and correctAnswer != "b" and correctAnswer != "c" and correctAnswer != "d");

    titles[numTitle].questions[numQuestion - 1].trueAnswer = "*   " + correctAnswer;

    // ������ ����������� ������� ��� ��������
    cout << titles[numTitle].questions[numQuestion - 1].question << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << titles[numTitle].questions[numQuestion - 1].answers[i] << endl;
    }
    cout << titles[numTitle].questions[numQuestion - 1].trueAnswer << endl;
    clearFile("Tests.txt");
    writeQuestionsInFile(titles, countTitles);
}

void editQuestions()
{
    Title titles[30];
    int count = parsingFileForTitles(titles);
    int numTitle;
    int choice;
    do
    {
        system("cls");
        cout << "+-----------------------------------------------------------------------------+" << endl;
        cout << "|                                                                             |" << endl;
        cout << "|                       �������������� ��������                               |" << endl;
        cout << "|                                                                             |" << endl;
        cout << "+-----------------------------------------------------------------------------+" << endl;
        cout << "|                                                                             |" << endl;
        cout << "|    1 - ��������                                                             |" << endl;
        cout << "|    2 - ����������                                                           |" << endl;
        cout << "|    3 - ���������                                                            |" << endl;
        cout << "|    4 - �����                                                                |" << endl;
        cout << "|                                                                             |" << endl;
        cout << "+-----------------------------------------------------------------------------+" << endl << endl << endl;

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            choice = 0;
        }

        switch (choice) {
        case 1:
            numTitle = chooseTitle(titles, count);
            deleteQuestion(titles, numTitle, count);
            Sleep(1000);
            break;
        case 2:
            numTitle = chooseTitle(titles, count);
            addQuestion(titles, numTitle, count);
            Sleep(3000);
            break;
        case 3:
            numTitle = chooseTitle(titles, count);
            editQuestion(titles, numTitle, count);
            Sleep(1000);
            break;
        case 4:
            cout << "������� �����..." << endl;
            Sleep(1000);
            break;
        default:
            cout << "�������� �����. ���������� �����." << endl;
        }
    } while (choice != 4);
}

int fillStudentsData(Student* students)
{
    int num = 0;
    ifstream file("data.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            students[num].login = line;
            getline(file, students[num].password);
            getline(file, students[num].FI);
            getline(file, students[num].cycles);
            getline(file, students[num].array);
            getline(file, students[num].stringa);
            getline(file, students[num].recursion);
            getline(file, students[num].structure);
            getline(file, students[num].files);
            getline(file, students[num].address);
            getline(file, students[num].dinamic);
            getline(file, students[num].final);
            getline(file, students[num].average);
            num++;
        }
    }
    return num;
}

void addStudent(Student* students, int& count)
{

    string login, password1, password2, FI;
    cin.ignore();
    do
    {
        cout << "������� ��� � ������� ����� ������: " << endl; getline(cin, FI);
        if (size(FI) < 4)
        {
            cout << "��������� ������ �����������!" << endl;
        }
    } while (size(FI) < 4);
    do
    {
        cout << "������� ����� ��������: " << endl; getline(cin, login);
        cout << "������� ������ ��������: " << endl; getline(cin, password1);
        cout << "����������� ������ ��������: " << endl; getline(cin, password2);
        if (password1 != password2)
        {
            cout << "������ �� ���������, ��������� �������!" << endl;
        }
    } while (password1 != password2);

    students[count].login = login;
    students[count].password = password1;
    students[count].FI = FI;
    students[count].cycles = "cycles: 0";
    students[count].array = "array: 0";
    students[count].stringa = "string: 0";
    students[count].recursion = "recursion: 0";
    students[count].structure = "struct: 0";
    students[count].files = "files: 0";
    students[count].address = "address: 0";
    students[count].dinamic = "dinamic: 0";
    students[count].final = "final: 0";
    students[count].average = "average: 0";
    count++;
}

void deleteStudent(Student* students, int& count)
{
    int number, proverka;
    do
    {
        do
        {
            cout << "������� ����� ��������, �������� ������ �������: " << endl;
            cin >> number;
            if (number < 1 or number > count)
            {
                cout << "������� ���������� ��������!" << endl;
            }
        } while (number < 1 or number > count);

        cout << "��������� ����� ��������:" << endl;
        cin >> proverka;
        if (number != proverka)
        {
            cout << "���-�� ��������� �� ���!" << endl;
        }
    } while (number != proverka);
    for (int i = number - 1; i < count - 1; i++)
    {
        students[i] = students[i + 1];
    }

    count--;
}

void addAndDeleteStudents()
{
    Student students[1000];
    int count = fillStudentsData(students);

    int choice;
    do
    {
        system("cls");
        cout << "----------------------------------------------" << endl;
        cout << "| � |" << setw(17) << "��" << "                  |" << endl;
        cout << "----------------------------------------------" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << "|" << setw(3) << left << i + 1 << "|" << setw(40) << left << students[i].FI << "|" << endl;
            cout << "----------------------------------------------" << endl;
        }

        cout << "+-----------------------------------------------------------------------------+" << endl
            << "|                                                                             |" << endl
            << "|                           ��� ������ �������?                               |" << endl
            << "|                                                                             |" << endl
            << "+-----------------------------------------------------------------------------+" << endl
            << "|                                                                             |" << endl
            << "|    1 - �������� ��������                                                    |" << endl
            << "|    2 - ������� ��������                                                     |" << endl
            << "|    3 - �����                                                                |" << endl
            << "|                                                                             |" << endl
            << "+-----------------------------------------------------------------------------+" << endl;

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            choice = 0;
        }

        switch (choice) {
        case 1:
            addStudent(students, count);
            clearFile("data.txt");
            writeInformationInFile(students, count, "data.txt");
            Sleep(1000);
            break;
        case 2:
            deleteStudent(students, count);
            clearFile("data.txt");
            writeInformationInFile(students, count, "data.txt");
            Sleep(1000);
            break;
        case 3:
            cout << "������� �����..." << endl;
            Sleep(1000);
            break;
        default:
            cout << "�������� �����. ���������� �����." << endl;
        }
    } while (choice != 3);
}

void replaceSubstring(string& str, const string& from, const string& to) {
    size_t start_pos = str.find(from);
    if (start_pos != string::npos) {
        str.replace(start_pos, from.length(), to);
    }
}

void editProgress()
{
    system("cls");
    Student students[100];
    Title titles[30];
    int countTitle = parsingFileForTitles(titles);
    int countStudents = fillStudentsData(students);
    int numStudent;

    for (int i = 0; i < countStudents; i++)
    {
        cout << i + 1 << ")" << students[i].FI << endl;
    }
    do
    {
        cout << "�������� ��������, �������� ����� ������ ������: " << endl;
        cin >> numStudent;
        if (numStudent < 1 or numStudent > countStudents)
        {
            cout << "������� ���������� ��������!" << endl;
        }
    } while (numStudent < 1 or numStudent > countStudents);

    cout << "�� ������� " << students[numStudent - 1].FI << endl;
    Sleep(1000);
    cout << "������ �� ����� ���� ����� ������? " << endl;
    int numTitle;
    do
    {
        for (int j = 0; j < 9; j++)
        {
            string temp = students[numStudent - 1].cycles;
            switch (j) {
            case 0:
                temp = students[numStudent - 1].cycles; break;
            case 1:
                temp = students[numStudent - 1].array; break;
            case 2:
                temp = students[numStudent - 1].stringa; break;
            case 3:
                temp = students[numStudent - 1].recursion; break;
            case 4:
                temp = students[numStudent - 1].structure; break;
            case 5:
                temp = students[numStudent - 1].files; break;
            case 6:
                temp = students[numStudent - 1].address; break;
            case 7:
                temp = students[numStudent - 1].dinamic; break;
            case 8:
                temp = students[numStudent - 1].final; break;
            }
            replaceSubstring(temp, "0", "�� �����");
            cout << j + 1 << ". " << temp << endl;
        }
        cin >> numTitle;
        if (numTitle < 1 or numTitle > countTitle)
        {
            cout << "������� ���������� ������!" << endl;
        }
    } while (numTitle < 1 or numTitle > countTitle);

    int number;
    do
    {
        cout << "������� ������:" << endl;
        cin >> number;
        if (number != 0 and number != 2 and number != 3 and number != 4 and number != 5)
        {
            cout << "������� ���������� ������!" << endl;
        }
    } while (number != 0 and number != 2 and number != 3 and number != 4 and number != 5);

    string temp;
    switch (numTitle - 1)//-1 ������ ��� ������� �� �������
    {
    case 0:
        temp = students[numStudent - 1].cycles; temp.replace(temp.length() - 1, temp.length() - 1, to_string(number)); students[numStudent - 1].cycles = temp;
        break;
    case 1:
        temp = students[numStudent - 1].array; temp.replace(temp.length() - 1, temp.length() - 1, to_string(number)); students[numStudent - 1].array = temp;
        break;
    case 2:
        temp = students[numStudent - 1].stringa; temp.replace(temp.length() - 1, temp.length() - 1, to_string(number)); students[numStudent - 1].stringa = temp;
        break;
    case 3:
        temp = students[numStudent - 1].recursion; temp.replace(temp.length() - 1, temp.length() - 1, to_string(number)); students[numStudent - 1].recursion = temp;
        break;
    case 4:
        temp = students[numStudent - 1].structure; temp.replace(temp.length() - 1, temp.length() - 1, to_string(number)); students[numStudent - 1].structure = temp;
        break;
    case 5:
        temp = students[numStudent - 1].files; temp.replace(temp.length() - 1, temp.length() - 1, to_string(number)); students[numStudent - 1].files = temp;
        break;
    case 6:
        temp = students[numStudent - 1].address; temp.replace(temp.length() - 1, temp.length() - 1, to_string(number)); students[numStudent - 1].address = temp;
        break;
    case 7:
        temp = students[numStudent - 1].dinamic; temp.replace(temp.length() - 1, temp.length() - 1, to_string(number)); students[numStudent - 1].dinamic = temp;
        break;
    case 8:
        temp = students[numStudent - 1].final; temp.replace(temp.length() - 1, temp.length() - 1, to_string(number)); students[numStudent - 1].final = temp;
        break;
    }

    for (int j = 0; j < 9; j++)
    {
        string temp = students[numStudent - 1].cycles;
        switch (j) {
        case 0:
            temp = students[numStudent - 1].cycles; break;
        case 1:
            temp = students[numStudent - 1].array; break;
        case 2:
            temp = students[numStudent - 1].stringa; break;
        case 3:
            temp = students[numStudent - 1].recursion; break;
        case 4:
            temp = students[numStudent - 1].structure; break;
        case 5:
            temp = students[numStudent - 1].files; break;
        case 6:
            temp = students[numStudent - 1].address; break;
        case 7:
            temp = students[numStudent - 1].dinamic; break;
        case 8:
            temp = students[numStudent - 1].final; break;
        }
        replaceSubstring(temp, "0", "�� �����");
        cout << j + 1 << ". " << temp << endl;
    }

    int count = 0;
    double sum = 0;
    //������ ������� ��������������
    for (int i = 0; i < 9; i++)
    {
        int len;
        string temp = students[numStudent - 1].cycles;
        switch (i) {
        case 0:
            temp = students[numStudent - 1].cycles[students[numStudent - 1].cycles.length() - 1]; break;
        case 1:
            temp = students[numStudent - 1].array[students[numStudent - 1].array.length() - 1]; break;
        case 2:
            temp = students[numStudent - 1].stringa[students[numStudent - 1].stringa.length() - 1]; break;
        case 3:
            temp = students[numStudent - 1].recursion[students[numStudent - 1].recursion.length() - 1]; break;
        case 4:
            temp = students[numStudent - 1].structure[students[numStudent - 1].structure.length() - 1]; break;
        case 5:
            temp = students[numStudent - 1].files[students[numStudent - 1].files.length() - 1]; break;
        case 6:
            temp = students[numStudent - 1].address[students[numStudent - 1].address.length() - 1]; break;
        case 7:
            temp = students[numStudent - 1].dinamic[students[numStudent - 1].dinamic.length() - 1]; break;
        case 8:
            temp = students[numStudent - 1].final[students[numStudent - 1].final.length() - 1]; break;

        }
        if (temp[temp.length() - 1] != '0')
        {
            count++;
            sum += atoi(temp.c_str());
        }
    }
    double num = sum / count;
    double result = round(num * 100.0) / 100.0;
    stringstream ss;
    ss << fixed << std::setprecision(2) << num;
    cout << ss.str() << endl;
    students[numStudent - 1].average = "average: " + ss.str();
    writeInformationInFile(students, countStudents, "data.txt");
}

int Choise_Topic()
{
    int t = 0;
    do
    {
        cout << "1 - �����" << endl << "2 - �������" << endl << "3 - ������" << endl << "4 - ��������" << endl << "5 - ���������" << endl <<
            "6 - �����" << endl << "7 - ������ � ���������" << endl << "8 - ������������ ������" << endl << "9 - �������� ����" <<
            endl << "10 - ������� ����" << endl;
        cin >> t;
    } while (t < 1 || t>10);
    return t;
}

int Choise_Mark()
{
    int t7;
    do
    {
        cout << "5" << endl << "4" << endl << "3" << endl << "2" << endl << "0 (�� ������ ��� ����)" << endl;
        cin >> t7;

    } while (t7 < 0 || t7>5);
    return t7;
}

void Output_All_Topics()
{
    cout << "� - �����" << endl << "� - �������" << endl << "� - ������" << endl << "� - ��������" << endl << "� - ���������" << endl <<
        "� - �����" << endl << "� - ������ � ���������" << endl << "� - ������������ ������" << endl << "� - �������� ����" <<
        endl << "� - ������� ����" << endl;
    cout << "������������ �� ���� �����:" << endl;
    cout << "|" << setw(20) << "�������/����" << "|" << " � " << "|" << " � " << "|" << " � " << "|" << " � " << "|" << " � " << "|" << " � " << "|" << " � " << "|"
        << " � " << "|" << " � " << "|" << "  �  " << " |" << endl;
    for (int i = 0; i < Students.size(); i++)
    {
        cout << "|" << setw(20) << Students[i].FIO << "| " << Students[i].Cycles << " | " << Students[i].Arrays << " | " << Students[i].Strings << " | "
            << Students[i].Recursion << " | " << Students[i].Structs << " | " << Students[i].Files << " | " <<
            Students[i].Address << " | " << Students[i].Dinamic << " | " << Students[i].Final << " | "
            << Students[i].Average << " |" << endl;
    }
}

void Output_Specific_Topic()
{
    cout << "�������� ����: " << endl;
    int t1;
    t1 = Choise_Topic();
    cout << "������������ �� ���������� ������:" << endl;
    cout << "|" << setw(20) << "�������" << "|" << endl;
    for (int i = 0; i < Students.size(); i++)
    {
        cout << "|" << setw(20) << Students[i].FIO << "| ";
        switch (t1)
        {
        case 1:cout << Students[i].Cycles << " |" << endl; break;
        case 2:cout << Students[i].Arrays << " |" << endl; break;
        case 3:cout << Students[i].Strings << " |" << endl; break;
        case 4:cout << Students[i].Recursion << " |" << endl; break;
        case 5:cout << Students[i].Structs << " |" << endl; break;
        case 6:cout << Students[i].Files << " |" << endl; break;
        case 7:cout << Students[i].Address << " |" << endl; break;
        case 8:cout << Students[i].Dinamic << " |" << endl; break;
        case 9:cout << Students[i].Final << " |" << endl; break;
        case 10:cout << Students[i].Average << " |" << endl; break;
        default:cout << "�������� ����" << endl; break;
        }
    }
}

void Filter()
{
    int t5 = 0, T;
    cout << "����������: " << endl << "1 - �� ���������� ����(�������� �������� ���� � ������� ����)" << endl << "2 - �� ���� �����" << endl;
    cout << "�������� ����� ��� ����������: " << endl;
    do { cin >> T; } while (T < 1 || T>2);
    switch (T)
    {
    case 1:cout << "�������� ����:" << endl; t5 = Choise_Topic(); break;
    case 2:T = 2; break;
    default:cout << "�������� ����" << endl; break;
    }
    int t6 = 0, n;
    cout << "�������� ������, �� ������� ������ �����������" << endl;
    t6 = Choise_Mark();
    if (T == 2)
    {
        cout << "� - �����" << endl << "� - �������" << endl << "� - ������" << endl << "� - ��������" << endl << "� - ���������" << endl <<
            "� - �����" << endl << "� - ������ � ���������" << endl << "� - ������������ ������" << endl << "� - �������� ����" <<
            endl << "� - ������� ����" << endl;
    }
    cout << "������������ �� ���������� ������:" << endl;
    cout << "- ���� ������ �������� �� �������� ��� ������" << endl;
    if (T == 1) cout << "|" << setw(20) << "�������" << "|" << endl;
    if (T == 2) cout << "|" << setw(20) << "�������/����" << "|" << " � " << "|" << " � " << "|" << " � " << "|" << " � " << "|" << " � " << "|" << " � " << "|" << " � " << "|"
        << " � " << "|" << " � " << "|" << "  �  " << " |" << endl;
    for (int i = 0; i < Students.size(); i++)
    {
        if (T == 2)
        {
            cout << endl << "|" << setw(20) << Students[i].FIO << "| ";
            if (atoi(Students[i].Cycles.c_str()) == t6) cout << Students[i].Cycles << " | ";
            else cout << "-" << " | ";
            if (atoi(Students[i].Arrays.c_str()) == t6) cout << Students[i].Arrays << " | ";
            else cout << "-" << " | ";
            if (atoi(Students[i].Strings.c_str()) == t6) cout << Students[i].Strings << " | ";
            else cout << "-" << " | ";
            if (atoi(Students[i].Recursion.c_str()) == t6) cout << Students[i].Recursion << " | ";
            else cout << "-" << " | ";
            if (atoi(Students[i].Structs.c_str()) == t6) cout << Students[i].Structs << " | ";
            else cout << "-" << " | ";
            if (atoi(Students[i].Files.c_str()) == t6) cout << Students[i].Files << " | ";
            else cout << "-" << " | ";
            if (atoi(Students[i].Address.c_str()) == t6) cout << Students[i].Address << " | ";
            else cout << "-" << " | ";
            if (atoi(Students[i].Dinamic.c_str()) == t6) cout << Students[i].Dinamic << " | ";
            else cout << "-" << " | ";
            if (atoi(Students[i].Final.c_str()) == t6) cout << Students[i].Final << " | ";
            else cout << "-" << " | ";
            if (atof(Students[i].Average.c_str()) == t6) cout << Students[i].Average << " |" << endl;
            else cout << " - " << " |";
        }
        else
        {
            switch (t5)
            {
            case 1:
                n = atoi(Students[i].Cycles.c_str());
                if (n == t6)
                {
                    cout << "|" << setw(20) << Students[i].FIO << "| ";
                    cout << Students[i].Cycles << " |" << endl;
                }
                break;
            case 2:
                n = atoi(Students[i].Arrays.c_str());
                if (n == t6)
                {
                    cout << "|" << setw(20) << Students[i].FIO << "| ";
                    cout << Students[i].Arrays << " |" << endl;
                }
                break;
            case 3:
                n = atoi(Students[i].Strings.c_str());
                if (n == t6)
                {
                    cout << "|" << setw(20) << Students[i].FIO << "| ";
                    cout << Students[i].Strings << " |" << endl;
                }
                break;
            case 4:
                n = atoi(Students[i].Recursion.c_str());
                if (n == t6)
                {
                    cout << "|" << setw(20) << Students[i].FIO << "| ";
                    cout << Students[i].Recursion << " |" << endl;
                }
                break;
            case 5:
                n = atoi(Students[i].Structs.c_str());
                if (n == t6)
                {
                    cout << "|" << setw(20) << Students[i].FIO << "| ";
                    cout << Students[i].Structs << " |" << endl;
                }
                break;
            case 6:
                n = atoi(Students[i].Files.c_str());
                if (n == t6)
                {
                    cout << "|" << setw(20) << Students[i].FIO << "| ";
                    cout << Students[i].Files << " |" << endl;
                }
                break;
            case 7:
                n = atoi(Students[i].Address.c_str());
                if (n == t6)
                {
                    cout << "|" << setw(20) << Students[i].FIO << "| ";
                    cout << Students[i].Address << " |" << endl;
                }
                break;
            case 8:
                n = atoi(Students[i].Dinamic.c_str());
                if (n == t6)
                {
                    cout << "|" << setw(20) << Students[i].FIO << "| ";
                    cout << Students[i].Dinamic << " |" << endl;
                }
                break;
            case 9:
                n = atoi(Students[i].Final.c_str());
                if (n == t6)
                {
                    cout << "|" << setw(20) << Students[i].FIO << "| ";
                    cout << Students[i].Final << " |" << endl;
                }
                break;
            case 10:
                n = atoi(Students[i].Average.c_str());
                if (n == t6)
                {
                    cout << "|" << setw(20) << Students[i].FIO << "| ";
                    cout << Students[i].Average << " |" << endl;
                }
                break;
            default:cout << "�������� ����" << endl; break;
            }
        }
    }
    t5 = 0; t6 = 0;
}

void Sorted()
{
    cout << "���������� �� �������" << endl;
    cout << "�������� ���� ��� ����������:" << endl;
    int t3 = 0; string* a = new string[Students.size()];
    t3 = Choise_Topic();
    switch (t3)
    {
    case 1:
        for (int i = 0; i < Students.size(); i++)
        {
            a[i] = Students[i].Cycles;
        }
        break;
    case 2:
        for (int i = 0; i < Students.size(); i++)
        {
            a[i] = Students[i].Arrays;
        }
        break;
    case 3:
        for (int i = 0; i < Students.size(); i++)
        {
            a[i] = Students[i].Strings;
        }
        break;
    case 4:
        for (int i = 0; i < Students.size(); i++)
        {
            a[i] = Students[i].Recursion;
        }
        break;
    case 5:
        for (int i = 0; i < Students.size(); i++)
        {
            a[i] = Students[i].Structs;
        }
        break;
    case 6:
        for (int i = 0; i < Students.size(); i++)
        {
            a[i] = Students[i].Files;
        }
        break;
    case 7:
        for (int i = 0; i < Students.size(); i++)
        {
            a[i] = Students[i].Address;
        }
        break;
    case 8:
        for (int i = 0; i < Students.size(); i++)
        {
            a[i] = Students[i].Dinamic;
        }
        break;
    case 9:
        for (int i = 0; i < Students.size(); i++)
        {
            a[i] = Students[i].Final;
        }
        break;
    case 10:
        for (int i = 0; i < Students.size(); i++)
        {
            a[i] = Students[i].Average;
        }
        break;
    default:cout << "�������� ����" << endl; break;
    }
    int len = Students.size();
    while (len--)
    {
        for (int i = 0; i < Students.size(); i++)
        {
            bool swapped = false;
            for (int i = 0; i < len; i++)
            {
                if (a[i] < a[i + 1])
                {
                    swap(a[i], a[i + 1]);
                    swapped = true;
                }
            }
            if (swapped == false) break;
        }
    }
    cout << "|" << setw(20) << "�������" << "|" << endl;
    for (int i = 0; i < Students.size(); i++)
    {
        cout << "|" << setw(20) << Students[i].FIO << "| ";
        cout << a[i] << " |" << endl;
    }

}

int Teacher_chek()
{
    string logincheck = "admin";
    string passwordcheck = "321";
    string login;
    string password;
    cout << "\t+-----------------------------------------------------+" << endl;
    cout << "\t|                                                     |" << endl;
    cout << "\t|              ����� �������������                   |" << endl;
    cout << "\t|                                                     |" << endl;
    cout << "\t| 1-������ ����� � ������ ��� �����                   |" << endl;
    cout << "\t| 2-����� � ������� ����                              |" << endl;
    cout << "\t+-----------------------------------------------------+" << endl << endl << endl;
    int t = 0;
    do
    {
        cin >> t;
        if (t != 1 && t != 2) cout << "�������� ����. ���������� �����..." << endl;
    } while (t < 1 || t>2);
    if (t == 1)
    {
        cout << "\t�����: ";
        do
        {
            cin >> login;
            if (logincheck != login) cout << "������������ �����, ��������� ����..." << endl << "\t";
        } while (logincheck != login);
        cout << "������: ";
        do
        {
            cin >> password;
            if (passwordcheck != password) cout << "������������ ������, ��������� ����..." << endl << "\t";
        } while (passwordcheck != password);
        return 1;
    }
    else return 0;
}

void Menu_Students()
{
    Title titles[30];
    int task = 0;
    int choice;
    do
    {
        //system("cls");
        cout << "+-----------------------------------------------------------------------------+" << endl;
        cout << "|                                                                             |" << endl;
        cout << "|                       ������ �� ������� ���������                           |" << endl;
        cout << "|                                                                             |" << endl;
        cout << "+-----------------------------------------------------------------------------+" << endl;
        cout << "|                                                                             |" << endl;
        cout << "|    1 - �������� � ����������� ���������                                     |" << endl;
        cout << "|    2 - ��������� ��������� ���������                                        |" << endl;
        cout << "|    3 - ����� ������ ��������� � ��������                                    |" << endl;
        cout << "|    4 - ����������                                                           |" << endl;
        cout << "|    5 - �����������                                                          |" << endl;
        cout << "|    6 - �����                                                                |" << endl;
        cout << "|                                                                             |" << endl;
        cout << "+-----------------------------------------------------------------------------+" << endl << endl << endl;

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            choice = 0;
        }

        switch (choice) {
        case 1:
            addAndDeleteStudents();
            Sleep(1000);
            break;
        case 2:
            editProgress();
            Sleep(1000);
            break;
        case 3:
            cout << "1 - �� ���� �����" << endl << "2 - �� ���������� ����(�������� ����� ��������� ����� � �������� �����)" << endl;
            do
            {
                cin >> task;
            } while (task != 1 && task != 2);
            if (task == 1)
            {
                Output_All_Topics();
                break;
            }
            else if (task == 2)
            {
                Output_Specific_Topic();
                break;
            }
            break;
        case 4:
            Filter();
            break;
        case 5:
            Sorted();
            break;
        case 6:
            cout << "������� �����..." << endl;
            Sleep(1000);
            break;
        default:
            cout << "�������� �����. ���������� �����." << endl;
        }
    } while (choice != 6);
}

int mainteacher()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string s;
    ifstream FILE("data.txt");
    while (getline(FILE, s))
    {
        Student_1 stud;
        stud.Login = s;
        getline(FILE, s);
        stud.Password = s;
        getline(FILE, s);
        stud.FIO = s;
        getline(FILE, s);
        stud.Cycles = s.back();
        getline(FILE, s);
        stud.Arrays = s.back();
        getline(FILE, s);
        stud.Strings = s.back();
        getline(FILE, s);
        stud.Recursion = s.back();
        getline(FILE, s);
        stud.Structs = s.back();
        getline(FILE, s);
        stud.Files = s.back();
        getline(FILE, s);
        stud.Address = s.back();
        getline(FILE, s);
        stud.Dinamic = s.back();
        getline(FILE, s);
        stud.Final = s.back();
        getline(FILE, s);
        stud.Average = s.substr(s.length() - 4);
        Students.push_back(stud);
    }
    FILE.close();
    int blok = 0;
    do
    {
        system("cls");
        if (Teacher_chek())
        {
            cout << "\t+-----------------------------------------------------+" << endl;
            cout << "\t|                                                     |" << endl;
            cout << "\t|            ����� ������������� ������               |" << endl;
            cout << "\t|                                                     |" << endl;
            cout << "\t+-----------------------------------------------------+" << endl;
            cout << "\t|                                                     |" << endl;
            cout << "\t| 1 - �������������� ��������                         |" << endl;
            cout << "\t| 2 - ������ �� ������� ���������                     |" << endl;
            cout << "\t| 3 - �����                                           |" << endl;
            cout << "\t|                                                     |" << endl;
            cout << "\t+-----------------------------------------------------+" << endl << endl << endl;
            cout << "\t";
        }
        else return 0;
        do
        {
            cin >> blok;
            if (blok < 1 && blok>3) cout << "�������� ����. ���������� �����..." << endl;
        } while (blok < 1 && blok>3);
        switch (blok)
        {
        case 1:
            editQuestions();
            Sleep(1000);
            break;
        case 2:
            Menu_Students();
            break;
        case 3:break;
        default:cout << "�������� ����" << endl; break;
        }
    } while (blok != 0);
    blok = 0;
    return 0;
}
