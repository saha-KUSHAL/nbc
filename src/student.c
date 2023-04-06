#include"system.h"
void student()
{
	short int ch;
	system(CLEAR);
	green();
		printf("\n\t\t-----------------\t\t------------");
		printf("\n\t\t|(1)Sign In|\t\t|(2)Sign Up|");
		printf("\n\t\t-----------------\t\t------------");
		reset();
	clrbuf();
	while(1){
		printf("\n>");
		scanf("%hd",&ch);
		if(ch==1){
			test key= login("std");
			if(key == pass)
				std_pnl;
			break;
		}
		else if(ch ==2){
			create_login("std");
			break;
		}
		else{
			red();
			printf("\nEnter Right Option.");
			reset();
		}
	}
}
//main student UX, need to work on...
void std_pnl(){
	short int key=1;
	while(key){
		short int ch;
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
			case 1:
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
				printf("\n>");
				while((getchar())!='\n');
				getchar();
				break;
			case 2:
				system(CLEAR);
				add_request();
				break;
			case 0:
				key=0;
				break;
			default: 
				printf("\nWrong input");
		}
	}
}
