#include <iostream>
#include <stdexcept>
using namespace std;
class Date {
private:
    int day, month, year;
    static const int max_days = 31;
    static const int max_months = 12;
public:
    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {
        if (month > max_months || day > max_days) return;
    }
    void Day() {
        day++;
        if (day > max_days) { day = 1; month++; }
        if (month > max_months) { month = 1; year++; }
    }

    Date& operator++() {
        Day(); 
        return *this; 
    } 
    Date operator++(int){ 
        Date temp = *this; Day(); return temp;
    } 
    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }
    bool operator>(const Date& other) const{
        return year > other.year || (year == other.year && (month > other.month || (month == other.month && day > other.day)));
    }
    bool operator<(const Date& other) const {
        return !(*this > other) && !(*this == other); 
    }
    Date& operator+=(int days) { 
        while (days--) Day(); return *this; 
    }
    Date& operator-=(int days) { 
        while (days--) day--; return *this;
    }
    friend ostream& operator<<(ostream& os, const Date& d) {
        os << d.day << "/" << d.month << "/" << d.year; return os;
    }
    friend istream& operator>>(istream& is, Date& d)  {
        is >> d.day >> d.month >> d.year; return is;
    }
};

class Fraction {
private:
    int numerator, denominator;
public:
    Fraction(int n = 0, int d = 1) { if (d == 0); numerator = n; denominator = d; }
    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }
    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator); 
    }
    Fraction operator*(const Fraction& other) const { 
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }
    Fraction operator/(const Fraction& other) const { 
        
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }
    friend ostream& operator<<(ostream& os, const Fraction& f) { 
        os << f.numerator << "/" << f.denominator; return os;
    }
    friend istream& operator>>(istream& is, Fraction& f) {
        is >> f.numerator >> f.denominator; return is;
    }
};
class Flat {
private:
    double area, price;
public:
    Flat(double a = 0, double p = 0) : area(a), price(p) {}
    bool operator==(const Flat& other) const { 
        return area == other.area;
    }
    bool operator>(const Flat& other) const { 
        return price > other.price;
    }
    Flat& operator=(const Flat& other) {
        if (this != &other) { area = other.area; price = other.price; 
        return *this; 
		}
	}
    friend ostream& operator<<(ostream& os, const Flat& f) { 
        os << "Flat: Area = " << f.area << " sq.m, Price = " << f.price << " USD"; return os; 
    }
};

int main() {
    Date d1(20, 01, 2025);
    cout << "Original Date: " << d1 << endl;
    ++d1;
    cout << "After increment: " << d1 << endl;

    Fraction f1(1, 2), f2(1, 3);
    cout << "Sum of fractions: " << (f1 + f2) << endl;

    Flat flat1(23, 70000), flat2(72, 120000);
    cout << (flat1 > flat2 ? "Flat1 is more expensive" : "Flat2 is more expensive") << endl;

}
