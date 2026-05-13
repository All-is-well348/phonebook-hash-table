#include "PhoneBook.h"

PhoneBook::PhoneBook() {
    totalContacts = 0;

    for(int i = 0; i < SIZE; i++) {
        table[i] = NULL;
    }
}

int PhoneBook::hashFunction(string name) {
    int sum = 0;

    for(char ch : name) {
        sum += ch;
    }

    return sum % SIZE;
}
void PhoneBook::addContact(string name, string phone) {
    int index = hashFunction(name);

    Contact* newNode = new Contact(name, phone);

    if(table[index] == NULL) {
        table[index] = newNode;
    }
    else {
        Contact* temp = table[index];

        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    totalContacts++;
}
void PhoneBook::searchContact(string name) {
    int index = hashFunction(name);

    Contact* temp = table[index];

    while(temp != NULL) {
        if(temp->name == name) {
            cout << "Contact Found" << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Phone: " << temp->phone << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Contact Not Found" << endl;
}

void PhoneBook::deleteContact(string name) {
    int index = hashFunction(name);

    Contact* temp = table[index];
    Contact* prev = NULL;

    while(temp != NULL && temp->name != name) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        cout << "Contact Not Found" << endl;
        return;
    }

    if(prev == NULL) {
        table[index] = temp->next;
    }
    else {
        prev->next = temp->next;
    }

    delete temp;
    totalContacts--;

    cout << "Contact Deleted Successfully" << endl;
}

void PhoneBook::displayContacts() {
    for(int i = 0; i < SIZE; i++) {
        Contact* temp = table[i];

        while(temp != NULL) {
            cout << "Name: " << temp->name << endl;
            cout << "Phone: " << temp->phone << endl;
            cout << "----------------" << endl;

            temp = temp->next;
        }
    }
}

float PhoneBook::loadFactor() {
    return (float)totalContacts / SIZE;
}