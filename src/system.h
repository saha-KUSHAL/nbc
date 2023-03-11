#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

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
    int year;
    int marks;
    char grade;
} student_data;
typedef struct student_personal_details{
    long int reg_no;
    char name[50],f_name[50],m_name[50];
    struct address{
        char vill[30],po[30],ps[30],dist[20],state[20];
        int pin;
    }
}std_per_det;
typedef struct student_edu_details{
    char course[10],inst[30],board[10],start_date[9],end_date[9];
    int marks;
    float persntg;
}std_edu_det;
typedef struct student_scholership_data{
    char schlr_name[100],auth[100],date[9],
}

typedef struct request_data
{
    char reqstr[1000];
    long int regno;
}req_data;

void logo();//logo
void black(); // text colors
void red();
void green();
void yellow();
void blue();
void purple();
void cyan();
void white();
void reset();
void c_printf(char s[]);

void admin();
void student();

test login();           // login function
int mt_file(char s[]); // function to check a file is empty or not.
void edit_data();
void view_data();                    // admin func
void stream();                       // prints whole sem data
void search_student_data(long int);          // prints student data by reg.no
void delete_student_data(long int);          // deletes student data by reg.no
void modify_student_data(long int);          // modifies student data by reg.no
void manage_data();                  // admin func
void create_data();                  // manage_data func
void add_request();
void view_request();
void add_path(char [],char []);
void add_stream(char []);
void printsdata(student_data *);
#endif
