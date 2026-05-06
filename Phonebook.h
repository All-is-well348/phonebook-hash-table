#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"

class PhoneBook {
private:
    static const int SIZE = 10;
    Contact* table[SIZE];
    int totalContacts;

public:
    PhoneBook();
    int hashFunction(string name);
    void addContact(string name, string phone);
    void searchContact(string name);
    void deleteContact(string name);
};

#endif