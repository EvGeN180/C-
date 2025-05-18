#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    cout << "Educational Testing System" << endl;
    cout << "Press 1 to register" << endl;
    cout << "Press 2 to login as student" << endl;
    cout << "Press 3 to login as admin" << endl;
    int choice;
    cin >> choice;

    if (choice == 1) {
        ofstream file("users.txt", ios::app);
        if (!file) {
            cout << "Error opening file!" << endl;
            return 1;
        }

        string firstname, lastname, email, phone, username, password;

        cout << "Enter your first name: ";
        cin >> firstname;
        file << "FirstName: " << firstname << endl;

        cout << "Enter your last name: ";
        cin >> lastname;
        file << "LastName: " << lastname << endl;

        cout << "Enter your email: ";
        cin >> email;
        file << "Email: " << email << endl;

        cout << "Enter your phone: ";
        cin >> phone;
        file << "Phone: " << phone << endl;

        cout << "Create username: ";
        cin >> username;
        file << "Username: " << username << endl;

        cout << "Create password: ";
        cin >> password;
        file << "Password: " << password << endl;

        file.close();

        cout << "Registration successful!" << endl;
    }
    else if (choice == 2) {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        bool validUsername = false;
        bool validPassword = false;

        ifstream file("users.txt");
        if (!file) {
            cout << "Error opening file!" << endl;
            return 1;
        }

        string line;
        while (getline(file, line)) {
            if (line == "Username: " + username) {
                validUsername = true;
            }
            if (line == "Password: " + password) {
                validPassword = true;
            }
        }
        file.close();

        if (validUsername && validPassword) {
            cout << "Login successful!" << endl;

            cout << "Select a test:" << endl;
            cout << "1. Mathematics" << endl;
            cout << "2. English" << endl;
            cout << "3. View my test results" << endl;

            int testChoice;
            cin >> testChoice;

            const int QUESTIONS = 10;
            int userAnswers[QUESTIONS];
            int score = 0;

            switch (testChoice) {
            case 1: {
                int mathAnswers[QUESTIONS] = { 3, 2, 1, 4, 2, 3, 1, 4, 2, 3 };

                cout << "\nMATHEMATICS TEST\n";
                cout << "Choose the correct answer (1-4)\n\n";

                cout << "Question 1: What is 15 + 27?\n";
                cout << "1) 32\n2) 37\n3) 42\n4) 52\n";
                cin >> userAnswers[0];

                cout << "Question 2: Calculate 8 × 9.\n";
                cout << "1) 63\n2) 72\n3) 81\n4) 56\n";
                cin >> userAnswers[1];

                cout << "Question 3: What is 144 ÷ 12?\n";
                cout << "1) 12\n2) 24\n3) 14\n4) 10\n";
                cin >> userAnswers[2];

                cout << "Question 4: Find the square root of 169.\n";
                cout << "1) 11\n2) 12\n3) 14\n4) 13\n";
                cin >> userAnswers[3];

                cout << "Question 5: What is 3² + 4²?\n";
                cout << "1) 49\n2) 25\n3) 7\n4) 12\n";
                cin >> userAnswers[4];

                cout << "Question 6: If x = 7, what is 2x + 5?\n";
                cout << "1) 14\n2) 12\n3) 19\n4) 24\n";
                cin >> userAnswers[5];

                cout << "Question 7: What is the perimeter of a square with side 5 cm?\n";
                cout << "1) 20 cm\n2) 25 cm\n3) 10 cm\n4) 15 cm\n";
                cin >> userAnswers[6];

                cout << "Question 8: Which is larger: 0.8 or 4/5?\n";
                cout << "1) 0.8\n2) 4/5\n3) They are equal\n4) Can't be determined\n";
                cin >> userAnswers[7];

                cout << "Question 9: What is the area of a rectangle with length 8 cm and width 5 cm?\n";
                cout << "1) 13 cm²\n2) 40 cm²\n3) 26 cm²\n4) 30 cm²\n";
                cin >> userAnswers[8];

                cout << "Question 10: Simplify: (2 + 3) × 4 - 6\n";
                cout << "1) 26\n2) 14\n3) 14\n4) 8\n";
                cin >> userAnswers[9];

                for (int i = 0; i < QUESTIONS; i++) {
                    if (userAnswers[i] == mathAnswers[i]) {
                        score++;
                    }
                }

                cout << "\nYour score: " << score << "/" << QUESTIONS << endl;

                ofstream resultFile("users.txt", ios::app);
                if (resultFile.is_open()) {
                    resultFile << "User: " << username << " - Mathematics Score: " << score << "/" << QUESTIONS << endl;
                    resultFile.close();
                }
                break;
            }

            case 2: {
                int englishAnswers[QUESTIONS] = { 1, 3, 2, 4, 1, 2, 3, 1, 4, 2 };

                cout << "\nENGLISH TEST\n";
                cout << "Choose the correct answer (1-4)\n\n";

                cout << "Question 1: Which word is a synonym for 'happy'?\n";
                cout << "1) Joyful\n2) Angry\n3) Sad\n4) Tired\n";
                cin >> userAnswers[0];

                cout << "Question 2: Which sentence is grammatically correct?\n";
                cout << "1) She don't like ice cream.\n2) They wasn't at home.\n3) He doesn't want to go.\n4) I be a student.\n";
                cin >> userAnswers[1];

                cout << "Question 3: What is the past tense of 'swim'?\n";
                cout << "1) Swimmed\n2) Swam\n3) Swimmed\n4) Swimming\n";
                cin >> userAnswers[2];

                cout << "Question 4: Choose the correct spelling:\n";
                cout << "1) Accomodation\n2) Acommodation\n3) Acomodation\n4) Accommodation\n";
                cin >> userAnswers[3];

                cout << "Question 5: 'Their', 'There', and 'They're' are examples of:\n";
                cout << "1) Homophones\n2) Synonyms\n3) Antonyms\n4) Adjectives\n";
                cin >> userAnswers[4];

                cout << "Question 6: What is the plural of 'child'?\n";
                cout << "1) Childs\n2) Children\n3) Childrens\n4) Child\n";
                cin >> userAnswers[5];

                cout << "Question 7: Which word is an adverb?\n";
                cout << "1) Happy\n2) Jump\n3) Quickly\n4) Beautiful\n";
                cin >> userAnswers[6];

                cout << "Question 8: What does the prefix 'un-' mean?\n";
                cout << "1) Not\n2) Again\n3) Before\n4) After\n";
                cin >> userAnswers[7];

                cout << "Question 9: Which punctuation mark ends an exclamatory sentence?\n";
                cout << "1) Period\n2) Comma\n3) Question mark\n4) Exclamation mark\n";
                cin >> userAnswers[8];

                cout << "Question 10: What is the opposite of 'expensive'?\n";
                cout << "1) Rich\n2) Cheap\n3) Cost\n4) Value\n";
                cin >> userAnswers[9];

                for (int i = 0; i < QUESTIONS; i++) {
                    if (userAnswers[i] == englishAnswers[i]) {
                        score++;
                    }
                }

                cout << "\nYour score: " << score << "/" << QUESTIONS << endl;

                ofstream resultFile("users.txt", ios::app);
                if (resultFile.is_open()) {
                    resultFile << "User: " << username << " - English Score: " << score << "/" << QUESTIONS << endl;
                    resultFile.close();
                }
                break;
            }


            case 3: {
                cout << "\nYour test results:\n";

                ifstream resultsFile("users.txt");
                if (!resultsFile) {
                    cout << "Error opening results file!" << endl;
                    break;
                }

                string line;
                bool foundResults = false;

                while (getline(resultsFile, line)) {
                    if (line.find("User: " + username) != string::npos) {
                        cout << line << endl;
                        foundResults = true;
                    }
                }

                if (!foundResults) {
                    cout << "No test results found for your account." << endl;
                }

                resultsFile.close();
                break;
            }

            default:
                cout << "Invalid choice!" << endl;
                break;
            }
        }
        else {
            if (!validUsername) {
                cout << "Username not found!" << endl;
            }
            else {
                cout << "Incorrect password!" << endl;
            }
        }
    }
    else if (choice == 3) {
        string adminUsername, adminPassword;
        cout << "Enter admin username: ";
        cin >> adminUsername;
        cout << "Enter admin password: ";
        cin >> adminPassword;

        if (adminUsername == "admin" && adminPassword == "admin") {
            cout << "Admin login successful!" << endl;

            int adminChoice;
            cout << "\nAdmin Menu:\n";
            cout << "1. View all users\n";
            cout << "2. View all test results\n";
            cout << "3. Search user by username\n";
            cout << "4. Delete user\n";
            cin >> adminChoice;

            switch (adminChoice) {
            case 1: {
                cout << "\nAll registered users:\n";

                ifstream usersFile("users.txt");
                if (!usersFile) {
                    cout << "Error opening users file!" << endl;
                    break;
                }

                string line;
                while (getline(usersFile, line)) {
                    if (line.find("Username: ") != string::npos) {
                        cout << line << endl;
                    }
                }

                usersFile.close();
                break;
            }

            case 2: {
                cout << "\nAll test results:\n";

                ifstream resultsFile("users.txt");
                if (!resultsFile) {
                    cout << "Error opening results file!" << endl;
                    break;
                }

                string line;
                while (getline(resultsFile, line)) {
                    if (line.find("User: ") != string::npos && line.find("Score") != string::npos) {
                        cout << line << endl;
                    }
                }

                resultsFile.close();
                break;
            }

            case 3: {
                string searchUsername;
                cout << "Enter username to search: ";
                cin >> searchUsername;

                ifstream usersFile("users.txt");
                if (!usersFile) {
                    cout << "Error opening users file!" << endl;
                    break;
                }

                string line;
                bool foundUser = false;
                bool printLines = false;

                while (getline(usersFile, line)) {
                    if (line == "Username: " + searchUsername) {
                        foundUser = true;
                        printLines = true;
                        cout << "\nUser found:\n";
                    }

                    if (printLines && line != "-------------------------") {
                        cout << line << endl;
                    }
                    else if (printLines && line == "-------------------------") {
                        printLines = false;
                    }
                }

                if (!foundUser) {
                    cout << "User not found!" << endl;
                }

                usersFile.close();
                break;
            }

            case 4: {
                string deleteUsername;
                cout << "Enter username to delete: ";
                cin >> deleteUsername;

                vector<string> fileContents;
                ifstream inFile("users.txt");

                if (!inFile) {
                    cout << "Error opening file!" << endl;
                    break;
                }

                string line;
                while (getline(inFile, line)) {
                    fileContents.push_back(line);
                }
                inFile.close();

                ofstream outFile("users.txt");
                if (!outFile) {
                    cout << "Error opening file for writing!" << endl;
                    break;
                }

                bool skipUser = false;
                bool userFound = false;

                for (size_t i = 0; i < fileContents.size(); i++) {
                    if (fileContents[i] == "Username: " + deleteUsername) {
                        skipUser = true;
                        userFound = true;
                        continue;
                    }

                    if (skipUser) {
                        if (fileContents[i] == "-------------------------") {
                            skipUser = false;
                            continue;
                        }
                        continue;
                    }

                    if (fileContents[i].find("User: " + deleteUsername) != string::npos) {
                        continue;
                    }

                    outFile << fileContents[i] << endl;
                }

                outFile.close();

                if (userFound) {
                    cout << "User deleted successfully!" << endl;
                }
                else {
                    cout << "User not found!" << endl;
                }
                break;
            }

            default:
                cout << "Invalid choice!" << endl;
                break;
            }
        }
        else {
            cout << "Invalid admin credentials!" << endl;
        }
    }
    else {
        cout << "Invalid choice!" << endl;
    }

}