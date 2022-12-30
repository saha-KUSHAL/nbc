#include "system.h"

void create_data()// function to store student marks by stream and semester
{
	short int sub[10], n, i;
	char ch = 'Y';
	char path[20];
	FILE *fp, *fp2;
	student_data *data = (student_data *)malloc(sizeof(student_data));
	stream_list *filename = (stream_list *)malloc(sizeof(stream_list));
	c_printf("--ADD NEW DATA--");
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
		fgets(data->stream, sizeof(data->stream), stdin);
		printf("Enter Student Sem:");
		fflush(stdin);
		fgets(data->sem, sizeof(data->sem), stdin);
		printf("Enter Admission Year:");
		fflush(stdin);
		fgets(data->year, sizeof(data->year), stdin);
		printf("How many written subjects?");
		fflush(stdin);
		scanf("%hd", &n);
		for (i = 0; i < n; i++)
		{
			printf("Enter marks of subject %d:", i + 1);
			fflush(stdin);
			scanf("%hd", &sub[i]);
		}
		data->marks = 0;
		for (i - 0; i < n; i++)
			data->marks += sub[i];

		int tmarks = (data->marks / n);
		if (tmarks >= 90)
			data->grade = 'O';
		else if (tmarks < 90 && tmarks >= 80)
			data->grade = 'E';
		else if (tmarks < 80 && tmarks >= 70)
			data->grade = 'A';
		else if (tmarks < 70 && tmarks >= 60)
			data->grade = 'B';
		else if (tmarks < 60 && tmarks >= 50)
			data->grade = 'C';
		else if (tmarks < 50 && tmarks >= 40)
			data->grade = 'D';
		else
			data->grade = 'F';
		concat(path, data->stream, data->sem);
		(fopen("files/filelist.txt", "r") == NULL) ? (fp2 = fopen("files/filelist.txt", "w")) : (fp2 = fopen("files/filelist.txt", "a"));
		(fopen(path, "r") == NULL) ? (fp = fopen(path, "w")) : (fp = fopen(path, "a"));
		fwrite(data, sizeof(student_data), 1, fp);
		strcpy(filename->path, path);
		fwrite(filename, sizeof(stream_list), 1, fp2);
		fclose(fp);
		fclose(fp2);
		printf("\nDo you want to add more ?(Y/n)");
		fflush(stdin);
		ch = getc(stdin);
	}
	free(data);
	free(filename);
}

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
        if(ch==0)
            printf("\nData not available!");
        fclose(fp);
        free(fname);
    }
}