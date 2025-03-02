#include <iostream>
#include <queue>
#include <stack>
#include <list>
using namespace std;

class Student {
private:
    string last_name;
    int id;

public:
    Student(const string lastname, int i) : id(i) { }
    
    void setId(int id){
        id = id;
    }
    int getId() const {
        return id; 
    }

    friend ostream& operator<<(ostream& os, const Student& s) {
        return os  << s.id ;
    }
};

int main() {
    queue<Student> studentQueue;
    studentQueue.push(Student("A", 1));
    studentQueue.push(Student("fsfs", 2));
    studentQueue.push(Student("Wthth", 3));
    studentQueue.push(Student("nynyn", 4));
    studentQueue.push(Student("gbbn", 5));

    stack<Student> studentStack;
    studentStack.push(Student("buh", 6));
    studentStack.push(Student("esarzres", 7));
    studentStack.push(Student("mjjo", 8));
    studentStack.push(Student("xrtcx", 9));
    studentStack.push(Student("ytgg", 10));

    list<Student> studentList;
	studentList.push_back(Student("8ioyyg", 11));
	studentList.push_back(Student("zxtes", 12));
	studentList.push_back(Student("d5ede", 13));
	studentList.push_back(Student("azwea", 14));
	studentList.push_back(Student("9ik9", 15));
    
    Student maxStudent = studentList.front();

    for (const Student& student : studentList) {
        if (student.getId() > maxStudent.getId()) {
            maxStudent = student;
        }
    }

    cout << "max ID: " << maxStudent << endl;
}
