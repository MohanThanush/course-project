#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();
void displayAll();

int main() {
    int choice;

    while (1) {
        printf("\n====== BANK TRANSACTION RECORD SYSTEM ======\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: checkBalance(); break;
            case 5: displayAll(); break;
            case 6: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void createAccount() {
    FILE *fp = fopen("bankdata.txt", "a");
    struct Account acc;

    printf("\nEnter Account Number: ");
    scanf("%d", &acc.accountNumber);
    printf("Enter Account Holder Name: ");
    scanf("%s", acc.name);
    printf("Enter Initial Deposit Amount: ");
    scanf("%f", &acc.balance);

    fwrite(&acc, sizeof(acc), 1, fp);
    fclose(fp);

    printf("Account created successfully!\n");
}

void depositMoney() {
    FILE *fp = fopen("bankdata.txt", "r+");
    struct Account acc;
    int accNo;
    float amount;
    int found = 0;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accountNumber == accNo) {
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);
            acc.balance += amount;

            fseek(fp, -sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);

            printf("Amount deposited successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) printf("Account not found!\n");

    fclose(fp);
}

void withdrawMoney() {
    FILE *fp = fopen("bankdata.txt", "r+");
    struct Account acc;
    int accNo;
    float amount;
    int found = 0;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accountNumber == accNo) {
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);

            if (amount > acc.balance) {
                printf("Insufficient Balance!\n");
            } else {
                acc.balance -= amount;
                fseek(fp, -sizeof(acc), SEEK_CUR);
                fwrite(&acc, sizeof(acc), 1, fp);
                printf("Amount withdrawn successfully!\n");
            }
            found = 1;
            break;
        }
    }

    if (!found) printf("Account not found!\n");

    fclose(fp);
}

void checkBalance() {
    FILE *fp = fopen("bankdata.txt", "r");
    struct Account acc;
    int accNo;
    int found = 0;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accountNumber == accNo) {
            printf("\nAccount Number: %d\n", acc.accountNumber);
            printf("Name: %s\n", acc.name);
            printf("Balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }

    if (!found) printf("Account not found!\n");

    fclose(fp);
}

void displayAll() {
    FILE *fp = fopen("bankdata.txt", "r");
    struct Account acc;

    printf("\n=== All Account Records ===\n");

    while (fread(&acc, sizeof(acc), 1, fp)) {
        printf("\nAccount Number: %d", acc.accountNumber);
        printf("\nName: %s", acc.name);
        printf("\nBalance: %.2f\n", acc.balance);
        printf("----------------------------\n");
    }

    fclose(fp);
}