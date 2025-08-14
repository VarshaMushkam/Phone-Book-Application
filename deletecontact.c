#include "header.h"
contact *DeleteContact(contact *head){
        contact *temp = head;
        contact *prev;
        char name[60];
        printf("enter the name to be delete\n");
        scanf("%s",name);
        if(head==NULL)
        {
                printf("list is empty\n");
                return head;
        }
        else if(/*head->next==NULL&&*/(strcmp(head->name,name)==0))
        {
                temp=head;
                head=head->next;
        }
        else
        {
                while(temp!=NULL &&(strcmp(temp->name,name)!=0))
                {
                        prev=temp;
                        temp=temp->next;

                }
                if(temp == NULL){
                        printf("Contact is not found\n");
                        return head;
                }
                prev->next=temp->next;
        }
       for(int i = 0; i < temp->num; i++)
                    free(temp->mobilenum[i]);
        free(temp->mobilenum);

        for(int i = 0; i < temp->email; i++)
                free(temp->emailid[i]);
        free(temp->emailid);
        free(temp);
        temp=NULL;
        return head;
}
