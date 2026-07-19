#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void login();
void registration();
void forgot();

int main() {
    int choice;

    while (true) {
        cout << "\n====== LOGIN SYSTEM ======\n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "3. Forgot Password\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                registration();
                break;
            case 3:
                forgot();
                break;
            case 4:
                cout << "Thank you! Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}

void registration() {
    string username, password;

    cout << "\nEnter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ofstream file("record.txt", ios::app);

    if (file.is_open()) {
        file << username << " " << password << endl;
        cout << "Registration successful!\n";
    } else {
        cout << "Error opening file!\n";
    }

    file.close();
}

void login() {
    string username, password, fileUser, filePass;
    int found = 0;

    cout << "\nEnter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("record.txt");

    if (!file.is_open()) {
        cout << "No users registered yet!\n";
        return;
    }

    while (file >> fileUser >> filePass) {
        if (fileUser == username && filePass == password) {
            found = 1;
            break;
        }
    }

    file.close();

    if (found)
        cout << "Login successful! Welcome " << username << "!\n";
    else
        cout << "Login failed! Incorrect username or password.\n";
}

void forgot() {
    string username, fileUser, filePass;
    int found = 0;

    cout << "\nEnter your username: ";
    cin >> username;

    ifstream file("record.txt");

    if (!file.is_open()) {
        cout << "No data found!\n";
        return;
    }

    while (file >> fileUser >> filePass) {
        if (fileUser == username) {
            cout << "Your password is: " << filePass << endl;
            found = 1;
            break;
        }
    }

    file.close();

    if (!found)
        cout << "User not found!\n";
}