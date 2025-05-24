#define CHANGE(a, b) { int t = a; a = b; b = t; }
#define IN_RANGE(x, a, b) (x >= a && x <= b)

#define FIND_MIN_MAX(arr, n, min, max) do {    \
    min = arr[0];                              \
    max = arr[0];                              \
    for (int i = 1; i < n; i++) {              \
        if (arr[i] < min) min = arr[i];        \
        if (arr[i] > max) max = arr[i];        \
    }                                          \
} while(0)
#include <iostream>
using namespace std;
int main() {
    int num1 = 2, num2 = 5;
    cout << num1 << " "<< num2 << endl;
    CHANGE(num1, num2);
    cout << num1 << " "<< num2<< endl;

    int num = 1;
    if (IN_RANGE(num,5, 3)) {
        cout << num << " is in range" << endl;
    }
    else {
        cout << num << " is not in range" << endl;
    }

    int arr[] = { 3, 7, 2, 9 };
    int minNum, maxNum;
    FIND_MIN_MAX(arr, 4, minNum, maxNum);
    cout << "Min: " << minNum << endl;
    cout << "Max: " << maxNum << endl;

}