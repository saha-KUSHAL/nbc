#include "system.h"

student_data *data;
void search_student_data(long int no)
{
    FILE *fp = fopen("files/student.dat", "r");
    if (fopen("files/student.dat", "r") == NULL)
    {
        red();
        printf("\nError!");
        reset();
    }
    else if (mt_file("files/student.dat"))
    {
        red();
        printf("\nNo Data.");
        reset();
    }
    else
    {
        data = (student_data *)malloc(sizeof(student_data));
        rewind(fp);  
        fread(data, sizeof(student_data), 1, fp);
        while (!feof(fp))
        {
            if (data->reg_no == no)
            {
                printf("\nReg no.              Name.           Stream         Semester");
                printf("\n%12ld           %10s       %4s      %s", data->reg_no, data->name, data->stream, data->sem);
            }
                fread(data, sizeof(student_data), 1, fp);
        }
        free(data);
    }
    fclose(fp);
}