#include<stdio.h>
#include<time.h>
#include<string.h>
void main()
{
    while(1){
    FILE *file;
    if (file == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    int input;
    int opt;


    printf("\t\t\t _____ _____ _____ _____      ____   ____   ____  _  __\n");
    printf("\t\t\t|  __ \\_   _/ ____|_   _|    |  _ \\ / __ \\ / __ \\| |/ /\n");
    printf("\t\t\t| |  | || || |  __  | |______| |_) | |  | | |  | | ' /\n");
    printf("\t\t\t| |  | || || | |_ | | |______|  _ <| |  | | |  | |  <\n");
    printf("\t\t\t| |__| || || |__| |_| |_     | |_) | |__| | |__| | . \\\n");
    printf("\t\t\t|_____/_____\\_____|_____|    |____/ \\____/ \\____/|_|\\_\\\n");

    printf("\n\n");


    printf("1. Add Book Information\n");
    printf("2. Book Search By Book Name\n");
    printf("3. Book Search By Author Name\n");
    printf("4. Total No of Books\n\n");
    printf("Enter Option:");

    scanf("%d",&opt);
    printf("\n");

    switch (opt)
    {
    case 1:
        file = fopen("lib_data.txt", "a");
        add_book(file);
        break;
    case 2:
        file = fopen("lib_data.txt", "r");
        display_book(file);
        printf("\nPress any  key to continue..");
        getch();
        break;
    case 3:
        file = fopen("lib_data.txt", "r");
        search_book(file);
        printf("\nPress any  key to continue..");
        getch();
        break;
    case 4:
        file = fopen("lib_data.txt", "r");
        total_books(file);
        printf("\nPress any  key to continue..");
        getch();
        break;
    default:
        printf("Enter Valid Option..");
    }
    usleep(1000000);
    system("cls");
    }





}
void add_book(FILE *file)
    {
    char book_name[20];
    char author[20];
    int pages;
    float price;

    printf("Enter book name: ");
    scanf("%s", book_name);
    printf("Enter author name: ");
    scanf("%s", author);
    printf("Enter pages: ");
    scanf("%d", &pages);
    printf("Enter price: ");
    scanf("%f", &price);

    // Write the book information to the file
    fprintf(file, "%s %s %d %f\n", book_name, author, pages, price);
    fclose(file);
    printf("Book added Succesfully!!!");
    fclose(file);


    }
void display_book(FILE *file)
{
    char author[20];
    char book_name[20];
    int pages;
    float price;
    char given_book[20];

    printf("Enter Book name: ");
    scanf("%s", given_book);

    rewind(file);
    printf("\n");

    printf("Book  Author   Pages \tPrice\n\n");

    while (fscanf(file, "%s %s %d %f", book_name, author, &pages, &price) != EOF) {
        if (strcmp(book_name, given_book) == 0)
            printf("%s\t%s\t%d\t%f\n", book_name, author, pages, price);

    }
    fclose(file);

}
void search_book(FILE *file)
{
    char author[20];
    char book_name[20];
    int pages;
    float price;
    char given_author[20];

    printf("Enter author name: ");
    scanf("%s", given_author);

    rewind(file);

    printf("\n");

    printf("Book  Author   Pages \tPrice\n\n");


    while (fscanf(file, "%s %s %d %f", book_name, author, &pages, &price) != EOF) {
        if (strcmp(author, given_author) == 0)
            printf("%s\t%s\t%d\t%f\n", book_name, author, pages, price);

    }
    fclose(file);
}
 void total_books(FILE *file)
 {
     int count = 0;
    char book_name[20];
    char author[20];
    int pages;
    float price;

    rewind(file);

    while (fscanf(file, "%s %s %d %f", book_name, author, &pages, &price) != EOF) {
        count++;
    }

    printf("\nNo of books in library: %d\n", count);
    fclose(file);
 }
