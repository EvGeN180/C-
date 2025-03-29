#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int strToInt(string line) {
    try {
        if (line.empty()) {
            throw 1;
        }

        int result = 0;
        bool isNegative = (line[0] == '-');
        size_t start = (isNegative || line[0] == '+') ? 1 : 0;

        for (size_t i = start; i < line.length(); ++i) {
            if (line[i] < '0' || line[i] > '9') {
                throw 2;
            }
            result = result * 10 + (line[i] - '0');
        }

        return isNegative ? -result : result;
    }
    catch (...) {
        cout << "something went wrong..." << endl;
    }
}

int main() {
    cout << strToInt("") << endl;  
    cout << strToInt("123") << endl; 
    cout << strToInt("ab") << endl;
    
}







//#include <iostream>
//#include <string>
//#include <stdexcept>
//
//int stringToInt(const std::string& str) {
//    if (str.empty()) {
//        throw std::runtime_error("Помилка: порожній рядок.");
//    }
//
//    int number = 0;
//    bool isNegative = false;
//    size_t i = 0;
//
//
//    if (str[0] == '-') {
//        isNegative = true;
//        i = 1;
//    }
//    else if (str[0] == '+') {
//        i = 1;
//    }
//
//    for (; i < str.length(); i++) {
//        if (str[i] < '0' || str[i] > '9') {
//            throw std::runtime_error("Помилка: рядок містить недопустимі символи.");
//        }
//
//        int digit = str[i] - '0';
//
//        // Перевірка на переповнення
//        if (number > (INT_MAX - digit) / 10) {
//            throw std::runtime_error("Помилка: число виходить за межі допустимого діапазону.");
//        }
//
//        number = number * 10 + digit;
//    }
//
//    return isNegative ? -number : number;
//}
//
//int main() {
//    std::string input;
//    std::cout << "Введіть число: ";
//    std::cin >> input;
//
//    try {
//        int result = stringToInt(input);
//        std::cout << "Число: " << result << std::endl;
//    }
//    catch (const std::exception& e) {
//        std::cerr << e.what() << std::endl;
//    }
//
//    return 0;
//}
//
