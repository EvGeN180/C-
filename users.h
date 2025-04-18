#pragma once
#include <iostream>

namespace userNamespace {
    class User {
    private:
        std::string name, email;
        int ID = 0, phone = 0;
    public:
        User() {}

        User(int ID) {
            this->ID = ID;
        }

        User(std::string name, int phone) {
            this->name = name;
            this->phone = phone;
        }

        User(std::string name, int ID, int phone) {
            this->name = name;
            this->ID = ID;
            this->phone = phone;
        }

        User(std::string name, std::string email, int ID, int phone) {
            this->name = name;
            this->email = email;
            this->ID = ID;
            this->phone = phone;
        }

        std::string getName() {
			if (name.empty()) {
				return " ";
			}
            return name;
		}
		

        std::string getEmail() {
			if (email.empty()) {
				return " ";
			}
			return email;
        }

        int getID() {
            return ID;
        }

        int getPhone() {
			return phone;
	
        }
    };
}

namespace users_admin {
    int user_count = 0;
    int index = 0;
    userNamespace::User* users_arr = nullptr;

    int count_of_users() {
        if (user_count == 0) {
            std::cout << "Enter the number of users: ";
            std::cin >> user_count;
        }
        return user_count;
    }

    void create_users_arr() {
        int size = count_of_users();
        users_arr = new userNamespace::User[size];
    }

    void show_users_arr() {
        for (size_t i = 0; i < index; i++) {
            std::cout << "User " << i + 1 << ":" << std::endl;
            std::cout << "Name: " << users_arr[i].getName() << std::endl;
            std::cout << "Email: " << users_arr[i].getEmail() << std::endl;
            std::cout << "ID: " << users_arr[i].getID() << std::endl;
            std::cout << "Phone number: " << users_arr[i].getPhone() << std::endl;
           
        }
    }

    void add_users_arr(userNamespace::User& obj) {
        if (index < user_count) {
            users_arr[index] = obj;
            index++;
        }
        else {
            std::cout << "Error: Array is full" << std::endl;
        }
    }
    void delete_user(userNamespace::User& obj) {
        for (size_t i = 0; i < index; i++) {
            if (obj.getID() == users_arr[i].getID() && obj.getPhone() == users_arr[i].getPhone()) {
                for (int j = i; j < index - 1; j++) {
                    users_arr[j] = users_arr[j + 1];
                }
                index--;
                std::cout << "User with ID " << obj.getID() << " and phone number " << obj.getPhone() << " has been deleted." << std::endl;
                return;
            }
        }
        std::cout << "User not found." << std::endl;
    }
}

