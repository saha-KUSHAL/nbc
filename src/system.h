#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef enum state
{
    fail,
    pass
} test;

void c_printf(char s[]);
void admin();
test login();           // login function
bool mt_file(char s[]); // function to check a file is empty or not.
typedef struct details
{
    char id[10];
    char password[10];
} details;

typedef struct entered_data
{
    char id[10];
    char password[10];
} entered_data;

typedef struct student_data
{
    long int reg_no;
    char name[50];
    char stream[5];
    char sem[3];
	int marks;
	char grade;
} student_data;

void black(); // text colors
void red();
void green();
void yellow();
void blue();
void purple();
void cyan();
void white();
void reset();

void edit_data();
void view_data();//admin func
void stream();//prints whole sem data
void search_student_data();//prints student data by reg.no
void delete_student_data();//deletes student data by reg.no
void modify_student_data();//modifies student data by reg.no
void manage_data();//admin func
void create_data();//manage_data func

#endif
