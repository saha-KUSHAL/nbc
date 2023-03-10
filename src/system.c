#include "system.h"

void logo(){
    cyan();
    printf("                             _            _____   ______\n");
    printf("                            / /_       _ /_____/_/______/_\n");
    printf("                           / /_/_     /_/ ____/_/      /_/\n");
    blue();
    printf("                          / /  /_/_      /___/_\n");
    printf("                         / /     /_/_       / /       _\n");
    purple();
    printf("                        / /        / / ___ /_/______ /_/\n");
    printf("                       /_/        /_/ /___/  /______/\n\n");
    reset();
}
void black()
{
    printf("\033[0;30m");
}
void red()
{
    printf("\033[0;31m");
}
void green()
{
    printf("\033[0;32m");
}
void yellow()
{
    printf("\033[0;33m");
}
void blue()
{
    printf("\033[0;94m");
}
void purple()
{
    printf("\033[0;35m");
}
void cyan()
{
    printf("\033[0;36m");
}
void white()
{
    printf("\033[0;37m");
}
void reset()
{
    printf("\033[0;0m");
}
void c_printf(char s[])
{
    int width = 85;
    int pad = (strlen(s) >= width) ? 0 : (width - strlen(s)) / 2;
    printf("%*.*s%s\n", pad, pad, " ", s);
}
int mt_file(char s[]) // checks if the file is empty or not
{
    long int size = 0;
    /*checking is file exists or not.if file doesn't exist then fuction will return 1 or true.
    if file exists the measure it's size. If the file is empty then it will be 0 byte,
    hence function will return 1 or true,else it will return 0*/
    if (fopen(s, "r") != NULL)
    {
        FILE *fp;
        fp=fopen(s, "r");
        fseek(fp,0,SEEK_END);
        size = ftell(fp);
        rewind(fp);//to avoid mistake seek the file pointer to the start
        fclose(fp);
    }
    if (size == 0)
        return 1;
    else
        return 0;
}
void add_path(char str1[],char str[]){
    strcat(str1,str);
    strcat(str1,".dat");
}
void add_stream(char stream[]){
    FILE *fp=fopen("files/streamlist.txt","r");
    char exstm[10];
    int flag=0;
    if(fp==NULL)
        printf("\nFile Cannot be opened.");
    else{
        rewind(fp);
        fread(exstm,10,1,fp);
        while(!feof(fp)){
            if(strcmp(stream,exstm)==0){
                flag=1;
                break;
            }
            else
                fread(exstm,10,1,fp);
            
        }
        fclose(fp);
    }
    if(flag==0){
        if(mt_file("files/streamlist.txt"))
            fp=fopen("files/streamlist.txt","w");
        else
            fp=fopen("files/streamlist.txt","a");
        fwrite(stream,10,1,fp);
        fclose(fp);
    }
}
// int input(int uplimit){
//     int input;
//     ffflush(stdin);
//     if(input>=0 && input <=uplimit)
//         return input;
//     else
//         return (-1);
// }