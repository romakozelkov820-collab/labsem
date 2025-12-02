#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

void process2(char* &str, int &len);

void method2() {
    const int BLOCK = 5;
    int capacity = BLOCK;
    int len = 0;

    char* str = (char*)calloc(capacity, sizeof(char));

    cout << "Метод 2 (calloc + realloc): введите строку: ";

    while (true) {
        char c = getchar();
        if (c == '\n' || c == EOF) break;

        if (len + 1 >= capacity) {
            capacity += BLOCK;
            str = (char*)realloc(str, capacity);
        }

        str[len++] = c;
        str[len] = '\0';
    }

    process2(str, len);

    cout << "Результат: " << str << endl;

    free(str);
}

void process2(char* &str, int &len) {
    int write = 0;
    for (int i = 0; i < len; i++)
        if (!(str[i] >= '0' && str[i] <= '9'))
            str[write++] = str[i];
    len = write;
    str[len] = '\0';

    for (int i = 0; i < len; i++) {
        if (str[i] == '+' || str[i] == '-') {
            str = (char*)realloc(str, len + 2);

            for (int j = len; j > i; j--)
                str[j] = str[j - 1];

            str[i + 1] = str[i];
            len++;
            i++;
        }
    }

    if (len % 2 == 0)
        for (int i = 0; i < len / 2; i++)
            swap(str[i], str[len - i - 1]);
}