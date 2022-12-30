#include "system.h"

student_data *data;
void search_student_data(long int no)
{
    FILE *fp;
    int ch = 0;
    if (mt_file("files/filelist.txt"))
    {
        printf("\nError or File not available.");
    }
    else
    {
        stream_list *fname = (stream_list *)malloc(sizeof(stream_list));
        fp = fopen("files/filelist.txt", "r");
        rewind(fp);
        fread(fname, sizeof(stream_list), 1, fp);
        while (!feof(fp) && ch == 0)
        {
            if (mt_file(fname->path))
                fread(fname, sizeof(stream_list), 1, fp);
            else
            {
                FILE *fp2 = fopen(fname->path, "r");
                student_data *data = (student_data *)malloc(sizeof(student_data));
                rewind(fp2);
                fread(data, sizeof(student_data), 1, fp2);
                while (!feof(fp2) && ch == 0)
                {
                    if (data->reg_no == no)
                    {
                        printf("\nReg.no      Name      Stream      Semester     Year    Total Marks    Grade");
                        printf("%ld    %s    %s    %s  %s    %d %c", data->reg_no, data->name, data->stream, data->sem, data->year, data->marks, data->grade);
                        ch = 1;
                    }
                    else
                        fread(data, sizeof(student_data), 1, fp2);
                }
                fclose(fp2);
                free(data);
            }
            fread(fname, sizeof(stream_list), 1, fp);
        }
        fclose(fp);
        free(fname);
    }
