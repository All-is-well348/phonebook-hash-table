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