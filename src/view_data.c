#include "system.h"
void view_data()
{
    int ch = 3;
    long int regno;
    while (ch != 0)
    {
        system(CLEAR);
        yellow();
        c_printf("--VIEW DATA--");
        blue();
        printf("\n----------\t\t\t------------\t\t\t-----------------\t\t\t-----------");
        printf("\n|(1)By Stream|\t\t\t|(2)By Reg.No|\t\t\t|(3)View Requests|\t\t\t|(0)Go Back|");
        printf("\n----------\t\t\t------------\t\t\t-----------------\t\t\t------------");
        reset();
        printf("\n>");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            stream(); // view_data.c
            break;
        case 2:{
            char ex;
            system(CLEAR);
            yellow();
            printf("Enter Reg.No\n");
            reset();
            printf("\n>");
            fflush(stdin);
            scanf("%12ld", &regno);
            search_student_data(regno); // search_sudent_data.c
            green();
            printf("\nPress any key to go back");
            reset();
            while((getchar())!='\n');
            scanf("%c",&ex);
            break;
        }
        case 3:
            view_request();//request.c
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
    char ex;
    if (mt_file("files/streamlist.txt")){
        system(CLEAR);
        red();
        c_printf("No Data Available");
        green();
        printf("\nPress any key to go back");
        reset();
        printf("\n>");
        while((getchar())!='\n');
        scanf("%c",&ex);
    }
    else
    {
        char path[30]="files/",stream[10],stmin[10];
        fp = fopen("files/streamlist.txt", "r");
        while (1){
            printf("\n\nStream List:");
            printf("\n-----------------");
            rewind(fp);

            fread(stream, 10, 1, fp);
            while (!feof(fp)){//displaing all the availabel streams
                printf("\n%s",stream);
                fread(stream,10,1,fp);
            }
            fclose(fp);
            printf("\n>");
            while ((getchar()) != '\n');
            scanf("%s",stmin); // input from the user
            add_path(path,stmin);
            printf("\n%s",path);
            fp=fopen(path,"r");
            if(fp==NULL)
                printf("\nWrong Filename");
            else{
                student_data *data=malloc(sizeof(student_data));
                rewind(fp);
                fread(data,sizeof(student_data),1,fp);
                printf("\nReg no    Name    Stream    Sem    Marks    Grade    Year");
                while(!feof(fp)){
                    printf("\n%ld  %s  %s  %s  %d  %c  %d",data->reg_no,data->name,data->stream,data->sem,data->marks,data->grade,data->year);
                    fread(data,sizeof(student_data),1,fp);
                }
                free(data);
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
