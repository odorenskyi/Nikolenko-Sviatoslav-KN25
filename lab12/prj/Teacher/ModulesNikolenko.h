#ifndef MODULES_NIKOLENKO_H
#define MODULES_NIKOLENKO_H
#include <iostream>

// --- Функції з Лабораторної роботи №9 ---
void task_9_1(int grade);
void task_9_2(int n);
int task_9_3(unsigned int N);

// --- Функція з Лабораторної роботи №8 ---
double s_calculation(double x, double y, double z);

// --- НОВІ Функції з Лабораторної роботи №10 ---
void task_10_1(const char* inFile, const char* outFile);

// Задача 10.2: підрахунок цифр, дозапис часу у той самий файл
void task_10_2(const char* inFile);

// Задача 10.3: виклик s_calculation, двійковий код, дозапис у файл
void task_10_3(const char* outFile, double x, double y, double z, unsigned int b);

class ClassLab12_Nikolenko {
private:
    double sideA;
    double sideB;
    double sideH;

public:
    ClassLab12_Nikolenko(double a = 1.0, double b = 1.0, double h = 1.0);

    void setA(double a);
    void setB(double b);
    void setH(double h);

    double getA() const;
    double getB() const;
    double getH() const;

    double calculateVolume() const;
};

ClassLab12_Nikolenko::ClassLab12_Nikolenko(double a, double b, double h) {

    this->setA(a);
    this->setB(b);
    this->setH(h);
}

void ClassLab12_Nikolenko::setA(double a) {
    if (a > 0) {
        sideA = a;
    } else {
        sideA = 1.0;
    }
}

void ClassLab12_Nikolenko::setB(double b) {
    if (b > 0) {
        sideB = b;
    } else {
        sideB = 1.0;
    }
}

void ClassLab12_Nikolenko::setH(double h) {
    if (h > 0) {
        sideH = h;
    } else {
        sideH = 1.0;
    }
}

double ClassLab12_Nikolenko::getA() const {
    return sideA;
}

double ClassLab12_Nikolenko::getB() const {
    return sideB;
}

double ClassLab12_Nikolenko::getH() const {
    return sideH;
}

double ClassLab12_Nikolenko::calculateVolume() const {
    return sideA * sideB * sideH;
}

#endif
