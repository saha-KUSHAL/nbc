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
    switch (ch)
    {
        case 1:
            create_data();//in student.c
            break;
        case 2: // modify_data();
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
