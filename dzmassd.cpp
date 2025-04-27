// dzmassd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
using namespace std;



void changeArray() {
    int size = 0;
    int* arr = new int[1];
    int num;

    cout << "Enter numbers (0 to stop): ";
    while (cin >> num && num != 0) {
        arr[size] = num;
        size++;
        int* temp = new int[size + 1];
        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }

    int* change = new int[size];
    for (int i = 0; i < size; i++) {
        change[i] = arr[size - 1 - i];
    }

    cout << "Original array: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "Changed array: ";
    for (int i = 0; i < size; i++) cout << change[i] << " ";
    cout << endl;

    delete[] arr;
    delete[] change;
}

void evenArray() {
    int size = 0;
    int* arr = new int[1];
    int num;

    cout << "Enter numbers (0 to stop): ";
    while (cin >> num && num != 0) {
        arr[size] = num;
        size++;
        int* temp = new int[size + 1];
        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }

    int evenCount = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) evenCount++;
    }

    int* even = new int[evenCount];
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            even[index++] = arr[i];
        }
    }

    cout << "Even elements: ";
    for (int i = 0; i < evenCount; i++) cout << even[i] << " ";
    cout << endl;

    delete[] arr;
    delete[] even;
}

void insertElement() {
    int size = 0;
    int* arr = new int[1];
    int num;

    cout << "Enter numbers (0 to stop): ";
    while (cin >> num && num != 0) {
        arr[size] = num;
        size++;
        int* temp = new int[size + 1];
        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }

    int number, index;
    cout << "Enter the number to insert: ";
    cin >> number;
    cout << "Enter the position (starting from 0): ";
    cin >> index;

    if (index < 0 || index > size) {
        cout << "Invalid index" << endl;
        delete[] arr;
        return;
    }

    int* newArr = new int[size + 1];
    for (int i = 0, j = 0; i < size + 1; i++) {
        if (i == index) {
            newArr[i] = number;
        }
        else {
            newArr[i] = arr[j++];
        }
    }

    cout << "New array: ";
    for (int i = 0; i < size + 1; i++) cout << newArr[i] << " ";
    cout << endl;

    delete[] arr;
    delete[] newArr;
}

class Item {
public:
    virtual void showInfo() = 0;
    virtual void giveItem() = 0;
    virtual ~Item() {}
};

class Book : public Item {
private:
    string title;
    string author;
    int year;
public:
    Book(string t, string a, int y) : title(t), author(a), year(y) {}

    void showInfo() override {
        cout << "Book: " << title << " Author: " << author << " Year: " << year << endl;
    }

    void giveItem() override {
        cout << "Giving book: " << title << endl;
    }
};

class Magazine : public Item {
private:
    string title;
    int number;
    string month;
public:
    Magazine(string t, int n, string m) : title(t), number(n), month(m) {}

    void showInfo() override {
        cout << "Magazine: " << title << " Number" << number << " Month: " << month << endl;
    }

    void giveItem() override {
        cout << "Giving magazine: " << title << endl;
    }
};
int main() {
	/*changeArray();
	evenArray();*/
	insertElement();
    Item* library[4];

    library[0] = new Book("ewdedw", "dewdwwdwe", 2000);
    library[1] = new Magazine("Newdc", 2, "edwddew");
    library[2] = new Book("Tqedwedw", "erferf", 1979);
    library[3] = new Magazine("f2ef3fe3", 5, "efrefef");

    for (int i = 0; i < 4; i++) {
        library[i]->showInfo();
        library[i]->giveItem();
        cout << endl;
    }

    for (int i = 0; i < 4; i++) {
        delete library[i];
    }
}
