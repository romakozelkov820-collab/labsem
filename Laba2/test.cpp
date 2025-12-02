#include <iostream>
#include "method1.h"
#include "method2.h"
#include "method3.h"

using namespace std;

int main() {
    int choice;

    cout << "Выберите метод:\n";
    cout << "1 — malloc (увеличение на 1)\n";
    cout << "2 — calloc + realloc (блоками по 5)\n";
    cout << "3 — файл input/output\n";
    cout << "> ";
    cin >> choice;
    getchar(); // убрать \n

    switch (choice) {
        case 1: method1(); break;
        case 2: method2(); break;
        case 3: method3(); break;
        default: cout << "Неверный выбор\n";
    }

    return 0;
}