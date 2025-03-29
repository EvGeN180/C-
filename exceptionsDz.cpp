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
