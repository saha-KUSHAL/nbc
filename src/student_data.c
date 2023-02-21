#include "system.h"

void create_data() // function to store student marks by stream and semester
{
	short int sub[10], n, i;
	int mark = 0;
	char ch = 'Y';
	FILE *fp;
	student_data *data = (student_data *)malloc(sizeof(student_data));
	system(CLEAR);
	yellow();
	c_printf("--Add Student Data--");
	reset();
	while (toupper(ch) == 'Y')
	{
		char path[31] = "files/";		
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

		add_stream(data->stream);
		add_path(path,data->stream);
		if(mt_file(path))
			fp=fopen(path,"w");
		else
			fp=fopen(path,"a");
		fwrite(data,sizeof(student_data),1,fp);
		free(data);
		fclose(fp);
		printf("\nDo you want to add more ?(Y/n)");
		while ((getchar()) != '\n');
		ch = getc(stdin);
	}
}
void printsdata(student_data *data){
	printf("\n%ld\t%s\t%s\t%s\t%d\t%d\t%c",data->reg_no,data->name,data->stream,data->sem,data->year,data->marks,data->grade);
}		
void search_student_data(long int no){
	FILE *fp;
	char stm[10];
	int ch=0;
	fp = fopen("files/streamlist.txt", "r");
	rewind(fp);
	fread(stm, 10, 1, fp);
	while (!feof(fp) && ch == 0){
		char path[30]="files/";
		add_path(path,stm);
		FILE *fp2 = fopen(path, "r");
		student_data *data = (student_data *)malloc(sizeof(student_data));
		rewind(fp2);
		fread(data, sizeof(student_data), 1, fp2);
		while (!feof(fp2) && ch == 0)
		{	if (data->reg_no != 0 && data->reg_no == no){
				blue();
				printf("\nReg. No    \tName          \tStream\tSem\tYear\tMarks\tGrade");
				reset();
				printsdata(data);
				ch=1;
			}
			else
				fread(data, sizeof(student_data), 1, fp2);
		}
		fclose(fp2);
		free(data);
		fread(stm, 10, 1, fp);
	}
	if (ch == 0)
		printf("\nData not available!");
	fclose(fp);
}
void delete_student_data(long int no){
	FILE *fp;
	char stm[10];
	int ch=0;
	fp = fopen("files/streamlist.txt", "r");
	rewind(fp);
	fread(stm, 10, 1, fp);
	while (!feof(fp) && ch == 0){
		char path[30]="files/";
		add_path(path,stm);
		FILE *fp2 = fopen(path, "r+");
		if(fp2 != NULL){
			student_data *data = (student_data *)malloc(sizeof(student_data));
			rewind(fp2);
			fread(data, sizeof(student_data), 1, fp2);
			while (!feof(fp2) && ch == 0)
			{	
				if (data->reg_no != 0 && data->reg_no == no){
					blue();
					printf("\nReg. No    \tName          \tStream\tSem\tYear\tMarks\tGrade");
					reset();
					printsdata(data);
					red();
					printf("\nPress 1 to confirm:");
					reset();
					scanf("%d", &ch);
					//while ((getchar()) != '\n');
					if (ch == 1)
					{
						data->reg_no = 0;
						fseek(fp2, -(sizeof(student_data)), SEEK_CUR);
						fwrite(data, sizeof(student_data), 1, fp2);
						green();
						printf("\nData deleted sucessfully.\n");
						reset();
					}
					ch = 1;
				}
				else
					fread(data, sizeof(student_data), 1, fp2);
			}
			free(data);
		}
		else
			printf("File Error!");
		fclose(fp2);
		fread(stm, 10, 1, fp);
	}
	fclose(fp);
	if (ch == 0)
		printf("\nData not available!");
}
void modify_student_data(long int no){
	FILE *fp;
	char stm[10];
	int ch=0;
	fp = fopen("files/streamlist.txt", "r");
	rewind(fp);
	fread(stm, 10, 1, fp);
	while (!feof(fp) && ch == 0){
		char path[30]="files/";
		add_path(path,stm);
		FILE *fp2 = fopen(path, "r+");
		if(fp2 != NULL){
			student_data *data = (student_data *)malloc(sizeof(student_data));
			rewind(fp2);
			fread(data, sizeof(student_data), 1, fp2);
			while (!feof(fp2) && ch == 0)
			{	
				if (data->reg_no != 0 && data->reg_no == no){
					blue();
					printf("\nReg. No    \tName          \tStream\tSem\tYear\tMarks\tGrade");
					reset();
					printsdata(data);
					red();
					printf("\nPress 1 to confirm:");
					reset();
					scanf("%d", &ch);
					if (ch == 1){
						short int sub[10], n, i,ch;
						int mark =0;
						printf("\nWhich Data you want to modify?");
						printf("\n1:Name\t2:Stream\t3:Sem\t4:Year\t5:Marks");
						printf("\n>");
						scanf("%hd",&ch);
					    while ((getchar()) != '\n');
						switch(ch){
							case 1:
								printf("\nEnter name:");
								scanf("%49[^\n]",data->name);
							break;
							case 2:
								printf("\nEnter Stream:");
								scanf("%s",data->stream);
							break;
							case 3:
								printf("\nEnter Sem:");
								scanf("%s",data->sem);
							break;
							case 4:
								printf("Enter Year:");
								scanf("%d",&data->year);
							break;
							case 5:
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
							break;
							dafault:
									printf("\nChoose an Correct Option\v0 For exit");
						}
						fseek(fp2, -(sizeof(student_data)), SEEK_CUR);
						fwrite(data, sizeof(student_data), 1, fp2);
						green();
						printf("\nData Modified sucessfully.\n");
						reset();
					}
					ch = 1;
				}
				else
					fread(data, sizeof(student_data), 1, fp2);
			}
			free(data);
		}
		else
			printf("File Error!");
		fclose(fp2);
		fread(stm, 10, 1, fp);
	}
	fclose(fp);
	if (ch == 0)
		printf("\nData not available!");
}
