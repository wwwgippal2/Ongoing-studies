//according to adv. learning tutorial

//of note: using char variable to let users continue with interaction or not.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct user{
char phone[50];
char ac[50];
char password[50];
float balance;

};

int main(){
    struct user usr,usr1;
    FILE *fp;
    char filename[50],phone[50],pword[50];
    int opt,choice;
    char cont = 'y';
    float deposit;

    printf("\nWhat do you want to do?\n");
    printf("\n\n1. Register account");
    printf("\n2. Log into account");

    printf("\n\nYour choice\t");
    scanf("%d",&opt);

    if(opt==1){
        system("cls");
        printf("Enter your account number: \t");
        scanf("%s",usr.ac);
        printf("\nEnter you phone number\t");
        scanf("%s",usr.phone);
        printf("\nEnter your password\t");
        scanf("%s",usr.password);
        usr.balance =0;
        strcpy(filename,usr.phone);
        fp = fopen(strcat(filename,".dat"),"w");
        fwrite(&usr,sizeof(struct user),1,fp);
        if(fwrite!=0){
            printf("\n\nAccount successfully registered");

        }else{
        printf("\n\nSomething went wrong. Please try again");
        }

    fclose(fp);
    }

    if(opt==2){
        system("cls");

        printf("\nEnter your phone number: \t");
        scanf("%s",phone);
        printf("\nPassword: \t");
        scanf("%s",pword);
        strcpy(filename,phone);
        fp = fopen(strcat(filename,".dat"),"r");

        if(fp == NULL){
            printf("\nAccount number not registered");

        }else{

        fread(&usr,sizeof(struct user),1,fp);
        fclose(fp);
        if(!strcmp(pword,usr.password)){
            while(cont == 'y'){
                system("cls");
                printf("\nPress 1 for balance inquiry");
                printf("\nPress 2 for depositing cash");
                printf("\nPress 3 for cash withdrawl");
                printf("\nPress 4 for online transfer");
                printf("\nPress 5 to change password");
                printf("\n\nYour choice\t");
                scanf("%d",&choice);

                    switch(choice){
                    case 1:
                        printf("\nYour current balance is: %.2f",usr.balance,"r");
                        break;
                    case 2:
                        printf("\nPlease specify the deposited amount: \t");
                        scanf("%f",&deposit);
                        usr.balance +=deposit;
                        printf("\nYour balance is now %.2f", usr.balance,"r");
                        fp = fopen(filename,"w");
                        fwrite(&usr,sizeof(struct user),1,fp);
                        if (fwrite!= NULL){printf("\nSuccessfully deposited");};
                        fclose(fp);
                        break;

                    case 3:
                        printf("\nPlease specify the withdrawed amount: \t");
                        scanf("%f",&deposit);
                        usr.balance -=deposit;
                        printf("\nYour balance is now %.2f", usr.balance);
                        break;
                    case 4:
                        printf("\nPlease enter the phone number to transfer balance: ");
                        scanf("%s",phone);
                        printf("\nPlease enter the amount to transfer: \t");
                        scanf("%f",&deposit);
                        strcpy(filename,phone);
                        if(deposit>usr.balance){printf("Insufficient funds");}
                        else{
                            strcpy(filename,phone);
                            fp = fopen(strcat(filename,".dat"),"r");
                            if(fp == NULL){
                               printf("\nPhone number not registered");}
                               return 0;
                            fread(&usr1,sizeof(struct user),1,fp);

                            fclose(fp);
                            fp = fopen(filename,"w");
                            usr1.balance +=deposit;
                            fwrite(&usr1,sizeof(struct user),1,fp);

                            fclose(fp);
                            if(fwrite!=NULL){
                                printf("\nYou have successfully transfered %.2f",deposit);
                                strcpy(filename,usr.phone);
                                fp = fopen(strcat(filename,".dat"),"w");
                                usr.balance -= deposit;
                                fwrite(&usr,sizeof(struct user),1,fp);
                                fclose(fp);
                            }
                        }
                        break;

                    case 5:
                    printf("Please enter your new password\t");
                    scanf("%s",pword);
                    fp = fopen(filename,"w");
                    strcpy(usr.password,pword);
                    fwrite(&usr,sizeof(struct user),1,fp);
                    if(fwrite!=NULL){
                    printf("\nPassword successfully changed\t");};
                    break;


                    }

                printf("\nDo you want to continue the transaction? [y/n]");
                scanf("%s",&cont);

            }

            printf("\nThank you for your time!");
        }
        else{
            printf("\nInvalid Password");
        }
        }
    }
return 0;
}
