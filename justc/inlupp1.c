#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define STRLEN 100
#define ARR_LEN 100

#define TRANSACTION_WITHDRAWAL "uttag"
#define TRANSACTION_DEPOSIT "ins"

typedef struct transaction
{
    char account_nr[STRLEN];
    float amount;
    char transaction_type[STRLEN];
    char date[STRLEN];
}Transaction;


typedef struct account
{
    char account_nr[STRLEN];
    float account_balance;
    int nr_transactions;
    Transaction transaction_log[ARR_LEN];
}Account;


const char* get_date(void);
Transaction create_transaction(char account_nr[], float amount, char transaction_type[]);
Account create_account(char account_nr[]);
void main_menu(Account account_list[], int* nr_accounts);
bool account_exists(Account account_list[], const char* new_account_nr, int* nr_accounts);
void create_new_account(Account account_list[], int* nr_accounts);
void administer_account_menu(Account account_list[], int nr_accounts);
void deposit(Account* active_account);
void withdraw(Account* active_account);
void display_balance(Account* active_account);
void display_transactions(Account* active_account);
Account* login(Account account_list[], int nr_accounts);

int main(void)
{
    Account account_list[ARR_LEN / 2];
    int nr_accounts = 0;

    main_menu(account_list, &nr_accounts);


    return 0;
}

void main_menu(Account account_list[], int* nr_accounts)
{
    int selection = 0;
    while (true)
    {
        printf("\n****HUVUDMENY****\n");
        printf("1. Skapa Konto\n2. Administrera Konto\n3. Avsluta");

        scanf("%d%*[^\n]", &selection);

        switch (selection)
        {
        case 1:
            create_new_account(account_list, nr_accounts);
            break;
        case 2:
            administer_account_menu(account_list, *nr_accounts);
            break;
        case 3:
            return;
        default:
            printf("\nFelaktig inmatning");
            break;
        }
    }
}
void administer_account_menu(Account account_list[], int nr_accounts)
{
    Account* active_account = login(account_list, nr_accounts);

    while (true)
    {
        int selection = 0;
        printf("\n****KONTOMENY**** - konto:%s", active_account->account_nr);
        printf("\n1. Ta ut pengar\n2. Sätt in pengar\n3. Visa Saldo\n4. Visa transaktioner\n5. Avsluta");
        printf("\nAnge val: ");
        scanf(" %d", &selection);
        switch (selection)
        {
        case 1:
            withdraw(active_account);
            break;
        case 2:
            deposit(active_account);
            break;
        case 3:
            display_balance(active_account);
            break;
        case 4:
            display_transactions(active_account);
            break;
        case 5:
            return;
        default:
            printf("Felaktig inmatning");
            break;
        }
    }
}
void deposit(Account* active_account)
{
    char input[STRLEN];
    float deposit_amount = 0;
    while (true)
    {
        printf("\nAnge belopp: ");
        scanf("%s%*[^\n]", input);
        deposit_amount = strtof(input, NULL);
        if (deposit_amount > 0)
        {
            printf("\nAmount: %.2f", deposit_amount);
            active_account->account_balance += deposit_amount;
            active_account->transaction_log[active_account->nr_transactions]
                = create_transaction(active_account->account_nr, deposit_amount, TRANSACTION_DEPOSIT);
            active_account->nr_transactions++;
            return;
        }
        else printf("\nFelaktig inmatning");
    }
}
void withdraw(Account* active_account)
{
    char input[STRLEN];
    float withdraw_amount = 0;
    while (true)
    {
        printf("\nAnge belopp: ");
        scanf("%s%[^\n]", input);
        withdraw_amount = strtof(input, NULL);

        if (withdraw_amount <= active_account->account_balance)
        {
            printf("\nAmount: %.2f", withdraw_amount);
            active_account->account_balance -= withdraw_amount;
            active_account->transaction_log[active_account->nr_transactions]
                = create_transaction(active_account->account_nr, withdraw_amount, TRANSACTION_WITHDRAWAL);
            active_account->nr_transactions++;
            return;
        }
        else printf("\nFelaktig inmatning");
    }
}
void display_balance(Account* active_account)
{
    printf("\nSaldo: %.2f", active_account->account_balance);
}
void display_transactions(Account* active_account)
{
    Transaction* log;
    if (active_account->nr_transactions > 0)
    {
        log = active_account->transaction_log;
        printf("\nKonto\tBelopp\t\tTyp\tDatum");
        for (int index = 0; index < active_account->nr_transactions; index++)
        {
            printf("\n%s\t%.2f\t\t%s\t%s", log[index].account_nr, log[index].amount,
                log[index].transaction_type, log[index].date);
        }


    }
    else printf("\nDet har kontot har inga transaktioner.");
}
Account* login(Account account_list[], int nr_accounts)
{
    char account_nr[STRLEN];
    Account* active_account;
    while (true)
    {
        printf("\nAnge kontonummer: ");
        scanf("%s%*[^\n]", account_nr);
        for (int index = 0; index < nr_accounts; index++)
        {
            if (!strcmp(account_list->account_nr, account_nr))
            {
                active_account = &account_list[index];
                return active_account;
            }
        }
        printf("\nHittade inget konto med det nummret.");
    }

}
void create_new_account(Account account_list[], int* nr_accounts)
{
    char new_account_nr[STRLEN];
    do
    {
        printf("\nAnge Kontonummer: ");
        scanf("%s", new_account_nr);
        if (account_exists(account_list, new_account_nr, nr_accounts)) {
            printf("\nKontonummer taget, ange ett nytt.");
        }
        else
            break;
    } while (true);
    account_list[*nr_accounts] = create_account(new_account_nr);
    (*nr_accounts)++;

}
bool account_exists(Account account_list[], const char* new_account_nr, int* nr_accounts)
{


    for (int index = 0; index < *nr_accounts; index++)
    {
        if (!strcmp(account_list[index].account_nr, new_account_nr))
            return true;
    }
    return false;
}
Account create_account(char account_nr[])
{
    Account new_account;

    strcpy(new_account.account_nr, account_nr);
    new_account.account_balance = 0;

    return new_account;
}
Transaction create_transaction(char account_nr[], float amount, char transaction_type[])
{
    Transaction new_transaction;

    strcpy(new_transaction.account_nr, account_nr);
    new_transaction.amount = amount;
    strcpy(new_transaction.transaction_type, transaction_type);
    strcpy(new_transaction.date, get_date());

    return new_transaction;

}
const char* get_date(void)
{
    char time_string[STRLEN];
    char* return_string = time_string;

    struct tm* units;
    time_t calendar = time(NULL);

    units = localtime(&calendar);
    strftime(time_string, STRLEN, "%x", units);
    return return_string; // check function
}
