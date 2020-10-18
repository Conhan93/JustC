#include "account.h"

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

            active_account->account_balance -= withdraw_amount;
            active_account->transaction_log[active_account->nr_transactions]
                = create_transaction(active_account->account_nr, withdraw_amount, TRANSACTION_WITHDRAWAL);
            active_account->nr_transactions++;
            return;
        }
        else printf("\nFelaktig inmatning");
    }
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
