/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGradeExceptions.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:26:57 by fde-capu          #+#    #+#             */
/*   Updated: 2021/05/19 15:28:57 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGRADEEXCEPTIONS_HPP
# define IGRADEEXCEPTIONS_HPP

# include <iostream>

class IGradeExceptions
{
	public:
		struct GradeTooHighException : public std::exception
		{
			const char * what() const throw()
			{
				return "Grade too HIGH!";
			}
		};
		struct GradeTooLowException : public std::exception
		{
			const char * what () const throw()
			{
				return "Grade too LOW!";
			}
		};
		int checkRange(int, int, int);
};

#endif
