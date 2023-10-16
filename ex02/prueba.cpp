#include "Account.hpp"
#include <iostream>

int main (void)
{
	Account	account(42), account1(35);

	Account::displayAccountsInfos();
	account.displayStatus();
	account1.displayStatus();
	account.makeDeposit(5);
	account1.makeDeposit(5);
	account.displayStatus();
	account1.displayStatus();
	account.makeWithdrawal(5);
	account1.makeWithdrawal(100);
	account.displayStatus();
	account1.displayStatus();
	Account::displayAccountsInfos();
}