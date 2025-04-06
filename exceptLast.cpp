#include <iostream>
#include <cmath>
#include <string>
#include "excpt.h"

using namespace std;

template <typename T>
class Math {
private:
    T num1, num2;
public:
    Math() {}
    Math(T num1, T num2) {
        this->num1 = num1;
        this->num2 = num2;
    }

    void setNum1(T num1) {
        this->num1 = num1;
    }

    void setNum2(T num2) {
        this->num2 = num2;
    }

    T getNum1() const {
        return num1;
    }

    T getNum2() const {
        return num2;
    }

    T plusNums() {
        return num1 + num2;
    }

    T minusNums() {
        return num1 - num2;
    }

    T multiplyNums() {
        return num1 * num2;
    }

    T divideNums() {
        if (num2 == 0) {
            throw InvalidNumberException("Zero Division ERROR.");
        }
        return num1 / num2;
    }

    void showInfo() const {
        cout << "First number: " << num1 << "Second number  : " << num2 << endl;
    }
};

class Line {
private:
    string line;
public:
    Line() {}
    Line(string line) {
        this->line = line;
    }

    void setLine(string line) {
        this->line = line;
    }

    string getString() const {
        return line;
    }

    string ifEmpty() {
        if (line.empty()) {
            throw MyStringException("Nothing in line");
        }
        return line;
    }

    string ifNumber() {
        for (char smth : line) {
            if (isdigit(smth)) {
                throw MyStringException("Number in line!!");
            }
        }
        return line;
    }

    string ifSpacesFirst() {
        if (!line.empty() && line[0] == ' ') {
            throw MyStringException("Space is thge first in line,ERROR");
        }
        return line;
    }

    string ifSpacesLast() {
        if (!line.empty() && line.back() == ' ') {
            throw MyStringException("Last character is a space.");
        }
        return line;
    }

    string ifSpaces() {
        for (char smth : line) {
            if (smth == ' ') {
                throw MyStringException("There are dpaces there!ERROR");
            }
        }
        return line;
    }

    void showLine() const {
        cout << "Line: " << line << endl;
    }
};


int main() {
    cout << "Math" << endl;
    try {
        Math<double> math(1, 12);
        math.showInfo();
        cout << "Sum: " << math.plusNums() << endl;
        cout << "Subtract: " << math.minusNums() << endl;
        cout << "Multiply: " << math.multiplyNums() << endl;
        cout << "Divide: " << math.divideNums() << endl;
    }
    catch (const InvalidNumberException& msg) {
        cout << "Math Exception: " << msg.what() << endl;
    }

    cout << "Line" << endl;
    try {
        Line line(" eevfev ");
        line.showLine();
        line.ifEmpty();
        line.ifNumber();
        line.ifSpacesFirst();
        line.ifSpacesLast();
    }
    catch (const MyStringException& e) {
        cout << "String Exception: " << e.what() << endl;
    }
}
