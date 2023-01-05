#include"system.h"
void student()
{
	short int ch;
	while(1)
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
	while((getchar())!='\n');
	scanf("%hd",&ch);
	switch(ch){
		case 1:
			long int regno;
			system(CLEAR);
            yellow();
            printf("Enter Reg.No\n");
            reset();
			printf("\n>");
            fflush(stdin);
            scanf("%ld", &regno);
            search_student_data(regno); // search_sudent_data.c
            break;
		case 2:
			system(CLEAR);
			add_request();
			break;
		case 0: 
			exit(0);
		default: 
			printf("\nWrong input");
		}
	}
}