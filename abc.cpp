#include <iostream>
#include <cmath>

//class Equation {
//public:
//    virtual ~Equation() {}
//    virtual void solve() const = 0;
//};
//
//class LinearEquation : public Equation {
//private:
//    double a, b;
//
//public:
//    LinearEquation(double a, double b) : a(a), b(b) {}
//
//    void solve() const override {
//        if (a == 0) {
//            if (b == 0) {
//                std::cout << "infinity solutions" << std::endl;
//            }
//            else {
//                std::cout << "no solutions" << std::endl;
//            }
//        }
//        else {
//            double x = -b / a;
//            std::cout << " x = " << x << std::endl;
//        }
//    }
//};
//
//class QuadraticEquation : public Equation {
//private:
//    double a, b, c;
//
//public:
//    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}
//
//    void solve() const override {
//        if (a == 0) {
//            LinearEquation linear(b, c);
//            linear.solve();
//            return;
//        }
//
//        double discriminant = b * b - 4 * a * c;
//
//        if (discriminant > 0) {
//            double x1 = (-b + sqrt(discriminant)) / (2 * a);
//            double x2 = (-b - sqrt(discriminant)) / (2 * a);
//            std::cout << " x1 = " << x1 << ", x2 = " << x2 << std::endl;
//        }
//        else if (discriminant == 0) {
//            double x = -b / (2 * a);
//            std::cout << " x = " << x << std::endl;
//        }
//        else {
//            double realPart = -b / (2 * a);
//            double imagPart = sqrt(-discriminant) / (2 * a);
//            std::cout << " x1 = " << realPart << " + " << imagPart << "i, x2 = "
//                << realPart << " - " << imagPart << "i" << std::endl;
//        }
//    }
//};
//
//int main() {
//    LinearEquation linear(2, 3);
//    std::cout << "linear 2x + 3 = 0:" << std::endl;
//    linear.solve();
//
//    QuadraticEquation quadratic1(1, -5, 6);
//    std::cout << "\nquadratic x^2 - 5x + 6 = 0:" << std::endl;
//    quadratic1.solve();
//
//}
#include <string>
#include <fstream>
#include <iostream>
#include <string>

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

//class Shape {
//public:
//    virtual void Show() const = 0;
//    virtual void Save(const std::string& filename) const = 0;
//    virtual void Load(const std::string& filename) = 0;
//    virtual ~Shape() {}
//};
//
//class Square : public Shape {
//private:
//    int x, y;
//    int side;
//
//public:
//    Square(int x = 0, int y = 0, int side = 0) : x(x), y(y), side(side) {}
//
//    void Show() const override {
//        std::cout << "Square: top-left(" << x << ", " << y << "), side = " << side << std::endl;
//    }
//
//    void Save(const std::string& filename) const override {
//        std::ofstream fout(filename);
//        fout <<"Square"<< x << " " << y << " " << side << std::endl;
//        fout.close();
//    }
//
//    void Load(const std::string& filename) override {
//        std::ifstream fin(filename);
//        fin >> x >> y >> side;
//        fin.close();
//    }
//};
//
//// RECTANGLE
//class Rectangle : public Shape {
//private:
//    int x, y, width, height;
//
//public:
//    Rectangle(int x = 0, int y = 0, int w = 0, int h = 0) : x(x), y(y), width(w), height(h) {}
//
//    void Show() const override {
//        std::cout << "Rectangle: top-left(" << x << ", " << y << "), width = " << width << ", height = " << height << std::endl;
//    }
//
//    void Save(const std::string& filename) const override {
//        std::ofstream fout(filename);
//        fout <<"Rectangle:"<< x << " " << y << " " << width << " " << height << std::endl;
//        fout.close();
//    }
//
//    void Load(const std::string& filename) override {
//        std::ifstream fin(filename);
//        fin >> x >> y >> width >> height;
//        fin.close();
//    }
//};
//
//class Circle : public Shape {
//private:
//    int centerX, centerY;
//    int radius;
//
//public:
//    Circle(int x = 0, int y = 0, int r = 0) : centerX(x), centerY(y), radius(r) {}
//
//    void Show() const override {
//        std::cout << "Circle: center(" << centerX << ", " << centerY << "), radius = " << radius << std::endl;
//    }
//
//    void Save(const std::string& filename) const override {
//        std::ofstream fout(filename);
//        fout <<"Circle:"<< centerX << " " << centerY << " " << radius << std::endl;
//        fout.close();
//    }
//
//    void Load(const std::string& filename) override {
//        std::ifstream fin(filename);
//        fin >> centerX >> centerY >> radius;
//        fin.close();
//    }
//};
//
//class Ellipse : public Shape {
//private:
//    int x, y, width, height;
//
//public:
//    Ellipse(int x = 0, int y = 0, int w = 0, int h = 0) : x(x), y(y), width(w), height(h) {}
//
//    void Show() const override {
//        std::cout << "Ellipse: bounding box top-left(" << x << ", " << y << "), width = " << width << ", height = " << height << std::endl;
//    }
//
//    void Save(const std::string& filename) const override {
//        std::ofstream fout(filename);
//        fout <<"Ellipce:"<< x << " " << y << " " << width << " " << height << std::endl;
//        fout.close();
//    }
//
//    void Load(const std::string& filename) override {
//        std::ifstream fin(filename);
//        fin >> x >> y >> width >> height;
//        fin.close();
//    }
//};

class Shape {
public:
    virtual void Show() const = 0;
    virtual void Save(const std::string& filename) const = 0;
    virtual ~Shape() {}
};

class Square : public Shape {
private:
    int x, y;
    int side;

public:
    Square(int x = 0, int y = 0, int side = 0) : x(x), y(y), side(side) {}

    void Show() const override {
        std::cout << "Square: top-left(" << x << ", " << y << "), side = " << side << std::endl;
    }

    void Save(const std::string& filename) const override {
        std::ofstream fout(filename, std::ios::app); 
        fout << "Square: " << x << " " << y << " " << side << std::endl;
        fout.close();
    }

};

class Rectangle : public Shape {
private:
    int x, y, width, height;

public:
    Rectangle(int x = 0, int y = 0, int w = 0, int h = 0) : x(x), y(y), width(w), height(h) {}

    void Show() const override {
        std::cout << "Rectangle: top-left(" << x << ", " << y << "), width = " << width << ", height = " << height << std::endl;
    }

    void Save(const std::string& filename) const override {
        std::ofstream fout(filename, std::ios::app);
        fout << "Rectangle: " << x << " " << y << " " << width << " " << height << std::endl;
        fout.close();
    }

};

class Circle : public Shape {
private:
    int centerX, centerY;
    int radius;

public:
    Circle(int x = 0, int y = 0, int r = 0) : centerX(x), centerY(y), radius(r) {}

    void Show() const override {
        std::cout << "Circle: center(" << centerX << ", " << centerY << "), radius = " << radius << std::endl;
    }

    void Save(const std::string& filename) const override {
        std::ofstream fout(filename, std::ios::app); 
        fout << "Circle: " << centerX << " " << centerY << " " << radius << std::endl;
        fout.close();
    }
};

class Ellipse : public Shape {
private:
    int x, y, width, height;

public:
    Ellipse(int x = 0, int y = 0, int w = 0, int h = 0) : x(x), y(y), width(w), height(h) {}

    void Show() const override {
        std::cout << "Ellipse: bounding box top-left(" << x << ", " << y << "), width = " << width << ", height = " << height << std::endl;
    }

    void Save(const std::string& filename) const override {
        std::ofstream fout(filename, std::ios::app);
        fout << "Ellipse: " << x << " " << y << " " << width << " " << height << std::endl;
        fout.close();
    }

};
int main() {
    std::ofstream file("C:\\Users\\Malin\\OneDrive\\Робочий стіл\\shapes.txt");


 
    Square s(1, 1, 5);
    Rectangle r(2, 2, 6, 4);
    Circle c(3, 3, 7);
    Ellipse e(4, 4, 10, 5);
    s.Show();
    r.Show();
	c.Show();
	e.Show();
    file.open("C:\\Users\\Malin\\OneDrive\\Робочий стіл\\shapes.txt");
	s.Save("C:\\Users\\Malin\\OneDrive\\Робочий стіл\\shapes.txt");
	r.Save("C:\\Users\\Malin\\OneDrive\\Робочий стіл\\shapes.txt");
	c.Save("C:\\Users\\Malin\\OneDrive\\Робочий стіл\\shapes.txt");
	e.Save("C:\\Users\\Malin\\OneDrive\\Робочий стіл\\shapes.txt");
    file.close();



   
	
}


