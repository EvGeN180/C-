#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Contact {
public:
    string name;
    int homePhone;
    int workPhone;
    int mobilePhone;
    string info;

    Contact(string name,  int homePhone, int workPhone, int mobilePhone, string info) {
        this->name=name;
        this->homePhone = homePhone;
        this->workPhone = workPhone;
        this->mobilePhone = mobilePhone;
        this->info = info;
    }
    Contact(string name, int homePhone, int workPhone, int mobilePhone) {
        this->name = name;
        this->homePhone = homePhone;
        this->workPhone = workPhone;
        this->mobilePhone = mobilePhone;
        info = "None";
    }
    Contact(string name, int homePhone, int workPhone) {
        this->name = name;
        this->homePhone = homePhone;
        this->workPhone = workPhone;
		mobilePhone = 0;
        info = "None";
    }
    Contact(string name, int homePhone) {
        this->name = name;
        this->homePhone = homePhone;
		workPhone = 0;
		mobilePhone = 0;    
        info = "None";
    }
	Contact(string name) {
		this->name = name;
		homePhone = 0;
        workPhone = 0;
        mobilePhone = 0;
        info = "None";
	}
    void showContact() const {
        cout << "Name: " << name << endl;
        cout << "Home Phone: " << homePhone << endl;
        cout << "Work Phone: " << workPhone << endl;
        cout << "Mobile Phone: " << mobilePhone << endl;
        cout << "Info: " << info << endl;
        cout << "----------------------------" << endl;
    }


    void saveToFile(){
        ofstream myfile;
        myfile.open("C:\\Users\\Malin\\OneDrive\\Робочий стіл\\Contact.txt",ios::app);
        myfile << "Name: " << name<<"| " << "Home Phone: " << homePhone <<" |" << "Work Phone: " << workPhone<<"| " << "Mobile Phone: " << mobilePhone <<"| " << "Info: " << info <<" |" << endl;
		myfile.close();
    }
};

int main() {

    Contact obj1("John", 123456, 456321, 789101, "Work");
    Contact obj2("John", 123456, 456321, 789101);
    Contact obj3("John", 123456, 456321);
    Contact obj4("John", 123456);
    Contact obj5("John");
	obj1.saveToFile();   
	obj1.showContact();
    obj2.saveToFile();
    obj2.showContact(); 
    obj3.saveToFile();
    obj3.showContact();
    obj4.saveToFile();
    obj4.showContact();
    obj5.saveToFile();
    obj5.showContact();


}