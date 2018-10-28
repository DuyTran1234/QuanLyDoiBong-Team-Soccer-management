#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Quan_Ly_Ket_Qua_Thi_Dau
{
    char nhap_tran[256]; // Nhập trận
    char doi_a[256];     // Đội A
    char doi_b[256];     // Đội B
    int g;               // số bàn thắng đội A
    int h;               // số bàn thắng đội B
};
struct Quan_Ly_Ket_Qua_Thi_Dau ketqua[256];
int p;

void menu3_2();
void menu3_1();
void menu3();


void menu3()
{

    int choice;
    while (1)
    {
        system("cls");
        printf("===========================");
        printf("\n\n1. Xem kết quả thi đấu ");
        printf("\n2. Nhập kết quả thi đấu ");
        printf("\n0. Quay về menu chính");
        printf("\n\n#Chọn: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 2:
            menu3_2();
            getchar();
            break;
        case 1:
            menu3_1();
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

void menu3_2()
{
    FILE *fp;
    int i = 0;
    char choice;
    while (1)
    {
        system("cls");

        printf("========= Kết quả thi đấu ==========");
        printf("\n\n");

        printf("\nĐội chủ nhà: ");
        fflush(stdin);
        scanf("%[^\n]s", &ketqua[i].doi_a);

        printf("\nĐội khách ");
        fflush(stdin);
        scanf("%[^\n]s", &ketqua[i].doi_b);

        printf("\nKết quả %s: ", ketqua[i].doi_a);
        fflush(stdin);
        scanf("%d", &ketqua[i].g);

        printf("\nKết quả %s: ", ketqua[i].doi_b);
        fflush(stdin);
        scanf("%d", &ketqua[i].h);
        i++;
        p = i;
        printf("\nBạn có muốn tiếp tục? YES( phím bất kì ) hoặc NO( phím n) : ");
        fflush(stdin);
        scanf("%c", &choice);

        if (choice == 'n')
        {
            fp = fopen("VL2018Log.dat", "w+");
            fwrite(ketqua, sizeof(struct Quan_Ly_Ket_Qua_Thi_Dau), p, fp);
            fclose(fp);
            break;
        }
    }
}

void menu3_1()
{
    FILE *fp;

    fp = fopen("VL2018Log.dat", "r");
    fread(ketqua, sizeof(struct Quan_Ly_Ket_Qua_Thi_Dau), p, fp);
    system("cls");
    printf("========= Xem kết quả thi đấu =========");
    printf("\n\n");
    for (int i = 0; i < p; i++)
    {
        printf("Trận: %s  vs  %s", ketqua[i].doi_a, ketqua[i].doi_b);
        printf("\nKết quả %s: %d", ketqua[i].doi_a, ketqua[i].g);
        printf("\nKết quả %s: %d", ketqua[i].doi_b, ketqua[i].h);
        printf("\n\n");
    }
    printf("\n\n\n\nNhấn Enter để quay lại");
    getchar();
    fclose(fp);
}