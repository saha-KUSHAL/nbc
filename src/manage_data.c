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
            printf("\nPress 1 to edit any Student Data.\nPress 2 to delete a student data.\nPress 0 to go back.");
            short int ch;
            while((getchar())!='\n');
            scanf("%hd",&ch);
            switch(ch){
                case 1:{
                    long int regno;
                    printf("\nEnter the reg no:");
                    while((getchar())!='\n');
                    scanf("%ld",&regno);
                    modify_student_data(regno);//need to modify the code
                }
                break;
                case 2:{
                    long int regno;
                    printf("\nEnter the reg no:");
                    while((getchar())!='\n');
                    scanf("%ld",&regno);
                    delete_student_data(regno);
                }
                break;
                case 0: break;
                default: printf("\nWrong input");
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
