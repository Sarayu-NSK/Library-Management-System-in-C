#include<stdio.h>
#include<string.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8

typedef struct book//book b
{
    char title[20];
    char author[20];
    char publisher[20];
    unsigned long int  booknum;//ISBN

}book;



void display()//display books
{
    system("cls");
    book b1;
    FILE *fp;
    fp=fopen("book.txt","r");
     printf("\n\n\t\t\t\t\t\t-----BOOK DETAILS-----");
      printf("\n\n\t\t\t\t\t   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
     printf("\n\t\t-------------------------------------------------------------------------------------");
    while(fread(&b1,sizeof(book),1,fp))
    {

        printf("\n\t\t\t\t\tBook title : %s",b1.title);
        printf("\n\t\t\t\t\tBook Author : %s",b1.author);
        printf("\n\t\t\t\t\tBook Publisher :%s",b1.publisher);
        printf("\n\t\t\t\t\tBook ISBN number : %lu",b1.booknum);
        printf("\n\t\t-------------------------------------------------------------------------------------");

    }
    fclose(fp);


}
void append()//add books
{
    system("cls");
    book *b;
    FILE *fp;
    int n,i;
    printf("\n\n\t\t\t\t\tADD BOOKS");
    printf("\n\n\t\t\t      \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\n\t\t\tEnter how many books you want to add : ");
    scanf("%d",&n);
    b=(book*)calloc(n,sizeof(book));
    fp=fopen("book.txt","a");

    for(i=0;i<n;i++)
    {
        fflush(stdin);//flush out data from keyboard//stdin - keyboard// stdout - monitor
        printf("\n\t\t\t\t\tEnter title : ");
        gets(b[i].title);
        printf("\n\t\t\t\t\tEnter author : ");
        gets(b[i].author);
        printf("\n\t\t\t\t\tEnter publisher : ");
        gets(b[i].publisher);
        printf("\n\t\t\t\t\tEnter book number : ");
        scanf("%lu",&b[i].booknum);

        fwrite(&b[i],sizeof(book),1,fp);//int char struct
    }
    fclose(fp);

}

void noofrec()
{
    system("cls");
    printf("\n\n\t\t\t\t\tNO.OF RECORDS");
    printf("\n\n\t\t\t      \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    book b1;
    FILE *fp;
    fp=fopen("book.txt","r");
    fseek(fp,0,SEEK_END);//fseek lets us to move the pointer from one record to another//B1.B2.
    //SEEK_CUR SEEK_SET//1.21 2.27
    int n = ftell(fp)/sizeof(book);
    //printf("size of the book =%d\n",sizeof(book));
    printf("\n\t\t\t\tNo.of books available = %d\n",n);
    fclose(fp);
}

void search()
{
    system("cls");
    book b1;
    FILE *fp;
    int found=0,num;
    fp=fopen("book.txt","r");
    printf("\n\n\t\t\t\t\tSEARCH BOOKS");
     printf("\n\n\t\t\t      \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\n\t\t\tEnter the book number(ISBN) to be searched : ");
    scanf("%d",&num);

    while(fread(&b1,sizeof(book),1,fp))
    {
        if(b1.booknum==num)
        {
            printf("\n\n\t\t\t\t-----BOOK DETAILS-----");
            printf("\n\n\t\t----------------------------------------------------------------------------------");
            printf("\n\t\tBook title\t\tBook author\t\tBook publisher\t\tBook number");
            printf("\n\t\t-----------------------------------------------------------------------------------");
            found =1;
            printf("\n\t\t%s",b1.title);
            printf("\t\t%s",b1.author);
            printf("\t\t\t%s",b1.publisher);
            printf("\t\t\t%lu\n",b1.booknum);
        }

    }
    if(!found)
        printf("\n\t\t\t\tSorry book not available\n");
    fclose(fp);

}

void update()//edit
{
    system("cls");
    printf("\n\n\t\t\t\t\t\tBOOK UPDATE");
    printf("\n\t\t\t\t      \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    book b1;
    FILE *fp,*fp1;
    int found=0,num;
    fp=fopen("book.txt","r");
    fp1=fopen("temp.txt","w");
    printf("\n\t\t\t\tEnter the num of book to be updated : ");
    scanf("%d",&num);

    while(fread(&b1,sizeof(book),1,fp))
    {
        if(b1.booknum==num)
        {
            found =1;
            fflush(stdin);
            printf("\n\t\t--------------------------------------------------------------------");
            printf("\n\t\t\t\t\tPLEASE ENTER THE NEW BOOK DETAILS");
            printf("\n\n\t\t\t\t\tEnter new title : ");
            gets(b1.title);
            printf("\t\t\t\t\tEnter new author : ");
            gets(b1.author);
            printf("\t\t\t\t\tEnter new publisher : ");
            gets(b1.publisher);
            printf("\t\t\t\t\tEnter book number : ");
            scanf("%lu",&b1.booknum);
            printf("\n\t\t\t\t\tBOOK IS UPDATED!!!");
        }
        fwrite(&b1,sizeof(book),1,fp1);

    }
    fclose(fp);
    fclose(fp1);

    if(found)
    {
        fp1=fopen("temp.txt","r");
        fp=fopen("book.txt","w");

        while(fread(&b1,sizeof(book),1,fp1))
        {
            fwrite(&b1,sizeof(book),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf("\n\t\t\t\t\tBook not found\n");

}

void Delete()
{
    system("cls");
    printf("\n\n\t\t\t\t\tBOOK DELETE");
     printf("\n\n\t\t\t      \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
     book b1;
    FILE *fp,*fp1;
    //char title;
    int found=0,num;
    fp=fopen("book.txt","r");
    fp1=fopen("temp.txt","w");
    printf("\n\t\t\tEnter the num of book to be deleted : ");
    scanf("%d",&num);
    //printf("\n\t\t\t\t\tBOOK DELETED!!");

    // printf("\n\t\t--------------------------");
    while(fread(&b1,sizeof(book),1,fp))
    {
        if(b1.booknum==num)
        {
            found =1;
        }
        else//*****************
        fwrite(&b1,sizeof(book),1,fp1);

    }
    fclose(fp);
    fclose(fp1);

    if(found)
      {
        fp1=fopen("temp.txt","r");
        fp=fopen("book.txt","w");

        while(fread(&b1,sizeof(book),1,fp1))
       {
            fwrite(&b1,sizeof(book),1,fp);

        }
        fclose(fp);
        fclose(fp1);

    }
    else
        printf("\n\t\t\t\t\tBook not found\n");


}

//////***************************USER***********************************

struct user{
    char fullname[50];
    char email[50];
    char password[50];
    char username[50];

};

void takeinput(char ch[50])
{
    fgets(ch,50,stdin);
    ch[strlen(ch)-1]=0;

}



void takepassword(char pwd[50])
{
    int i;
    char ch;
    while(1)
    {
        ch=getch();
    if(ch==ENTER||ch==TAB)
    {
        pwd[i]='\0';
        break;

    }

      else if(ch==BCKSPC)
      {
        if(i>0)
        {
            i--;
            printf("\b \b");
        }
      }
             else
        {
            pwd[i++]=ch;
            printf("* \b");
        }
      }

}


void main()
{
    FILE*fp;
    //FILE *fptr;
    int opt,c,ursfound=0,c1,ch;
    struct user user,urs;
    char username[50],pword[50],email[50];

    char password2[50];

    printf("\n\t\t\t\t\t\WELCOME TO LIBRARY DATABASE!!!");
    printf("\n\n\t\t\t\t   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\n\t\t\t\t   Please choose from options below :" );
    printf("\n\n\t\t\t\t\t\t1.STUDENT\n\t\t\t\t\t\t2.LIBRARIAN\n\n\t\t\t\t\tYour choice:\t");
    scanf("%d",&c);
    if(c==1)
    {
        one :
        system("cls");
        printf("\n\n\t\t\t\t\tLOGIN/REGISTER");
        printf("\n\n\t\t\t      \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");

    printf("\n\t\t\t\tPlease choose an operation \n");
    printf("\n\t\t\t\t1.NEW USER REGISTRATION\n\t\t\t\t2.LOGIN\n\t\t\t\t3.EXIT");
    printf("\n\n\t\t\t\t\tYour choice :\t");
    scanf("%d",&opt);
    fgetc(stdin);//reads from the keyboard

     switch(opt)
    {
        case 1:
            system("cls");
            printf("\n\n\t\t\t\tUSER REGISTRATION");
            printf("\n\n\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");

        printf("\n\t\t\tEnter your FullName :\t");//registration of user
        takeinput(user.fullname);
        printf("\n\t\t\tEnter your Email :\t");
        takeinput(user.email);
        printf("\n\t\t\tEnter your Password :\t");
        takepassword(user.password);
        printf("\n\t\t\tConfirm your Password :\t");
        takepassword(password2);

        if(!strcmp(user.password,password2))
        {
            fp=fopen("user.txt","a+");
            fwrite(&user,sizeof(user),1,fp);
            if(fwrite!=0) {

              goto one;
            }

            else printf("\nSorry something went wrong :(");
        }
        else
        {
            printf("\n\n\t\t\t\t\t\apassword doesnot match!!\n");
        }
        fclose(fp);
        break;//end of registration

        case 2:
            system("cls");
            printf("\n\n\t\t\t\t\tUSER LOGIN");
            printf("\n\n\t\t\t    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            printf("\n\t\t\Please enter the username and password that you have registered with!!");
            printf("\n\n\t\t\t\tEnter your Username :\t");
            takeinput(username);
            printf("\n\t\t\t\tEnter your Email : \t");
            takeinput(email);
            printf("\n\t\t\t\tEnter your Password :\t");
            takepassword(pword);
            system("cls");
            fp=fopen("user.txt","r");

            while(fread(&user,sizeof(user),1,fp))
             {
               if(strcmp(user.fullname,username)==0&&strcmp(pword,password2)==0)


                    printf("\n*");
                    printf("\n\n\t\t\t\tWELCOME TO STUDENT PAGE");
                    printf("\n\n\t\t\t  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
                    printf("\n\t\t\t\t*****USER MENU*****");
                    printf("\n\n\t\t\t\tPlease choose one operation");
                    printf("\n\t\t\t\t1.USER PROFILE\n\t\t\t\t2.SEARCH BOOKS");
                    printf("\n\n\t\t\t\tEnter your choice: ");
                    scanf("%d",&c1);

                 switch(c1)
                    {
                        case 1:
                        system("cls");
                        printf("\n\t\t\t\t***USER DETAILS***");
                        printf("\n\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
                        printf("\n\t\t\t\tFullname : %s",username);
                        printf("\n\t\t\t\tEmail :%s",email);
                        printf("\n\t\t\t\tPassword :%s\n",pword);
                       //direct to logout page
                        break;
                        case 2:
                            search();
                    }
                    break;
                ursfound=1;

             }
              break;
               if(ursfound!=1)
               {
                 printf("\n\t\tUSER NOT REGISTERED");
               }

        fclose(fp);
        break;

             }

    }
    if(c==2)   //*********LIBRARIAN**************
    { two :
        system("cls");
        printf("\n\t\t\t\t\t    ADMIN PAGE");
        printf("\n\t\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
        printf("\n\t\t\t\t       WELCOME TO ADMIN LOGIN");
        printf("\n\n\t\t\t\t\tEnter username : ");
        scanf("%s",&username);
        printf("\n\t\t\t\t\tEnter password : ");
        scanf("%s",&pword);
        if(strcmp(username,"admin")!=0 || strcmp(pword,"admin")!=0)
        {

            printf("\nWRONG CREDENTIALS!!\a");
            goto two;
        }
        else
        {
            system("cls");
            printf("\n\t\t\t\tWELCOME TO ADMIN PROFILE PAGE\n");
            printf("\n\t\t\t\t\tADMIN MENU");
            printf("\n\n\t\t\t    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
              do{
                  printf("\n\n\t\t\t\t\t1.ADD BOOKS\n\t\t\t\t\t2.VIEW BOOKS\n\t\t\t\t\t3.EDIT BOOKS\n\t\t\t\t\t4.DELETE BOOKS\n\t\t\t\t\t5.NO.OF RECORDS\n\t\t\t\t\t0.exit");
                  printf("\n\t\t\t\t\tEnter your choice : ");
                  scanf("%d",&ch);

                   switch(ch)
                    {
                     case 1:
                       append();
                       break;
                      case 2 :
                        display();
                        break;
                        case 3:
                        update();
                        break;
                      case 4:
                        Delete();
                        break;
                      case 5 :
                        noofrec();
                        break;
                      }

                 }while(ch!=0);

        }


    }
    return 0;
}

