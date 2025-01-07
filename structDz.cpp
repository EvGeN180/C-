// structDz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//struct Calculator
//{
//    int num1;
//    int num2;
//    Calculator(int num1,int num2) {
//        this->num1 = num1;
//        this->num2 = num2;
//    }
//
//    int add() {
//        return num1+num2;
//    }
//    int subtract() {
//        return num1 - num2;
//    }
//    int multiply() {
//        return num1 * num2;
//    }
//    int divide() {
//        if (num2 == 0) {
//            cout << "Error!" << endl;
//        }
//        return num1 / num2;
//    }
//   
//};
//struct Auto
//{
//    int length = 0, engine_p = 0, wheel_d = 0;
//    string gearbox = "", color = "";
//    float engine = 0.0f, clirenc = 0.0f;
//    Auto(int length, int engine_p, int wheel_d, string gearbox, string color, float engine, float clirenc) {
//        this->length = length;
//        this->engine_p = engine_p;
//        this->wheel_d = wheel_d;
//        this->gearbox = gearbox;
//        this->color = color;
//        this->engine = engine;
//        this->clirenc = clirenc;
//    }
//    Auto(int length, int engine_p, int wheel_d, string gearbox, string color, float engine) {
//        this->length = length;
//        this->engine_p = engine_p;
//        this->wheel_d = wheel_d;
//        this->gearbox = gearbox;
//        this->color = color;
//        this->engine = engine;
//    }
//    Auto(int length, int engine_p, int wheel_d, string gearbox, string color) {
//        this->length = length;
//        this->engine_p = engine_p;
//        this->wheel_d = wheel_d;
//        this->gearbox = gearbox;
//        this->color = color;
//    }
//    Auto(int length, int engine_p, int wheel_d, string gearbox) {
//        this->length = length;
//        this->engine_p = engine_p;
//        this->wheel_d = wheel_d;
//        this->gearbox = gearbox;
//    }
//    Auto(int length, int engine_p, int wheel_d, string gearbox, string color, float engine, float clirenc) {
//        this->length = length;
//        this->engine_p = engine_p;
//        this->wheel_d = wheel_d;
//    }
//    Auto(int length, int engine_p) {
//        this->length = length;
//        this->engine_p = engine_p;
//    }
//    Auto(int length) {
//        this->length = length;
//    }
//    void setLength(int length) {
//        if (length > 0) {
//            this->length = length;
//        }
//        else {
//            cout << "Something went wrong, can't be 0 or lower" << endl;
//        }
//    }
//    void setEngine_p(int length) {
//        if (engine_p > 0) {
//            this->engine_p = engine_p;
//        }
//        else {
//            cout << "Something went wrong, can't be 0 or lower" << endl;
//        }
//
//    }
//    void setWheel_d(int wheel_d) {
//        if (length > 0) {
//            this->wheel_d = wheel_d;
//        }
//        else {
//            cout << "Something went wrong,length can't be 0 or lower" << endl;
//        }
//    }
//    void setGearbox(string gearbox) {
//        this->gearbox = gearbox;
//    }
//    void setColor(string color) {
//        this->color = color;
//    }
//    void setEngine(float engine) {
//        if (engine > 0) {
//            this->engine = engine;
//        }
//        else {
//            cout << "Something went wrong, can't be 0 or lower" << endl;
//        }
//    }
//    void setClirenc(float clirenc) {
//        if (clirenc > 0) {
//            this->clirenc = clirenc;
//        }
//        else {
//            cout << "Something went wrong, can't be 0 or lower" << endl;
//        }
//
//    }
//    int getLength() {
//        return length;
//    }
//    int getEngine_p() {
//        return engine_p;
//    }
//    int getWheel_d() {
//        return wheel_d;
//    }
//    string getGearbox() {
//        return gearbox;
//    }
//    string getColor() {
//        return color;
//    }
//    float getEngine() {
//        return engine;
//    }
//    float getClirenc() {
//        return clirenc;
//    }
//};

struct Auto {
    int length = 0, engine_p = 0, wheel_d = 0;
    string gearbox = "", color = "";
    float engine = 0.0f, clirenc = 0.0f;

    Auto(int length, int engine_p, int wheel_d, string gearbox, string color, float engine, float clirenc) {
        this->length = length;
        this->engine_p = engine_p;
        this->wheel_d = wheel_d;
        this->gearbox = gearbox;
        this->color = color;
        this->engine = engine;
        this->clirenc = clirenc;
    }

    void setLength(int length) {
        if (length > 0) {
            this->length = length;
        }
        else {
            cout << "Something went wrong, can't be 0 or lower" << endl;
        }
    }

    void setEngine_p(int engine_p) {
        if (engine_p > 0) {
            this->engine_p = engine_p;
        }
        else {
            cout << "Something went wrong, can't be 0 or lower" << endl;
        }
    }

    void setWheel_d(int wheel_d) {
        if (wheel_d > 0) {
            this->wheel_d = wheel_d;
        }
        else {
            cout << "Something went wrong, wheel diameter can't be 0 or lower" << endl;
        }
    }

    void setGearbox(string gearbox) {
        this->gearbox = gearbox;
    }

    void setColor(string color) {
        this->color = color;
    }

    void setEngine(float engine) {
        if (engine > 0) {
            this->engine = engine;
        }
        else {
            cout << "Something went wrong, engine can't be 0 or lower" << endl;
        }
    }

    void setClirenc(float clirenc) {
        if (clirenc > 0) {
            this->clirenc = clirenc;
        }
        else {
            cout << "Something went wrong, clearance can't be 0 or lower" << endl;
        }
    }

    int getLength() {
        return length;
    }
    int getEngine_p() {
        return engine_p;
    }
    int getWheel_d() {
        return wheel_d;
    }
    string getGearbox() {
        return gearbox;
    }
    string getColor() {
        return color;
    }
    float getEngine() {
        return engine;
    }
    float getClirenc() {
        return clirenc;
    }
};

int main()
{
    //Calculator obj1(10,5);
    //cout << obj1.add() << endl;
    //cout << obj1.subtract() << endl;
    //cout << obj1.multiply() << endl;
    //cout << obj1.divide() << endl;


    Auto myCar(2500, 500, 21, "Manual", "White", 3.5f, 20.0f);
    cout << "Length: " << myCar.getLength() << " mm" << endl;
    cout << "Engine Power: " << myCar.getEngine_p() << " hp" << endl;
    cout << "Wheel Diameter: " << myCar.getWheel_d() << " inches" << endl;
    cout << "Gearbox: " << myCar.getGearbox() << endl;
    cout << "Color: " << myCar.getColor() << endl;
    cout << "Engine Size: " << myCar.getEngine() << " L" << endl;
    cout << "Clearance: " << myCar.getClirenc() << " cm" << endl;

    myCar.setLength(4600);
    myCar.setEngine_p(250);
    myCar.setGearbox("Automatic");


    cout << "\nUpdated Car Details:" << endl;
    cout << "Length: " << myCar.getLength() << " mm" << endl;
    cout << "Engine Power: " << myCar.getEngine_p() << " hp" << endl;
    cout << "Gearbox: " << myCar.getGearbox() << endl;
}


