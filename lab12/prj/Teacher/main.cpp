#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <clocale>
#include "ModulesNikolenko.h"

using namespace std;


bool isPathCorrect() {
    string compilePath = __FILE__;

    if (compilePath.find("\\lab12\\prj\\Teacher\\") != string::npos ||
        compilePath.find("/lab12/prj/Teacher/") != string::npos) {
        return true;
    }
    return false;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    if (!isPathCorrect()) {
        ofstream errorFile("TestResults.txt");
        if (errorFile.is_open()) {
            errorFile << "Встановлені вимоги порядку виконання лабораторної роботи порушено!" << endl;
            errorFile.close();
        }

        cout << "Порушено вимоги розташування проєкту! Запуск звукових сигналів..." << endl;
        for (int i = 0; i < 100; ++i) {
            Beep(1000, 150);
            Sleep(50);
        }
        return 0;
    }

    cout << "Перевірку шляху пройдено успішно. Починаємо Unit-тестування класу..." << endl;
    ofstream logFile("../TestSuite/TestResults.txt");
    if (!logFile.is_open()) {
        logFile.open("TestResults.txt");
    }

    logFile << "=== ПРОТОКОЛ АВТОМАТИЗОВАНОГО ТЕСТУВАННЯ ===" << endl;

    class TestRunner {
    public:
        static void executeTestSuite(const string& filename, ofstream& log) {
            ifstream testFile(filename);
            if (!testFile.is_open()) {
                log << "Помилка: Не вдалося відкрити файл тестів: " << filename << endl;
                cout << "Файл тестів не знайдено!" << endl;
                return;
            }

            string tc_id, delimiter;
            double a, b, h, expectedVolume;

            while (testFile >> tc_id >> delimiter >> a >> b >> h >> delimiter >> expectedVolume) {
                ClassLab12_Nikolenko aquarium;
                aquarium.setA(a);
                aquarium.setB(b);
                aquarium.setH(h);

                double actualVolume = aquarium.calculateVolume();

                string result = (abs(actualVolume - expectedVolume) < 0.0001) ? "PASSED" : "FAILED";

                log << tc_id << " -> Inputs: a=" << a << ", b=" << b << ", h=" << h
                    << " -> Expected Volume: " << expectedVolume
                    << " -> Actual Volume: " << actualVolume
                    << " -> Result: " << result << endl;

                cout << tc_id << ": " << result << endl;
            }
            testFile.close();
        }
    };
    TestRunner::executeTestSuite("../../TestSuite/test_suite_01.txt", logFile);

    logFile << "=== ТЕСТУВАННЯ ЗАВЕРШЕНО ===" << endl;
    logFile.close();

    cout << "Тестування успішно завершено! Результати записано в TestResults.txt" << endl;
    return 0;
}
