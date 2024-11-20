/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:14:40 by crebelo-          #+#    #+#             */
/*   Updated: 2024/11/20 10:16:05 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string.h>
# include <iostream>


/*

	- Custom exception classes included as nested classes inheriting from std::exception
	- We override the what() method to return custom messages
	- We perform encapsulation to make these exceptions specific to the Bureaucrat
	- Throw() is to garanty that the method does not throw exceptions
	- Throw *Exception* created a temporary object of the exception class and call it
*/


class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& bureaucrat);
		Bureaucrat(std::string const& name, unsigned int grade);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& bureaucrat);
		
		std::string const getName() const;
		int getGrade() const;
		
		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
	
	private:
		const std::string 	_name;
		int					_grade;
};

std::ostream &operator<<(std::ostream& out, const Bureaucrat& bureaucrat);


#endif