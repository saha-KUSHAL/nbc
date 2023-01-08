#include "system.h"

void create_data() // function to store student marks by stream and semester
{
	short int sub[10], n, i;
	char ch = 'Y';
	FILE *fp, *fp2;
	student_data *data = (student_data *)malloc(sizeof(student_data));
	system(CLEAR);
	yellow();
	c_printf("--Add Student Data--");
	reset();
	while (toupper(ch) == 'Y')
	{
		char path[30] = "files/";
		printf("\nEnter Student Reg no:");
		// while ((getchar()) != '\n');
		scanf("%12ld", &data->reg_no);
		printf("Enter Student Name:");
		while ((getchar()) != '\n');
		scanf("%49[^\n]", data->name);
		printf("Enter Student Stream:");
		while ((getchar()) != '\n');
		scanf("%s", data->stream);
		printf("Enter Student Sem(i to x):");
		while ((getchar()) != '\n');
		scanf("%s", data->sem);
		printf("Enter Admission Year:");
		while ((getchar()) != '\n');
		scanf("%d", &data->year);
		int mark = 0;
		printf("How many written subjects?");
		while ((getchar()) != '\n');
		scanf("%hd", &n);
		for (i = 0; i < n; i++)
		{
			printf("Enter marks of subject %d:",i + 1);
			while ((getchar()) != '\n');
			scanf("%hd", &sub[i]);
		}
		for (i = 0; i < n; i++)
			mark += sub[i];
		data->marks = mark;
		int tmarks = (mark / n);
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

		strcat(path, data->stream);
		strcat(path, data->sem);
		strcat(path, ".dat");

		if (mt_file("files/filelist.txt") == 1)
			fp2 = fopen("files/filelist.txt", "w");
		else
			fp2 = fopen("files/filelist.txt", "a");

		if (mt_file(path))
			fp = fopen(path, "w");
		else
			fp = fopen(path, "a");

		fwrite(data, sizeof(student_data), 1, fp);
		fwrite(path, 30, 1, fp2);
		fclose(fp);
		fclose(fp2);
		free(data);
		printf("\nDo you want to add more ?(Y/n)");
		while ((getchar()) != '\n');
		ch = getc(stdin);
	}
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
		char fname[30];
		fp = fopen("files/filelist.txt", "r");
		rewind(fp);
		fread(fname, 30, 1, fp);
		while (!feof(fp) && ch == 0)
		{
			if (mt_file(fname))
				fread(fname, 30, 1, fp);
			else
			{
				FILE *fp2 = fopen(fname, "r");
				student_data *data = (student_data *)malloc(sizeof(student_data));
				rewind(fp2);
				fread(data, sizeof(student_data), 1, fp2);
				while (!feof(fp2) && ch == 0)
				{
					if (data->reg_no != 0 && data->reg_no == no)
					{
						blue();
						printf("\nReg.no      Name      Stream      Semester     Year    Total Marks    Grade");
						reset();
						printf("\n%ld    %s    %s    %s  %d    %d %c", data->reg_no, data->name, data->stream, data->sem, data->year, data->marks, data->grade);
						red();
						printf("\nPress 1 to go back:");
						reset();
						while((getchar())!='\n');
						scanf("%d", &ch);
					}
					else
						fread(data, sizeof(student_data), 1, fp2);
				}
				fclose(fp2);
				free(data);
			}
			fread(fname, 30, 1, fp);
		}
		if (ch == 0)
			printf("\nData not available!");
		fclose(fp);
	}
}
void delete_student_data(long int no)
{
	// It modifes the reg no filed if found.The student data containg reg no as 0 is filtered out and
	// doesn't displayed anywhere.It helps to keep data to recover for further use.
	FILE *fp;
	int ch = 0;
	if (mt_file("files/filelist.txt"))
	{
		printf("\nError or File not available.");
	}
	else
	{
		char fname[30];
		fp = fopen("files/filelist.txt", "r");
		rewind(fp);
		fread(fname, 30, 1, fp);
		while (!feof(fp) && ch == 0)
		{
			if (mt_file(fname))
				fread(fname, 30, 1, fp);
			else
			{
				FILE *fp2 = fopen(fname, "r+");
				student_data *data = (student_data *)malloc(sizeof(student_data));
				rewind(fp2);
				fread(data, sizeof(student_data), 1, fp2);
				while (!feof(fp2) && ch == 0)
				{
					if (data->reg_no != 0 && data->reg_no == no)
					{
						blue();
						printf("\nReg.no      Name      Stream      Semester     Year    Total Marks    Grade");
						reset();
						printf("\n%ld    %s    %s    %s  %d    %d %c", data->reg_no, data->name, data->stream, data->sem, data->year, data->marks, data->grade);
						while ((getchar()) != '\n');
						red();
						printf("\nPress 1 to confirm:");
						reset();
						scanf("%d", &ch);
						if (ch == 1)
						{
							data->reg_no = 0;
							fseek(fp2, -(sizeof(student_data)), 1);
							fwrite(data, sizeof(student_data), 1, fp2);
							green();
							printf("\nData deleted sucessfully.");
							reset();
						}
						ch = 1;
					}
					else
						fread(data, sizeof(student_data), 1, fp2);
				}
				fclose(fp2);
				free(data);
			}
			fread(fname, 30, 1, fp);
		}
		if (ch == 0)
			printf("\nData not available!");
		fclose(fp);
	}
}

void modify_student_data(long int no)
{
	FILE *fp;
	int ch = 0;
	if (mt_file("files/filelist.txt"))
	{
		printf("\nError or File not available.");
	}
	else
	{
		char fname[30];
		fp = fopen("files/filelist.txt", "r");
		rewind(fp);
		fread(fname, 30, 1, fp);
		while (!feof(fp) && ch == 0)
		{
			if (mt_file(fname))
				fread(fname, 30, 1, fp);
			else
			{
				FILE *fp2 = fopen(fname, "r+");
				student_data *data = (student_data *)malloc(sizeof(student_data));
				rewind(fp2);
				fread(data, sizeof(student_data), 1, fp2);
				while (!feof(fp2) && ch == 0)
				{
					if (data->reg_no != 0 && data->reg_no == no)
					{
						blue();
						printf("\nReg.no      Name      Stream      Semester     Year    Total Marks    Grade");
						reset();
						printf("\n%ld    %s    %s    %s  %d    %d %c", data->reg_no, data->name, data->stream, data->sem, data->year, data->marks, data->grade);
						while ((getchar()) != '\n');
						red();
						printf("\nPress 1 to confirm:");
						reset();
						scanf("%d", &ch);
						if (ch == 1)
						{
							int n=1;
							while (n!=0)
							{
								printf("\nEnter which data you want to modify");
								printf("\n1.Name  2.Stream  3.Semester  4.Year  5.Enter marks");
								printf("\nEnter 0 to go back.");
								scanf("%d", &n);
								switch (n)
								{
								case 1:
									printf("Enter Student Name:");
									while ((getchar()) != '\n');
									scanf("%49[^\n]", data->name);
									break;
								case 2:
									printf("Enter Student Stream:");
									while ((getchar()) != '\n');
									scanf("%s", data->stream);
									break;
								case 3:
									printf("Enter Student Semseter:");
									while ((getchar()) != '\n');
									scanf("%s", data->sem);
									break;
								case 4:
									printf("Enter Student Year:");
									while ((getchar()) != '\n');
									scanf("%d", &data->year);
									break;
								case 5:
								{
									short int mark = 0,i,n,sub[10];
									printf("How many written subjects?");
									while ((getchar()) != '\n');
									scanf("%hd", &n);
									for (i = 0; i < n; i++)
									{
										printf("Enter marks of subject %d:", i + 1);
										while ((getchar()) != '\n');
										scanf("%hd", &sub[i]);
									}
									for (i = 0; i < n; i++)
										mark += sub[i];
									data->marks = mark;
									int tmarks = (mark / n);
									data->marks = mark;
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
								}
								break;
								case 0:
									break;
								default:
								{
									system(CLEAR);
									red();
									printf("Wrong input!");
									reset();
								}
								}
								system(CLEAR);
								green();
								printf("\nSaved");
								reset();
							}
							fseek(fp2, -(sizeof(student_data)), 1);
							fwrite(data, sizeof(student_data), 1, fp2);
							green();
							printf("\nData Modified sucessfully.");
							reset();
						}
						ch = 1;
					}
					else
						fread(data, sizeof(student_data), 1, fp2);
				}
				fclose(fp2);
				free(data);
			}
			fread(fname, 30, 1, fp);
		}
		if (ch == 0)
			printf("\nData not available!");
		fclose(fp);
	}
}