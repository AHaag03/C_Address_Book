#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/address_book.h"

static int g_numContacts = 0;
struct contact AddressBook[10];

void addContact(char* name, char* phoneNumber, char* emailAddress)
{
    struct contact contact = { name, phoneNumber, emailAddress };
    printContact(contact);

    if (g_numContacts < 10)
    {
        AddressBook[g_numContacts].name = malloc(strlen(name) + 1);
        strcpy(AddressBook[g_numContacts].name, name);
        AddressBook[g_numContacts].phoneNumber = malloc(strlen(phoneNumber) + 1);
        strcpy(AddressBook[g_numContacts].phoneNumber, phoneNumber);
        AddressBook[g_numContacts].emailAddress = malloc(strlen(emailAddress) + 1);
        strcpy(AddressBook[g_numContacts].emailAddress, emailAddress);
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
        if (strcmp(AddressBook[i].name, name) == 0)
        {
            printContact(AddressBook[i]);
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
        if (strcmp(AddressBook[i].phoneNumber, phoneNumber) == 0)
        {
            printContact(AddressBook[i]);
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
        if (strcmp(AddressBook[i].emailAddress, emailAddress) == 0)
        {
            printContact(AddressBook[i]);
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
        AddressBook[index].name = newName;
    }
}

void editContactPhone(char* phoneNumber, char* newPhoneNumber)
{
    int index = searchContactByPhone(phoneNumber);
    if(index != -1)
    {
        AddressBook[index].phoneNumber = newPhoneNumber;
    }
}

void editContactEmail(char* emailAddress, char* newEmailAddress)
{
    int index = searchContactByEmail(emailAddress);
    if(index != -1)
    {
        AddressBook[index].emailAddress = newEmailAddress;
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
            AddressBook[i] = AddressBook[i + 1];
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
            AddressBook[i] = AddressBook[i + 1];
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
            AddressBook[i] = AddressBook[i + 1];
            g_numContacts--;
            return 0;
        }
    }
    return -1;
}

void printContact(struct contact contact)
{
    printf("Name: %s\n", contact.name);
    printf("Phone #: %s\n", contact.phoneNumber);
    printf("Email Address: %s\n", contact.emailAddress);
    //printf("Name: %s\nPhone #: %s\nEmail Address: %s\n\n", contact.name, contact.phoneNumber, contact.emailAddress);
}

void listContacts()
{
    for (int i = 0; i < g_numContacts; i++)
    {
        struct contact contact = AddressBook[i];
        printf("Contact %d\n", i + 1);
        printContact(contact);
    }
}

void cleanAddressBook()
{
    for(int i = 0; i < g_numContacts; i++)
    {
        free(AddressBook[i].name);
        free(AddressBook[i].phoneNumber);
        free(AddressBook[i].emailAddress);
    }
}