#pragma once // Включення гарантує, що цей файл підключається лише один раз під час компіляції
#include <iostream>
#include <Windows.h>
#include "Fractions.h"
#include <conio.h>
#include <cstdlib>

using namespace std;

class Menu {
public:
    Menu() { realSize = 0; } // Конструктор класу, що ініціалізує розмір масиву
    void mainMenu(); // Оголошення функції головного меню
    void MakeFractionsMenu(); // Оголошення функції меню створення дробів

private:
    static const int MAX_SIZE = 100; // Максимальний розмір масиву дробів
    Fractions fraction[MAX_SIZE]; // Масив дробів
    int realSize; // Реальний розмір масиву дробів
};

void Menu::mainMenu() { // Оголошення функції головного меню
    SetConsoleCP(1251); // Встановлюємо кодування введення
    SetConsoleOutputCP(1251); // Встановлюємо кодування виведення
    int choice = 0; // Змінна для зберігання вибору користувача
    cout << " ---------------------------------------- " << endl;
    cout << "¦ 1. [~] Створити дроби для операцій [~] ¦" << endl;
    cout << "¦ 2. [-] Операція віднімання         [-] ¦" << endl;
    cout << "¦ 3. [*] Операція множення           [*] ¦" << endl;
    cout << "¦ 4. [=] Порівняння об'єтків         [=] ¦" << endl;
    cout << "¦ 5. [!] Вихід                       [!] ¦" << endl;
    cout << " ---------------------------------------- " << endl;

    cout << "\n    • Виберіть пункт із списку: ";
    cin >> choice; // Отримуємо вибір користувача
    system("cls"); // Очищаємо екран
    if (choice == 1) { // Якщо користувач обрав створення дробів
        MakeFractionsMenu(); // Викликаємо функцію меню створення дробів
    }
    if (choice == 2) { // Якщо користувач обрав операцію віднімання
        if (realSize < 2) { // Якщо кількість дробів менша 2-х
            cout << "[!] Ви ввели недостатньо об'єктів [!] " << endl; // Повідомлення про помилку
            cout << "Нажміть любу клавішу для продовження..." << endl; // Повідомлення для продовження
            (void)_getch(); // Очікування натискання клавіші
            system("cls"); // Очищення екрану
            mainMenu(); // Повернення до головного меню
        }
        else { // Якщо кількість дробів достатня
            Fractions sum = fraction[realSize - 2] - fraction[realSize - 1]; // Виконуємо операцію віднімання над останніми двома дробами в масиві
            if (sum.getA() == 0) { // Якщо чисельник рівний 0
                cout << "# Результат: " << sum.getA() << endl; // Виводимо на екран результат з чисельником 0
                cout << "Нажміть любу клавішу для продовження..." << endl; // Повідомлення для продовження
                (void)_getch(); // Очікування натискання клавіші
                system("cls"); // Очищення екрану
                MakeFractionsMenu(); // Повернення до меню створення дробів
            }
            else if (sum.getB() == 1) { // Якщо знаменник рівний 1
                cout << "# Результат: " << sum.getA() << endl; // Виводимо на екран результат з чисельником
                cout << "Нажміть любу клавішу для продовження..." << endl; // Повідомлення для продовження
                (void)_getch(); // Очікування натискання клавіші
                system("cls"); // Очищення екрану
                mainMenu(); // Повернення до головного меню
            }

            else if (sum.getB() == -1) { // перевірка, чи дріб не містить дробової частини і від'ємний
                cout << "# Результат: " << sum.getA() * -1 << endl; // виведення від'ємного цілого числа зі знаком мінус
                cout << "Нажміть любу клавішу для продовження..." << endl;
                (void)_getch();
                system("cls");
                mainMenu();
            }

            else { // дріб містить дробову частину
                cout << "# Результат: " << sum.getA() << "/" << sum.getB() << endl; // виведення дробу
                cout << "Нажміть любу клавішу для продовження..." << endl;
                (void)_getch();
                system("cls");
                mainMenu();
            }
        }
    }
    if (choice == 3) { // якщо користувач обрав опцію множення
        if (realSize < 2) { // якщо в масиві недостатньо дробів
            cout << "[!] Ви ввели недостатньо об'єктів [!] " << endl;
            cout << "Нажміть любу клавішу для продовження..." << endl;
            (void)_getch();
            system("cls");
            mainMenu();
        }
        else { // якщо в масиві принаймні два дроби
            Fractions sum = fraction[realSize - 2] * fraction[realSize - 1]; // обчислення добутку останніх двох дробів у масиві
            if (sum.getA() == 0) { // якщо результат - ціле число
                cout << "# Результат: " << sum.getA() << endl; // виведення цілого числа
                cout << "Нажміть любу клавішу для продовження..." << endl;
                (void)_getch();
                system("cls");
                mainMenu();
            }
            else if (sum.getB() == 1) { // якщо результат - ціле число
                cout << "# Результат: " << sum.getA() << endl; // виведення цілого числа
                cout << "Нажміть любу клавішу для продовження..." << endl;
                (void)_getch();
                system("cls");
                mainMenu();
            }
            else if (sum.getB() == -1) { // якщо результат - від'ємне ціле число
                cout << "# Результат: " << sum.getA() * -1 << endl; // виведення від'ємного цілого числа зі знаком мінус
                cout << "Нажміть любу клавішу для продовження..." << endl;
                (void)_getch();
                system("cls");
                mainMenu();
            }
            else { // якщо результат є дробом
                cout << "# Результат: " << sum.getA() << "/" << sum.getB() << endl; // виведення дробу
                cout << "Нажміть любу клавішу для продовження..." << endl;
                (void)_getch();
                system("cls");
                mainMenu();
            }
        }
    }
    if (choice == 4) { // якщо користувач обрав опцію порівняння дробів
        if (realSize == 0) { // якщо в масиві немає дробів
            cout << "[!] Ви ще не добавили дроби [!]" << endl;
            cout << "Нажміть любу клавішу для продовження..." << endl;
            (void)_getch();
            system("cls");
            mainMenu();
        }
        if (realSize == 1) { // якщо в масиві є лише один дріб
            cout << "[!] Ви добавили лише один дріб [!]" << endl;
            cout << "Нажміть любу клавішу для продовження..." << endl;
            (void)_getch();
            system("cls");
            mainMenu();
        }
        if (realSize >= 2) { // якщо в масиві є принаймні два дроби
            if (fraction[realSize - 2].getX() != NULL && fraction[realSize - 1].getX() != NULL) { // якщо існують змінні для дробів, які будуть порівнюватися
                cout << "Зараз ви порівнюєте: ";
                cout << fraction[realSize - 2].getX() << "*" << "(" << fraction[realSize - 2].getA() << "/" << fraction[realSize - 2].getB() << ")";
                cout << " і " << fraction[realSize - 1].getX() << "+" << "(" << fraction[realSize - 1].getA() << "/" << fraction[realSize - 1].getB() << ")";
                cout << "Дроби які ви порівняли є "; fraction[realSize - 2] == fraction[realSize - 1]; // виклик функції порівняння дробів
                cout << "Нажміть любу клавішу для продовження..." << endl;
                (void)_getch();
                system("cls");
                mainMenu();
            }
            else if (fraction[realSize - 2].getX() != NULL && fraction[realSize - 1].getX() == NULL) { // якщо перший дріб має змінну, а другий ні
                cout << "Зараз ви порівнюєте: ";
                cout << fraction[realSize - 2].getX() << "+" << "(" << fraction[realSize - 2].getA() << "/" << fraction[realSize - 2].getB() << ")";
                cout << " і " << fraction[realSize - 1].getA() << "/" << fraction[realSize - 1].getB() << endl;
                cout << "Дроби які ви порівняли є "; fraction[realSize - 2] == fraction[realSize - 1]; // виклик функції порівняння дробів
                cout << "Нажміть любу клавішу для продовження..." << endl;
                (void)_getch();
                system("cls");
                mainMenu();
            }
            else if (fraction[realSize - 2].getX() == NULL && fraction[realSize - 1].getX() != NULL) { // якщо другий дріб має змінну, а перший ні
                cout << "Зараз ви порівнюєте: ";
                cout << fraction[realSize - 2].getA() << "/" << fraction[realSize - 2].getB();
                cout << " і " << fraction[realSize - 1].getX() << "+" << "(" << fraction[realSize - 1].getA() << "/" << fraction[realSize - 1].getB() << ")" << endl;
                cout << "Дроби які ви порівняли є "; fraction[realSize - 2] == fraction[realSize - 1]; // виклик функції порівняння дробів
                cout << "Нажміть любу клавішу для продовження..." << endl;
                (void)_getch();
                system("cls");
                mainMenu();
            }

            else if (fraction[realSize - 2].getX() == NULL && fraction[realSize - 1].getX() == NULL) { // якщо обидва дроби не мають змінних
                cout << "Зараз ви порівнюєте: ";
                cout << fraction[realSize - 2].getA() << "/" << fraction[realSize - 2].getB();
                cout << " і " << fraction[realSize - 1].getA() << "/" << fraction[realSize - 1].getB() << endl;
                cout << "Дроби які ви порівняли є "; fraction[realSize - 2] == fraction[realSize - 1]; // виклик функції порівняння дробів
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

    if (choice > 4 || choice < 0) { // перевіряється, чи введено коректний номер меню
        cout << "Такого пункту не існує" << endl;
        cout << "Нажміть любу клавішу для продовження...";
        (void)_getch();
        system("cls");
        mainMenu(); // якщо вибір користувача некоректний, програма повертається до меню
    }
}

void Menu::MakeFractionsMenu() { // функція меню для додавання дробів
    int choice = 0;
    cout << "  -------------------------------––––-  " << endl;
    cout << "¦ 1. [+] Додати дріб у вигляді x+(a/b) ¦" << endl; // опція для додавання дробу зі змінною
    cout << "¦ 2. [+] Додати дріб у вигляді a/b     ¦" << endl; // опція для додавання дробу без змінної
    cout << "¦ 3. [-] Повернутися до головного меню ¦" << endl; // опція для виходу до головного меню
    cout << "  ------------------------------------  " << endl;
    cout << endl;
    cout << "     • Виберіть пункт із списку: ";
    cin >> choice;
    system("cls");

    if (choice == 1) { // додавання дробу зі змінною
        int x, a, b;
        cout << "[+] -> Введіть значення x, a, b: ";
        cin >> x >> a >> b;
        if (b == 0) { // якщо b == 0, то ділення на 0 не допустиме
            system("cls");
            cout << "[!] Змінна b не може дорівнювати нулю! [!]\n>> Нажміть любу клавішу для продовження..." << endl;
            (void)_getch();
            system("cls");
            MakeFractionsMenu();
        }
        else { // якщо все введене коректно, створюється дріб та зберігається в масив
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
        // У цьому рядку користувач вводить значення для змінних a та b
        cin >> a >> b;
        // Якщо змінна b дорівнює 0, виводимо повідомлення про помилку
        if (b == 0) {
            system("cls");
            cout << "[!] Змінна b не може дорівнювати нулю! [!]\n>> Нажміть любу клавішу для продовження..." << endl;
            // Користувач повинен натиснути будь-яку клавішу, щоб продовжити програму
            (void)_getch();
            system("cls");
            // Якщо користувач ввів 0 для b, повертаємося до головного меню програми
            MakeFractionsMenu();
        }
        else {
            // Якщо змінна b не дорівнює 0, створюємо об'єкт класу Fractions і додаємо його до масиву fraction
            Fractions fr(a, b);
            fraction[realSize] = fr;
            realSize++;
            system("cls");
            // Після додавання нової дробу повертаємося до меню дробів
            MakeFractionsMenu();
        }
    }
    // Якщо користувач ввів "3" в головному меню програми, повертаємося до головного меню
    if (choice == 3) {
        mainMenu();
    }
}
