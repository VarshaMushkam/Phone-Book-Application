a.out:main.o createcontact.o deletecontact.o findcontact.o editcontact.o print.o savecontact.o sync.o
        gcc main.o createcontact.o deletecontact.o findcontact.o editcontact.o print.o savecontact.o sync.o
main.o:main.c
        gcc -c main.c
createcontact.o:createcontact.c
        gcc -c createcontact.c
deletecontact.o:deletecontact.c
        gcc -c deletecontact.c
findcontact.o:findcontact.c
        gcc -c findcontact.c
editcontact.o:editcontact.c
        gcc -c editcontact.c
print.o:print.c
        gcc -c print.c
savecontact.o:savecontact.c
        gcc -c savecontact.c
sync.o:sync.c
        gcc -c sync.c
