#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5
#define MAXINDEX 1000

typedef struct
{
 int bookID;
 char title[40];
 char author[40];
 double price;
 int quantity;
} Book;

void listBooks(Book books[],int count);
void addBooks(Book books[],int *count);
void removeBook(Book books[],int *count);
void findBook(Book books[]);
void updateBook(Book books[]);

int main() {

    Book books[MAXINDEX];
    int select, count;
    count = 0;
    select = 0;


    printf("NTU BOOKSHOP MANAGEMENT PROGRAM: \n1: listBooks() \n2: addBook() \n3: removeBook() \n4: findBook() \n5: updateBook() \n6: quit \nEnter your choice: \n");

    while (select != 6){
        scanf("%d", &select);

        switch(select){
            case 1: {
                printf("listBooks():\n");
                listBooks(books,count);

                printf("Enter your choice: \n");
                break;
            }
            case 2: {
                printf("addBook():\n");
                addBook(books,&count);
                printf("Enter your choice: \n");
                break;
            }
            case 3: {
                printf("removeBook():\n");
                removeBook(books,&count);
                printf("Enter your choice: \n");
                break;
            }
            case 4: {
                printf("findBook():\n");
                findBook(books);
                printf("Enter your choice: \n");
                break;
            }
            case 5: {
                printf("updateBook():\n");
                updateBook(books);
                printf("Enter your choice: \n");
                break;
            }
            case 6: {
                break;
            }
            default: {
                printf("Error. Please select valid option\n");
                printf("Enter your choice: \n"); }

            }

    }
    return 0;
}

// option1
void listBooks(Book books[],int count){
    if (count == 0)
        printf("The bookshop is empty \n");
    else {
        for (int ID = 1; ID<=MAXINDEX;ID++)
            if (books[ID].bookID == ID)
                printf("BookID: %d \nBook title: %s \nAuthor name: %s \nBook price: %.2f \nQuantity: %d \n", books[ID].bookID,books[ID].title,books[ID].author,books[ID].price,books[ID].quantity);
            else
                continue;
    }
}



// option 2
void addBook(Book books[],int *count){
    int ID;
    int tempID, tempprice, tempquantity;
    char temptitle[40], tempauthor[40];

    // if full
    if (*count == MAX) {
        // get temp inputs
        printf("Enter bookID: \n");
        scanf("%d",&tempID);
        printf("Enter book title: \n");
        scanf(" %[^\n]s",&temptitle);
        printf("Enter author name: \n");
        scanf(" %[^\n]s",&tempauthor);
        printf("Enter price: \n");
        scanf("%lf",&tempprice);
        printf("Enter quantity: \n");
        scanf("%d",&tempquantity);
        printf("The bookshop is full! Unable to addBook()\n");
    }

    else { //if not full

    // get input
    printf("Enter bookID: \n");
    scanf("%d",&ID);

        // if book exists
        if (ID == books[ID].bookID) {
            printf("Enter book title: \n");
            scanf(" %[^\n]s",&temptitle);
            printf("Enter author name: \n");
            scanf(" %[^\n]s",&tempauthor);
            printf("Enter price: \n");
            scanf("%lf",&tempprice);
            printf("Enter quantity: \n");
            scanf("%d",&tempquantity);
            printf("The bookID has already existed! Unable to addBook()\n");
        }
        else { // if new book

            books[ID].bookID = ID;
            printf("Enter book title: \n");
            scanf(" %[^\n]s",books[ID].title);
            printf("Enter author name: \n");
            scanf(" %[^\n]s",books[ID].author);
            printf("Enter price: \n");
            scanf("%lf",&books[ID].price);
            printf("Enter quantity: \n");
            scanf("%d",&books[ID].quantity);
            printf("The book has been added successfully\n");
            *count = *count + 1;
            //printf("count is %d\n",*count);
        }
    }

}

//option 3
void removeBook(Book books[],int *count){
    char inputtitle[40], inputauthor[40];
    int match = 0;
    int matchedID;
    int removedID, removedquantity;
    float removedprice;
    char removedtitle[40],removedauthor[40];

    typedef struct
    {
     char stitle[40];
     char sauthor[40];
    } saved;

    saved sbook[MAXINDEX];


    //get user inputs
    printf("Enter the target book title:\n");
    scanf(" %[^\n]s", inputtitle);
    printf("Enter the target author name:\n");
    scanf(" %[^\n]s", inputauthor);

    //convert inputs to lowercase
    for(int i = 0; i<=40; i++){
      inputtitle[i] = tolower(inputtitle[i]);
      inputauthor[i] = tolower(inputauthor[i]);
    }

    //check whether bookshop empty
    if (*count == 0)
        printf("The bookshop is empty\n");
    else { //bookshop not empty

    //debug
    //printf("inputs %s, %s", inputtitle, inputauthor);
    //printf("test %s, %s",tolower(books[3].title),tolower(books[3].author ));

    //convert saved details to lowercase
    //books[ID].title[n] = tolower(books[ID].title[n])

    //save saved details


    //matching block
    for (int ID = 1; ID <= MAXINDEX; ID++){
        for (int n = 0; n<=40;n++){ //convert saved to lower
            sbook[ID].stitle[n] = tolower(books[ID].title[n]);
            sbook[ID].sauthor[n] = tolower(books[ID].author[n]);
        }

        if ((strcmp(inputtitle,sbook[ID].stitle)==0) && (strcmp(inputauthor,sbook[ID].sauthor)==0)) { //test match
            matchedID = ID;
            match = 1;

        }

        else
            continue;
    }


    if (match == 1) {
        //copy removed book details
        removedID = books[matchedID].bookID;
        strcpy(removedtitle,books[matchedID].title);
        strcpy(removedauthor,books[matchedID].author);
        removedprice = books[matchedID].price;
        removedquantity = books[matchedID].quantity;

        //removal
        books[matchedID].bookID = NULL;
        strcpy(books[matchedID].title,"");
        strcpy(books[matchedID].author,"");
        books[matchedID].price = 0.0;
        books[matchedID].quantity = NULL;

        printf("The target book is removed\n");
        *count = *count - 1;
        // print details of book
        printf("BookID: %d \nBook title: %s \nAuthor name: %s \nBook price: %.2f \nQuantity: %d \n",removedID,removedtitle,removedauthor,removedprice,removedquantity);


        //printf("count is %d\n",*count);

    }
    else
        printf("The target book is not in the bookshop\n");
    }

}

//option 4
void findBook(Book books[]){
    char inputtitle[40], inputauthor[40];
    int match = 0;
    int matchedID;

      typedef struct
    {
     char stitle[40];
     char sauthor[40];
    } saved;

    saved sbook[MAXINDEX];


    //get user inputs
    printf("Enter the target book title:\n");
    scanf(" %[^\n]s", inputtitle);
    printf("Enter the target author name:\n");
    scanf(" %[^\n]s", inputauthor);

    //convert inputs to lowercase
    for(int i = 0; i<=40; i++){
      inputtitle[i] = tolower(inputtitle[i]);
      inputauthor[i] = tolower(inputauthor[i]);
    }

     //matching block
    for (int ID = 1; ID <= MAXINDEX; ID++){
        for (int n = 0; n<=40;n++){ //convert saved to lower
            sbook[ID].stitle[n] = tolower(books[ID].title[n]);
            sbook[ID].sauthor[n] = tolower(books[ID].author[n]);
        }

        if ((strcmp(inputtitle,sbook[ID].stitle)==0) && (strcmp(inputauthor,sbook[ID].sauthor)==0)) { //test match
            matchedID = ID;
            match = 1;

        }

        else
            continue;
    }

    if (match == 1) {
        printf("The target book is found\n");
        printf("BookID: %d \nBook title: %s \nAuthor name: %s \nBook price: %.2f \nQuantity: %d \n", books[matchedID].bookID,books[matchedID].title,books[matchedID].author,books[matchedID].price,books[matchedID].quantity);


    }
    else
        printf("The target book is not found\n");

}

//option 5
void updateBook(Book books[]){
    char inputtitle[40], inputauthor[40];
    float updateprice;
    int updatequantity;
    int match = 0;
    int matchedID;

      typedef struct
    {
     char stitle[40];
     char sauthor[40];
    } saved;

    saved sbook[MAXINDEX];


    //get user inputs
    printf("Enter the target book title:\n");
    scanf(" %[^\n]s", inputtitle);
    printf("Enter the target author name:\n");
    scanf(" %[^\n]s", inputauthor);

      //convert inputs to lowercase
    for(int i = 0; i<=40; i++){
      inputtitle[i] = tolower(inputtitle[i]);
      inputauthor[i] = tolower(inputauthor[i]);
    }

    //matching block
    for (int ID = 1; ID <= MAXINDEX; ID++){
        for (int n = 0; n<=40;n++){ //convert saved to lower
            sbook[ID].stitle[n] = tolower(books[ID].title[n]);
            sbook[ID].sauthor[n] = tolower(books[ID].author[n]);
        }

        if ((strcmp(inputtitle,sbook[ID].stitle)==0) && (strcmp(inputauthor,sbook[ID].sauthor)==0)) { //test match
            matchedID = ID;
            match = 1;

        }

        else
            continue;
    }


    //if match
    if (match == 1) {
        //get user update inputs and update
        printf("Enter updated book price: \n");
        scanf("%lf",&books[matchedID].price);
        printf("Enter updated quantity: \n");
        scanf("%d",&books[matchedID].quantity);

        //print details
        printf("The target book is updated\n");

        printf("BookID: %d \nBook title: %s \nAuthor name: %s \nBook price: %.2f \nQuantity: %d \n", books[matchedID].bookID,books[matchedID].title,books[matchedID].author,books[matchedID].price,books[matchedID].quantity);


    }
    else
        printf("The target book is not in the bookshop\n");

}
