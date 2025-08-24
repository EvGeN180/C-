#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class ICommon {
public:
    virtual void printInfo() const = 0;  
    virtual double getValue() const = 0;
    virtual ~ICommon() = default;
};

class ILogger {
public:
    virtual void log() const = 0;
    virtual ~ILogger() = default;
};

class Item : public ICommon, public ILogger {
private:
    string name;
    double value;
    string extra;

public:
    Item(const string& n, double v, const string& e)
        : name(n), value(v), extra(e)
    {
        if (v < 0) {
            throw invalid_argument("Value cannot be negative!");
        }
    }

    void printInfo() const override {
        cout << "Item: " << name
            << ", Value = " << value
            << ", Extra = " << extra << endl;
    }

    double getValue() const override {
        return value;
    }

    void log() const override {
        cout << "LOG " << name << ": " << value << endl;
    }
};

int main() {
    vector<shared_ptr<ICommon>> items;
    double sum = 0;
    int count = 0;

    try {
        items.push_back(make_shared<Item>("First", 10.5, "text data"));
        items.push_back(make_shared<Item>("Second", 25, "more data"));
        items.push_back(make_shared<Item>("Third", -5, "error data"));
    }
    catch (const invalid_argument& ex) {
        cerr << "Exception: " << ex.what() << endl;
    }

    for (auto& obj : items) {
        auto logger = dynamic_pointer_cast<ILogger>(obj);
        if (logger) {
            obj->printInfo();
            logger->log();
            sum += obj->getValue();
            count++;
        }
    }

    cout << "\nTotal sum = " << sum
        << ", Processed items = " << count << endl;
}
