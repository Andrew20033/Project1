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
        cout << "Укажите расстояние в км: "; cin >> S;
        cout << "У вас есть багаж? (y/n)";
        cin >> c;
        if (c == 'y')
        {
            cout << "Время езды: " << S * time << " минут" << endl;
            cout << "Стоимость проезда с багажом: " << (cost + 20) * S * time << " гривен" << endl;
        }
        else if (c == 'n')
        {
            cout << "Стоимость проезда без багажа: " << cost * S << " гривен" << endl;
            cout << "Время езды: " << time * S << " минут" << endl;
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
        cout << "Укажите расстояние в км: "; cin >> S;
        cout << "У вас есть багаж? (y/n)";
        cin >> c;
        if (c == 'y')
        {
            cout << "Время езды: " << S * (time + 10) << endl;
            cout << "Стоимость проезда с багажом: " << ((cost - 10) + 20) * S * (time + 10) << " гривен" << endl;
        }
        else if (c == 'n')
        {
            cout << "Стоимость проезда без багажа: " << cost * S << " гривен" << endl;
            cout << "Время езды: " << time * S << " минут" << endl;
        }

    }
};
class velo : public moped
{
    void getData()
    {
        char c;
        double S;
        cout << "Укажите расстояние в км: "; cin >> S;
        cout << "У вас есть багаж? (y/n) ";
        cin >> c;
        if (c == 'y')
        {
            cout << "Да какая разница? Пфф, места то нет. Либо вы, либо багаж? (i/b)";
            cin >> c;
            if (c == 'i')
            {
                cout << "Стоимость проезда без багажа: " << cost << " гривен" << endl;
                cout << "Время езды: " << time << " минут" << endl;
            }
            else if (c == 'b')
            {
                cout << "Стоимость проезда багажа 0 гривен" << endl;
                cout << "Спасибо за подарок!" << endl;
            }
        }
        else
        {
            cout << "Стоимость проезда без багажа: " << cost << " гривен" << endl;
            cout << "Время езды: " << time << " минут" << endl;
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
    cout << "На чем хотим проехаться?\n"
        "1. Авто\n"
        "2. Мопед\n"
        "3. Велосипед\n";
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