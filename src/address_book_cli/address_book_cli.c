#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/address_book.h"
#include "../../include/address_book_cli.h"

#define BUFFER_SIZE 1024

void cli_setup()
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
        if(*input == '6')
        {
            free(input);
            cleanAddressBook();
            break;
        }
        handle_selection(input);
    }
}

void handle_selection(const char* selection)
{
    switch (*selection)
    {
        case '1':
            printf("Enter contact name:");
            char* name = malloc(BUFFER_SIZE);
            fgets(name, BUFFER_SIZE, stdin);
            name[strcspn(name, "\n")] = 0;

            printf("Enter contact phone number:");
            char* phoneNumber = malloc(BUFFER_SIZE);
            fgets(phoneNumber, BUFFER_SIZE, stdin);
            phoneNumber[strcspn(phoneNumber, "\n")] = 0;

            printf("Enter contact email address:");
            char* emailAddress = malloc(BUFFER_SIZE);
            fgets(emailAddress, BUFFER_SIZE, stdin);
            emailAddress[strcspn(emailAddress, "\n")] = 0;

            addContact(name, phoneNumber, emailAddress);

            free(name);
            free(phoneNumber);
            free(emailAddress);

            break;
        case '5':
            listContacts();
            break;
        default:
            printf("Invalid selection. Please try again.\n");
            break;
    }
}