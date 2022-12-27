#include "src/system.h"
int main()
{
    int ch;
    c_printf("NOTHING BUT C\n");
    c_printf("...........................................................................");
    while (1)
    {
        red();
        c_printf("Login as:");
        yellow();
        printf("\n----------\t\t\t------------\t\t\t---------");
        printf("\n|(1)admin|\t\t\t|(2)student|\t\t\t|(0)Exit|");
        printf("\n----------\t\t\t------------\t\t\t---------");
        reset();
        printf("\n>");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            admin();
            break;
        case 2:
            // student();
            break;
        case 3:
            exit(0);
        }
    }
    return (0);
}
