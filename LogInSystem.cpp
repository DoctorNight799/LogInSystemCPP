#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>

using namespace std;

bool isLoggedIn()
{
    string username, password, un, pw;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream read("d:\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password) 
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int choice;

    cout << "Choose an option.\n1: Register\n2: LogIn\nYour choice is: ";
    cin >> choice;

    if (choice == 1) {
        string username, password;

        cout << "Write your username: ";
        cin >> username;
        cout << "Write your password: ";
        cin >> password;

        ofstream file;
        file.open ("d:\\" + username + ".txt");
        file << username << endl << password;
        file.close();
        
        main();
    }
    else if (choice == 2)
    {
        bool status = isLoggedIn();

        if (!status) {
            cout << "Failed to Login." << endl;
            system("pause");
            return 0;
        }
        else
        {
            cout << "Succesfully logged in." << endl;
            system("pause");
            return 0;
        }
    }
    else
    {
        cout << "Error." << endl;
        system("pause");
    }
}
