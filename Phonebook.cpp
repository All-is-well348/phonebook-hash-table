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