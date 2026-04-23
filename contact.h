#ifndef CONTACT_H
#define CONTACT_H
/* Variable and structre defintion */
typedef struct Contact_data
{
    char Name[32];
    char Mobile_number[11];
    char Mail_ID[35];
} Contacts;

typedef struct AddressBook_Data
{
    Contacts contact_details[100];
    int contact_count;
} AddressBook;

/* Function declarations */
int create_contact(AddressBook *);
void list_contacts(AddressBook *);
int search_contacts(AddressBook *);
int edit_contact(AddressBook *);
int delete_contact(AddressBook *);
int save_contacts(AddressBook *);
int name_search(AddressBook *);
int Mobile_number_search(AddressBook *);
int Mail_ID_search(AddressBook *);
int validation_name(char *);
int validation_mobile(char *);
int validation_mail(char *);
void get_mail_ID(AddressBook *,char *);
void get_mobile_number(AddressBook *,char *);
void get_name(char *);
void Load_contacts(AddressBook *);
#endif // CONTACT_H
       // CONTACT_H
