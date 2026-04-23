/*
NAME: KAVANA
DESCRIPTION: This project is like a digital telephone directory that allows user to store and manage contact information 
such as name, mobile number, and email ID. It provides options to add new contacts, search for existing ones, edit 
their details, delete unwanted entries, and display all saved contacts in a list.All contact information is saved to a 
file,so the data remains safe even after exiting.

Functionalities:

1.Add Contact- Allows the user to enter a new name, phone number,email and validates them, and saves the contact 
to the address book.

2.Search Contact- Lets the user to find a contact using name, mobile number, or email and displays the matching 
contact details.

3.Edit Contact- Enables updating an existing contact’s name, phone number, email, or all details after searching 
for the contact.

4. Delete Contact- Removes a selected contact from the address book after confirmation and updates the list.

5.Display Contacts- Shows all saved contacts in a list format with name, number, and email.

6. Save Contacts- Writes all contact details into a text file so that the data is stored permanently.

7. Exit- Safely closes the program after saving all the contact details to prevent data loss.

*/

#include <stdio.h>
#include "contact.h"
/*color definition*/
#define RED  "\033[31m"
#define RESET  "\033[0m"
#define BOLDRED  "\033[1;31m"
#define BLUE "\033[34m"
#define BOLD_WHITE "\033[1;37m"
#define BOLDGREEN "\033[1;32m"
int main()
{
    /*declaraing variables*/
    int option;
    int ch;
    AddressBook addressbook; /* Structure declaration */
    addressbook.contact_count = 0; 

    
    Load_contacts(&addressbook); //calling load_contacts function to load the contacts from the file

    while (1) //loop for address book menu
    {
        printf(BOLDRED"\n::::ADDRESS BOOK MENU::::\n"RESET); /* Giving a prompt message for a user */
        printf(BOLD_WHITE"1.Add contact\n2.search contact\n3.Edit contact\n4.Delete contact\n5.Display contact\n6.Save contact\n7.Exit\n\n"RESET);
        printf(BLUE"Enter the option : "RESET);
        scanf("%d", &option);
        
        switch (option) /* Based on choosed option */
        {
        case 1:
        {
            create_contact(&addressbook); //calling creat function to add the contacts
            break;
        }

        case 2:
        {
            ch=1;
            while(ch)
            {
            printf(RED"\nSearch Contact menu : \n"RESET"1.Name \n2.Mobile number\n3.Mail ID\n4. Exit\n"BLUE"Enter the option : "RESET); /* Providing menu */
            ch=search_contacts(&addressbook); //calling function to search the contacts
            }
            break;
        }
        case 3:
        {
            ch=1;
            while(ch)
            {
            printf(RED"\nEdit Contact menu : \n"RESET"1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\n"BLUE"Enter the option : "RESET); /* Providing menu */
            ch=edit_contact(&addressbook); //calling function to edit the contacts
            }
            break;
        }

        case 4:
        {
            ch=1;
            while(ch)
            {
            printf(RED"Delete Contact menu : \n"RESET"1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\n"BLUE"Enter the option : "RESET); /* Providing menu */

            ch=delete_contact(&addressbook);//calling function to delete contact
            }
            break;
        }
        case 5:
        {
            printf(RED"\nList Contacts:\n"RESET);
            list_contacts(&addressbook); //calling function to display all the contacts details
            break;
        }

        case 6:
            printf(BOLDGREEN"Saving contacts\n"RESET);
            save_contacts(&addressbook); //calling function to save all the contact details in the file
            break;

        case 7:/* saving contacts in file and exiting from the menu*/
            printf(BOLDGREEN"INFO : Save and Exit...\n"RESET);
            save_contacts(&addressbook);
            return 0;

        default:
            printf(BOLDRED"Invalid option! Try again.\n"RESET);
            break;
        }
        getchar();
        
        
    }
    return 0;
}
