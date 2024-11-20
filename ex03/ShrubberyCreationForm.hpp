/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:24:03 by crebelo-          #+#    #+#             */
/*   Updated: 2024/11/20 14:15:24 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFROM_HPP
# define SHRUBBERYCREATIONFROM_HPP

#define TREE "    *    \n" \
              "   ***   \n" \
              "  *****  \n" \
              " ******* \n" \
              "*********\n" \
              "   |||   \n" \
              "   |||   \n"

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <string.h>
# include <fstream>

class ShrubberyCreationForm: public AForm
{
	private:
		std::string	_target;
		ShrubberyCreationForm();
	
	public:
		ShrubberyCreationForm(const ShrubberyCreationForm& shrubberyCreationForm);
		ShrubberyCreationForm(std::string const& target);
		~ShrubberyCreationForm();

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& shrubberyCreationForm);
		
		class FailedToExecuteException : public std::exception {
			public:
				const char *what() const throw();
		};
		
		void		execute(Bureaucrat const& executor) const;
		std::string	const getTarget() const;
};

std::ostream &operator<<(std::ostream& out, const ShrubberyCreationForm& form);

#endif