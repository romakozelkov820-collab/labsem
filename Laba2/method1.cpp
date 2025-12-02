#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

void process(char* &str, int &len);

void method1() {
    cout << "Метод 1 (malloc): введите строку: ";

    char c;
    int len = 0;
    char* str = nullptr;

    while (true) {
        c = getchar();
        if (c == '\n' || c == EOF) break;

        char* newStr = (char*)malloc(len + 2);
        for (int i = 0; i < len; i++)
            newStr[i] = str[i];

        newStr[len] = c;
        newStr[len + 1] = '\0';

        free(str);
        str = newStr;
        len++;
    }

    process(str, len);

    cout << "Результат: " << str << endl;

    free(str);
}

void process(char* &str, int &len) {
    int write = 0;
    for (int i = 0; i < len; i++)
        if (!(str[i] >= '0' && str[i] <= '9'))
            str[write++] = str[i];
    len = write;
    str[len] = '\0';

    for (int i = 0; i < len; i++) {
        if (str[i] == '+' || str[i] == '-') {
            char* newStr = (char*)malloc(len + 2);
            int pos = 0;

            for (int j = 0; j < i; j++)
                newStr[pos++] = str[j];

            newStr[pos++] = str[i];
            newStr[pos++] = str[i];

            for (int j = i + 1; j < len; j++)
                newStr[pos++] = str[j];

            newStr[pos] = '\0';

            free(str);
            str = newStr;

            len++;
            i++;
        }
    }

    if (len % 2 == 0)
        for (int i = 0; i < len / 2; i++)
            swap(str[i], str[len - i - 1]);
}