#include"Headerteacher.h"
vector<Student_1>Students;
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
            cout << "\t|            РЕЖИМ ПРЕПОДАВАТЕЛЯ ОТКРЫТ               |" << endl;
            cout << "\t|                                                     |" << endl;
            cout << "\t+-----------------------------------------------------+" << endl;
            cout << "\t|                                                     |" << endl;
            cout << "\t| 1 - Редактирование вопросов                         |" << endl;
            cout << "\t| 2 - Работа со списком студентов                     |" << endl;
            cout << "\t| 3 - ВЫХОД                                           |" << endl;
            cout << "\t|                                                     |" << endl;
            cout << "\t+-----------------------------------------------------+" << endl << endl << endl;
            cout << "\t";
        }
        else return 0;
        do
        {
            cin >> blok;
            if (blok < 1 && blok>3) cout << "Неверный ввод. Попробуйте снова..." << endl;
        } while (blok < 1 && blok>3);
        switch (blok)
        {
        case 1:
            editQuestions();
            Sleep(1000);
            break;
        case 2:
            Menu_Students(Students);
            break;
        case 3:break;
        default:cout << "Неверный ввод" << endl; break;
        }
    } while (blok != 0);
    blok = 0;
    return 0;
}
