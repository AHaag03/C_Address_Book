#ifndef ADDRESS_BOOK_ADDRESS_BOOK_H
#define ADDRESS_BOOK_ADDRESS_BOOK_H

struct contact
{
    char* name;
    char* phoneNumber;
    char* emailAddress;
};

struct address_book
{
    struct contact contacts[10];
};

void addContact(char* name, char* phoneNumber, char* emailAddress);

int searchContactByName(const char* name);

int searchContactByPhone(const char* phoneNumber);

int searchContactByEmail(const char* emailAddress);

void editContactName(char* name, char* newName);

void editContactPhone(char* phoneNumber, char* newPhoneNumber);

void editContactEmail(char* emailAddress, char* newEmailAddress);

int deleteContactByName(char* name);

int deleteContactByPhone(char* phoneNumber);

int deleteContactByEmail(char* emailAddress);

void printContact(struct contact contact);

void listContacts();

void cleanAddressBook();

#endif //ADDRESS_BOOK_ADDRESS_BOOK_H
