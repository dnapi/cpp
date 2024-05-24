#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void){
	return _nbAccounts;
}
int	Account::getTotalAmount(void){
	return _totalAmount;
}
int	Account::getNbDeposits(void){
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos(void){
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount 
		<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

//	[19920104_091532] index:0;amount:42;created
Account::Account(int initial_deposit){
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount +=initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" <<std::endl;
	return ;
}

//[19920104_091532] index:0;amount:47;closed
Account::~Account(void){
	_nbAccounts = 0;
	_totalAmount = 0;
	_totalNbDeposits = 0;
	_totalNbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex 
		<< ";amount:" << this->_amount 
		<< ";closed" <<std::endl;
	return ;
}

//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	Account::makeDeposit( int deposit ){
	int p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
		<< ";p_amount:" << p_amount
		<< ";deposit:" << deposit
		<< ";amount:" << this->_amount
		<< ";nb_deposits:" << this->_nbDeposits
		<<std::endl;
	return ;
};

//[19920104_091532] index:4;p_amount:1321;withdrawal:76;amount:1245;nb_withdrawals:1
//[19920104_091532] index:5;p_amount:23;withdrawal:refused
bool	Account::makeWithdrawal( int withdrawal ){
	int p_amount = this->_amount;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex 
		<< ";p_amount:" << p_amount
		<< ";withdrawal:";
	if (this->_amount < withdrawal){
		std::cout << "refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << withdrawal
		<< ";amount:" << this->_amount 
		<< ";nb_withdrawals:" << this->_nbWithdrawals 
		<< std::endl;
	return true;
}	

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount 
		<< ";deposits:" << this->_nbDeposits << ";withdrawals:" << _nbWithdrawals <<std::endl;
	return ;
}

void	Account::_displayTimestamp(void){
    std::time_t now = std::time(0);
    std::tm* now_local = std::localtime(&now);
	char buffer[80];

    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", now_local);
    std::cout << buffer;
 }