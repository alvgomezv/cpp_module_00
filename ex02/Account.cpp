#include"Account.hpp"
#include<iostream>
#include<ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
	return ;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;
	Account::_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex << ";";
	std::cout << "amount:"<< this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex << ";";
	std::cout << "amount:"<< this->_amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
    std::cout << "total:" << Account::getTotalAmount() << ";";
    std::cout << "deposits:" << Account::getNbDeposits() << ";";
    std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void    Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";  
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t		now;
	struct tm	*ltm;

	now = time(0);
	ltm = localtime(&now);
	std::cout << "[" << 1900 + ltm->tm_year;
	std::cout << 1 + ltm->tm_mon;
	std::cout << ltm->tm_mday << "_";
	std::cout << ltm->tm_hour;
	std::cout << ltm->tm_min;
	std::cout << ltm->tm_sec << "] ";
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex << ";";
	std::cout << "p_amount:"<< this->_amount << ";";
	std::cout << "deposit:"<< deposit << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << "amount:"<< this->_amount << ";";
	std::cout << "nb_deposits:"<< this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex << ";";
	std::cout << "p_amount:"<< this->_amount << ";";
	std::cout << "withdrawal:";
	this->_amount -= withdrawal;
	if (Account::checkAmount() == 0)
	{
		this->_amount += withdrawal;
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << withdrawal << ";";
	std::cout << "amount:"<< this->_amount << ";";
	std::cout << "nb_withdrawals:"<< this->_nbWithdrawals << std::endl;
	return (true);
}

int  Account::getNbAccounts(void)
{
    return (Account::_nbAccounts);
}
int  Account::getTotalAmount(void)
{
    return (Account::_totalAmount);
}
int  Account::getNbDeposits(void)
{
    return (Account::_totalNbDeposits);
}
int  Account::getNbWithdrawals(void)
{
    return (Account::_totalNbWithdrawals);
}

int	Account::checkAmount(void) const
{
	if (this->_amount < 0)
		return (0);
	return (1);
}