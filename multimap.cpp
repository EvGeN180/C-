#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Book {
    string title;
    int year;

    bool operator<(const Book& other) const {
        if (year == other.year)
            return title < other.title;
        return year < other.year;
    }
};

struct Student {
    string name;
    int group;

    bool operator<(const Student& other) const {
        return group < other.group;
    }
};

int main() {
    set<Book> books = {
        {"a", 2000},
        {"b", 1995},
      
    };

    cout << "Books:\n";
    for (auto b : books) {
        cout << b.title << " (" << b.year << ")\n";
    }

    map<Student, double> students;
    students[{ "s1", 1 }] = 90.5;
    students[{ "s2", 2 }] = 85.3;


    cout << "Students:\n";
    for (auto s : students) {
        cout << s.first.name << " (group " << s.first.group << ") - " << s.second << "\n";
    }

    multimap<string, int> grades;
    grades.insert({ "s1", 80 });
    grades.insert({ "s2", 90 });

    string name = "s1";
    cout << "Marks " << name << ": ";
    auto range = grades.equal_range(name);
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->second << " ";
    }

    pair<string, pair<int, double>> p = { "s3", {15, 88.5} };
    cout << "name: " << p.first << ", age: " << p.second.first << ", mark: " << p.second.second << "\n";

}
