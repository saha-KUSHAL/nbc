#include "system.h"

void create_login()
{
    FILE *fp;
    if (mt_file("files/user.txt") == 1)
        fp = fopen("files/user.bin", "w");
    else
        fp = fopen("files/user.bin", "a");
    if (fp != NULL)
    {
        details *data = (details *)malloc(sizeof(details)); // pointer variable of details structure
        red();
        c_printf("--Create Account--");
        reset();
        printf("\nEnter User Name:");
        fflush(stdin);
        scanf("%s", data->id);
        printf("Create a Password:");
        fflush(stdin);
        scanf("%s", data->password);
        fwrite(data, sizeof(details), 1, fp);
        system(CLEAR);
        green();
        printf("Account Created Sucessfully !\n");
        reset();
        free(data);
        fclose(fp);
    }
    else{
        red();
        printf("\nError, cannot create file\n");
    }
    reset();
}

test login()
{
    if (mt_file("files/user.bin") == 1) // cheking if there is data or not;
    {
        int n;
        red();
        printf("\nNo Admin Found.");
        reset();
        green();
        printf("\nPress 1 to create an admin account.\nPress any key to go back.\n>");
        reset();
        scanf("%d", &n);
        fflush(stdin);
        if (n == 1)
            create_login();
        else
            return fail; // have to chnage this.
    }
    else
    {
        char ch = 'Y';
        details *data = (details *)malloc(sizeof(details));
        entered_data *input = (entered_data *)malloc(sizeof(entered_data));

        FILE *fp = fopen("files/user.bin", "r");
        while (toupper(ch) != 'N')
        {
            int flag = 0;
            short int n = 1;
            printf("\nEnter User Name:");
            fflush(stdin);
            scanf("%s", input->id);
            
            rewind(fp);
            fread(data, sizeof(details), 1, fp);

            while (!feof(fp) && toupper(ch) != 'N')
            {
                if (strcmp(input->id, data->id) == 0 && toupper(ch) != 'N'){
                    flag = 1;
                    while(n == 1){
                        printf("Enter Password:");
                        fflush(stdin);
                        scanf("%s", input->password);
                        if (strcmp(input->password, data->password) == 0){
                            system(CLEAR);
                            ch = 'Y';
                            free(input);
                            free(data);
                            fclose(fp);
                            return pass;
                        }
                        else{
                            red();
                            printf("\nPassword didn't match.");
                            blue();
                            printf("\nPress 1 to retry.");
                            reset();
                            printf("\n>");
                            scanf("%hd",&n);
                            fflush(stdin);
                        }
                    }
                    return fail;
                }
                else
                    fread(data, sizeof(details), 1, fp);
            }
            if (flag == 0)
            {
                red();
                printf("\nUser not Found.Press any key to Try again...\nPress 'N' to exit");
                reset();
                printf("\n>");
                while ((getchar()) != '\n');
                scanf("%c", &ch);
            }
        }
        free(input);
        free(data);
        fclose(fp);
    }
    return fail;
}
