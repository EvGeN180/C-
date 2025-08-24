#include <iostream>
#include <map>
#include <string>
using namespace std;

class Logger {
public:
    static void log(const string& message) {
        cerr << "LOG " << message << endl;
    }
};

class BankAccount {
private:
    int id;
    double balance;

public:
    BankAccount(int accId, double initialBalance) : id(accId), balance(initialBalance) {}

    int getId() const { return id; }
    double getBalance() const { return balance; }

    void deposit(double amount) {
        if (amount <= 0) {
            Logger::log("Error: deposit amount must be positive. ID=" + to_string(id));
            return;
        }
        balance += amount;
        Logger::log("Deposit " + to_string(amount) + " to ID=" + to_string(id));
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            Logger::log("Error: withdraw amount must be positive. ID=" + to_string(id));
            return;
        }
        if (amount > balance) {
            Logger::log("Error: not enough funds to withdraw. ID=" + to_string(id));
            return;
        }
        balance -= amount;
        Logger::log("Withdraw " + to_string(amount) + " from ID=" + to_string(id));
    }

    void transferTo(BankAccount* other, double amount) {
        if (!other) {
            Logger::log("Error: target account does not exist. From ID=" + to_string(id));
            return;
        }
        if (amount <= 0) {
            Logger::log("Error: transfer amount must be positive. From ID=" + to_string(id));
            return;
        }
        if (amount > 10000) {
            Logger::log("Error: transfer > 10000 not allowed. From ID=" + to_string(id));
            return;
        }
        if (amount > balance) {
            Logger::log("Error: not enough funds for transfer. From ID=" + to_string(id));
            return;
        }
        balance -= amount;
        other->balance += amount;
        Logger::log("Transfer " + to_string(amount) + " from ID=" + to_string(id) +
            " to ID=" + to_string(other->id));
    }
};

class BankSystem {
private:
    map<int, BankAccount*> accounts;

public:
    void addAccount(BankAccount* acc) {
        accounts[acc->getId()] = acc;
    }

    BankAccount* getAccount(int id) {
        if (accounts.find(id) == accounts.end()) {
            Logger::log("Error: account ID " + to_string(id) + " not found!");
            return nullptr;
        }
        return accounts[id];
    }
};
int main() {
    BankSystem bank;

    BankAccount acc1(1, 5000);
    BankAccount acc2(2, 20000);
    bank.addAccount(&acc1);
    bank.addAccount(&acc2);

    acc1.deposit(1000);
    acc1.deposit(-50);
    acc1.withdraw(6000);
    acc1.withdraw(0);

    acc2.transferTo(bank.getAccount(1), 5000);
    acc2.transferTo(bank.getAccount(1), 20000);
    acc2.transferTo(bank.getAccount(1), 15000);
    acc2.transferTo(bank.getAccount(99), 100);

    cout << "\nFinal balances:\n";
    cout << "Acc1: " << acc1.getBalance() << endl;
    cout << "Acc2: " << acc2.getBalance() << endl;

}
