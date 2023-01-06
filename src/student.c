#include"system.h"
void student()
{
	short int ch;
	test key= pass;
	while(key)
	{
	system(CLEAR);
	purple();
	c_printf("--Student Panel--");
    green();
    printf("\n-----------------\t\t------------\t\t\t---------");
    printf("\n|(1)View Details|\t\t|(2)Request|\t\t\t|(0)EXIT|");
    printf("\n-----------------\t\t------------\t\t\t---------");
	reset();
	printf("\n>");
	scanf("%hd",&ch);
	while((getchar())!='\n');
	switch(ch){
		case 1:{
			long int regno;
			system(CLEAR);
            yellow();
			c_printf("--View Student Details--");
            reset();
            printf("Enter Reg.No\n");
			printf("\n>");
            fflush(stdin);
            scanf("%12ld", &regno);
            search_student_data(regno); // search_sudent_data.c
            break;
		}
		case 2:
			system(CLEAR);
			add_request();
			break;
		case 0: 
			key=fail;
			break;
		default: 
			printf("\nWrong input");
		}
	}
	system(CLEAR);
}