/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:14:47 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/29 09:23:30 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Form.hpp"
#include <sstream>
#include "RatcliffObershelpSimilarity.hpp"

const Form * Intern::all_I_need_to_know[THIS_MANY_FORMS] = { ALL_I_KNOW };

Intern::Intern(void)
{
	return ;
}

Intern::Intern(Intern const & src)
{
	*this = src;
	return ;
}

Intern & Intern::operator = (Intern const & rhs)
{
	if (this != &rhs)
	{
//		this->member = rhs.getMember();
	}
	return *this;
}

std::ostream & operator << (std::ostream & o, Intern const & self)
{
	o << "::Intern::" << std::endl;
	(void)self;
	return o;
}

Intern::~Intern(void)
{
	for (int i = 0; i < THIS_MANY_FORMS; i++)
		delete all_I_need_to_know[i];
	return ;
}

Intern * Intern::clone() const
{
	return new Intern(*this);
}

Form * Intern::makeForm(std::string form_name, std::string form_target)
{
	toDo = thinkHard(form_name);
	if (toDo != 0)
	{
		toDo->setTarget(form_target);
		std::cout << "Intern creates " << *toDo << std::endl;
		return toDo;
	}
	else
	{
		std::cout << "[Explicit error]" << std::endl << "Intern: I - I c - could not understand what you asked for." << std::endl;
		return 0;
	}
}

bool too_similar(double a, double b)
{
	double x = a - b;
	if (x < 0.0) x *= -1;
	if (x < TEXT_SIMILARITY_READING) return true;
	return false;
}

int best_score(RatcliffObershelpSimilarity * score[THIS_MANY_FORMS])
{
	double best = 0;
	int out = 0;
	int confusion = 0;
	for (int i = 0; i < THIS_MANY_FORMS; i++)
	{
		if (static_cast<bool>(best) && too_similar(best, score[i]->getScore())) confusion = 1;
		if (score[i]->getScore() > best && !too_similar(best, score[i]->getScore())) confusion = 0;
		if (score[i]->getScore() > best) best = score[i]->getScore();
		if (score[i]->getScore() == best) out = i;
	}
	if (best < TEXT_SIMILARITY_READING || confusion) out = -1;
	return out;
}

Form * Intern::thinkHard(std::string poorly_writen_request)
{
	RatcliffObershelpSimilarity * score[THIS_MANY_FORMS];
	for (int i = 0; i < THIS_MANY_FORMS; i++)
	{
		score[i] = new RatcliffObershelpSimilarity \
		( \
			all_I_need_to_know[i]->getName(), \
			poorly_writen_request \
		);
	}
	int best = best_score(score);
	for (int i = 0; i < THIS_MANY_FORMS; i++)
		delete score[i];
	return best != -1 ? all_I_need_to_know[best]->clone() : 0;
}
