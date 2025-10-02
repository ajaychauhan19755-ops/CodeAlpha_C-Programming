#include <stdio.h>
#include <stdlib.h>

struct Account {
    int accNo;
    char name[50];
    float balance;
} acc = {101,"Ajay",1000};   // Example account

void deposit(float amt) {
    acc.balance += amt;
    printf("Deposited %.2f\n", amt);
}

void withdraw(float amt) {
    if(amt > acc.balance)
        printf("Insufficient Balance!\n");
    else {
        acc.balance -= amt;
        printf("Withdrawn %.2f\n", amt);
    }
}

void balance() {
    printf("Account:%d Name:%s Balance:%.2f\n", acc.accNo, acc.name, acc.balance);
}

int main() {
    int choice;
    float amt;
    while(1) {
        printf("\n1.Deposit\n2.Withdraw\n3.Balance\n4.Exit\nChoice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: printf("Amount: "); scanf("%f",&amt); deposit(amt); break;
            case 2: printf("Amount: "); scanf("%f",&amt); withdraw(amt); break;
            case 3: balance(); break;
            case 4: exit(0);
            default: printf("Invalid!\n");
        }
    }
    return 0;
}
