#include "header.h"
void Print(contact *head) {
    if(head == NULL){
            printf("Contact list is empty\n");
            return;
    }
    contact *temp = head;
    while (temp) {
        printf("Name: %s\n ", temp->name);

        printf("Mobile Number/Mobile Numbers:");
        for (int i = 0; i <temp->num; i++) {
            printf(" %s ", temp->mobilenum[i]);
        }printf("\n");

        printf("Email ID's:");
        for (int i = 0; i < temp->email; i++) {
            printf(" %s ", temp->emailid[i]);
        }printf("\n");

        printf("Address: %s\n ", temp->address);
        temp = temp->next;
    }
}
