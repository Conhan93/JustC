#ifndef ACCOUNT_INFO_INCLUDED
#define ACCOUNT_INFO_INCLUDED
#include <time.h>
#include <string.h>
#include <stdlib.h>
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

void deposit(Account* active_account, int deposit_amount);
bool valid_deposit(int deposit_amount);
void withdraw(Account* active_account, int withdraw_amount);
bool valid_withdrawal(Account* active_account, int withdraw_amount);


Transaction create_transaction(char account_nr[], float amount, char transaction_type[]);
Account create_account(char account_nr[]);
const char* get_date(void);


#endif // ACCOUNT_INFO_INCLUDED