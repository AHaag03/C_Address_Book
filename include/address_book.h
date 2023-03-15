#ifndef ADDRESS_BOOK_ADDRESS_BOOK_H
#define ADDRESS_BOOK_ADDRESS_BOOK_H

struct contact
{
    char* name;
    char* phoneNumber;
    char* emailAddress;
};

void addContact(char* name, char* phoneNumber, char* emailAddress);

void cleanAddressBook();

int searchContactByName(const char* name);

int searchContactByPhone(const char* phoneNumber);

int searchContactByEmail(const char* emailAddress);

int editContactName(int index, char* newName);

int editContactPhone(int index, char* newPhoneNumber);

int editContactEmail(int index, char* newEmailAddress);

int deleteContact(int index);

void printContact(struct contact contact);

void listContacts();

#endif //ADDRESS_BOOK_ADDRESS_BOOK_H
