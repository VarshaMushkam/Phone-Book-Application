#include "header.h"
void save(contact *head)
{
        contact*ptr = head;
        FILE *fp = NULL;
        fp = fopen("contact.txt","w");
        if(fp == NULL)
        {
                printf("failed to open\n");
                return;
        }
        else{
                while(ptr)
                {
                        fprintf(fp,"%s ",ptr->name);
                        fprintf(fp,"%d ",ptr->num);
                        for(int i=0;i<ptr->num;i++){
                                fprintf(fp,"%s ",ptr->mobilenum[i]);
                        }
                        fprintf(fp,"%d ",ptr->email);
                        for(int i=0;i<ptr->email;i++){
                                fprintf(fp,"%s ",ptr->emailid[i]);
                        }
                        fprintf(fp,"%s ",ptr->address);
                        ptr= ptr->next;
                }
        }
        fclose(fp);
}
