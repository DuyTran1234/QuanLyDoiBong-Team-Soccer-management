#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Bang_Xep_Hang
{
    char ma_doi[256];
    char ten_doi[256];
    int win;
    int draw;
    int lose;
    int tran;
    int point;
};

struct Bang_Xep_Hang bxh[256];

int q;

void menu4_1();
void menu4_2();
void menu4();
void menu4()
{
    int choice;
    while (1)
    {
        system("cls");
        printf("================================");
        printf("\n\n1. Nhập số trận thắng thua của mỗi đội");
        printf("\n2. Bảng xếp hạng");
        printf("\n0. Quay về menu chính");
        printf("\n\n#Chọn: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            menu4_1();
            getchar();
            break;
        case 2:
            menu4_2();
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

void menu4_1()
{
    int i = 0;
    char choice;
    while (1)
    {
        system("cls");

        do
        {
            printf("Nhập mã đội: ");
            fflush(stdin);
            scanf("%[^\n]s", &bxh[i].ma_doi);
            if (strlen(bxh[i].ma_doi) > 6)
            {
                printf("Nhập quá 6 ký tự, vui lòng nhập lại\n");
                continue;
            }
        } while (strlen(bxh[i].ma_doi) > 6);

        do
        {
            printf("\nNhập tên đội: ");
            fflush(stdin);
            scanf("%[^\n]s", &bxh[i].ten_doi);
            if (strlen(bxh[i].ten_doi) > 30)
            {
                printf("Nhập quá 30 ký tự, vui lòng nhập lại\n");
            }
        } while (strlen(bxh[i].ten_doi) > 30);


        do
        {
        printf("\nSố trận thắng của đội %s: ", bxh[i].ten_doi);
        fflush(stdin);
        scanf("%d", &bxh[i].win);
        if (bxh[i].win > 100 || bxh[i].win <0)
        {
            printf("Nhập quá 2 ký tự hoặc số trận thắng nhỏ hơn 0, vui lòng nhập lại\n");
            continue;
        }
        } while (bxh[i].win > 100 || bxh[i].win <0 );

        do
        {
        printf("\nSố trận hòa của đội %s: ", bxh[i].ten_doi);
        fflush(stdin);
        scanf("%d", &bxh[i].draw);
        if (bxh[i].draw >100 || bxh[i].draw <0)
        {
            printf("Nhập quá 2 ký tự hoặc số trận hòa nhỏ hơn 0, vui lòng nhập lại\n");
            continue;
        } 
        } while (bxh[i].draw >100 || bxh[i].draw <0);


        do
        {
        printf("\nSố trận thua của đội %s: ", bxh[i].ten_doi);
        fflush(stdin);
        scanf("%d", &bxh[i].lose);
        if (bxh[i].lose > 100 || bxh[i].lose <0 )
        {
            printf("Nhập quá 2 ký tự hoặc số trận thua nhỏ hơn 0, vui lòng nhập lại\n");
        }

        }while (bxh[i].lose > 100 || bxh[i].lose <0);

        bxh[i].tran = bxh[i].win + bxh[i].draw + bxh[i].lose;
        bxh[i].point = bxh[i].win * 3 + bxh[i].draw * 1;
        printf("\nTổng số trận đã đá của đội %s là: %d", bxh[i].ten_doi, bxh[i].tran);
        printf("\n\nTổng điểm của đội %s là: %d", bxh[i].ten_doi, bxh[i].point);

        i++;
        q = i;

        printf("\nBạn có muốn tiếp tục? YES( phím bất kì ) hoặc NO( phím n) : ");
        fflush(stdin);
        scanf("%c", &choice);

        if (choice == 'n')

        {
            break;
        }
    }
}

void menu4_2()
{
    int max;
    system("cls");

    for (int i = 0; i < q - 1; i++)
    {
        max = i;

        for (int j = i + 1; j < q; j++)
        {
            if (bxh[max].point < bxh[j].point)
            {
                max = j;
            }
        }
        if (max != i)
        {
            int temp1 = bxh[max].point;
            bxh[max].point = bxh[i].point;
            bxh[i].point = temp1;

            int temp2 = bxh[max].tran;
            bxh[max].tran = bxh[i].tran;
            bxh[i].tran = temp2;

            int temp3 = bxh[max].win;
            bxh[max].win = bxh[i].win;
            bxh[i].win = temp3;

            int temp4 = bxh[max].draw;
            bxh[max].draw = bxh[i].draw;
            bxh[i].draw = temp4;

            int temp5 = bxh[max].lose;
            bxh[max].lose = bxh[i].lose;
            bxh[i].lose = temp5;

            char temp6[500];
            strcpy(temp6, bxh[max].ma_doi);
            strcpy(bxh[max].ma_doi, bxh[i].ma_doi);
            strcpy(bxh[i].ma_doi, temp6);

            char temp7[500];
            strcpy(temp7, bxh[max].ten_doi);
            strcpy(bxh[max].ten_doi, bxh[i].ten_doi);
            strcpy(bxh[i].ten_doi, temp7);
        }
    }

    printf("\n BẢNG XẾP HẠNG: ");
    printf("\n\n================================================================================");
    printf("\n|Mã Đội|           Tên Đội            | Trận | Thắng | Hòa | Thua | Điểm |");
    printf("\n\n================================================================================");

    for (int i = 0; i < q; i++)
    {
        printf("\n|%-6s|%-30s| %-5d| %-6d|%-5d|%-6d| %-5d|", bxh[i].ma_doi, bxh[i].ten_doi, bxh[i].tran, bxh[i].win, bxh[i].draw, bxh[i].lose, bxh[i].point);
        printf("\n");
    }
    printf("\n\n\n\nNhấn Enter để quay lại");
    getchar();
}
// cái căn lề chưa đc
// có lỗi nào tí liệt kê lại cho anh