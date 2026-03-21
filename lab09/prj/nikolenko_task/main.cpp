#include <iostream>
#include <cmath>
#include "D:\Nikolenko-Sviatoslav-KN25\lab08\prj\ModulesNikolenko.h"


using namespace std;

double s_calculation(double x, double y, double z) {
    if (sin(z) == 0.0) {
        return -INFINITY;
    }
    double term1 = 0.5 * pow(x, 2);
    double term2 = sqrt(abs(pow(y + z, 2) - pow(x, 5)));
    double term3 = log(abs(sin(z)));
    return term1 - term2 - term3;
}

int main() {
    char choice;

    // Головний цикл програми (ітераційний процес)
    do {
        cout << "\n================ ГОЛОВНЕ МЕНЮ ================" << endl;
        cout << "q - Виклик задачi 9.1 (Стан моря)" << endl;
        cout << "e - Виклик задачi 9.2 (Пiдрахунок чисел)" << endl;
        cout << "r - Виклик задачi 9.3 (Побiтовi операцiї)" << endl;
        cout << "t - Виклик задачi 8.1 (Обчислення функцiї S)" << endl;
        cout << "y, Y, н, Н - Вихiд з програми" << endl;
        cout << "==============================================" << endl;
        cout << "Ваш вибiр: ";
        cin >> choice;

        switch (choice) {
            case 'q': {
                int grade;
                cout << "\n--- Задача 9.1 ---" << endl;
                cout << "Введiть бал стану моря (0-9): ";
                cin >> grade;
                task_9_1(grade); // Виклик функції з модуля
                break;
            }
            case 'e': {
                int n;
                cout << "\n--- Задача 9.2 ---" << endl;
                cout << "Введiть кiлькiсть чисел (n): ";
                cin >> n;
                task_9_2(n); // Виклик функції з модуля
                break;
            }
            case 'r': {
                unsigned int N;
                cout << "\n--- Задача 9.3 ---" << endl;
                cout << "Введiть число N: ";
                cin >> N;
                int res = task_9_3(N); // Виклик функції з модуля
                if (res == -1) {
                    cout << "\aПомилка: число поза ОДЗ (має бути <= 70700)!" << endl;
                } else {
                    cout << "Результат: " << res << endl;
                }
                break;
            }
            case 't': {
                double x, y, z;
                cout << "\n--- Задача 8.1 ---" << endl;
                cout << "Введiть x, y, z: ";
                cin >> x >> y >> z;
                cout << "Результат S = " << s_calculation(x, y, z) << endl; // Виклик функції з модуля 8-ї лаби
                break;
            }
            case 'y':
            case 'Y':
            case 'н': // Українська літера 'н'
            case 'Н': // Українська літера 'Н'
                cout << "\nЗавершення роботи програми..." << endl;
                break;
            default:
                // \a створює системний звук (звуковий сигнал помилки)
                cout << "\a\nПомилка: Невiдома команда! Спробуйте ще раз." << endl;
                break;
        }
    } while (choice != 'y' && choice != 'Y' && choice != 'н' && choice != 'Н');

    return 0;
}
