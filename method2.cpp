#include "method2.h"
#include <cstring>

std::string processMethod2(const std::string& input) {
    char str[1000];
    strncpy(str, input.c_str(), sizeof(str) - 1);
    str[sizeof(str) - 1] = '\0';
    
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
    
    return std::string(str);
}
