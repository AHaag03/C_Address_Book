#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/address_book.h"
#include "../../include/address_book_cli.h"

#define BUFFER_SIZE 64

int cli_driver()
{
    char* input = malloc(BUFFER_SIZE);
    printf("*****ADDRESS BOOK*****\n\n");
    while (1)
    {
        printf("1. Add Contact\n");
        printf("2. Search for Contact\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. List Contacts\n");
        printf("6. Exit\n");

        printf(">");
        fgets(input, BUFFER_SIZE, stdin);
        switch (*input)
        {
            case '1':
                handle_add_contact();
                break;
            case '2':
                handle_search_contact();
                break;
            case '3':
                handle_edit_contact();
                break;
            case '4':
                handle_delete_contact();
                break;
            case '5':
                listContacts();
                break;
            case '6':
                cleanAddressBook();
                return 0;
            default:
                printf("Invalid input. Please try again.\n");
        }
    }
}

void handle_add_contact()
{
    char* name = malloc(BUFFER_SIZE);
    printf("Enter contact name:");
    fgets(name, BUFFER_SIZE, stdin);
    name[strcspn(name, "\n")] = 0;

    char* phoneNumber = malloc(BUFFER_SIZE);
    printf("Enter contact phone number:");
    fgets(phoneNumber, BUFFER_SIZE, stdin);
    phoneNumber[strcspn(phoneNumber, "\n")] = 0;

    char* emailAddress = malloc(BUFFER_SIZE);
    printf("Enter contact email address:");
    fgets(emailAddress, BUFFER_SIZE, stdin);
    emailAddress[strcspn(emailAddress, "\n")] = 0;

    addContact(name, phoneNumber, emailAddress);

    free(name);
    free(phoneNumber);
    free(emailAddress);
}

void handle_search_contact()
{
    char* selection = malloc(BUFFER_SIZE);

    printf("How would you like to search?\n");
    printf("1. Name\n");
    printf("2. Phone Number\n");
    printf("3. Email Address\n");
    printf(">");
    fgets(selection, BUFFER_SIZE, stdin);
    switch (*selection)
    {
        case '1':
            printf("Enter name:");
            char* name = malloc(BUFFER_SIZE);
            fgets(name, BUFFER_SIZE, stdin);
            name[strcspn(name, "\n")] = 0;
            searchContactByName(name);
            free(selection);
            free(name);
            break;
        case '2':
            printf("Enter phone number:");
            char* phoneNumber = malloc(BUFFER_SIZE);
            fgets(phoneNumber, BUFFER_SIZE, stdin);
            phoneNumber[strcspn(phoneNumber, "\n")] = 0;
            searchContactByPhone(phoneNumber);
            free(selection);
            free(phoneNumber);
            break;
        case '3':
            printf("Enter email address:");
            char* emailAddress = malloc(BUFFER_SIZE);
            fgets(emailAddress, BUFFER_SIZE, stdin);
            emailAddress[strcspn(emailAddress, "\n")] = 0;
            searchContactByEmail(emailAddress);
            free(selection);
            free(emailAddress);
            break;
        default:
            printf("Invalid input.\n");
            free(selection);
            break;
    }
}

int select_contact()
{
    char* input = malloc(BUFFER_SIZE);
    printf("Select contact\n");
    listContacts();
    printf(">");
    fgets(input, BUFFER_SIZE, stdin);
    input[strcspn(input, "\n")] = 0;
    int selection = atoi(input);
    free(input);
    return selection;
}

void handle_edit_contact()
{
    int contactIndex = select_contact();

    char* selection = malloc(BUFFER_SIZE);
    printf("What would you like to edit?\n");
    printf("1. Name\n");
    printf("2. Phone Number\n");
    printf("3. Email Address\n");
    printf(">");
    fgets(selection, BUFFER_SIZE, stdin);

    switch(*selection)
    {
        case '1':
            printf("Enter new name:");
            char* newName = malloc(BUFFER_SIZE);
            fgets(newName, BUFFER_SIZE, stdin);
            newName[strcspn(newName, "\n")] = 0;
            editContactName(contactIndex, newName);
            free(newName);
            free(selection);
            break;
        case '2':
            printf("Enter new phone number:");
            char* newPhone = malloc(BUFFER_SIZE);
            fgets(newPhone, BUFFER_SIZE, stdin);
            newPhone[strcspn(newPhone, "\n")] = 0;
            editContactPhone(contactIndex, newPhone);
            free(newPhone);
            free(selection);
            break;
        case '3':
            printf("Enter new email address:");
            char* newEmail = malloc(BUFFER_SIZE);
            fgets(newEmail, BUFFER_SIZE, stdin);
            newEmail[strcspn(newEmail, "\n")] = 0;
            editContactEmail(contactIndex, newEmail);
            free(newEmail);
            free(selection);
            break;
        default:
            printf("Invalid input.\n");
            free(selection);
            break;
    }
}

void handle_delete_contact()
{
    int index = select_contact();
    deleteContact(index);
}