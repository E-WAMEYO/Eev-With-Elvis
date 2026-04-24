#include <iostream>
#include <fstream>
#include <string>
#include <conio.h> // For _getch() masking

using namespace std;

// Function Prototypes
void login();
void registration();
void forgot();
string encrypt(string data);
string decrypt(string data);
string getMaskedPassword();

int main() {
    int choice;

    while (true) {
        cout << "\n============================";
        cout << "\n    SECURE LOGIN SYSTEM";
        cout << "\n============================";
        cout << "\n1. Login";
        cout << "\n2. Register";
        cout << "\n3. Forgot Password";
        cout << "\n4. Exit";
        cout << "\n\nEnter choice: ";
        cin >> choice;
        
        

        switch (choice) {
            case 1: login(); break;
            case 2: registration(); break;
            case 3: forgot(); break;
            case 4: 
                cout << "\nSafe travels! Exiting...\n"; 
                return 0;
            default: cout << "\nInvalid choice! Please try again.\n";
        }
    }
}


string encrypt(string data) {
    for(int i = 0; i < data.length(); i++) {
        data[i] = data[i] + 5; 
    }
    return data;
}

string decrypt(string data) {
    for(int i = 0; i < data.length(); i++) {
        data[i] = data[i] - 5;
    }
    return data;
}


string getMaskedPassword() {
    string password;
    char ch;
	
    while (cin.get(ch)) {
        if(ch == '\n') {
        	break;
		}
		else
		if(ch =='\b'){
			if(!password.empty()){
				cout <<"\b \b";
			//	password.pop_back();
			}
		}
		else{
			password += ch;
			cout <<'*';
		}
    }
    cout << endl;
    return password;
}

void registration() {
    string username, password, u, p;
    bool exists = false;

    cout << "\n--- REGISTER ---";
    cout << "\nEnter username: ";
    cin >> username;

    // Check if username already exists
    ifstream checkFile("record.txt");
    while (checkFile >> u >> p) {
        if (u == username) {
            exists = true;
            break;
        }
    }
    checkFile.close();

    if (exists) {
        cout << "\nError: Username already taken!\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;
    password = getMaskedPassword();

    ofstream file("record.txt", ios::app);
    if (file.is_open()) {
        // Save encrypted password
        file << username << " " << encrypt(password) << endl;
        cout << "\nRegistration successful!\n";
    } else {
        cout << "\nFile Error!\n";
    }
    file.close();
    system ("cls"); {
	int main;
	}
}

void login() {
    string username, password, fileUser, filePass;
    bool found = false;

    cout << "\n--- LOGIN ---";
    cout << "\nEnter username: ";
    cin >> username;
    cout << "Enter password: ";
    password = getMaskedPassword();

    ifstream file("record.txt");
    if (!file.is_open()) {
        cout << "\nDatabase empty. Please register first.\n";
        return;
    }

    while (file >> fileUser >> filePass) {
        // We compare the entered password (encrypted) with the stored (encrypted) password
        if (fileUser == username && filePass == encrypt(password)) {
            found = true;
            break;
        }
    }
    file.close();
    

    if (found) {
        cout << "\nLogin successful! Welcome, " << username << ".\n";
    } else {
        cout << "\nLogin failed! Incorrect credentials.\n";
        
    }
}

void forgot() {
    string username, fileUser, filePass;
    bool found = false;

    cout << "\n--- RECOVER PASSWORD ---";
    cout << "\nEnter your username: ";
    cin >> username;

    ifstream file("record.txt");
    while (file >> fileUser >> filePass) {
        if (fileUser == username) {
            // Decrypt it so the user can actually read their old password
            cout << "\nUser Found! Your password is: " << decrypt(filePass) << endl;
            found = true;
            break;
        }
    }
    file.close();
    

    if (!found) {
        cout << "\nUsername not found in our records.\n";
        system ("cls"); {
		int main;
		}
    }
}
