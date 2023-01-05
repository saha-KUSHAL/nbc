#include "system.h"
void view_data()
{
    int ch = 3;
    long int regno;
    system(CLEAR);
    yellow();
    c_printf("--VIEW DATA--");
    while (ch != 0)
    {
        system(CLEAR);
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
            system(CLEAR);
            stream(); // view_data.c
            break;
        case 2:
            system(CLEAR);
            yellow();
            printf("Enter Reg.No\n");
            reset();
            fflush(stdin);
            scanf("%ld", &regno);
            search_student_data(regno); // search_sudent_data.c
            reset();
            break;
        case 0:
            break;

        default:
            red();
            printf("\nWrong Input!");
            reset();
        }
    }
}
void stream() // displays a perticuler stream data
{
    FILE *fp;

    if (mt_file("files/filelist.txt"))
        printf("\nNo Data Available");
    else
    {
        fp = fopen("files/filelist.txt", "r");
        char fname[30];
        while (1)
        {
            printf("\nStream List:");
            printf("\n-----------------");
            rewind(fp);
            fread(fname, 30, 1, fp);
            while (!feof(fp))
            {
                printf("\n%s", fname);
                fread(fname, 30, 1, fp);
            }
            int ch = 0;
            int flag = 0;
            char fname_choice[30];
            printf("\n>");
            while ((getchar()) != '\n');
            scanf("%29[^\n]", fname_choice); // input from the user
            rewind(fp);
            fread(fname, 30, 1, fp);
            while (!feof(fp) && flag == 0) // checking if user input is vaild
            {
                if ((strcmp(fname_choice, fname)) == 0)
                {
                    FILE *fp2 = fopen(fname_choice, "r");
                    student_data *data = (student_data *)malloc(sizeof(student_data));
                    printf("\nReg.no      Name      Stream      Semester     Year    Total Marks    Grade");
                    rewind(fp2);
                    fread(data, sizeof(student_data), 1, fp2);
                    while (!feof(fp2))
                    {
                        if(data->reg_no != 0)
                            printf("\n%ld    %s    %s    %s  %d    %d %c", data->reg_no, data->name, data->stream, data->sem, data->year, data->marks, data->grade);
                        fread(data, sizeof(student_data), 1, fp2);
                    }
                    fclose(fp2);
                    free(data);
                    flag = 1;
                    // ch=0;
                }
                else
                    fread(fname, 30, 1, fp);
            }
            if (flag != 1)
            {
                printf("\nWrong input");
            }
            printf("\n\nDo you want to view again\?(Y/N)");
            char sel;
            while ((getchar()) != '\n');
            scanf("%c",&sel);
            if((toupper(sel))=='N')
                break;
        }
        fclose(fp);
    }
}
