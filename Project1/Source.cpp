#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

class transport
{
public:
    virtual void getData() = 0;
};
class car : public transport
{
protected:
    int time = 10;
    int cost = 20;
public:
    void getData()
    {
        char c;
        double S;
        cout << "������� ���������� � ��: "; cin >> S;
        cout << "� ��� ���� �����? (y/n)";
        cin >> c;
        if (c == 'y')
        {
            cout << "����� ����: " << S * time << " �����" << endl;
            cout << "��������� ������� � �������: " << (cost + 20) * S * time << " ������" << endl;
        }
        else if (c == 'n')
        {
            cout << "��������� ������� ��� ������: " << cost * S << " ������" << endl;
            cout << "����� ����: " << time * S << " �����" << endl;
        }

    }
};
class moped : public car
{
public:
    void getData()
    {
        char c;
        double S;
        cout << "������� ���������� � ��: "; cin >> S;
        cout << "� ��� ���� �����? (y/n)";
        cin >> c;
        if (c == 'y')
        {
            cout << "����� ����: " << S * (time + 10) << endl;
            cout << "��������� ������� � �������: " << ((cost - 10) + 20) * S * (time + 10) << " ������" << endl;
        }
        else if (c == 'n')
        {
            cout << "��������� ������� ��� ������: " << cost * S << " ������" << endl;
            cout << "����� ����: " << time * S << " �����" << endl;
        }

    }
};
class velo : public moped
{
    void getData()
    {
        char c;
        double S;
        cout << "������� ���������� � ��: "; cin >> S;
        cout << "� ��� ���� �����? (y/n) ";
        cin >> c;
        if (c == 'y')
        {
            cout << "�� ����� �������? ���, ����� �� ���. ���� ��, ���� �����? (i/b)";
            cin >> c;
            if (c == 'i')
            {
                cout << "��������� ������� ��� ������: " << cost << " ������" << endl;
                cout << "����� ����: " << time << " �����" << endl;
            }
            else if (c == 'b')
            {
                cout << "��������� ������� ������ 0 ������" << endl;
                cout << "������� �� �������!" << endl;
            }
        }
        else
        {
            cout << "��������� ������� ��� ������: " << cost << " ������" << endl;
            cout << "����� ����: " << time << " �����" << endl;
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    transport* autom = new car;
    transport* mop = new moped;
    transport* vel = new velo;
    int choice;
    cout << "�� ��� ����� ����������?\n"
        "1. ����\n"
        "2. �����\n"
        "3. ���������\n";
    cout << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        autom->getData();
        break;
    case 2:
        mop->getData();
        break;
    case 3:
        vel->getData();
        break;
    }
    delete autom;
    delete mop;
    delete vel;
}