#include <iostream>
using namespace std;
class Person {
protected:
	string firstName;
	string lastName;
	int age;
public:
	explicit Person() {}
	explicit Person(string firstName, string lastName, int age) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->age = age;
	}

	void show_person() {
		cout << "firstname: " << firstName << " lastname: " << lastName << " age: " << age;
	}

};
class Academic {
protected:
	string major;
	double gpa;
public:
	explicit Academic() {}
	explicit Academic(string major, double gpa) {
		this->major = major;
		this->gpa = gpa;
	}

	void show_academic() {
		cout << "major: " << major << " gpa: " << gpa;
	}

};
class Extracurricular {
protected:
	string clubs;
public:
	explicit Extracurricular() {}
	explicit Extracurricular(string clubs) {
		this->clubs = clubs;
	}
	void show_extracurricular() {
		cout << " clubs: " << clubs << endl;
	}
};

class Student : Person, Academic, Extracurricular {
private:
	int studentID;
public:
	explicit Student(int studentID, string firstName, string lastName, int age, string major, double gpa, string clubs) : Person(firstName, lastName, age), Academic(major, gpa), Extracurricular(clubs) {}
	void setID(int studentID) {
		this->studentID = studentID;
	}
	int getID() {
		return studentID;
	}
	void show_student() {
		cout << "ID: " << getID();
		show_person();
		show_academic();
		show_extracurricular();
	}
	friend ostream& operator<<(ostream& cout, Student& obj) {
		cout << "ID: " << obj.studentID << endl;
		cout << "firstname: " << obj.firstName << endl;
		cout << "lastname: " << obj.lastName << endl;
		cout << "Age: " << obj.age << endl;
		cout << "Mayor: " << obj.major << endl;
		cout << "Gpa: " << obj.gpa << endl;
		cout << "Clubs: " << obj.clubs << endl;
		return cout;
	}
};



int main()
{
	Student student(1, "ffe", "dede", 19, "major", 11, "club1");
	student.show_student();
	cout << student;


}
