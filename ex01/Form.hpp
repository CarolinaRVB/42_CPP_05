/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 22:08:54 by crebelo-          #+#    #+#             */
/*   Updated: 2024/11/13 05:18:45 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <string.h>
# include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string   _name;
		bool                _signed;
		int        			_gradeSign;
		int        			_gradeExec;
		
	public:
		Form();
		Form(const Form& form);
		Form(std::string const& name, bool sign, const int gradeSign, const int gradeExec);
		Form& operator=(const Form& form);
		~Form();

		std::string	const getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExec() const;

		void	beSigned(Bureaucrat& bureaucrat);

		/*
			Custom exceptions that inherit from the std::exception and override the
			what() method.
			In our main, thanks to polymorphism we can simply call the std::exception block as &e
			and it will call the respective overridden what() methods from either GradeTooHigh
			or GradeTooLow
		*/
	
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

};

std::ostream &operator<<(std::ostream& out, const Form &form);

#endif
