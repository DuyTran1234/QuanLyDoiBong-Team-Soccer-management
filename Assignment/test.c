#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

struct Books 
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   isbn; 
};
// declare struct pointer
//struct Books books[100];
// declare total of inputed struct elements
int n;
// function prototype 
void addBook();
void printBooks(); 

int main() 
{
    int choice;
    while(1)
    {
        system("clear");
        printf("MENU");
        printf("\n===========================");
        printf("\n1. Add book");
        printf("\n2. Display all books");
        printf("\n0. Exit");
        printf("\n===========================");
        printf("\n#Select: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                addBook();
                getchar();
                break;
            case 2:
                printBooks();
                getchar();
                break;
            case 0:
                exit(0);
        }
    }
   return 0; 
}

void addBook()
{
    char choice;
    int i = 0;
    char isbn[10];
    int count = 0; // count total of books struct and save to file
    struct Books books[200]; // input books array and save to file
    FILE *fp;
    while(1)
    {
        system("clear");
        printf("\nAdd Student Info");
        printf("\n=================================");
        printf("\nTitle: ");
        getchar();
        scanf("%[^\n]s", books[i].title);
        printf("Author: ");
        getchar();
        scanf("%[^\n]s", books[i].author);
        printf("Subject: ");
        getchar();
        scanf("%[^\n]s", books[i].subject);
        printf("ISBN: ");
        getchar();
        scanf("%d", &books[i].isbn);
        i++;
        count = i;
        printf("\n=================================");
        printf("\nDo you want to continue? (y/n): ");
        getchar();
        scanf("%c", &choice);
        if(choice == 'n')
        {
            // open binary file to write data
            fp = fopen("books.dat", "wb");
            // check file exist and can open
            if (fp != NULL)
            {
                // write one count variable value to fp
                fwrite(&count, sizeof(int), 1, fp);
                // write all inputed books array to fp
                fwrite(books, sizeof(struct Books), count, fp);
                fclose(fp);
            }
            break;
        }
    }
}

void printBooks() 
{
    system("clear");
    struct Books newbooks[200];
    int count = 0;
    FILE *fp;
    fp = fopen("books.dat", "rb");
    if (fp != NULL)
    {
        fread(&count, sizeof(int), 1, fp);
        if (count > 0)
        {
            fread(newbooks, sizeof(struct Books), count, fp);
        }
        fclose(fp);
    }
    printf("Books Info\n");
    printf("=================================\n"); 
    for (int i = 0; i < count; i++)
    {
        printf("Book %d title: %s\n", i + 1, newbooks[i].title);
        printf("Book %d author: %s\n", i + 1, newbooks[i].author);
        printf("Book %d subject: %s\n", i + 1, newbooks[i].subject);
        printf("Book %d isbn: %d\n", i + 1, newbooks[i].isbn);
        printf("=================================\n"); 
    }
    getchar();
}