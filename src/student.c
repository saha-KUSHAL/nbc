// function to store student marks by stream and semester
#include "system.h"
void create_data()
{
    char ch = 'Y';
    student_data *data = (student_data *)malloc(sizeof(student_data));
    c_printf("--ADD NEW DATA--");
   /*when we are adding new student data, we will add marks too by  add_marks fucntion.
    which will create files with name concating stream and sem names.*/
   /* if (fopen("files/student.dat", "r") == NULL)
        fp = fopen("files/student.dat", "w");
    else
        fp = fopen("files/student.dat", "a");*/
    while (toupper(ch) == 'Y')
    {
        printf("\nEnter Student Reg no:");
        fflush(stdin);
        scanf("%ld", &data->reg_no);
        printf("Enter Student Name:");
        fflush(stdin);
        fgets(data->name, sizeof(data->name), stdin);
        printf("Enter Student Stream:");
        fflush(stdin);
        fgets(data->stream,sizeof(data->stream), stdin);
        printf("Enter Student Sem:");
        fflush(stdin);
        fgets(data->sem,sizeof(data->sem),stdin);
       	printf("Enter marks of subject 1:");
        fwrite(data, sizeof(student_data), 1, fp);
        printf("\nDo you want to add more ?(Y/n)");
        fflush(stdin);
        ch=getc(stdin);   
