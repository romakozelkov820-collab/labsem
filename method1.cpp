#include "method1.h"
#include <cstring>
#include <iostream>

std::string processMethod1(const std::string& input) {
    char str[1000];
    strncpy(str, input.c_str(), sizeof(str) - 1);
    str[sizeof(str) - 1] = '\0';
    
    int length = 0;
    
    // Удаляем цифры и удваиваем '+' и '-'
    int writeIndex = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            continue;
        }
        
        str[writeIndex++] = str[i];
        
        if (str[i] == '+' || str[i] == '-') {
            str[writeIndex++] = str[i];
        }
    }
    str[writeIndex] = '\0';
    
    length = writeIndex;
    
    if (length % 2 == 0) {
        for (int i = 0; i < length / 2; i++) {
            char temp = str[i];
            str[i] = str[length - 1 - i];
            str[length - 1 - i] = temp;
        }
    }
    
    return std::string(str);
}
