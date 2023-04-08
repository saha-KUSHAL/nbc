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
/* WIll nuke this function later*/
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
void clrbuf(){
    while((getchar()) != '\n');  //a dummy getchar() takes all the buffer contains untill it takes enter key
}

//Function take a file pointer and return the size of that file
int fsizeof(FILE *fp){
    int size=0;
    fseek(fp,0,SEEK_END);   //takes the file cursor to the end
    size = ftell(fp);       //ftell returns the cursor position in terms of the bytes
    return size;
}
void bubblesort(FILE *fp){
    char key[50];
    int i,j,n;
    std_data * det = (std_data *)malloc(sizeof(std_data));
    std_data * det1 = (std_data *)malloc(sizeof(std_data));
    std_data * temp = (std_data *)malloc(sizeof(std_data));
    n=(fsizeof(fp)/sizeof(std_data));
    rewind(fp);
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            fread(det,sizeof(std_data),1,fp);
            fread(temp,sizeof(std_data),1,fp);
            if(strcmp((det->data->adhar),(det1->data->adhar))==1){
                temp=det1;
                det1=det;
                det=temp;
            }
        }
    }
    free(det);
    free(det1);
    free(temp);
}