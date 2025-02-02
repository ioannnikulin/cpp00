#include <ctime>
#include <iostream>

#include "Account.hpp"

using std::cout;
using std::endl;

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	cout 
		<< "accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals()
		<< endl;
}

Account::Account( int initial_deposit )
	: _accountIndex(getNbAccounts())
	, _amount(initial_deposit)
	, _nbDeposits(0)
	, _nbWithdrawals(0)
{
	_nbAccounts ++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	cout
		<< "index:" << _accountIndex
		<< ";amount:" << checkAmount()
		<< ";created" << endl;
}

Account::~Account() {
	_displayTimestamp();
	cout
		<< "index:" << _accountIndex
		<< ";amount:" << checkAmount()
		<< ";closed" << endl;
}

void	Account::makeDeposit( int deposit ) {
	if (deposit < 0)
		return ;
	_amount += deposit;
	_nbDeposits ++;
	_totalAmount += deposit;
	_totalNbDeposits ++;
	_displayTimestamp();
	cout
		<< "index:" << _accountIndex
		<< ";p_amount:" << checkAmount() - deposit
		<< ";deposit:" << deposit
		<< ";amount:" << checkAmount()
		<< ";nb_deposits:" << _nbDeposits
		<< endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	if (withdrawal < 0)
		return (false);
	if (withdrawal > checkAmount()) {
		_displayTimestamp();
		cout
			<< "index:" << _accountIndex
			<< ";p_amount:" << checkAmount()
			<< ";withdrawal:refused"
			<< endl;
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals ++;
	_totalNbWithdrawals ++;
	_displayTimestamp();
	cout
		<< "index:" << _accountIndex
		<< ";p_amount:" << checkAmount() + withdrawal
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << checkAmount()
		<< ";nb_withdrawals:" << _nbWithdrawals
		<< endl;
	return (true);
}

int		Account::checkAmount( void ) const {
	return (_amount);
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	cout
		<< "index:" << _accountIndex
		<< ";amount:" << checkAmount()
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< endl;
}

void	Account::_displayTimestamp( void ) {
	std::time_t time = std::time(NULL);
	std::tm *local = std::localtime(&time);
	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", local);
	cout << buffer;
}