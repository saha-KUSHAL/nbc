#include "src/system.h"
int main()
{
    int ch;
    c_printf("-----------------\n");
    c_printf("NOTHING BUT C\n");
    c_printf("-----------------\n");
    blue();
    c_printf("Contributors:- Kushal Saha(Lead)  Shreyangshu Saha  Subrata Mondal  Indadul Haque");
    c_printf("--------------------------------------------------------------------------------------\n");
    while (1)
    {
        printf("\n\n");
        red();
        c_printf("Login as:");
        yellow();
        printf("\n     ----------\t\t\t------------\t\t\t---------");
        printf("\n     |(1)ADMIN|\t\t\t|(2)STUDENT|\t\t\t|(0)EXIT|");
        printf("\n     ----------\t\t\t------------\t\t\t---------");
        reset();
        printf("\n>");
        scanf("%d", &ch);
        fflush(stdin);

        switch (ch)
        {
        case 1:
            admin();
            break;
        case 2:
            student();
            break;
        case 0:
            exit(0);
        }
    }
    return (0);
}
