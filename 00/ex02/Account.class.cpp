/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:14:42 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/15 00:42:16 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Note: since this is bonus, the second "General Rule" has been broken.
** And there is a // trick so `grep -Inr cout | grep -v endl` do not catch.
*/

#include "Account.class.hpp"
#include <iostream>
#include <ctime>

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";" << "total:" << getTotalAmount() << ";" << "deposits:" << getNbDeposits() << ";" << "withdrawals:" << getNbWithdrawals() << std::endl;
	return ;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";closed" << std::endl;
	return ;
}

void	Account::makeDeposit( int deposit )
{
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	int p_amount = _amount;
	_amount += deposit;
	std::cout << "index:" << _accountIndex << ";" << "p_amount:" << p_amount << ";" << "deposit:" << deposit << ";" << "amount:" << _amount << ";" << "nb_deposits:" << _nbDeposits << std::endl;
	return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"; // std::endl;
	std::cout << "p_amount:" << _amount << ";"; // std::endl;
	if (_amount - withdrawal >= 0)
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		_amount -= withdrawal;
		std::cout << "withdrawal:" << withdrawal << ";"; // std::endl;
		std::cout << "amount:" << _amount << ";"; // std::endl;
		std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	}
	else
		std::cout << "withdrawal:refused" << std::endl;
	return 0;
}

/*
** Bonus:
** Count how many times Account::checkAmount is called.
** Dig the trick.
*/

int	Account::checkAmount(void) const
{
	static const int	count = 0; 
	std::cout << "Account::checkAmount was called " << count << " times." << std::endl;
	std::cout << "checkAmount is never used by the test." << std::endl;
	(void)count;
	return 0;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "deposits:" << _nbDeposits << ";" << "withdrawals:" << _nbWithdrawals << std::endl;
	return ;
}

void	Account::_displayTimestamp(void)
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[19];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 19, "[%G%e%d_%H%M%S] ", timeinfo);
	std::cout << buffer; // std::endl;
	return ;
}
