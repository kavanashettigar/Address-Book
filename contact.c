#include <stdio.h>
#include "contact.h"
#include <string.h>
#include<ctype.h>
/*color definition*/
#define RED  "\033[31m"
#define RESET  "\033[0m"
#define BOLDRED  "\033[1;31m"
#define BLUE "\033[34m"
#define BOLD_WHITE "\033[1;37m"
#define BOLDGREEN "\033[1;32m"
/* Function definitions */
int create_contact(AddressBook *addressbook) //funtion definition for creating contact
{
    int i=1;
    while(i) // loop for create contact 
    {
    char name[32],mobile_number[11],mail[35]; //declaring variables to store the entered details from user
    get_name(name);//function call for reading and validating the name
    strcpy(addressbook->contact_details[addressbook->contact_count].Name,name);//coping the name into structure variable

    get_mobile_number(addressbook,mobile_number);//function call for reading and validating the mobile number
    strcpy(addressbook->contact_details[addressbook->contact_count].Mobile_number,mobile_number);//coping the mobile number into structure variable


    get_mail_ID(addressbook,mail);//function call for reading and validating the mail id
    strcpy(addressbook->contact_details[addressbook->contact_count].Mail_ID,mail);//coping the mail id into structure variable


    printf(BOLDGREEN"\nContact added successfully\n"RESET);
    (addressbook->contact_count)++;

    printf(BLUE"\nDo you want to continue:(1->yes 0->no):"RESET);
    scanf("%d",&i);
    }
    return 0;
}
void list_contacts(AddressBook *addressbook) //funtion definition for displaying contacts
{
    if(addressbook->contact_count==0)
    {
        printf(BOLDRED"\nThere is no contacts in addressbook\n"RESET);
    }
    else
    {
        //printing all contact details
    for(int i=0;i<addressbook->contact_count;i++)
    {
        printf("\nName: %s Mobile Number: %s Mail ID: %s\n",addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
    }
}
}

int search_contacts(AddressBook *addressbook) //funtion definition for searching contact
{
    int ch,ind;
    scanf("%d",&ch);
    switch(ch)//based on choosed option
    {
        case 1:
        ind=name_search(addressbook);//calling function to search the contact from addressbook based on name
        break; 

        case 2:
        ind=Mobile_number_search(addressbook);//calling function to search the contact from addressbook based on mobile number
        break;

        case 3:
        ind=Mail_ID_search(addressbook);//calling function to search the contact from addressbook based on mail id
        break;

        case 4:
        return 0; //returning 0 to exit from search menu

        default:
        printf(BOLDRED"\nInvalid option!!!\n"RESET);
        return 1;

    }
    if(ind==-1) //if contact not found in addressbook printing contact not found
    {
    printf(BOLDRED"\nContact not found\n"RESET);
    return 1;
    }
    else
    {
        printf(RED"\nConctact Details:\n"RESET);//if found printing that particular contact details
        printf("Name: %s Mobile Number: %s Mail ID: %s\n",addressbook->contact_details[ind].Name,addressbook->contact_details[ind].Mobile_number,addressbook->contact_details[ind].Mail_ID);
        return 1; //returning 1 to print search menu 
    }   
}
int edit_contact(AddressBook *addressbook)//function definition for editing contact
{
    int ch,choice,ind,flag;
    char name[32],mobile[11],mail[35]; //variable declarations 
    scanf("%d",&ch);
    switch(ch)//based on option searching whether entered contact is present or not
    {
        case 1:
        ind=name_search(addressbook);
        break;

        case 2:
        ind=Mobile_number_search(addressbook);
        break;

        case 3:
        ind=Mail_ID_search(addressbook);
        break;

        case 4:
        return 0;//returning 0 to exit from edit menu

        default:
        printf(BOLDRED"Invalid option!!!\n"RESET);
        return 1;

    }
    if(ind==-1) //if contact not found printing contact not found
    {
    printf(BOLDRED"Contact not found\n"RESET);
    return 1;
    }
    else
    {  /*if contact found printing that particular contact details */
        printf(RED"Conctact Details:\n"RESET);
        printf("Name:%s Mobile Number:%s Mail ID:%s\n",addressbook->contact_details[ind].Name,addressbook->contact_details[ind].Mobile_number,addressbook->contact_details[ind].Mail_ID);
        printf(RED"Edit Options:\n"RESET"1.Name\n2.Mobile Number\n3.Mail ID\n4.All\n"BLUE"Enter the option to edit:"RESET);/*proving menu to edit details*/
        scanf("%d",&choice);
        switch(choice) //based on option editing details 
        {
           case 1:
           get_name(name); //calling function to edit name 
           strcpy(addressbook->contact_details[ind].Name,name);//coping valid edited name
           break;

           case 2:
           get_mobile_number(addressbook,mobile);//function call to edit mobile number
           strcpy(addressbook->contact_details[ind].Mobile_number,mobile);//coping valid edited mobile number
           break;

           case 3:
           get_mail_ID(addressbook,mail);//function call to edit mail id
           strcpy(addressbook->contact_details[ind].Mail_ID,mail);//coping valid edited mail id
           break;

           case 4:
           //editing all details and coping it to addressbook
           get_name(name);
           strcpy(addressbook->contact_details[ind].Name,name);
           get_mobile_number(addressbook,mobile);
           strcpy(addressbook->contact_details[ind].Mobile_number,mobile);
           get_mail_ID(addressbook,mail);
           strcpy(addressbook->contact_details[ind].Mail_ID,mail);
           break;

           default:
           printf(BOLDRED"INVALID INPUT\n"RESET);

        }
    }
    return 1;
}

int delete_contact(AddressBook *addressbook)//function definition to delete contact
{
    int ch,ind,choice,new=0;
    scanf("%d",&ch);
    switch(ch)//based on option searching contact detail to delete
    {
        case 1:
        ind=name_search(addressbook);
        break;

        case 2:
        ind=Mobile_number_search(addressbook);
        break;

        case 3:
        ind=Mail_ID_search(addressbook);
        break;

        case 4:
        return 0;

        default:
        printf(BOLDRED"INVALID INPUT\n"RESET);
        return 1;

    }
    if(ind==-1)
    {
    printf(BOLDRED"Contact not found\n"RESET);
    return 1;
    }
    else
    {
        //if contact found printing that contact details 
        printf(RED"\nConctact Details:\n"RESET);
        printf("\nName:%s Mobile number:%s Mail ID:%s\n",addressbook->contact_details[ind].Name,addressbook->contact_details[ind].Mobile_number,addressbook->contact_details[ind].Mail_ID);
        printf(BLUE"Do you want to delete or not(1->yes 0->no):"RESET);
        scanf("%d",&choice);
        if(choice)//deleting contact detail from addressbook
        {
            for(int i=0;i<addressbook->contact_count;i++)
            {
                if(i!=ind)
                {
                    addressbook->contact_details[new]=addressbook->contact_details[i];
                    new++;
                }
                
            } 
            printf(BOLDGREEN"\nContact deleted\n\n"RESET);
            addressbook->contact_count=new;//storing new contact count after deleting from addressbook
            return 1;
        }
        
    }

}   

int save_contacts(AddressBook *addressbook) //function definition to save contact in file
{
    FILE *fptr=fopen("addressbook.txt","w"); //opening file in write mode
    if(fptr==NULL)
    {
        printf(BOLDRED"File not found\n"RESET);
        return 0;
    }
    //printing contact details from structure to file
    fprintf(fptr,"#%d\n",addressbook->contact_count);
    for(int i=0;i<addressbook->contact_count;i++)
    {
        fprintf(fptr,"%s,%s,%s\n",addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);

    }
    fclose(fptr);
    return 0;
}

int name_search(AddressBook *addressbook) //function definition to search name 
{
    char name[32],mobile[11],mail[35];
    int a[100],ch,count=0,flag=1,i;
    printf(BLUE"Enter the name:"RESET);
    scanf(" %[^\n]",name); //reading name from user
    for(int i=0;i<addressbook->contact_count;i++)
    {
        if(strcmp(addressbook->contact_details[i].Name,name)==0)//checking entered name is present in addressbook
        {
            a[count]=i; //storing index of found contact
            count++;
        }
    }
    if(count>1)//checking duplicate name there or not
    {
        for(int i=0;i<count;i++)//loop to print duplicate name contact details
        {
            printf("\nName: %s,Mobile Number: %s,Mail ID: %s\n",addressbook->contact_details[a[i]].Name,addressbook->contact_details[a[i]].Mobile_number,addressbook->contact_details[a[i]].Mail_ID);

        }
        printf(RED"\nMultiple contacts found with this name...\nPlease Try with mobile number or mail id\n"RESET);
        while(flag)
        {
        printf("1.Mobile number\n2.Mail id\n"BLUE"Enter the option:"RESET);//menu to search based on mobile number or mail id for duplicate name contacts
        scanf("%d",&ch);
        switch(ch)//based on option
        {
            case 1:
            //searching contact based on mobile number 
            printf(BLUE"Enter the mobile number:"RESET);
            scanf(" %[^\n]",mobile);
            getchar();
            for(i=0;i<count;i++)
            {
                if(strcmp(addressbook->contact_details[a[i]].Mobile_number,mobile)==0)
                {
                return a[i]; //returing index of found contact 
                }
            }
            printf(BOLDRED"\nMobile number not found!Try again.\n\n"RESET);
            break;

            case 2:
            //searching contact based on mail id
            printf(BLUE"Enter the Mail ID:"RESET);
            scanf(" %[^\n]",mail);
            for(i=0;i<count;i++)
            {
                if(strcmp(addressbook->contact_details[a[i]].Mail_ID,mail)==0)
                {
                return a[i];//returing index of found contact 
                }
            }
            printf(BOLDRED"\nMail ID not found! Try again.\n\n"RESET);
            break;

            default:
            printf(BOLDRED"\nInvalid option! Try again.\n\n"RESET);
        }
       }
    }
    else if(count==0)
    return -1;//returning -1 if contact not found

    return a[0]; //returing index of found contact if only one name is present
}

int Mobile_number_search(AddressBook *addressbook)//function definition to search contact based on mobile number
{
    char str[11];
    printf(BLUE"Enter the Mobile number:"RESET);
    scanf(" %[^\n]",str); //rearding mobile number from user
    for(int i=0;i<addressbook->contact_count;i++)
    {
        if(strcmp(addressbook->contact_details[i].Mobile_number,str)==0)//checking contact there or not in addressbook
        return i;//if found returing index
    }
    return -1;//if not found returing -1

}
int Mail_ID_search(AddressBook *addressbook)//function definition to search contact based on mail id
{
    char str[35];
    printf(BLUE"Enter the Mail ID:"RESET);
    scanf(" %[^\n]",str);//rearding mobile number from user
    for(int i=0;i<addressbook->contact_count;i++)
    {
        if(strcmp(addressbook->contact_details[i].Mail_ID,str)==0)//checking contact there or not in addressbook
        return i;//if found returing index
    }
    return -1;//if not found returing -1


}
int validation_name(char *name)//function definition for validating name 
{
    int i=0,flag=0;
     while(name[i]!='\0')
    {
        if((name[i]>='A'&& name[i]<='Z') || (name[i]>='a' && name[i]<='z') || (name[i]==' '))
        {
            i++;
        }
        else
        {
            printf(BOLDRED"\nName should contain only alphabets and spaces! Try again.\n"RESET);
            flag=1;
            break;
        }
    }
    
    return flag;
}
int validation_mobile(char *mobile)//function definition for validating mobile number
{
    int i=0,flag=0;
    while(mobile[i]!='\0')
    {
        if(isdigit(mobile[i]))
        i++;
        else
        {
            printf(BOLDRED"\nMobile number should contain only numbers! Try again.\n"RESET);
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        if(i>10)
        {
            printf(BOLDRED"\nMobile number should only have 10 digits! Try again.\n"RESET);
            flag=1;
        }
        if(i<10)
        {
         printf(BOLDRED"\nMobile number must have 10 digits! Try again.\n"RESET);
         flag=1;
        }
        if(i==10)
        {
            if(mobile[0]<='5')
        {
            printf(BOLDRED"\nMobile number should start from 6 or above!! Try again.\n"RESET);
            flag=1;
        }

        }
    }
    return flag;
}
int validation_mail(char *mail)//function definition for validating mail
{
    char *at_pos=strchr(mail,'@');//storing address of @ position 
    char *dot_pos=strchr(mail,'.');//storing address of . position
    int len=strlen(mail);
    int flag=0;
    for(int i=0;i<=len;i++)
    {
        if((mail[i]>='A'&& mail[i]<= 'Z')|| mail[i]==' ')
        {
            printf(BOLDRED"\nMail ID should only contain numbers ,lower case letters,@ symbol and full stop(.)! Try again.\n"RESET);
            return 1;
        }
    }
    if(at_pos==NULL)
    {
        printf(BOLDRED"\nOne @ symbol must be present! Try again.\n"RESET);
        return 1;
    }

    if(at_pos<mail+4)
    {
        printf(BOLDRED"\nBefore @ there should be atleast 4 alphanumeric characters! Try again.\n"RESET);
        return 1;
    }
    if(strchr(at_pos+1,'@')!=NULL)
    {
        printf(BOLDRED"\nOnly one @ symbol should be in the Mail ID! Try again.\n"RESET);
        return 1;
    }
    
    if(dot_pos==NULL)
    {
        printf(BOLDRED"\nEither .com or .in must be present at the end of Mail ID! Try again.\n"RESET);
        return 1; 
    }
    if(dot_pos==at_pos+1)
    {
        printf(BOLDRED"\nDomain name should be present after @ symbol! Try again.\n"RESET);
        return 1;
    }
    char *dot=strchr(at_pos,'.');
    
    if(dot==NULL)
    {
        printf(BOLDRED"\nEither .com or .in must be present at the end of Mail ID! Try again.\n"RESET);
        return 1; 
    }
    if(dot==at_pos+1)
    {
        printf(BOLDRED"\nDomain name should be present after @ symbol! Try again.\n"RESET);
        return 1;
    }
    if((strcmp(dot,".com")!=0) && (strcmp(dot,".in")!=0))
    {
        printf(BOLDRED"\nEither .com or .in must be present at the end of Mail ID! Try again.\n"RESET);
        return 1;
    }
    while(mail<at_pos)
    {
        if(*mail>='a'&& *mail<='z')
        {
            flag=1;
            break;
        }
        mail++;
    }
    if(flag==0)
    {
        printf(BOLDRED"\nBefore @ there should be alphabet character also! Try again\n"RESET);
        return 1;
    }
   
    return 0;
}
void get_name(char *name)//funtion definition for reading name from user
{
    int flag=1;
    while(flag)
    {
    getchar();
    printf(BLUE"Enter the name:"RESET);
    scanf("%[^\n]",name);
    flag=validation_name(name);//calling function to validate name
    }
    

}
void get_mobile_number(AddressBook *addressbook,char *mobile_number)//function definition for reading mobile number from user
{
    int flag=1;
    while(flag)
    {
    getchar();
    printf(BLUE"Enter the phone number:"RESET);
    scanf("%[^\n]",mobile_number);
    flag=validation_mobile(mobile_number);//calling function to validate mobile number
    if(flag==0)
    {
    //checking whether entered valid number is already present in addressbook
    for(int i=0;i<addressbook->contact_count;i++)
    {
        if(strcmp(addressbook->contact_details[i].Mobile_number,mobile_number)==0)
        {
        printf(BOLDRED"This number is already present.Mobile number should be unique! Try again.\n"RESET);
        flag=1;
        break;
        }
    }
    }
   }

}
void get_mail_ID(AddressBook *addressbook,char *mail)//function definition for reading mail id from user

{
    int flag=1;
    while(flag)
    {
    getchar();
    printf(BLUE"Enter the email id:"RESET);
    scanf("%[^\n]",mail);
    flag=validation_mail(mail);//calling function to validate mail id
    if(flag==0)
    {
        //checking whether entered valid mail id is already present in addressbook
        for(int i=0;i<addressbook->contact_count;i++)
    {
        if(strcmp(addressbook->contact_details[i].Mail_ID,mail)==0)
        {
        printf(BOLDRED"This Mail ID is already present.Mail ID should be unique! Try again.\n"RESET);
        flag=1;
        break;
        }
    }
    }
    }
}
void Load_contacts(AddressBook *addressbook) //function definition to load contacts from file
{
    FILE *fptr=fopen("addressbook.txt","r");//opening file in read mode
    if(fptr==NULL)
    printf(BOLDRED"File not found\n"RESET);
    //reading contact details from file to structure 
    fscanf(fptr,"#%d\n",&addressbook->contact_count);
    for(int i=0;i<addressbook->contact_count;i++)
    {
        fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);

    }
    fclose(fptr);//closing file
}