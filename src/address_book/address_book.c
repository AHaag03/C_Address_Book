#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/address_book.h"

/*
* g_numContacts keeps track of how many contacts are currently
* in the user's address book. Used mainly for indexing purposes.
*
* AddressBook keeps track of all the contacts that the user has
* added.
*/
static int g_numContacts = 0;
static struct contact AddressBook[10];

/*
* If there are less than 10 contacts, copies the information provided by the user into the current
* index of the AddressBook and increments the number of contacts in the book.
*
* Else, it will print a message to standard error that the user is at the max number of contacts.
*/
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
        fprintf(stderr, "You already have 10 contacts, cannot fit any more.\n");
    }
}

/*
* Frees the memory of all the contacts stored in the user's AddressBook.
* Called whenever the user chooses to exit the program.
*/
void cleanAddressBook()
{
    for (int i = 0; i < g_numContacts; i++)
    {
        free(AddressBook[i].name);
        free(AddressBook[i].phoneNumber);
        free(AddressBook[i].emailAddress);
    }
}

/*
* Loops over the user's contact book searching for a match
* to the name provided by the user.
*
* If the contact is found, returns the index of the contact
* with this name.
*
* If the contact could not be found, returns -1.
*/
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
    fprintf(stderr, "Contact not found.\n\n");
    return -1;
}

/*
* Loops over the user's contact book searching for a match
* to the phone number provided by the user.
*
* If the contact is found, returns the index of the contact
* with this phone number.
*
* If the contact could not be found, returns -1.
*/
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
    fprintf(stderr, "Contact not found.\n\n");
    return -1;
}

/*
* Loops over the user's contact book searching for a match
* to the email address provided by the user.
*
* If the contact is found, returns the index of the contact
* with this email address.
*
* If the contact could not be found, returns -1.
*/
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
    fprintf(stderr, "Contact not found.\n\n");
    return -1;
}

/*
* If the index is within the specified range, frees the memory
* currently occupied by the contacts old name, and reallocates
* it to the new name provided by the user.
*
* On success, returns 0.
*
* On failure, return -1.
*/
int editContactName(int index, char* newName)
{
    if (index >= 0 && index < g_numContacts)
    {
        free(AddressBook[index].name);
        AddressBook[index].name = malloc(strlen(newName) + 1);
        strcpy(AddressBook[index].name, newName);
        return 0;
    }
    fprintf(stderr, "Contact not found.\n");
    return -1;
}

/*
* If the index is within the specified range, frees the memory
* currently occupied by the contacts old phone number, and reallocates
* it to the new phone number provided by the user.
*
* On success, returns 0.
*
* On failure, return -1.
*/
int editContactPhone(int index, char* newPhoneNumber)
{
    if (index >= 0 && index < g_numContacts)
    {
        free(AddressBook[index].phoneNumber);
        AddressBook[index].phoneNumber = malloc(strlen(newPhoneNumber) + 1);
        strcpy(AddressBook[index].phoneNumber, newPhoneNumber);
        return 0;
    }
    fprintf(stderr, "Contact not found.\n");
    return -1;
}

/*
* If the index is within the specified range, frees the memory
* currently occupied by the contacts old email address, and reallocates
* it to the new email address provided by the user.
*
* On success, returns 0.
*
* On failure, return -1.
*/
int editContactEmail(int index, char* newEmailAddress)
{
    if (index >= 0 && index < g_numContacts)
    {
        free(AddressBook[index].emailAddress);
        AddressBook[index].emailAddress = malloc(strlen(newEmailAddress) + 1);
        strcpy(AddressBook[index].emailAddress, newEmailAddress);
        return 0;
    }
    fprintf(stderr, "Contact not found.\n");
    return -1;
}

/*
* If the index provided is within the specified range,
* removes the selected index from the user's AddressBook
* and decrements the total number of contacts.
*
* On success, returns 0.
*
* On failure, returns -1.
*/
int deleteContact(int index)
{
    printf("Deleting...\n");

    if (index >= 0 && index < g_numContacts)
    {
        for (int i = index; i < g_numContacts; i++)
        {
            AddressBook[i] = AddressBook[i + 1];
            g_numContacts--;
            return 0;
        }
    }
    fprintf(stderr, "Contact not found.\n");
    return -1;
}

/*
* Prints a formatted string of the contact provided by the user.
*/
void printContact(struct contact contact)
{
    printf("Name: %s\nPhone #: %s\nEmail Address: %s\n\n", contact.name, contact.phoneNumber, contact.emailAddress);
}

/*
* Lists a formatted string of all the contacts currently
* in the user's AddressBook.
*/
void listContacts()
{
    for (int i = 0; i < g_numContacts; i++)
    {
        printf("Contact %d\n", i);
        printContact(AddressBook[i]);
    }
}