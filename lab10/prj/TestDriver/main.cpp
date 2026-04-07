#include <iostream>
#include <fstream>
#include <cstdlib>
#include "D:\Nikolenko-Sviatoslav-KN25\lab08\prj\ModulesNikolenko.h"

using namespace std;

void prepareTestFiles() {
    ofstream f1("in1.txt");
    if (f1.is_open()) {
        f1 << "Студент написав модуль, а програміст - програма." << endl;
        f1.close();
    }

    ofstream f2("in2.txt");
    if (f2.is_open()) {
        f2 << "Сьогодні 2023 рік, 10 місяць." << endl;
        f2.close();
    }

    ofstream f3("out3.txt");
    if (f3.is_open()) {
        f3.close();
    }
}

int main() {
    system("chcp 65001 > nul");

    cout << "=== ПРОТОКОЛ ТЕСТУВАННЯ ФАЙЛОВИХ МОДУЛІВ ===" << endl;
    cout << "Підготовка вхідних файлів..." << endl;
    prepareTestFiles();
    cout << "Файли in1.txt та in2.txt успішно створено.\n" << endl;

    cout << "--- Тестування Задачі 10.1 ---" << endl;
    cout << "Очікується: створення out1.txt з підрахунком символів та знайденими словами." << endl;
    task_10_1("in1.txt", "out1.txt");

    cout << "\n--- Тестування Задачі 10.2 ---" << endl;
    cout << "Очікується: підрахунок цифр в in2.txt та дозапис дати/часу." << endl;
    task_10_2("in2.txt");

    cout << "\n--- Тестування Задачі 10.3 ---" << endl;
    cout << "Очікується: виклик S_calculation та дозапис трьох результатів у out3.txt." << endl;

    task_10_3("out3.txt", 1.0, 2.0, 3.0, 5);
    task_10_3("out3.txt", 0.0, 0.0, 1.57, 0);
    task_10_3("out3.txt", 2.0, 1.0, 1.57, 10);

    cout << "\n============================================" << endl;
    cout << "Тестування завершено! Перевірте вміст файлів:" << endl;
    cout << "- out1.txt" << endl;
    cout << "- in2.txt (оновлений)" << endl;
    cout << "- out3.txt" << endl;
    cout << "Вони знаходяться у папці вашого проекту TestDriver." << endl;

    system("pause");
    return 0;
}
