#include <stdio.h>  //perform input and output operations in C.
#include <stdlib.h> //includes functions involving memory allocation, process control, conversions and others.
#include <string.h> //contains macro definitions, constants and declarations of functions and types used not only for string handling but also various memory handling functions

struct bank_account
{
    int account_number;
    float balance;
    char password[50];
};

// function to create a new bank account
void create_account(struct bank_account *accounts, int num_accounts, FILE *fp)
{
    printf("Enter account number (9 digits only): ");
    scanf("%d", &accounts[num_accounts].account_number);
    while (accounts[num_accounts].account_number < 100000000 || accounts[num_accounts].account_number > 999999999)
    {
        printf("Invalid account number length. Please enter a 9-digit account number: ");
        scanf("%d", &accounts[num_accounts].account_number);
    }
    printf("Enter initial balance: ");
    scanf("%f", &accounts[num_accounts].balance);
    printf("Create a password (6 digits only): ");
    scanf("%s", accounts[num_accounts].password);

    while (strlen(accounts[num_accounts].password) != 6)
    {
        printf("Invalid password length. Please enter a 6-digit password: ");
        scanf("%s", accounts[num_accounts].password);
    }

    fprintf(fp, "%d %.2f %s\n", accounts[num_accounts].account_number, accounts[num_accounts].balance, accounts[num_accounts].password);
    printf("Account created successfully.\n");
}

// function to authenticate user
int authenticate(struct bank_account account)
{
    char password[50];
    printf("Enter password: ");
    scanf("%s", password);
    if (strcmp(password, account.password) == 0)
    {
        return 1;
    }
    else
    {
        printf("Incorrect password.\n");
        return 0;
    }
}

// function to deposit money
void deposit(struct bank_account *accounts, int num_accounts, FILE *fp)
{
    int account_number;
    float amount;
    int i;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (i = 0; i < num_accounts; i++)
    {
        if (accounts[i].account_number == account_number)
        {
            if (authenticate(accounts[i]))
            {
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                accounts[i].balance += amount;
                fprintf(fp, "%d %.2f %s\n", accounts[i].account_number, accounts[i].balance, accounts[i].password);
                printf("Deposit successful. New balance: $%.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found.\n");
}

// function to withdraw money
void withdraw(struct bank_account *accounts, int num_accounts, FILE *fp)
{
    int account_number;
    float amount;
    int i;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (i = 0; i < num_accounts; i++)
    {
        if (accounts[i].account_number == account_number)
        {
            if (authenticate(accounts[i]))
            {
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if (amount > accounts[i].balance)
                {
                    printf("Insufficient funds.\n");
                }
                else
                {
                    accounts[i].balance -= amount;
                    fprintf(fp, "%d %.2f %s\n", accounts[i].account_number, accounts[i].balance, accounts[i].password);
                    printf("Withdrawal successful. New balance: $%.2f\n", accounts[i].balance);
                }
            }
            return;
        }
    }
    printf("Account not found.\n");
}

int main()
{
    FILE *fp;
    fp = fopen("accounts.txt", "r");
    int num_accounts = 0;
    struct bank_account accounts[100];
    while (fscanf(fp, "%d %f %s", &accounts[num_accounts].account_number, &accounts[num_accounts].balance, accounts[num_accounts].password) != EOF)
    {
        num_accounts++;
    }
    fclose(fp);

    fp = fopen("accounts.txt", "a");
    int choice;
    do
    {
        printf("1. Create new account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create_account(accounts, num_accounts, fp);
            num_accounts++;
            break;
        case 2:
            deposit(accounts, num_accounts, fp);
            break;
        case 3:
            withdraw(accounts, num_accounts, fp);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 4);

    fclose(fp);
    return 0;
}