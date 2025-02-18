#include <iostream>
using namespace std;

class Array {
private:
    int* arr;
    size_t size;
    size_t capacity;

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (size_t i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
public:
    Array() {
        this->arr = new int[1];
        this->size = 0;
        this->capacity = 1;
    }

    ~Array() {
        delete[] this->arr; 
    }

    void add(int value) {
        if (this->size == this->capacity) resize();
        this->arr[this->size++] = value;
    }

    void remove(int value) {
        for (size_t i = 0; i < this->size; i++) {
            if (this->arr[i] == value) {
                for (size_t j = i; j < this->size - 1; j++) this->arr[j] = this->arr[j + 1];
                this->size--;
            }
        }
    }

    void print() const {
        cout << "[ ";
        for (size_t i = 0; i < this->size; i++) cout << this->arr[i] << " ";
        cout << "]" << endl;
    }
};

int main() {
    Array arr1, arr2;
    arr1.add(1);
    arr1.add(2);
    arr1.add(3);
    arr2.add(4);
    arr2.add(5);
    arr1.print();
    arr2.print();
    Array arr3;
    arr3.print();
    arr1.remove(2);
    arr1.print();
}
