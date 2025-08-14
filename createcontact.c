#include "header.h"
char* getstring(){
        char * p = NULL;
        int i=0;
        do{
                p = realloc(p,(i+1)*sizeof(char));
                p[i] = getchar();
        }while(p[i++]!='\n');
        p[i-1] = '\0';
        return p;
}

contact *CreateContact(contact*head)
{
        contact*node,*temp,*prev;

        node=malloc(sizeof(contact));
        if(!node){
                printf("memory allocation failed\n");
                return head;
        }
        node->num=0;
        node->email=0;
        node->mobilenum=NULL;
        node->emailid = NULL;

        printf("enter the node information\n");

        printf("enter the name:");
        scanf("%s",node->name);

        contact *duplicate = head;
        while(duplicate){
                if(strcmp(duplicate->name,node->name)==0){
                            printf("Contact name already exists.");
                            free(node);
                            return head;
                }
                duplicate = duplicate->next;
        }

        int dup;
        char ch;
        duplicate = head;
        do{
                 dup = 0;
                 printf("enter the mobile number:");
                 __fpurge(stdin);
                 char *temp  = getstring();

                 for(int i=0;i<node->num;i++)
                 {
                         if(strcmp(temp,node->mobilenum[i])==0){
                                 printf("This number already exists.\n");
                                 dup = 1;
                                 free(temp);
                                 break;
                         }

                 }
                 if(!dup){
                    duplicate = head;
                 while(duplicate){
                         if(duplicate!=node){
                 for(int i=0;i<duplicate->num;i++)
                 {
                         if(strcmp(temp,duplicate->mobilenum[i])==0){
                                 printf("This number already exists.\n");
                                 dup = 1;
                                 free(temp);
                                 break;
                         }
                 }
                 }if(dup) break;
                 duplicate = duplicate->next;
                 }
                 }

                if(!dup)
                {
                        node->mobilenum = realloc(node->mobilenum,(node->num+1)*sizeof(char*));
                        node->mobilenum[node->num] = temp;
                        node->num++;
                }

                printf("Do you have any alternate mobile number(y/Y or n/N):");
                scanf(" %c",&ch);
        }while(ch=='y' || ch == 'Y');

        do{
                dup = 0;
                printf("enter the email id:");
                __fpurge(stdin);
                char *temp1 = getstring();
                for(int i=0;i<node->email;i++){
                        if(strcmp(temp1,node->emailid[i])==0){
                               printf("This emailid already exists.\n");
                               dup = 1;
                               free(temp1);
                               break;

                        }
             }
             if(!dup)
             {
                        node->emailid = realloc(node->emailid,(node->email+1)*sizeof(char*));
                        node->emailid[node->email] = temp1;
                        node->email++;
             }
             printf("Do you want to enter alternate email id(y/Y or n/N):");
             scanf("%c",&ch);
        }while(ch =='y'||ch=='Y');

        printf("enter the address:");
        int c;
while ((c = getchar()) != '\n' && c != EOF);
        char *addr = getstring();
        strncpy(node->address,addr,sizeof(node->address)-1);
        node->address[sizeof(node->address)-1] ='\0';
        free(addr);
        duplicate = head;
        node->next = 0;
        if(head ==NULL){
                head = node;
        }
        else if(strcmp(head->name,node->name)>0)
        {
            node->next=head;
            head=node;
        }
        else
        {
            temp=head;
            while(temp&&strcmp(temp->name,node->name)<0)
            {
                   prev = temp;
                   temp=temp->next;
            }
            if(temp)
            {
                    node->next=temp;
                    prev->next=node;
            }
            else
            {
                    prev->next=node;
            }
        }
        return head;
}
