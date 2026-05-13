#include <iostream>
#include "PhoneBook.h"

using namespace std;

int main() {

    PhoneBook pb;

    int choice;
    string name, phone;

    do {
        cout << "\n===== PHONE BOOK MENU =====" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Search Contact" << endl;
        cout << "3. Delete Contact" << endl;
        cout << "4. Display Contacts" << endl;
        cout << "5. Show Load Factor" << endl;
        cout << "6. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cout << "Enter Name: ";
                cin >> name;

                cout << "Enter Phone Number: ";
                cin >> phone;

                pb.addContact(name, phone);

                cout << "Contact Added Successfully" << endl;
                break;

            case 2:
                cout << "Enter Name to Search: ";
                cin >> name;

                pb.searchContact(name);
                break;

            case 3:
                cout << "Enter Name to Delete: ";
                cin >> name;

                pb.deleteContact(name);
                break;

            case 4:
                cout << "\n===== CONTACT LIST =====" << endl;
                pb.displayContacts();
                break;

            case 5:
                cout << "Load Factor: "
                     << pb.loadFactor() << endl;
                break;

            case 6:
                cout << "Exiting Program..." << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while(choice != 6);

    return 0;
}