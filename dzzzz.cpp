#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;
template <typename T>
T average(T arr[], int size) {
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

template <typename T>
T maxi(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>
T mini(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
    int arr[] = { 1, 2, 3, 4 };
    int size = 4;
    cout << "Average: " << average(arr, size) << endl;

    cout << "MAX: " << maxi(10, 2) << endl;
    cout << "MAX:"<<maxi(2.33, 3.22) << endl;

    cout << "MIN: " << mini(10, 20) << endl;
    cout << "MIN: " << mini(34.1, 288.71) << endl;

}
