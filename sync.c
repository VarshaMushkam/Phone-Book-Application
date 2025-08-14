#include "header.h"
contact *sync(contact *head)
{
        FILE *fp = NULL;
        char temp[100];
        contact var;
        contact *node = NULL;
        fp = fopen("contact.txt","r");
        if(fp == NULL)
        {
                printf("failed to open");
                return NULL;
        }
        while(!feof(fp))
        {
                fscanf(fp,"%s ",var.name);

                fscanf(fp,"%d ",&var.num);
                node = malloc(sizeof(contact));
                strcpy(node->name, var.name);
                node->num=var.num;
                node->mobilenum = malloc(var.num*sizeof(char *));
                for(int i=0;i<node->num;i++)
                {
                    fscanf(fp,"%s ",temp);
                    node->mobilenum[i] = malloc(strlen(temp)+1);
                    strcpy(node->mobilenum[i],temp);
                }
                fscanf(fp,"%d ",&var.email);

                node->email=var.email;
                node->emailid = malloc(node->email*sizeof(char*));
                for(int i=0;i<node->email;i++)
                {
                        fscanf(fp,"%s ",temp);
                        node->emailid[i] = malloc(strlen(temp)+1);
                        strcpy(node->emailid[i],temp);
                }
                fscanf(fp,"%s ",node->address);
                node->next=NULL;
                if(head==NULL)
                {
                    head = node;
                }
                else
                {
                    node->next = head;
                    head = node;
                }
        }
        fclose(fp);
        return head;
}
