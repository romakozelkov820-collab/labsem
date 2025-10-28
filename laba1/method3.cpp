#include "method3.h"
#include <iostream>
#include <fstream>
#include <cstring>

void processMethod3() {
    const char* inputFile = "input.txt";
    const char* outputFile = "output.txt";
    
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);
    
    if (!inFile.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл " << inputFile << std::endl;
        return;
    }
    
    if (!outFile.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл " << outputFile << std::endl;
        inFile.close();
        return;
    }
    
    char str[1000];
    inFile.getline(str, sizeof(str));
    
    char* readPtr = str;
    char* writePtr = str;
    
    while (*readPtr != '\0') {
        if (*readPtr >= '0' && *readPtr <= '9') {
            readPtr++;
            continue;
        }
        
        *writePtr = *readPtr;
        writePtr++;
        
        if (*readPtr == '+' || *readPtr == '-') {
            *writePtr = *readPtr;
            writePtr++;
        }
        
        readPtr++;
    }
    *writePtr = '\0';
    
    int length = writePtr - str;
    
    if (length % 2 == 0) {
        char* start = str;
        char* end = str + length - 1;
        
        while (start < end) {
            char temp = *start;
            *start = *end;
            *end = temp;
            start++;
            end--;
        }
    }
    
    outFile << str;
    
    inFile.close();
    outFile.close();
    
    std::cout << "Обработка завершена. Результат в " << outputFile << std::endl;
}
