#include "system.h"
void add_request()
{
    char ch = 'N';
    while ((toupper(ch))!='Y')
    {
        FILE *fp;
        req_data *req = malloc(sizeof(req_data));
        printf("\nEnter You reg no:");
        scanf("%ld", &req->regno);
        printf("\nType your request(Within 1000 charecters)");
        printf("\n>");
        while((getchar())!='\n');
        fgets(req->reqstr, sizeof(req->reqstr), stdin);
        system(CLEAR);
        printf("\nYour request is:");
        printf("\n\"%s\"",req->reqstr);
        printf("\nPress \"Y\" to confirm.");
        while((getchar())!='\n');
        scanf("%c",&ch);

        if(mt_file("files/request.bin"))
            fp=fopen("files/request.bin","w");
        else
            fp=fopen("files/request.bin","a");
        fwrite(req,sizeof(req_data),1,fp);
        fclose(fp);
        free(req);
    }
}
void view_request()
{
    short int ch=0;
    while(ch!=1){
        FILE *fp;
        req_data *req=malloc(sizeof(req_data));
        fp=fopen("files/request.bin","r");
        rewind(fp);
        fread(req,sizeof(req_data),1,fp);
        while(!feof(fp)){
            printf("\n%ld",req->regno);
            printf("\v%s",req->reqstr);
            fread(req,sizeof(req_data),1,fp);
        }
        fclose(fp);
        free(req);
        printf("\nPress 1 to go back.");
        while((getchar())!='\n');
        scanf("%hd",&ch);
    }
}