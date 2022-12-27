#include "system.h"

void admin()
{
  test value=login();
  while (value == pass)
  {
    int ch;
    printf("\n");
    red();
    c_printf("--ADMIN PANEL--");
    green();
    printf("\n--------------\t\t\t----------------");
    printf("\n|(1)View Data|\t\t\t|(2)Manage Data|");
    printf("\n--------------\t\t\t----------------");
    printf("\n--------------\t\t\t  ---------");
    printf("\n|(3)Settings|\t\t\t  |(0)Exit|");
    printf("\n--------------\t\t\t  ---------");
    reset();
    printf("\n>");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      view_data();
      break;
    case 2:
      manage_data();
      break;
    case 3:
      //  settings();
      break;
    case 0:
      exit(0);
    }
  }
}
