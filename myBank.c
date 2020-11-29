#include <stdio.h>
#include "myBank.h"
#include <stdbool.h>
void OpenAccount(float amount)
{
     bool stop=false;
     int indexAccount=50;
    for(int i=0;i<50 && !stop;i++){
        if(bankStatus[i][1]==0){//this is close
            bankStatus[i][1]=1;//change to 1 is open
            bankStatus[i][0]=amount;//update balance
            stop=true;
            indexAccount=i;
        }
    }
        if(indexAccount==50){
            printf("There is no place to insertion\n");
            return;
        }
        printf("New account number is:%d\n",indexAccount+901);
}
bool isOk(int account_number){
    if(account_number>950 || account_number<901){
        return false;
    }
  return true;
}
void BalanceInquiry(int account_number){
    int indexArray=account_number-901;
    if(bankStatus[indexArray][1]==0) {
        printf("This account is closed\n");
        return;
    }
    printf("The balance of account number %d is :%.2f\n",account_number,bankStatus[indexArray][0]);
}
void Despoit(int account_number){
    float moneyToIn;
    int indexArray=account_number-901;
    if(bankStatus[indexArray][1]==0) {
        printf("This account is closed\n");
        return;
    }
    printf("Enter the amount Money you want to despoit please\n");
    scanf("%f",&moneyToIn);
    bankStatus[indexArray][0]+=moneyToIn;
    printf("The new balance after insertion is:%.2f\n",bankStatus[indexArray][0]);
}
void Withrawal(int account_number){
    float moneyToOut;
    int indexArray=account_number-901;
    if(bankStatus[indexArray][1]==0) {
        printf("This account is closed\n");
        return;
    }
    printf("Please enter the amount to withdraw: ");
    scanf("%f",&moneyToOut);
    if(moneyToOut>bankStatus[indexArray][0]){
        printf("Cannot withdraw more than the balance");
        return;
    }
    bankStatus[indexArray][0]-=moneyToOut;
    printf("The new balance is: %.2f\n",bankStatus[indexArray][0]);
    }
    void CloseAccount(int account_number){
         int indexArray=account_number-901;
         if(bankStatus[indexArray][1]==0){
             printf("This account is closed\n");
             return;
         }
         bankStatus[indexArray][1]=0;
    }
    void InterestAdding(float interest_rate){
        float interest=0;
        for(int i=0;i<50;i++){
            if(bankStatus[i][1]==1)
            {
            interest=(interest_rate*bankStatus[i][0])/100;
            bankStatus[i][0]+=interest;
            }
        }
    }
    void PrintOpenAccounts()
    {
        for(int i=0;i<50;i++){
            if(bankStatus[i][1]==1)
            {
                printf("The balance of account number: %d is: %.2f\n",i+901,bankStatus[i][0]);
            }
        }
    }
    void Exit(){
        for(int i=0;i<50;i++){
            bankStatus[i][1]=0;
        }
    }