#include "header.h"
void menu1(){
        printf("n/N:editName m/M:editMobileNumber e/E: editEmailID a/A: editAddress q/Q:exit\n");
}

contact *EditContact(contact *head){
        contact *temp = head;
        char name[60];
        printf("enter the contact name that you want to edit\n");
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

                    char c;
                    while(1){
                        menu1();
                        scanf(" %c",&c);
                        switch(c){
                                case 'n':
                                case 'N': editName(temp);
                                          break;
                                case 'm':
                                case 'M': editMobileNumber(temp);
                                          break;
                                case 'e':
                                case 'E': editEmailid(temp);
                                          break;
                                case 'a':
                                case 'A': editAddress(temp);
                                          break;
                                case 'q':
                                case 'Q': return temp;

                          default : printf("Invalid choice\n");
                    }
                 }
          }
            temp=temp->next;
        }
        return head;

}
contact *editName(contact *head){
        contact *temp = head;
        printf("enter the name\n");
        scanf("%s", temp->name);
}
contact *editMobileNumber(contact *head){
        contact*node=head;
        char ch;
        int dup;
        node->num=0;
        do{
                 dup =0;
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
                if(!dup)
                {
                        node->mobilenum = realloc(node->mobilenum,(node->num+1)*sizeof(char*));
                        node->mobilenum[node->num] = temp;
                        node->num++;
                }

                printf("Do you have any alternate mobile number(y/Y or n/N):");
                scanf("%c",&ch);
        }while(ch=='y' || ch == 'Y');
}
contact *editEmailid(contact *head)
{
        contact*node=head;
        char ch;
        int dup;
        node->email=0;
        do{
                 dup =0;
                 printf("enter the email id:");
                 __fpurge(stdin);
                 char *temp  = getstring();
                 for(int i=0;i<node->email;i++)
                 {
                         if(strcmp(temp,node->emailid[i])==0){
                                 printf("This email id already exists.\n");
                                 dup = 1;
                                 free(temp);
                                 break;
                         }
                }
                if(!dup)
                {
                        node->emailid = realloc(node->emailid,(node->email+1)*sizeof(char*));
                        node->emailid[node->email] = temp;
                        node->email++;
                }

                printf("Do you have any alternate email id(y/Y or n/N):");
                scanf("%c",&ch);
        }while(ch=='y' || ch == 'Y');
}
contact *editAddress(contact *head){
        contact *temp = head;
        printf("enter the address:\n");
        scanf("%s",temp->address);
}
