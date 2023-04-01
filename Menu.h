#pragma once
#include <iostream>
#include <Windows.h>
#include "Fractions.h"
#include <conio.h>
#include <cstdlib>

using namespace std;


class Menu {
public:
    Menu() { realSize = 0; }
    void mainMenu();
    void MakeFractionsMenu();

private:
    static const int MAX_SIZE = 100;
    Fractions fraction[MAX_SIZE];
    int realSize;
};


void Menu::mainMenu() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice = 0;
    cout << " ---------------------------------------- " << endl;
    cout << "¦ 1. [~] Створити дроби для операцій [~] ¦" << endl;
    cout << "¦ 2. [-] Операція віднімання         [-] ¦" << endl;
    cout << "¦ 3. [*] Операція множення           [*] ¦" << endl;
    cout << "¦ 4. [=] Порівняння об'єтків         [=] ¦" << endl;
    cout << "¦ 5. [!] Вихід                       [!] ¦" << endl;
    cout << " ---------------------------------------- " << endl;

    cout << "\n    • Виберіть пункт із списку: ";
    cin >> choice;
    system("cls");
    if (choice == 1) {
        MakeFractionsMenu();
    }
    if (choice == 2) {
        if (realSize < 2) {
            cout << "[!] Ви ввели недостатньо об'єктів [!] " << endl;
            cout << "Нажміть любу клавішу для продовження..." << endl;
            (void)_getch();
            system("cls");
            mainMenu();
        }
        else {
            Fractions sum = fraction[realSize - 2] - fraction[realSize - 1];
            if (sum.getA() == 0) {
                cout << "# Результат: " << sum.getA() << endl;
                cout << "Нажміть любу клавішу для продовження..." << endl;
                (void)_getch();
                system("cls");
                MakeFractionsMenu();
            }
            else if (sum.getB() == 1) {
                cout << "# Результат: " << sum.getA() << endl;
                cout << "Нажміть любу клавішу для продовження..." << endl;
                (void)_getch();
                system("cls");
                mainMenu();
            }
       
            else if (sum.getB() == -1) {
                cout << "# Результат: " << sum.getA() * -1<< endl;
                cout << "Нажміть любу клавішу для продовження..." << endl;
                (void)_getch();
                system("cls");
                mainMenu();
            }
            
            else {
                cout << "# Результат: " << sum.getA() << "/" << sum.getB() << endl;
                cout << "Нажміть любу клавішу для продовження..." << endl;
                (void)_getch();
                system("cls");
                mainMenu();
            }
        }
    }
    if (choice == 3) {
        if (realSize < 2) {
            cout << "[!] Ви ввели недостатньо об'єктів [!] " << endl;
            cout << "Нажміть любу клавішу для продовження..." << endl;
            (void)_getch();
            system("cls");
            mainMenu();
        }
        else {
            Fractions sum = fraction[realSize - 2] * fraction[realSize - 1];
            if (sum.getA() == 0) {
                cout << "# Результат: " << sum.getA() << endl;
                cout << "Нажміть любу клавішу для продовження..." << endl;
                (void)_getch();
                system("cls");
                mainMenu();
            }
            else if (sum.getB() == 1) {
                cout << "# Результат: " << sum.getA() << endl;
                cout << "Нажміть любу клавішу для продовження..." << endl;
                (void)_getch();
                system("cls");
                mainMenu();
            }
            else if (sum.getB() == -1) {
                cout << "# Результат: " << sum.getA() * -1 << endl;
                cout << "Нажміть любу клавішу для продовження..." << endl;
                (void)_getch();
                system("cls");
                mainMenu();
            }
            else {
                cout << "# Результат: " << sum.getA() << "/" << sum.getB() << endl;
                cout << "Нажміть любу клавішу для продовження..." << endl;
                (void)_getch();
                system("cls");
                mainMenu();
            }
        }
    }
    if (choice == 4) {
        if (realSize == 0) {
            cout << "[!] Ви ще не добавили дроби [!]" << endl;
            cout << "Нажміть любу клавішу для продовження..." << endl;
            (void)_getch();
            system("cls");
            mainMenu();
        }
        if (realSize == 1) {
            cout << "[!] Ви добавили лише один дріб [!]" << endl;
            cout << "Нажміть любу клавішу для продовження..." << endl;
            (void)_getch();
            system("cls");
            mainMenu();
        }
        if (realSize >= 2) { 
            if (fraction[realSize - 2].getX() != NULL && fraction[realSize - 1].getX() != NULL) {
                cout << "Зараз ви порівнюєте: ";
                cout << fraction[realSize - 2].getX() << "*" << "(" << fraction[realSize - 2].getA() << "/" << fraction[realSize - 2].getB() << ")";
                cout <<" і "<< fraction[realSize - 1].getX() << "+" << "(" << fraction[realSize - 1].getA() << "/" << fraction[realSize - 1].getB() << ")";
                cout << "Дроби які ви порівняли є "; fraction[realSize - 2] == fraction[realSize - 1];
                cout << "Нажміть любу клавішу для продовження..." << endl;
                (void)_getch();
                system("cls");
                mainMenu();
            }
            else if (fraction[realSize - 2].getX() != NULL && fraction[realSize - 1].getX() == NULL) {
                cout << "Зараз ви порівнюєте: ";
                cout << fraction[realSize - 2].getX() << "+" << "(" << fraction[realSize - 2].getA() << "/" << fraction[realSize - 2].getB() << ")";
                cout << " і "  << fraction[realSize - 1].getA() << "/" << fraction[realSize - 1].getB() << endl;
                cout << "Дроби які ви порівняли є "; fraction[realSize - 2] == fraction[realSize - 1];
                cout << "Нажміть любу клавішу для продовження..." << endl;
                (void)_getch();
                system("cls");
                mainMenu();
            }
            else if (fraction[realSize - 2].getX() == NULL && fraction[realSize - 1].getX() != NULL) {
                cout << "Зараз ви порівнюєте: ";
                cout <<  fraction[realSize - 2].getA() << "/" << fraction[realSize - 2].getB();
                cout <<" і "<< fraction[realSize - 1].getX() << "+" << "(" << fraction[realSize - 1].getA() << "/" << fraction[realSize - 1].getB() << ")" << endl;
                cout << "Дроби які ви порівняли є "; fraction[realSize - 2] == fraction[realSize - 1];
                cout << "Нажміть любу клавішу для продовження..." << endl;
                (void)_getch();
                system("cls");
                mainMenu();
            }
            else if (fraction[realSize - 2].getX() == NULL && fraction[realSize - 1].getX() == NULL) {
                cout << "Зараз ви порівнюєте: ";
                cout << fraction[realSize - 2].getA() << "/" << fraction[realSize - 2].getB();
                cout << " і " << fraction[realSize - 1].getA() << "/" << fraction[realSize - 1].getB() << endl;
                cout << "Дроби які ви порівняли є "; fraction[realSize - 2] == fraction[realSize - 1];
                cout << "Нажміть любу клавішу для продовження..." << endl;
                (void)_getch();
                system("cls");
                mainMenu();
            }
        }
    }
    if (choice == 5) {
        exit(0);
    }


    if (choice > 4 || choice < 0) {
        cout << "Такого пункту не існує" << endl;
        cout << "Нажміть любу клавішу для продовження...";
        (void)_getch();
        system("cls");
        mainMenu();
    }
}

void Menu::MakeFractionsMenu() {
    int choice = 0;
    cout << "  -------------------------------––––-  " << endl;
    cout << "¦ 1. [+] Додати дріб у вигляді x+(a/b) ¦" << endl;
    cout << "¦ 2. [+] Додати дріб у вигляді a/b     ¦" << endl;
    cout << "¦ 3. [-] Повернутися до головного меню ¦" << endl;
    cout << "  ------------------------------------  " << endl;
    cout << endl;
    cout << "     • Виберіть пункт із списку: ";
    cin >> choice;
    system("cls");
    if (choice == 1) {
        int x, a, b;
        cout << "[+] -> Введіть значення x, a, b: ";
        cin >> x >> a >> b;
        if (b == 0) {
            system("cls");
            cout << "[!] Змінна b не може дорівнювати нулю! [!]\n>> Нажміть любу клавішу для продовження..." << endl;
            (void)_getch();
            system("cls");
            MakeFractionsMenu();
        }
        else {
            Fractions fr(x, a, b);
            fraction[realSize] = fr;
            realSize++;
            system("cls");
            MakeFractionsMenu();
        }
    }
    if (choice == 2) {
        int a, b;
        cout << "[+] -> Введіть значення a, b: ";
        cin >> a >> b;
        if (b == 0) {
            system("cls");
            cout << "[!] Змінна b не може дорівнювати нулю! [!]\n>> Нажміть любу клавішу для продовження..." << endl;
            (void)_getch();
            system("cls");
            MakeFractionsMenu();
        }
        else {
            Fractions fr(a, b);
            fraction[realSize] = fr;
            realSize++;
            system("cls");
            MakeFractionsMenu();
        }
    }
    if (choice == 3) {
        mainMenu();
    }
}
