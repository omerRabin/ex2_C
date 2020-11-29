#include <stdio.h>
#include "myBank.h"

int main()
{
bool temp=true,flag1,flag2,flag3,flag4;
int accountNum;
float amount,interest;
char chosenValue;
int countinueSpace=0;
while(temp){
  if(countinueSpace==0)
  {
  printf("\n\n");
printf("Please choose a transaction type: \n"); 
printf("O-Open Account\n");
printf("B-Balance Inquiry\n");
printf("D-Deposit\n");
printf("W-Withdrawal\n");
printf("C-Close Account\n");
printf("I-Interest\n");
printf("P-Print\n");
printf("E-Exit\n");
  }
    flag1=true;
    flag2=true;
    flag3=true;
    flag4=true;
scanf("%c",&chosenValue);
if(chosenValue==' ') {
countinueSpace=1;
continue;
}
else{
  countinueSpace=0;
}
int numValue=(int)chosenValue;
int stop=1,stop1=1;;
float n=-1;
char NextChar = '\n';
int count;
switch (numValue)
{
case 'O':
 printf("Please enter amount for deposit: ");
   scanf("%f",&n);
   if(n==-1){
     printf("Failed to read the amount\n");
   }
   else
   {
     OpenAccount(n); 
   }
   break;
case 'B':
while(flag1){
    printf("Please enter account number: ");
    if(scanf("%d",&accountNum)==0){
 printf("Failed to read the account number\n");
  break;
    }
if(isOk(accountNum)){
    BalanceInquiry(accountNum);
    flag1=false;
}
else
{
     printf("This account is closed\n");
}
}
break;

case 'D':
while(flag2){
    printf("Please enter account number: ");
      if(scanf("%d",&accountNum)==0){
 printf("Failed to read the account number:\n");
  break;
  }
if(isOk(accountNum)){
    Despoit(accountNum);
    flag2=false;
}
else
{
     printf("This account is closed\n");
}
}
break;

case 'W':
while(flag3){
    printf("Please enter account number: ");
    if(scanf("%d",&accountNum)==0){
 printf("Failed to read the account number\n");
  break;
}
//scanf("%d",&accountNum);
if(isOk(accountNum)){
    Withrawal(accountNum);
    flag3=false;
}
else
{
     printf("This account is closed\n");
}
}
break;

case 'C':
while(flag4){
     printf("Please enter account number: ");
      if(scanf("%d",&accountNum)==0){
       printf("Failed to read the account number\n");
        break;
      }
if(isOk(accountNum)){
    CloseAccount(accountNum);
   flag4=false;
}
else
{
     printf("This account is closed\n");
}
}
break;

case 'I':
printf("Please enter interest rate: ");
if(scanf("%f",&interest)==0){
 printf("Failed to read the interest rate\n");
  break;
}
InterestAdding(interest);
break;

case 'P':
PrintOpenAccounts();
break;

case 'E':
Exit();
temp=false;
break;
default:
printf("Invalid transaction type\n");
break;
}
}
    return 0;
}