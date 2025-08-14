#include "header.h"
void menu(){
        printf("c/C:CreateContact d/D:DeleteContact e/E:EditContact f/F:FindContact p/P:print s/S:save q:exit\n");
}
int main(){
        contact* head=NULL;
        char choice;
        head=sync(head);
        while(1){
                menu();
                scanf(" %c", &choice);

                switch(choice){
                        case 'c':
                        case 'C':
                                head=CreateContact(head);
                                  break;
                        case 'd':
                        case 'D':
                                 head=DeleteContact(head);
                                   break;
                        case 'e':
                        case 'E':
                                   EditContact(head);
                                   break;
                        case 'f':
                        case 'F':
                                  FindContact(head);
                                  break;
                        case 'p':
                        case 'P':
                                  Print(head);
                                  break;
                        case 's':
                        case 'S':
                                  save(head);
                                  break;
                        case 'q':exit(0);

                default : printf("invaild choice\n");
                }
        }
}
