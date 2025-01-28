#include <iostream>
#include <string>
using namespace std;

//class Employee {
//private:
//    string name;
//    string position;
//    double salary;
//    static int count; 
//    int year;  
//
//public:
//    Employee(string name, string position, double salary, int year) {
//        this->name = name;
//        this->position = position;
//        this->salary = salary;
//        this->year = year;
//        count++;
//    }
//
//
//    void showInfo() const {
//        cout << "Name: " << name << "\nPosition: " << position
//            << "\nSalary: " << salary << "\nYear: " << year << endl;
//    }
//
//    void changeSalary(double newSalary) {
//        salary = newSalary;
//    }
//
//    static int getCount() {
//        return count;
//    }
//
//    string getName() const {
//        return name;
//    }
//    void setName(string name) {
//        this->name = name; 
//    }
//
//    string getPosition() const {
//        return position;
//    }
//    void setPosition(string position) {
//        this->position = position; 
//    }
//
//    double getSalary() const {
//        return salary; 
//    }
//    void setSalary(double salary) {
//        this->salary = salary; 
//    }
//
//    int getYear() const {
//        return year; 
//    }
//    void setYear(int year) {
//        this->year = year;
//    }
//    void addPercentSalary(double percent) {
//        salary += salary * percent / 100;
//    }
//
//    int years() const {
//        return 2025 - year; 
//    }
//};
//
//int Employee::count = 0;
//
//int main() {
//    Employee obj1("lALA", "work", 5000, 2021);
//    obj1.showInfo();
//    cout << Employee::getCount() << endl;
//
//    obj1.addPercentSalary(15); 
//    obj1.showInfo();
//	obj1.changeSalary(10000);
//	obj1.setName("LALAala");
//	obj1.setPosition("work");
//	obj1.setYear(2011);
//    obj1.showInfo();
//
//    cout << obj1.years() << " years" << endl;
//
//
//}
#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand; 
    string model;  
    int year;    
    double mileage; 
    static int count;

public:
    Car(string brand, string model, int year, double mileage) {
        this->brand = brand;
        this->model = model;
        this->year = year;
        this->mileage = mileage;
        count++; 
    }

     void showInfo() const {
        cout << "Brand: " << brand << "\nModel: " << model<< "\nYear: " << year << "\nMileage: " << mileage << " km\n";
    }


    void addMileage(double addMileage) {
        mileage += addMileage;
    }


    static int getCount() {
        return count;
    }

   
    string getBrand() const {
        return brand; 
    }
    void setBrand(string brand) {
        this->brand = brand; 
    }

    string getModel() const {
        return model;
    }
    void setModel(string model) {
        this->model = model; 
    }

    int getYear() const {
        return year; 
    }
    void setYear(int year) {
        this->year = year; 
    }

    double getMileage() const { 
        return mileage; 
    }
    void setMileage(double mileage) {
        this->mileage = mileage;
    }
};

int Car::count = 5;

int main() {
    Car car1("Audi", "A7", 2018, 22000);
    car1.showInfo();
    cout <<  Car::getCount() << endl;
    car1.addMileage(5000);
    car1.showInfo();
    car1.setBrand("audi");
    car1.setModel("a4");
    car1.setYear(2022);
    car1.setMileage(30000);
    car1.showInfo();


}

