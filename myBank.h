#include<stdio.h>
#include<stdbool.h>
float bankStatus[50][2];
void OpenAccount(float amount);
bool isOk(int account_number);
void BalanceInquiry(int account_number);
void Despoit(int account_number);
void Withrawal(int account_number);
void CloseAccount(int account_number);
void InterestAdding(float interest_rate);
void PrintOpenAccounts();
void Exit();