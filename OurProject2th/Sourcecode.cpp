#include "Header.h"

void Shifrin()
{
    ifstream in("data.txt");
    ofstream out("output.txt");
    string s;
    if (in) {
        while (getline(in, s)) { //��������� �� ������� �����
            char key = 'X'; //���������� ���� ���������� (����� ������ ��������) 
            int len = s.length(); //���������� ����� ������
            for (int i = 0; i < len; i++) {
                s[i] = s[i] ^ key; //������� ������ ������
                out << s[i]; //������� ������������� ������
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
        while (getline(in1, s1)) { //��������� �� ������� �����
            ofstream out1("output.txt");
            char key1 = 'X'; //���������� ���� ���������� (����� ������ ��������) 
            int len1 = s1.length(); //���������� ����� ������
            for (int i = 0; i < len1; i++) {
                s1[i] = s1[i] ^ key1; //������� ������ ������
                out1 << s1[i]; //������� ������������� ������
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