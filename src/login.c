#include "system.h"

void create_login()
{

    details *data; // pointer variable of details structure
    data = (details *)malloc(sizeof(details));
    FILE *fp;
    if (mt_file("files/user.dat"))
    {
        fp = fopen("files/user.dat", "w");
    }
    else
    {
        fp = fopen("files/user.dat", "a");
    }
    printf("\nEnter User Name:");
    fflush(stdin);
    fgets(data->id, sizeof(data->id), stdin);
    printf("\nCreate a Password:");
    fflush(stdin);
    fgets(data->password, sizeof(data->password), stdin);
    fwrite(data, sizeof(details), 1, fp);
    fclose(fp);
    free(data);
}

test login()
{
    if (mt_file("files/user.dat")) // cheking if there is data or not;
    {
        int n;
        printf("\nNo Admin Found.");
        printf("\nCreate an admin:");
        printf("\nPress 1 to create an admin account.\nPress any key to go back.\n>");
        if (scanf("%d", &n) == 1)
        {
            create_login();
            return pass;
        }
        else
            return fail; // have to chnage this.
    }
    else
    {
        char ch = 'Y';
        details *data = (details *)malloc(sizeof(details));
        entered_data *input = (entered_data *)malloc(sizeof(entered_data));

        FILE *fp = fopen("files/user.dat", "r");
        while (ch != 'N')
        {
            int flag = 0;
            printf("\nEnter User Name:");
            fflush(stdin);
            fgets(input->id,sizeof(input->id),stdin);

            printf("\nEnter Password:");
            fflush(stdin);
            fgets(input->id,sizeof(input->password),stdin);
            rewind(fp);
            fread(data, sizeof(details), 1, fp);

            while (!feof(fp) && ch != 'N')
            {
                if (strcmp(input->id, data->id) == 0 && ch != 'N')
                {
                    flag = 1;
                    if (strcmp(input->password,data->password) == 0)
                    {
                        printf("\nAuthorization Sucessfull.");
                        ch = 'Y';
                        return pass;
                    }
                    else
                    {
                        printf("\nPassword didn't match.");
                        printf("\nWant to retry ? (Y/n)");
                        fflush(stdin);
                        ch = toupper(getc(stdin));
                        break;
                    }
                }
                else
                    fread(data, sizeof(details), 1, fp);
            }
            if (flag == 0)
            {
                red();
                printf("\nUser not Found.Try again...");
                reset();
            }
        }
        free(input);
        free(data);
        fclose(fp);
    }
    return fail;
}
