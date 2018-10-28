#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Quan_Ly_Danh_Sach_Doi_Bong
{
    char ma_doi[256];  // Khai báo kiểu dữ liệu của Mã đội
    char ten_doi[256]; // Khai báo kiểu dữ liệu của Tên đội
    char huan_luyen_vien[256];
};
struct Quan_Ly_Danh_Sach_Doi_Bong danhsach[100];
int n;

void menu1_3();
void menu1_1();
void menu1_2();
void menu1();
void menu1()
{

    int choice;
    while (1)
    {
        system("cls");
        printf("Quản lý danh sách đội bóng");
        printf("\n\n1. Xem danh sách đội bóng");
        printf("\n2. Cập nhật thông tin đội bóng");
        printf("\n3. Thêm mới một đội bóng");
        printf("\n0. Trở về menu chính");
        printf("\n\n#Chọn: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 3:
            menu1_3();
            getchar();
            break;
        case 2:
            menu1_2();
            getchar();
            break;
        case 1:
            menu1_1();
            getchar();
            break;
        case 0:
            system("cls");
            Mainmenu();
            break;
        default:
            printf("\n\nNhập sai, vui lòng nhập lại từ 0-3");
            printf("\n\n");
            break;
        };
    }
}

void menu1_3()
{
    FILE *fp;
    char choice;
    int i = 0;
    int k;
    while (1)
    {
        char s1[256];

        system("cls");
        do
        {
            printf("\nNhập mã đội: ");
            fflush(stdin);
            scanf("%[^\n]s", &danhsach[i].ma_doi);
            if (strlen(danhsach[i].ma_doi) != 4)
            {
                printf("Phải nhập đúng 4 ký tự, vui lòng nhập lại");
                continue;
            }
        } while (strlen(danhsach[i].ma_doi) != 4);

        do
        {
            printf("\nNhập tên đội: ");
            fflush(stdin);
            scanf("%[^\n]s", &danhsach[i].ten_doi);
            if (strlen(danhsach[i].ten_doi) > 30)
            {
                printf("Nhập quá 30 ký tự, vui lòng nhập lại");
                continue;
            }
        } while (strlen(danhsach[i].ten_doi) > 30);

        do
        {
            printf("\nNhập tên huấn luyện viên: ");
            fflush(stdin);
            scanf("%[^\n]s", &danhsach[i].huan_luyen_vien);

            if (strlen(danhsach[i].huan_luyen_vien) > 30)
            {
                printf("Nhập quá 30 ký tự hoặc có chứa kí tự đặc biệt, vui lòng nhập lại");
                continue;
            }
        } while (strlen(danhsach[i].huan_luyen_vien) > 30);
        // || strlen(danhsach[i].huan_luyen_vien) > 30
        i++;
        n = n + i;

        printf("\nBạn có muốn tiếp tục? YES( phím bất kì ) hoặc NO( phím n) : ");
        fflush(stdin);
        scanf("%c", &choice);

        if (choice == 'n')
        {

            fp = fopen("VL2018Teams.dat", "wb");

            fwrite(danhsach, sizeof(struct Quan_Ly_Danh_Sach_Doi_Bong), n, fp);
            fclose(fp);
            break;
        }
        else
        {
            continue;
        }
    }
}

void menu1_1()
{
    system("cls");
    FILE *fp;
    fp = fopen("books.dat", "rb");
    fread(danhsach, sizeof(struct Quan_Ly_Danh_Sach_Doi_Bong), n, fp);
    printf("%d", n);
    printf("===============================");
    printf("\n\nDanh Sách Đội Bóng");
    printf("\n\n=============================================================================");
    printf("\n\n|Mã đội\t|           Tên Đội            |       Huấn Luyện Viên       |");
    for (int i = 0; i < n; i++)
    {
        printf("\n\n|%-6s\t|%-30s|%-30s", danhsach[i].ma_doi, danhsach[i].ten_doi, danhsach[i].huan_luyen_vien);
    }
    printf("\n\n\nNhấn Enter để quay lại");
    getchar();
    fclose(fp);
}

void menu1_2()
{
    FILE *fp;

    system("cls");
    char choice;
    int x;
    char c[256]; //strcmp là hàm so sánh 2 chuỗi
    int e;
    int z;
    printf("Nhập mã đội cần sửa: ");
    fflush(stdin);
    scanf("%[^\n]s", &c);
    for (int j = 0; j < n; j++)
    {

        x = strcmp(c, danhsach[j].ma_doi);

        if (x == 0)

        {
            e = 1;
            z = j;
        }
    }

    if (e != 1)
    {
        printf("Nhập sai, vui lòng nhập lại mã đội");
        printf("\n\nNhấn Enter để quay lại menu Quản lý đội bóng");
        getchar();
    }
    else if (e == 1)

    {
        fp = fopen("VL2018Teams.dat", "wb");

        do
        {
            printf("\nSửa mã đội: ");
            fflush(stdin);
            scanf("%[^\n]s", &danhsach[z].ma_doi);
            if (strlen(danhsach[z].ma_doi) > 6)
            {
                printf("Nhập quá 6 ký tự, vui lòng nhập lại");
                continue;
            }
        } while (strlen(danhsach[z].ma_doi) > 6);

        do
        {
            printf("\nSửa tên đội: ");
            fflush(stdin);
            scanf("%[^\n]s", &danhsach[z].ten_doi);
            if (strlen(danhsach[z].ten_doi) > 30)
            {
                printf("Nhập quá 30 ký tự, vui lòng nhập lại");
                continue;
            }
        } while (strlen(danhsach[z].ten_doi) > 30);

        do
        {
            printf("\nSửa tên huấn luyện viên: ");
            fflush(stdin);
            scanf("%[^\n]s", &danhsach[z].huan_luyen_vien);
            if (strlen(danhsach[z].huan_luyen_vien) > 30)
            {
                printf("Nhập quá 30 ký tự, vui lòng nhập lại");
            }
        } while (strlen(danhsach[z].huan_luyen_vien) > 30);

        fwrite(danhsach, sizeof(struct Quan_Ly_Danh_Sach_Doi_Bong), z, fp);
        fclose(fp);

        printf("\n\nBạn có muốn tiếp tục cập nhật? y/n: ");
        fflush(stdin);
        scanf("%c", &choice);

        if (choice == 'n')
        {
            system("cls");
            menu1();
            getchar();
        }
        else if (choice == 'y')
        {
            system("cls");
            menu1_2();
            getchar();
        }
        fclose(fp);
    }
}
