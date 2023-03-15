#include <stdio.h>
#include <string.h>
#include "../../include/address_book.h"

static int g_numContacts = 0;
static struct address_book AddressBook;

void addContact(const char* name, const char* phoneNumber, const char* emailAddress)
{
    if (g_numContacts < 10)
    {
        struct contact contact = { name, phoneNumber, emailAddress };
        AddressBook.contacts[g_numContacts] = contact;
        g_numContacts++;
    }
    else
    {
        printf("You already have 10 contacts, cannot fit any more.\n");
    }
}

int searchContactByName(const char* name)
{
    for (int i = 0; i < g_numContacts; i++)
    {
        if (strcmp(AddressBook.contacts[i].name, name) == 0)
        {
            printContact(AddressBook.contacts[i]);
            return i;
        }
    }
    printf("Contact not found.\n\n");
    return -1;
}

int searchContactByPhone(const char* phoneNumber)
{
    for (int i = 0; i < g_numContacts; i++)
    {
        if (strcmp(AddressBook.contacts[i].phoneNumber, phoneNumber) == 0)
        {
            printContact(AddressBook.contacts[i]);
            return i;
        }
    }
    printf("Contact not found.\n\n");
    return -1;
}

int searchContactByEmail(const char* emailAddress)
{
    for (int i = 0; i < g_numContacts; i++)
    {
        if (strcmp(AddressBook.contacts[i].emailAddress, emailAddress) == 0)
        {
            printContact(AddressBook.contacts[i]);
            return i;
        }
    }
    printf("Contact not found.\n\n");
    return -1;
}

void editContactName(char* name, char* newName)
{
    int index = searchContactByName(name);
    if(index != -1)
    {
        AddressBook.contacts[index].name = newName;
    }
}

void editContactPhone(char* phoneNumber, char* newPhoneNumber)
{
    int index = searchContactByPhone(phoneNumber);
    if(index != -1)
    {
        AddressBook.contacts[index].phoneNumber = newPhoneNumber;
    }
}

void editContactEmail(char* emailAddress, char* newEmailAddress)
{
    int index = searchContactByEmail(emailAddress);
    if(index != -1)
    {
        AddressBook.contacts[index].emailAddress = newEmailAddress;
    }
}

int deleteContactByName(char* name)
{
    printf("Deleting...\n");
    int index = searchContactByName(name);

    if (index != -1)
    {
        for (int i = index; i < g_numContacts; i++)
        {
            AddressBook.contacts[i] = AddressBook.contacts[i + 1];
            g_numContacts--;
            return 0;
        }
    }
    return -1;
}

int deleteContactByPhone(char* phoneNumber)
{
    printf("Deleting...\n");
    int index = searchContactByPhone(phoneNumber);

    if (index != -1)
    {
        for (int i = index; i < g_numContacts; i++)
        {
            AddressBook.contacts[i] = AddressBook.contacts[i + 1];
            g_numContacts--;
            return 0;
        }
    }
    return -1;
}

int deleteContactByEmail(char* emailAddress)
{
    printf("Deleting...\n");
    int index = searchContactByEmail(emailAddress);

    if (index != -1)
    {
        for (int i = index; i < g_numContacts; i++)
        {
            AddressBook.contacts[i] = AddressBook.contacts[i + 1];
            g_numContacts--;
            return 0;
        }
    }
    return -1;
}

void printContact(struct contact contact)
{
    printf("Name: %s\nPhone #: %s\nEmail Address: %s\n\n", contact.name, contact.phoneNumber, contact.emailAddress);
}

void listContacts()
{
    for (int i = 0; i < g_numContacts; i++)
    {
        printf("Contact %d\n", i + 1);
        printf("Name: %s\nPhone #: %s\nEmail Address: %s\n\n", AddressBook.contacts[i].name,
               AddressBook.contacts[i].phoneNumber, AddressBook.contacts[i].emailAddress);
    }
}