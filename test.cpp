#include <iostream>
#include <cassert>
#include "method1.h"
#include "method2.h"
#include "method3.h"

void runTests() {
    std::cout << "=== Запуск Unit-тестов ===" << std::endl;
    
    // Тест 1: Проверка метода 1
    std::string test1 = "abc123+-";
    std::string result1 = processMethod1(test1);
    std::cout << "Тест 1 - Метод 1: " << test1 << " -> " << result1 << std::endl;
    
    // Тест 2: Проверка метода 2
    std::string test2 = "abc123+-";
    std::string result2 = processMethod2(test2);
    std::cout << "Тест 2 - Метод 2: " << test2 << " -> " << result2 << std::endl;
    
    // Тест 3: Сравнение методов 1 и 2
    std::string test3 = "test123+-abc";
    std::string result3_1 = processMethod1(test3);
    std::string result3_2 = processMethod2(test3);
    assert(result3_1 == result3_2);
    std::cout << "Тест 3 пройден: Оба метода дают одинаковый результат" << std::endl;
    
    // Тест 4: Метод 3 (работа с файлами)
    std::cout << "Тест 4 - Запуск метода 3..." << std::endl;
    processMethod3();
    std::cout << "Тест 4 завершен: Проверьте файл output.txt" << std::endl;
    
    // Тест 5: Строка без цифр
    std::string test5 = "hello+-world";
    std::string result5 = processMethod1(test5);
    std::cout << "Тест 5: " << test5 << " -> " << result5 << std::endl;
    
    // Тест 6: Строка только с цифрами
    std::string test6 = "123456";
    std::string result6 = processMethod1(test6);
    std::cout << "Тест 6: " << test6 << " -> " << result6 << std::endl;
    
    std::cout << "=== Все тесты завершены ===" << std::endl;
}

int main() {
    runTests();
    return 0;
}
