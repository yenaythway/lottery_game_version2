#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int agecheck();
int idcheck();
int deposit();
int userremainmoneycheck();
int betmoneycheck();
int numbercheck();
int playagainornot();
int id,depositamount,intronum,userid,age,userremainmoney,betmoney,userluckynumber,quitornotnumber=0;
int severluckynumber=0;
int hello(){
    printf("****My Dear %d****\n",id);
}
int intro(){
    printf("Enter 1 to play game: \nenter 2 to read rules and privicy: \nenter 3 to quit: \n");
    scanf("%d",&intronum);
    switch(intronum){
        case 1:
            printf("********Let's play*******\n");
            agecheck();
        case 2:
            printf("\n\nThis is my first project.\nThis is very simple.\nWe use only 'if else','while','functions with no parameter'.\nThis is very human to play.\n\n");
            intro();
        case 3:
            printf("QUIT.....\n");
            exit(1);
        default:
            printf("Invalid condition");
            intro();
    }
}
int agecheck(){
    printf("enter your age:\n");
    scanf("%d",&age);
    if (age<18){
        printf("You cannot play game.\n");
        exit(1);
    }else if(age>18){
        printf("You can play game.\n");
        idcheck();

    }else{
        printf("___Invalid condition___");
        agecheck();
    }
}
int idcheck(){
    printf("enter your id: ");
    scanf("%d",&userid);
    id=userid;
    deposit();
}
int deposit(){
    hello();
    printf("enter your deposit amount: ");
    scanf("%d",&depositamount);
    if (depositamount<999){
        printf("\n\n\nYou deposited lower than minimun amount.\nSo deposit more amount.\nU should try more than 999ks\n\n\n");
        deposit();
    }else if(depositamount>999){
        userremainmoney=userremainmoney+depositamount;
        printf("\n\nYou deposited %d\n",depositamount);
        userremainmoneycheck();

    }else{
        printf("You enter invalid words");
        deposit();
    }
}
int userremainmoneycheck(){
    if(userremainmoney<1){
        printf("\n\nYour total money: %d\n",userremainmoney);
        printf("There is no money to play.\nPlease deposit money\n\n");
        deposit();
    }else if(userremainmoney>0){
        printf("This is your total money: %d\n\n",userremainmoney);
        betmoneycheck();
    }
}
int betmoneycheck(){
    printf("enter amount of your money to bet :");
    scanf("%d",&betmoney);
     if(betmoney>userremainmoney){
        printf("Your remain money:%d\n",userremainmoney);
        printf("Your bet money: %d\n",betmoney);
        printf("Look your remain money!\nThat is over your total money.\nOh god please!\nAre u crazyyy?\nYou will get only shit!\n");
        betmoneycheck();
    }else if(betmoney<500){
         printf("You cannot bet lower than 500ks\n");
         betmoneycheck();
     }else if(betmoney>=500){
         userremainmoney=userremainmoney-betmoney;
         printf("this is your bet money: %d\n",betmoney);
         numbercheck();
     }else{
         printf("Invalid condition");
         betmoneycheck();
     }

}
int numbercheck(){
    printf("enter your lucky number: ");
    scanf("%d",&userluckynumber);
    srand(time(NULL));
    severluckynumber=(rand()%3)+1;
    printf("Sever lucky number is ***%d***\n",severluckynumber);
    if(userluckynumber==severluckynumber){
        printf("####*******YOU ARE WINNNNNNERRRRRRRRR*******####\n");
        userremainmoney=userremainmoney+(betmoney*80);
        userremainmoneycheck();
        playagainornot();
    }else{
        printf("***U lose***\n");
        printf("This is your remain money: %d\n",userremainmoney);
        playagainornot();
    }
}
int playagainornot(){
    printf("if u want to play again press 1:\n if u want to quit press 2 :");
    scanf("%d",&quitornotnumber);
    if(quitornotnumber==1){
        userremainmoneycheck();
    }else if(quitornotnumber==2){
        printf("Good Bye,Have a great day!");
        exit(1);
    }
}
int main() {
    printf("****Welcome to our lottery game****\n");
    intro();
}
