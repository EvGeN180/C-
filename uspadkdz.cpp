#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Square {
private:
    double side;
public:
    Square(double s) : side(s) {}

    double getArea() const {
        return side * side;
    }

    double getSide() const {  
        return side;
    }

    void showInfo() const {
        cout << "Square: Side = " << side << ", Area = " << getArea() << endl;
    }
};

class Circle : public Square {
public:
    Circle(double s) : Square(s) {}

    double getArea() const {
        double radius = getSide() / 2;  
        return 3.14 * radius * radius;
    }

    void showInfo() const {
        cout << "Circle in square, Radius = " << (getSide() / 2)
            << ", Area = " << getArea() << endl;
    }
};





class Pet {
private:
    string name;
    int age;
public:
    Pet(string n, int a) : name(n), age(a) {}

    void showInfo() const {
        cout << "Name: " << name << ", Age: " << age  << endl;
    }

    ~Pet() {}  
};

class Dog : Pet {
private:
    string breed;
public:
    Dog(string n, int a, string b) : Pet(n, a), breed(b) {}

    void display(){
        cout << "Dog: ";
        Pet::showInfo();
        cout << "Breed: " << breed << endl;
    }
};

class Cat : Pet {
private:
    string color;
public:
    Cat(string n, int a, string c) : Pet(n, a), color(c) {}

    void display() {
        cout << "Cat: ";
        Pet::showInfo();
        cout << "Color of fair:: " << color << endl;
    }
};

class Parrot : Pet {
private:
    string colorF;
public:
    Parrot(string n, int a, string colorF) : Pet(n, a), colorF(colorF) {}

    void display() {
        cout << "Parrot: ";
        Pet::showInfo();
        cout << "Color of feather: " <<colorF << endl;
    }
};

int main() {
   
    Square square(12);
    Circle circle(10);
    square.showInfo();
    circle.showInfo();


    Dog dog("Dog", 5, "Pitbull");
    Cat cat("Cat", 3, "White");
    Parrot parrot("Parrot", 2, "colorful");
    dog.display();
    cat.display();
    parrot.display();

}
