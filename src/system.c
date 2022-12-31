#include "system.h"

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
    printf("\033[0;34m");
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
    if (fopen(s, "r") != NULL)
    {
        FILE *fp;
        fp=fopen(s, "r");
        rewind(fp);
        while (!feof(fp))
        {
            fgetc(fp);
            size++;
        }
        rewind(fp);
        fclose(fp);
    }
    if (size == 0)
        return 1;
    else
        return 0;
}
void concat(char a[], char b[], char c[])
{
    char path[] = ".dat";
    strcat(b, c);
    strcat(b, path);
    strcat("files/", b);
    strcpy(a, b);
}
