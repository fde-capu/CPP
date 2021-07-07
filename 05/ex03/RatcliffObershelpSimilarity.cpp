/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RatcliffObershelpSimilarity.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:07:57 by fde-capu          #+#    #+#             */
/*   Updated: 2021/07/06 12:23:54 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RatcliffObershelpSimilarity.hpp"
#include <string>
#include <iostream>

std::string bestMatch(const std::string a, const std::string b)
{
	std::string shortstr = a.length() <= b.length() ? a : b;
	std::string largestr = b.length() >= a.length() ? b : a;
	size_t size = shortstr.length();
	size_t found = largestr.find(shortstr);
	if (found != std::string::npos)
		return largestr.substr(found, size);
	std::string recursion_l;
	std::string recursion_r;
	recursion_l = bestMatch(shortstr.substr(0, size - 1), largestr);
	recursion_r = bestMatch(shortstr.substr(1, size - 0), largestr);
	if (recursion_l.length() >= recursion_r.length())
		return recursion_l;
	else
		return recursion_r;
}

std::string stringToUpper(std::string s)
{
	for(unsigned long i = 0; i < s.length(); i++)
		s[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[i])));
	return s;
}

RatcliffObershelpSimilarity::RatcliffObershelpSimilarity(std::string u_a, std::string u_b)
: a_(stringToUpper(u_a)), b_(stringToUpper(u_b))
{
	a_len_ = a_.length();
	b_len_ = b_.length();
	total_of_chars_ = a_len_ + b_len_;
	if (!a_len_ || !b_len_)
	{
		score_ = 0;
		return ;
	}
	best_substring_ = bestMatch(a_, b_);
	if (best_substring_ == "")
	{
		score_ = 0;
		return ;
	}
	substr_len_ = best_substring_.length();
	substr_at_a_ = a_.find(best_substring_);
	substr_at_b_ = b_.find(best_substring_);
	score_ = substr_len_;
	a_left_ = a_.substr(0, substr_at_a_);
	a_right_ = a_.substr(a_left_.length() + substr_len_, std::string::npos);
	b_left_ = b_.substr(0, substr_at_b_);
	b_right_ = b_.substr(b_left_.length() + substr_len_, std::string::npos);
	RatcliffObershelpSimilarity l_recursive(a_left_, b_left_);
	RatcliffObershelpSimilarity r_recursive(a_right_, b_right_);
	score_ += l_recursive.getScoreRaw() + r_recursive.getScoreRaw();
	return ;
}

RatcliffObershelpSimilarity::RatcliffObershelpSimilarity(RatcliffObershelpSimilarity const & src)
{
	*this = src;
	return ;
}

RatcliffObershelpSimilarity & RatcliffObershelpSimilarity::operator = (RatcliffObershelpSimilarity const & rhs)
{
	if (this != &rhs)
	{
		score_ = rhs.getScoreRaw();
		total_of_chars_ = rhs.getTotalOfChars();
	}
	return *this;
}

std::ostream & operator << (std::ostream & o, RatcliffObershelpSimilarity const & self)
{
	o << self.getScore();
	return o;
}

RatcliffObershelpSimilarity::~RatcliffObershelpSimilarity(void)
{
	return ;
}

double RatcliffObershelpSimilarity::getScoreRaw() const
{
	return score_;
}

double RatcliffObershelpSimilarity::getScore() const
{
	return (2.0 * score_) / total_of_chars_;
}

unsigned long RatcliffObershelpSimilarity::getTotalOfChars() const
{
	return total_of_chars_;
}
