/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RatcliffObershelpSimilarity.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:07:26 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/21 18:59:32 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RATCLIFFOBERSHELPSIMILARITY_HPP
# define RATCLIFFOBERSHELPSIMILARITY_HPP
# include <string>
# include <iostream>

std::string bestMatch(const std::string, const std::string);

class RatcliffObershelpSimilarity
{
	private:
		const std::string a_;
		const std::string b_;
		unsigned long a_len_;
		unsigned long b_len_;
		unsigned long total_of_chars_;
		std::string best_substring_; 
		unsigned long substr_len_;
		unsigned long substr_at_a_;
		unsigned long substr_at_b_;
		double score_;
		std::string a_left_;
		std::string a_right_;
		std::string b_left_;
		std::string b_right_;
	public:
		RatcliffObershelpSimilarity(std::string, std::string);
		RatcliffObershelpSimilarity(RatcliffObershelpSimilarity const & src);
		RatcliffObershelpSimilarity & operator = (RatcliffObershelpSimilarity const & rhs);
		~RatcliffObershelpSimilarity(void);
		double getScoreRaw() const;
		double getScore() const;
		unsigned long getTotalOfChars() const;
};

std::ostream & operator << (std::ostream & o, RatcliffObershelpSimilarity const & self);

#endif
