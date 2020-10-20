#include "account.h"

void deposit(Account* active_account, int deposit_amount)
{
    // deposits amount to account balance, updates transaction log
    active_account->account_balance += deposit_amount;

    active_account->transaction_log[active_account->nr_transactions]
        = create_transaction(active_account->account_nr, deposit_amount, TRANSACTION_DEPOSIT);

    active_account->nr_transactions++;

    return;
}
bool valid_deposit(int deposit_amount)
{
    // checks if valid deposit amount
    if (deposit_amount > 0) return true;
    else return false;
}
void withdraw(Account* active_account, int withdraw_amount)
{
    // withdraws amount from account balance, updates transaction log
    active_account->account_balance -= withdraw_amount;

    active_account->transaction_log[active_account->nr_transactions]
        = create_transaction(active_account->account_nr, withdraw_amount, TRANSACTION_WITHDRAWAL);

    active_account->nr_transactions++;

    return;
}
bool valid_withdrawal(Account* active_account, int withdraw_amount)
{
    // checks if valid withdrawal amount
    if (withdraw_amount <= active_account->account_balance) return true;
    else return false;
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
    return return_string;
}
