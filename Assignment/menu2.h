#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Quan_Ly_Lich_Thi_Dau
{
    char tran[256]; // khai báo biến Trận
    char ngay_thi_dau[256];
    char gio_thi_dau[256];
    char san_thi_dau[256];
};
struct Quan_Ly_Lich_Thi_Dau lichthidau[256];

int m;

void menu2_2();
void menu2_1();
void menu2();

void menu2()
{
    int choice;
    while (1)
    {
        system("cls");
        printf("====================================");
        printf("\n\n Quản lý lịch thi đấu");
        printf("\n\n1. Xem lịch thi đấu");
        printf("\n2. Tạo lịch thi đấu");
        printf("\n0. Trở về menu chính");
        printf("\n\n#Chọn: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 2:
            menu2_2();
            getchar();
            break;
        case 1:
            menu2_1();
            getchar();
            break;
        case 0:
            system("cls");
            Mainmenu();
            break;
        default:
            printf("\n\nNhập sai, vui lòng nhập lại từ 0-2");
            printf("\n\n");
            break;
        }
    }
}

void menu2_2()
{

    int i = 0;
    char choice;
    FILE *fp;

    while (1)
    {
        system("cls");
        printf("========= Tạo lịch thi đấu ==========");

        printf("\n\nTrận: ");
        fflush(stdin);
        scanf("%[^\n]s", &lichthidau[i].tran);

        printf("\nNgày thi đấu: ");
        fflush(stdin);
        scanf("%[^\n]s", &lichthidau[i].ngay_thi_dau);

        printf("\nGiờ thi đấu: ");
        fflush(stdin);
        scanf("%[^\n]s", &lichthidau[i].gio_thi_dau);

        printf("\nSân thi đấu: ");
        fflush(stdin);
        scanf("%[^\n]s", &lichthidau[i].san_thi_dau);
        i++;
        m = i;

        printf("\nBạn có muốn tiếp tục? YES( phím bất kì ) hoặc NO( phím n) : ");
        fflush(stdin);
        scanf("%c", &choice);
        if (choice == 'n')
        {
            fp = fopen("VL2018Schedule.dat", "w+");
            fwrite(lichthidau, sizeof(struct Quan_Ly_Lich_Thi_Dau), m, fp);

            fclose(fp);
            break;
        }
    }
}

void menu2_1()
{
    FILE *fp;
    fp = fopen("VL2018Schedule.dat", "r");
    fread(lichthidau, sizeof(struct Quan_Ly_Lich_Thi_Dau), m, fp);
    system("cls");
    printf("========== Xem lịch thi đấu ==========");

    for (int i = 0; i < m; i++)
    {

        printf("\nTrận %d : %s", i + 1, lichthidau[i].tran);
        printf("\nNgày thi đấu: %s", lichthidau[i].ngay_thi_dau);
        printf("\nGiờ thi đấu: %s", lichthidau[i].gio_thi_dau);
        printf("\nSân thi đấu: %s", lichthidau[i].san_thi_dau);
        printf("\n\n");
    }

    printf("\n\n\n\nNhấn Enter để quay lại");
    getchar();
    fclose(fp);
}