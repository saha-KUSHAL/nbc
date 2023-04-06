#include "system.h"

void admin()
{
  test key = login("adm");
  while (key)
  {
    int ch;
    system(CLEAR);
    red();
    c_printf("--ADMIN PANEL--");
    green();
    printf("\n\t--------------\t\t\t----------------");
    printf("\n\t|(1)View Data|\t\t\t|(2)Manage Data|");
    printf("\n\t--------------\t\t\t----------------");
    printf("\n\t--------------\t\t\t  ---------");
    printf("\n\t|(3)Settings|\t\t\t  |(0)Exit|");
    printf("\n\t--------------\t\t\t  ---------");
    reset();
    printf("\n>");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      view_data();//view_data.c
      break;
    case 2:
      manage_data();//manage_data.c
      break;
    case 3:
      printf("\nSettings Module not found\n");
      break;
    case 0:
      key=fail;
      break;
    default : 
        red();
        printf("\nWrong Input");
        reset();
    }
  }
  system(CLEAR);
}
