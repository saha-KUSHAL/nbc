#include "system.h"
void add_request()
{
    char ch = 'N';
    while ((toupper(ch))!='Y')
    {
        FILE *fp;
        req_data *req = malloc(sizeof(req_data));
        printf("\nEnter You reg no:");
        scanf("%d", &req->regno);
        printf("\nType your request(Within 1000 charecters)");
        printf("\n>");
        while((getchar())!='\n');
        fgets(req->reqstr, sizeof(req), stdin);
        system(CLEAR);
        printf("\nYour request is:");
        printf("\n\"%s\"",req->reqstr);
        printf("\nPress \"Y\" to confirm.");
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
    
}