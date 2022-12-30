#include "system.h"
void view_data()
{
    int ch = 3;
    long int regno;
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
            stream(); // view_data.c
            break;
        case 2:
            yellow();
            printf("Enter Reg.No\n");
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
    int flag = 0;
    char fname_choice[20];
    printf("\nSelect Stream:");
    printf("\n-----------------");

    if (mt_file("files/filelist.txt"))
        printf("\nNo Data Available");
    else
    {
        fp = fopen("files/filelist", "r");
        stream_list *filename = (stream_list *)malloc(sizeof(stream_list));
        rewind(fp);
        fread(filename, sizeof(stream_list), 1, fp);
        while (!feof(fp))
        {
            printf("\n%s", filename->path);
            fread(filename, sizeof(stream_list), 1, fp);
        }
        int ch = 1;
        while (ch == 1)
        {
            printf("\n>");
            fflush(stdin);
            fgets(fname_choice, sizeof(fname_choice), stdin); // input from the user
            rewind(fp);
            while (!feof(fp) && flag == 0) // checking if user input is vaild
            {
                if (strcmp(fname_choice, filename->path) == 0)
                    flag = 1;
                else
                    fread(filename, sizeof(stream_list), 1, fp);
            }
            if (flag == 1)
                break;
            else
            {
                printf("\nWrong input");
                printf("\nPress 1 to enter again...Press any key to go back");
                printf("\n>");
                fflush(stdin);
                scanf("%d", &ch);
            }
        }
        free(filename);
        fclose(fp);
    }

    if (flag == 1)
    {
        FILE *fp2 = fopen(fname_choice, "r");
        student_data *data = (student_data *)malloc(sizeof(student_data));
        printf("\nReg.no      Name      Stream      Semester     Year    Total Marks    Grade");
        rewind(fp2);
        fread(data, sizeof(student_data), 1, fp2);
        while (!feof(fp2))
        {
            printf("%ld    %s    %s    %s  %s    %d %c", data->reg_no, data->name, data->stream, data->sem, data->year, data->marks, data->grade);
            fread(data, sizeof(student_data), 1, fp2);
        }
        fclose(fp2);
        free(data);
    }
}
