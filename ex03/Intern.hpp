/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 05:54:29 by crebelo-          #+#    #+#             */
/*   Updated: 2024/11/20 14:59:14 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern {	
	public:
		Intern();
		Intern(const Intern& intern);
		~Intern();

		Intern& operator=(const Intern& intern);
		
		AForm	*makeForm(std::string name, std::string target);
		class NoFormException :public std::exception {
			public:
				const char *what() const throw();
		};
};

int getAsciiCode(const std::string target);

#endif
