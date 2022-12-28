#include "system.h"
void view_data()
{
    int ch = 3;
    long int  regno;
    yellow();
    c_printf("--VIEW DATA--");
    while (ch != 0)
    {
        blue();
        printf("\n----------\t\t\t------------\t\t\t-----------");
        printf("\n|(1)By Stream|\t\t\t|(2)By Reg.No|\t\t\t|(0)Go Back|");
        printf("\n----------\t\t\t------------\t\t\t------------");
        reset();
        printf("\n>");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            stream();
            break;
        case 2:
	    yellow();
	    printf("Enter Reg.No\n");
	    fflush(stdin);
	    scanf("%ld",&regno);
            search_student_data(regno);
	    reset();
            break;
        case 0:break;

        default:
            red();
            printf("\nWrong Input!");
            reset();
        }
    }
}
void stream()
{
    FILE *fp;
    if (fopen("files/student.dat", "r") == NULL)
    {
        red();
        printf("\nERROR!");
        reset();
    }
    else if (mt_file("files/student.txt"))
    {
        red();
        printf("\nNo data available!");
        reset();
    }
    else
    {
        printf("This is where whole sem data print code is needed\n");
    }
}

