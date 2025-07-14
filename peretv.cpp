#include <iostream>
#include <cmath>      
using namespace std;

class Transport {
public:
    virtual void info() const { cout << "Transport "; }
    virtual ~Transport() = default;
};

class Bicycle : public Transport {
public:
    void info() const override { cout << "Bicycle "; }
};

class Car : public Transport {
public:
    void info() const override { cout << "Car "; }
};

class Moto : public Transport {
public:
    void info() const override { cout << "Moto"; }
};

void addUserNumber(int* ptr)          
{
    int add{};
    cout << "Enter num: ";
    cin >> add;
    *ptr += add;                 
}

int main()
{
    cout << "Enter float num: ";
    double d{};
    cin >> d;
    int i = static_cast<int>(round(d));

    cout << "float: " << d << endl;
    cout << "int   : " << i << endl;

    Transport* base = new Car;       
    base->info();

    if (auto car = dynamic_cast<Car*>(base)) {
        car->info();
    }
    delete base;

    const int kConst10 = 10;
    int value = kConst10;
    addUserNumber(&value);
    cout << value ;

}
