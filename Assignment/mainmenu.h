
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu1.h"
#include "menu2.h"
#include "menu3.h"
#include "menu4.h"
int Mainmenu();

int Mainmenu()
{
    // {gcc -c func.c # generates the object file func.o
    // gcc -c main.c # generates the object file main.o
    // gcc func.o main.o -o main # generates the executable main

    int choice;
    while (1)
    {
        printf("--- Chào mừng đến với V-League 2018");
        printf("\n\n==================================");
        printf("\n1. Quản lý danh sách đội bóng");
        printf("\n2. Quản lý lịch thi đấu");
        printf("\n3. Quản lý kết quả thi đấu");
        printf("\n4. Bảng xếp hạng");
        printf("\n0. Thoát");
        printf("\n\n#Chọn: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            menu1();
            getchar();
            break;
        case 2:
            menu2();
            getchar();
            break;
        case 3:
            menu3();
            getchar();
            break;
        case 4:
            menu4();
            getchar();
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("\n\nNhập sai, vui lòng nhập lại từ 0-4");
            printf("\n\n");
            break;
        }
    }
}
