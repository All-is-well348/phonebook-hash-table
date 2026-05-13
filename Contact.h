#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
using namespace std;
class Contact {
public:
    string name;
    string phone;
    Contact* next;

    Contact(string n, string p);
};

#endif