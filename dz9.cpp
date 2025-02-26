#include <iostream>
using namespace std;
class Array {
private:
    int* arr;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

public:
    Array(int cap = 10) : size(0), capacity(cap) {
        arr = new int[capacity];
    }

    ~Array() {
        delete[] arr;
    }

    void add(int value) {
        if (size == capacity) resize();
        arr[size++] = value;
    }

    void removeLast() {
        if (size > 0) size--;
    }

    void insert(int index, int value) {
        if (index < 0 || index > size) return;
        if (size == capacity) resize();
        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        size++;
    }

    void removeAt(int index) {
        if (index < 0 || index >= size) return;
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    double average() {
        if (size == 0) return 0;
        double sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return sum / size;
    }

    int indexOf(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) return i;
        }
        return -1;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << std::endl;
    }

    void clear() {
        delete[] arr;
        size = 0;
        capacity = 10;
        arr = new int[capacity];
    }
};

int main() {
    Array arr;
    arr.add(5);
    arr.add(10);
    arr.add(15);
    arr.print();

    arr.insert(1, 7);
    arr.print();
    arr.print();
    arr.removeAt(2);
    arr.print();

    cout << "Average: " << arr.average() << std::endl;
    cout << "Index of 10: " << arr.indexOf(10) << std::endl;

    arr.clear();
    arr.print();
	arr.indexOf(10);

    return 0;
}
