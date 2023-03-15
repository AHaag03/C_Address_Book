#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/address_book.h"

static int g_numContacts = 0;
static struct contact AddressBook[10];

void addContact(char* name, char* phoneNumber, char* emailAddress)
{
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

void cleanAddressBook()
{
    for (int i = 0; i < g_numContacts; i++)
    {
        free(AddressBook[i].name);
        free(AddressBook[i].phoneNumber);
        free(AddressBook[i].emailAddress);
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

int editContactName(int index, char* newName)
{
    if (index != -1)
    {
        free(AddressBook[index].name);
        AddressBook[index].name = malloc(strlen(newName) + 1);
        strcpy(AddressBook[index].name, newName);
        return 0;
    }
    printf("Contact not found.\n");
    return -1;
}

int editContactPhone(int index, char* newPhoneNumber)
{
    if (index >= 0 && index <= g_numContacts)
    {
        free(AddressBook[index].phoneNumber);
        AddressBook[index].phoneNumber = malloc(strlen(newPhoneNumber) + 1);
        strcpy(AddressBook[index].phoneNumber, newPhoneNumber);
        return 0;
    }
    printf("Contact not found.\n");
    return -1;
}

int editContactEmail(int index, char* newEmailAddress)
{
    if (index >= 0 && index <= g_numContacts)
    {
        free(AddressBook[index].emailAddress);
        AddressBook[index].emailAddress = malloc(strlen(newEmailAddress) + 1);
        strcpy(AddressBook[index].emailAddress, newEmailAddress);
        return 0;
    }
    printf("Contact not found.\n");
    return -1;
}

int deleteContact(int index)
{
    printf("Deleting...\n");

    if (index >= 0 && index <= g_numContacts)
    {
        for (int i = index; i < g_numContacts; i++)
        {
            AddressBook[i] = AddressBook[i + 1];
            g_numContacts--;
            return 0;
        }
    }
    printf("Contact not found.\n");
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
        struct contact contact = AddressBook[i];
        printf("Contact %d\n", i);
        printContact(contact);
    }
}