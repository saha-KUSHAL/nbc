#include "system.h"
void manage_data() // manage data from ADMIN
{
    int ch = 4;
    cyan();
    c_printf("--MANAGE DATA--");
    blue();
    printf("\n--------\t\t\t-----------\t\t\t---------");
    printf("\n|(1)Add|\t\t\t|(2)Modify|\t\t\t|(0)Go Back|");
    printf("\n--------\t\t\t-----------\t\t\t---------");
    reset();
    printf("\n>");
    scanf("%d", &ch);
    system(CLEAR);
    switch (ch)
    {
        case 1:
            create_data();//in student_data.c
            break;
        case 2:
            yellow();
            c_printf("--Modify Data--");
            reset();
            blue();
            printf("\n--------\t\t\t-----------\t\t\t---------");
            printf("\n|(1)Edit|\t\t\t|(2)Delete|\t\t\t|(0)Go Back|");
            printf("\n--------\t\t\t-----------\t\t\t---------");
            reset();
            short int ch;
            printf("\n>");
            scanf("%hd",&ch);
            while((getchar())!='\n');
            switch(ch){
                case 1:{
                    long int regno;
                    system(CLEAR);
                    c_printf("--Edit Data--");
                    cyan();
                    printf("\nEnter the reg no:");
                    reset();
                    while((getchar())!='\n');
                    scanf("%ld",&regno);
                    modify_student_data(regno);//need to modify the code
                }
                break;
                case 2:{
                    long int regno;
                    system(CLEAR);
                    c_printf("--Delete Data--");
                    cyan();
                    printf("\nEnter the reg no:");
                    reset();
                    while((getchar())!='\n');
                    scanf("%ld",&regno);
                    delete_student_data(regno);
                }
                break;
                case 0: break;
                default:
                red();
                printf("\nWrong input");
                reset();
            }
            break;
        case 0:
            break;
        default:
        {
            red();
            printf("\nWrong Input");
            reset();
        }
    }
}
