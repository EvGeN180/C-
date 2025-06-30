#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Car {
public:
    string model;
    int year;

    Car(string m, int y) {
        model = m;
        year = y;
    }

    void info() {
        cout << "model: " << model << ", year: " << year << "\n";
    }
};

class Student {
public:
    string name;

    Student(string n) {
        name = n;
    }

    void greet() {
        cout << "Hello,i am " << name << "!\n";
    }
};

int main() {

    vector<Car> cars = {
        Car("Audi", 2015),
        Car("Tesla", 2020),
    };

    for (auto& c : cars) c.info();

    sort(cars.begin(), cars.end(), [](Car& a, Car& b) {
        return a.year < b.year;
        });

    for (auto& c : cars) c.info();

    cout << "\n";

    vector<shared_ptr<Student>> list;

    shared_ptr<Student> s1 = make_shared<Student>("s1");
    shared_ptr<Student> s2 = make_shared<Student>("s2");

    list.push_back(s1);
    list.push_back(s2);
    list.push_back(s1); 

    for (auto s : list) {
        s->greet();
        cout << "use_count: " << s.use_count() << "\n";
    }

    s1 = nullptr; 

    for (auto s : list) {
        cout << s->name << " - use_count: " << s.use_count() << "\n";
    }

}
