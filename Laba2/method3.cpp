#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

void process3(char* &str, int &len);

char* readDynamic(int &len) {
    char c;
    len = 0;
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
    return str;
}

void method3() {
    int len;
    cout << "Метод 3: введите строку: ";
    char* str = readDynamic(len);

    FILE* f = fopen("input.txt", "w");
    fputs(str, f);
    fclose(f);

    free(str);

    char buffer[4096];
    FILE* f2 = fopen("input.txt", "r");
    fgets(buffer, 4096, f2);
    fclose(f2);

    int n = strlen(buffer);
    char* str2 = (char*)malloc(n + 1);
    strcpy(str2, buffer);

    process3(str2, n);

    FILE* f3 = fopen("output.txt", "w");
    fputs(str2, f3);
    fclose(f3);

    free(str2);

    cout << "Результат записан в output.txt\n";
}

void process3(char* &str, int &len) {
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