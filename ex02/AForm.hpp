/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 22:08:54 by crebelo-          #+#    #+#             */
/*   Updated: 2024/11/20 10:50:38 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include "Bureaucrat.hpp"
# include <string.h>
# include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string   _name;
		bool                _signed;
		const int  			_gradeSign;
		const int  			_gradeExec;
		
	public:
		AForm();
		AForm(const AForm& AForm);
		AForm(std::string const& name, bool sign, const int gradeSign, const int gradeExec);
		AForm& operator=(const AForm& AForm);
		virtual ~AForm();

		std::string	const getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExec() const;

		void			beSigned(Bureaucrat& bureaucrat);
		bool			checkRequirements(Bureaucrat const& bureaucrat) const;
		virtual void	execute(Bureaucrat const& executor) const = 0;  // virtual function

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

};

std::ostream &operator<<(std::ostream& out, const AForm &AForm);

#endif
