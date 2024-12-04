// funcdz1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int factorialFunc(int num) {
    int result = 1;
    for (int i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}
bool isPrimeFunc(int num1) {
    if (num1 <= 1) {
        return false;
    }
    for (int j = 2; j < num1; j++) {
        if (num1 % j == 0) {
            return false;
        }
    }
    return true;
}
int maxFunc(int number1, int number2, int number3) {
    int maxnum = number1;
    if (maxnum < number2) {
        maxnum = number2;
    }
    if (maxnum < number3) {
        maxnum = number3;
    }
    return maxnum;
}
int main()
{
    cout << "Enter num" << endl;
    int num;
    cin >>num;
    cout << factorialFunc(num) << endl;

    cout << "Enter num prime or no" << endl;
    cin >> num;
    cout  <<"0- noprime, 1 - prime, your result ---" << isPrimeFunc(num) << endl;

    int num1, num2, num3;
    cout << "Enter 3 nums" << endl;
    cin >> num1 >> num2 >> num3;
    cout << "Max num is " << maxFunc(num1, num2, num3) << endl;


}

