#include "Account.hpp"
#include <sys/time.h>
#include <iostream>

void print_number(long int num)
{
	if (num < 10)
		std::cout << "0";
	std::cout << num;
}

void print_and_calculate(long int num)
{
	int i;
	int days[12];

	i = -1;
	while (++i < 12)
	{
		if (i == 1)
			days[i] = 28;
		else if (i % 2)
			days[i] = 30;
		else
			days[i] = 31;
	}
	i = 0;
	num++;
	while (num > days[i])
		num -= days[i++];
	print_number(i + 1);
	print_number(num);
}

void print_time(void)
{
	struct timeval ctime;

	gettimeofday(&ctime, NULL);
	print_number((ctime.tv_sec) / (365.25 * 24 * 60 * 60) + 1970);
	print_and_calculate((ctime.tv_sec % (long int)(60*60*24*(365.25)) / (60*60*24)));
	std::cout << "_";
	print_number(((ctime.tv_sec % (60*60*24)) / 3600) + 1);
	print_number((ctime.tv_sec % 3600) / 60);
	print_number(ctime.tv_sec % 60);
}


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


Account::Account()
{
	_accountIndex = 0;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

Account::Account(int num)
{
	this->_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts++;
	std::cout << "index:" << this->_accountIndex;
	this->_amount = num;
	std::cout << ";amount:" << this->_amount;
	Account::_totalAmount += num;
	std::cout << ";created\n";
}

Account::~Account(void)
{
	this->_displayTimestamp();
	this->_accountIndex = --Account::_nbAccounts;
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	Account::_totalAmount -= this->_amount;
	std::cout << ";closed\n";
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts;
	std::cout << ";total:" << Account::_totalAmount;
	std::cout << ";deposits:" << Account::_totalNbDeposits;
	std::cout << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp()
{
	std::cout << "[";
	print_time();
	std::cout << "] ";
}

void	Account::displayStatus(void) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	this -> _amount += deposit;
	this->_totalAmount += deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withd)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";withdrawal:";
	if (withd > this->_amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_amount -= withd;
	this->_totalAmount -= withd;
	std::cout << withd << ";amount:" << this->_amount;
	std::cout << ";nb_withdrawals:" << ++this->_nbWithdrawals << std::endl;
	Account::_totalNbWithdrawals++;
	return (true);
}	
