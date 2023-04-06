#include "system.h"

void create_login(char typ[4])
{
    FILE *fp;
    if(strcmp(typ,"std")==0){
        log_crdls *data=(log_crdls *)malloc(sizeof(log_crdls));
        if(fopen("files/user_std.bin","r")== NULL) //checking if the file has not been created
            fp=fopen("files/user_std.bin","w"); //creating the file and opening in write mode
        else
            fp=fopen("files/user_std.bin","a"); //opening file in append mode
        printf("\nEnter Name:");
        fgets(data->name,sizeof(data->name),stdin);
        printf("\nEnter Username:");
        clrbuf();
        fgets(data->id,sizeof(data->id),stdin);
        printf("\nEnter Password:");
        clrbuf();
        fgets(data->password,sizeof(data->password),stdin);
        
    }
    else if (strcmp(typ,"adm"==0)){

    }
    else
        printf("\nThere may be a typo in login func call.");
}

test login(char typ[4]){
    if((strcmp(typ,"adm"))==0){ //admin login ui
        if(mt_file("files/user_admin.bin"))
            create_login("adm");
        else{
            FILE *fp = fopen("files/user_admin.bin","r");
            log_crdls *data_in=(log_crdls *)malloc(sizeof(log_crdls));
            log_crdls *data_chk=(log_crdls *)malloc(sizeof(log_crdls));
            printf("\nEnter Username:");
            clrbuf();
            fgets(data_in->id,sizeof(data_in->id),stdin);
            fread(data_chk,sizeof(log_crdls),1,fp);
            rewind(fp);
            while(!feof(fp)){
                if(strcmp(data_chk->id,data_in->id)==0){
                    while(1){
                        printf("\nEnter Password:");
                        clrbuf();
                        fgets(data_chk->password,sizeof(data_chk->password),stdin);
                        if(strcmp(data_chk->password,data_in->id)==0){
                            free(data_chk);
                            free(data_in);
                            return pass;
                        }
                        else{
                            short int ch;
                            red();
                            printf("\nWrong Password !");
                            green();
                            printf("\nPress 1 to Enter again.");
                            reset();
                            if(ch != 1)
                                break;
                        }
                        free(data_chk);
                        free(data_in);
                        return fail;
                    }
                }
                else
                    fread(data_chk,sizeof(log_crdls),1,fp);
            }
        }
    }
    if((strcmp(typ,"std"))==0){ // student login ui
if(mt_file("files/user_std.bin"))
            create_login("std");
        else{
            FILE *fp = fopen("files/user_std.bin","r");
            log_crdls *data_in=(log_crdls *)malloc(sizeof(log_crdls));
            log_crdls *data_chk=(log_crdls *)malloc(sizeof(log_crdls));
            printf("\nEnter Username:");
            clrbuf();
            fgets(data_in->id,sizeof(data_in->id),stdin);
            fread(data_chk,sizeof(log_crdls),1,fp);
            rewind(fp);
            while(!feof(fp)){
                if(strcmp(data_chk->id,data_in->id)==0){
                    while(1){
                        printf("\nEnter Password:");
                        clrbuf();
                        fgets(data_chk->password,sizeof(data_chk->password),stdin);
                        if(strcmp(data_chk->password,data_in->id)==0)
                            return pass;
                        else{
                            short int ch;
                            red();
                            printf("\nWrong Password !");
                            green();
                            printf("\nPress 1 to Enter again.");
                            reset();
                            if(ch != 1)
                                break;
                        }
                        return fail;
                    }
                }
                else
                    fread(data_chk,sizeof(log_crdls),1,fp);
            }
        }
    }
}