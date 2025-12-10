#include <iostream>
#include <string>
#include "OneList.h"
#include "DoubleList.h"
#include "processor.h"

using namespace std;

int main() {
    cout << "Выберите структуру для хранения строки:\n";
    cout << "1 - OneList (односвязный)\n";
    cout << "2 - DoubleList (двухсвязный)\n";
    cout << "> ";
    int choice;
    if (!(cin >> choice)) return 0;
    string line;
    getline(cin, line); 

    cout << "Введите строку: ";
    getline(cin, line);

    if (choice == 1) {
        OneList<char> lst;
        for (char c : line) lst.push_back(c);

        process_string_list(lst);

        for (auto it = lst.begin(); it != lst.end(); ++it) cout << *it;
        cout << '\n';
    } else if (choice == 2) {
        DoubleList<char> lst;
        for (char c : line) lst.push_back(c);

        process_string_list(lst);

        for (auto it = lst.begin(); it != lst.end(); ++it) cout << *it;
        cout << '\n';
    } else {
        cout << "Неверный выбор\n";
    }

    return 0;
}