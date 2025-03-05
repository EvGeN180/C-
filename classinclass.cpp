#include <iostream>
using namespace std;
class Customer {
public:
    class Order {
    private:
        int numberId;
        double price;
    public:
        Order(int id = 0, double p = 0.0) : numberId(id), price(p) {}

        int getNumberId() const {
            return numberId; 
        }
        double getPrice() const {
            return price;
        }

        void setNumberId(int id) { 
            numberId = id;
        }
        void setPrice(double p) {
            price = p;
        }

        void show() const {
            if (numberId != 0)
                cout << "ID: " << numberId << ", Sum: " << price << "\n";
        }
    };

private:
    string name;
    Order orders[2];

public:
    Customer(const string& n) : name(n) {}

    void addOrder(int id, double price, int index) {
        if (index >= 0 && index < 2) {
            orders[index].setNumberId(id);
            orders[index].setPrice(price);
        }
    }


    void showOrders() const {
        cout << "Name: " << name << ":\n";
        for (int i = 0; i < 2; ++i) {
            orders[i].show();
        }
    }

    double getSum() const {
        return orders[0].getPrice() + orders[1].getPrice();
    }
};

int main() {

    Customer customer("pcdcd");
    customer.addOrder(1, 500.50, 0);
    customer.addOrder(2, 250.75, 1);

    customer.showOrders();
    cout << "Sum: " << customer.getSum() << "\n";
}
