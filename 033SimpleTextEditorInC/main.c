#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world, from simple text editor in c!\n");
    int optiune;
    do{
        printf("\n\tMENIU\n");
        printf("\t1.\t CREATE\n"
               "\t2.\t DISPLAY\n"
               "\t3.\t APPEND\n"
               "\t4.\t DELETE\n"
               "\t5.\t EXIT\n");

        printf("Introduce-ti optiunea: ");
        scanf("%d", &optiune);
        switch(optiune){
            case 1:
                Create();
                break;
            case 2:
                Display();
                break;
            case 3:
                Append();
                break;
            case 4:
                Delete();
                break;
            case 5: exit(0);
        }
    } while(1);
    return 0;
}
