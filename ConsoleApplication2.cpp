#include <iostream>
#include <string>
#include <sqlite3.h>
#include <cstdlib>
#include <ctime>
using namespace std;

class Car {
private:
    string model;
    int year;
    double price;
    string factory;
    double discount;

public:
    Car(string m, int y, double p, string f, double d)
        : model(m), year(y), price(p), factory(f), discount(d) {
    }

    string getModel() const { return model; }
    int getYear() const { return year; }
    double getPrice() const { return price; }
    string getFactory() const { return factory; }
    double getDiscount() const { return discount; }

    void setModel(string m) { model = m; }
    void setYear(int y) { year = y; }
    void setPrice(double p) { price = p; }
    void setFactory(string f) { factory = f; }
    void setDiscount(double d) { discount = d; }

    double finalPrice() const {
        return price - (price * discount / 100.0);
    }
};

static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << " ";
    }
    cout << endl;
    return 0;
}

int main() {
    sqlite3* DB;
    char* messageError;
    int exit = sqlite3_open("DataBaseCar.db", &DB);
    string sql = "CREATE TABLE IF NOT EXISTS Car_objects("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
        "Model TEXT, "
        "Year INT, "
        "Price REAL, "
        "Factory TEXT, "
        "Discount REAL);";

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK) {
        cerr << "Error Create Table: " << messageError << endl;
        sqlite3_free(messageError);
    }
    else {
        cout << "Table created successfully!" << endl;
    }

    Car car1("BMW X5", 2020, 50000, "BMW", 10);
    Car car2("Audi A6", 2019, 40000, "Audi", 15);
    Car car3("Tesla Model 3", 2021, 55000, "Tesla", 5);

    string insert1 = "INSERT INTO Car_objects (Model, Year, Price, Factory, Discount) VALUES('" +
        car1.getModel() + "', " + to_string(car1.getYear()) + ", " +
        to_string(car1.getPrice()) + ", '" + car1.getFactory() + "', " +
        to_string(car1.getDiscount()) + ");";

    string insert2 = "INSERT INTO Car_objects (Model, Year, Price, Factory, Discount) VALUES('" +
        car2.getModel() + "', " + to_string(car2.getYear()) + ", " +
        to_string(car2.getPrice()) + ", '" + car2.getFactory() + "', " +
        to_string(car2.getDiscount()) + ");";

    string insert3 = "INSERT INTO Car_objects (Model, Year, Price, Factory, Discount) VALUES('" +
        car3.getModel() + "', " + to_string(car3.getYear()) + ", " +
        to_string(car3.getPrice()) + ", '" + car3.getFactory() + "', " +
        to_string(car3.getDiscount()) + ");";

    sqlite3_exec(DB, insert1.c_str(), NULL, 0, &messageError);
    sqlite3_exec(DB, insert2.c_str(), NULL, 0, &messageError);
    sqlite3_exec(DB, insert3.c_str(), NULL, 0, &messageError);

    cout << "Cars inserted into database!" << endl;
    srand(time(0));
    for (int i = 1; i <= 3; i++) {
        double newPrice = rand() % 20000 + 30000; // від 30000 до 50000
        string update = "UPDATE Car_objects SET Price = " + to_string(newPrice) +
            " WHERE ID = " + to_string(i) + ";";
        sqlite3_exec(DB, update.c_str(), NULL, 0, &messageError);
    }
    cout << "Prices updated!" << endl;

    string select = "SELECT * FROM Car_objects;";
    sqlite3_exec(DB, select.c_str(), callback, NULL, &messageError);

    sqlite3_close(DB);
}
