/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:14:40 by crebelo-          #+#    #+#             */
/*   Updated: 2024/11/20 10:17:20 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

// Text colors
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define RESET   "\033[0m"

# include "Form.hpp"
# include <string.h>
# include <iostream>

class Form;

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& bureaucrat);
		Bureaucrat(std::string const& name, unsigned int grade);
		Bureaucrat& operator=(const Bureaucrat& bureaucrat);
		~Bureaucrat();
		
		std::string const getName() const;
		int 	getGrade() const;
		void	signForm(Form *form);		// Added this 
		
		void 	incrementGrade();
		void 	decrementGrade();

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
	
	private:
		const std::string	_name;
		int 				_grade;
};

std::ostream &operator<<(std::ostream& out, const Bureaucrat& bureaucrat);


#endif