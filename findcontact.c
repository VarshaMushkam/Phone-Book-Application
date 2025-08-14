#include "header.h"
contact *FindContact(contact *head){
        contact *temp = head;
        char name[60];
        printf("enter the name to search\n");
        scanf("%s",name);
        if(head==NULL)
        {
                printf("list is empty\n");
                return head;
        }
        while(temp!=NULL)
        {
            if(strcmp(temp->name,name)==0)
            {
                printf("Contact found\n");
                Print(temp);
                return temp;
            }
            temp=temp->next;
       }
       printf("Contact not found\n");

}
