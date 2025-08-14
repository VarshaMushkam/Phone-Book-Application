#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>

typedef struct phonebook{
        char name[60];
        char **mobilenum;
        int num;
        char **emailid;
        int email;
        char address[100];
        struct phonebook *next;
}contact;
char *getstring();
void menu();
void menu1();
contact *CreateContact(contact*);
contact *DeleteContact(contact*);
contact *FindContact(contact*);
contact *EditContact(contact*);
void Print(contact *);
contact *editName(contact*);
contact *editMobileNumber(contact*);
contact *editEmailid(contact*);
contact *editAddress(contact*);
void save(contact*);
contact *sync(contact*);
