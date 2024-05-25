#include "Header.h"

void Shifrin()
{
    ifstream in("data.txt");
    ofstream out("output.txt");
    string s;
    if (in) {
        while (getline(in, s)) { //Пробегаем по строкам файла
            char key = 'X'; //Определяем ключ шифрования (любой символ подойдет) 
            int len = s.length(); //Определяем длину строки
            for (int i = 0; i < len; i++) {
                s[i] = s[i] ^ key; //Шифруем каждый символ
                out << s[i]; //Выводим зашифрованную строку
            }
            out << endl;
        }
    }
    out.close();
    in.close();
    remove("data.txt");
    rename("output.txt", "data.txt");
}

void Shifrout()
{
    ifstream in1("data.txt");
    string s1;
    if (in1) {
        while (getline(in1, s1)) { //Пробегаем по строкам файла
            ofstream out1("output.txt");
            char key1 = 'X'; //Определяем ключ шифрования (любой символ подойдет) 
            int len1 = s1.length(); //Определяем длину строки
            for (int i = 0; i < len1; i++) {
                s1[i] = s1[i] ^ key1; //Шифруем каждый символ
                out1 << s1[i]; //Выводим зашифрованную строку
            }
            out1<< endl;
            out1.close();
        }
    }
    in1.close();
    remove("data.txt");
    rename("output.txt", "data.txt");
}

void clearall()
{
	system("cls");
}