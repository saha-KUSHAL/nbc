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
            while((getchar())!= '\n');//clearing the buffer
            getchar();//for holding the screen
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
    if (mt_file("files/streamlist.txt")){//checking if there is any stream availble or not
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
            printf("\n\nStream List:");
            printf("\n-----------------");
            rewind(fp);
            fread(stream, 10, 1, fp);
            while (!feof(fp)){      //displaing all the available streams
                printf("\n%s",stream);
                fread(stream,10,1,fp);
            }
            fclose(fp);
            printf("\n>");
            while ((getchar()) != '\n');        //clearing the buffer
            scanf("%s",stmin);      // input from the user
            add_path(path,stmin);    //creating a path string using stream, ex- files/stream.dat from "stream"
            fp=fopen(path,"r");
            if(fp==NULL)
                printf("\nWrong Filename");
            else{
                student_data *data=malloc(sizeof(student_data));
                rewind(fp);
                fread(data,sizeof(student_data),1,fp);
                blue();
				printf("\nReg. No    \tName          \tStream\tSem\tYear\tMarks\tGrade");
                reset();
                while(!feof(fp)){                           //printing the whole data except reg no == 0 as
                    if(data->reg_no!= 0)                    //they are treated as deleted logs
                        printsdata(data);                       
                    fread(data,sizeof(student_data),1,fp);
                }
                free(data);
            }
        fclose(fp);
    }
}
int pending(){
    FILE * fp = fopen("files/pending.dat","r");
    std_data * det;
    char input[50];
    if(fp == NULL)
        printf("\nFile can't be opened.");
        return 0;
    c_printf("--Pending Students--");
    /*Reading data from the file and printing name and ADHAR card only.
    User can input name or ADHAR which is the key for printing whole stdudent data.*/
    rewind(fp);
    fread(det,sizeof(std_data),1,fp);
    while(!feof(fp)){
        printf("\n%s%s",det->data->name,det->data->adhar);
        fread(det,sizeof(std_data),1,fp);
    }
    printf("Enter Name or Adhar:");
    clrbuf();
    fgets(input,sizeof(input),stdin);
    rewind(fp);
    fread(det,sizeof(std_data),1,fp);
    //Binary search implementaion(WIP)
    while(!foef(fp)){
        if((strcmp(input,det->data->name) > 0 )|| (strcmp(input,det->data->adhar)> 0))
            //logic here
        if((strcmp(input,det->data->name) < 0 )|| (strcmp(input,det->data->adhar)< 0))
            //logic here
        if((strcmp(input,det->data->name) == 0 )|| (strcmp(input,det->data->adhar)== 0))
            //logic here
    }
}