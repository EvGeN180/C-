#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

class Directory {
private:
    struct Company {
        string name, owner, phone, address;

        Company(const string& n = "", const string& o = "", const string& p = "", const string& a = "")
            : name(n), owner(o), phone(p), address(a) {}

        string toString() const {
            return name + "|" + owner + "|" + phone + "|" + address;
        }

        static Company fromString(const string& line) {
            stringstream ss(line);
            string n, o, p, a;
            getline(ss, n, '|');
            getline(ss, o, '|');
            getline(ss, p, '|');
            getline(ss, a, '|');
            return Company(n, o, p, a);
        }

        void display() const {
            cout << "Name: " << name
                << "\nOwner: " << owner
                << "\nPhone: " << phone
                << "\nAddress: " << address
                << "\n---\n";
        }
    };

    vector<Company> companies;
    string filename;
    mutex mtx;

public:
    Directory(const string& file = "directory.txt") : filename(file) { load(); }
    ~Directory() { save(); }

    void add(const string& name, const string& owner, const string& phone, const string& address) {
        lock_guard<mutex> lock(mtx);
        companies.emplace_back(name, owner, phone, address);
    }

    void load() {
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            if (!line.empty()) companies.push_back(Company::fromString(line));
        }
    }

    void save() {
        ofstream file(filename);
        for (const auto& c : companies) {
            file << c.toString() << '\n';
        }
    }

    void searchByName(const string& query) {
        lock_guard<mutex> lock(mtx);
        cout << "\nSearching by name: " << query << '\n';
        for (const auto& c : companies) {
            if (c.name.find(query) != string::npos) c.display();
        }
    }

    void searchByOwner(const string& query) {
        lock_guard<mutex> lock(mtx);
        cout << "\nSearching by owner: " << query << '\n';
        for (const auto& c : companies) {
            if (c.owner.find(query) != string::npos) c.display();
        }
    }

    void searchByPhone(const string& query) {
        lock_guard<mutex> lock(mtx);
        cout << "\nSearching by phone: " << query << '\n';
        for (const auto& c : companies) {
            if (c.phone.find(query) != string::npos) c.display();
        }
    }

    void displayAll() {
        lock_guard<mutex> lock(mtx);
        cout << "\n All companies in directory:\n";
        for (const auto& c : companies) {
            c.display();
        }
    }
};

int main() {
    Directory dir;

    dir.add("Google", "Alphabet Inc", "+1-650-253-0000", "Mountain View");
    dir.add("Microsoft", "Microsoft Corp", "+1-425-882-8080", "Redmond");
    dir.add("Apple", "Apple Inc", "+1-408-996-1010", "Cupertino");

    thread t1(&Directory::searchByName, &dir, "Google");
    thread t2(&Directory::searchByOwner, &dir, "Inc");
    thread t3(&Directory::searchByPhone, &dir, "408");

    t1.join();
    t2.join();
    t3.join();
    dir.displayAll();

    return 0;
}
