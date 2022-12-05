#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tm *mytime;

struct Points{
    int artistry;
    int technique;
};
typedef struct Points points;

struct brigade_referee{
    points ref1;
    points ref2;
    points ref3;
    points ref4;
    points ref5;
};

typedef struct brigade_referee br;

struct name{
    int ID;
    char Surnames[100];
    char Name[100];
    br ref1;
    br ref2;
};

typedef struct name nm;

nm CreatePoint(nm User){
    User.ref1.ref1.artistry=(rand() % 9) + 1;
    User.ref1.ref1.technique=(rand() % 9) + 1;
    User.ref1.ref2.artistry=(rand() % 9) + 1;
    User.ref1.ref2.technique=(rand() % 9) + 1;
    User.ref1.ref3.artistry=(rand() % 9) + 1;
    User.ref1.ref3.technique=(rand() % 9) + 1;
    User.ref1.ref4.artistry=(rand() % 9) + 1;
    User.ref1.ref4.technique=(rand() % 9) + 1;
    User.ref1.ref5.artistry=(rand() % 9) + 1;
    User.ref1.ref5.technique=(rand() % 9) + 1;
    
    User.ref2.ref1.artistry=(rand() % 9) + 1;
    User.ref2.ref1.technique=(rand() % 9) + 1;
    User.ref2.ref2.artistry=(rand() % 9) + 1;
    User.ref2.ref2.technique=(rand() % 9) + 1;
    User.ref2.ref3.artistry=(rand() % 9) + 1;
    User.ref2.ref3.technique=(rand() % 9) + 1;
    User.ref2.ref4.artistry=(rand() % 9) + 1;
    User.ref2.ref4.technique=(rand() % 9) + 1;
    User.ref2.ref5.artistry=(rand() % 9) + 1;
    User.ref2.ref5.technique=(rand() % 9) + 1;
    
    return User;
}

void create_new(){
    FILE *fp;
    fp = fopen("/Users/kostya/c Lab/DataBase/DataBase/DataBase.txt", "a");
    fprintf(fp ,"%s\n%s\n%s\n");
    fclose(fp);
}

int main() {
    
    int stime;
    long ltime;
    ltime = time(NULL);
    stime = (unsigned) ltime/2;
    srand(stime);
    
    int n,d=1;
    int A,T,AT;
    nm User;
    char id=0;
    while (d==1) {
        printf("База данных\n");
        printf("1)Создать пользователя\n");
        printf("2)Посмотреть пользователей\n");
        printf("3)Таблица\n");
        printf("4)Сумма за А\n");
        printf("5)Сумма за Т\n");
        printf("6)Сумма за всё\n");
        printf("4)Выход\n");
        scanf("%i",&n);
        switch (n) {
            case 1:
                printf("Введите имя\n");
                getchar();
                scanf("%s",User.Name);
                printf("Введите фамилию\n");
                getchar();
                scanf("%s",User.Surnames);
                User.ID=id;
                id+=1;
                User=CreatePoint(User);
                break;
            case 2:
                printf("|           Судья 1           |  |           Судья 2           |\n");
                printf("|т   а|т   а|т   а|т   а|т   а|  |т   а|т   а|т   а|т   а|т   а|\n");
                printf("|%i   %i|%i   %i|%i   %i|%i   %i|%i   %i| ",User.ref1.ref1.technique,User.ref1.ref1.artistry,User.ref1.ref2.technique,User.ref1.ref2.artistry,User.ref1.ref3.technique,User.ref1.ref3.artistry,User.ref1.ref4.technique,User.ref1.ref4.artistry,User.ref1.ref5.technique,User.ref1.ref5.artistry);
                printf(" |%i   %i|%i   %i|%i   %i|%i   %i|%i   %i| \n",User.ref1.ref1.technique,User.ref2.ref1.artistry,User.ref2.ref2.technique,User.ref2.ref2.artistry,User.ref2.ref3.technique,User.ref2.ref3.artistry,User.ref2.ref4.technique,User.ref2.ref4.artistry,User.ref2.ref5.technique,User.ref2.ref5.artistry);
                printf("%i,%s,%s\n",User.ID,User.Name,User.Surnames);
                break;
            case 3:
                break;
            case 4:
                A=User.ref1.ref1.artistry+User.ref1.ref2.artistry+User.ref1.ref3.artistry+User.ref1.ref4.artistry+User.ref1.ref5.artistry+User.ref2.ref1.artistry+User.ref2.ref2.artistry+User.ref2.ref3.artistry+User.ref2.ref4.artistry+User.ref2.ref5.artistry;
                printf("%s|%s|Сумма за A=%i\n",User.Name,User.Surnames,A);
                break;
            case 5:
                T=User.ref1.ref1.technique+User.ref1.ref2.technique+User.ref1.ref3.technique+User.ref1.ref4.technique+User.ref1.ref5.technique+User.ref2.ref1.technique+User.ref2.ref2.technique+User.ref2.ref3.technique+User.ref2.ref4.technique+User.ref2.ref5.technique;
                printf("%s|%s|Сумма за T=%i\n",User.Name,User.Surnames,T);
                break;
            case 6:
                A=User.ref1.ref1.artistry+User.ref1.ref2.artistry+User.ref1.ref3.artistry+User.ref1.ref4.artistry+User.ref1.ref5.artistry+User.ref2.ref1.artistry+User.ref2.ref2.artistry+User.ref2.ref3.artistry+User.ref2.ref4.artistry+User.ref2.ref5.artistry;
                T=User.ref1.ref1.technique+User.ref1.ref2.technique+User.ref1.ref3.technique+User.ref1.ref4.technique+User.ref1.ref5.technique+User.ref2.ref1.technique+User.ref2.ref2.technique+User.ref2.ref3.technique+User.ref2.ref4.technique+User.ref2.ref5.technique;
                printf("%s|%s|Сумма за A и T=%i\n",User.Name,User.Surnames,A+T);
                break;
            default:
                break;
        }
    }
}
