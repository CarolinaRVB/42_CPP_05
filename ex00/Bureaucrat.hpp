/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:14:40 by crebelo-          #+#    #+#             */
/*   Updated: 2024/10/14 19:24:30 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string.h>
# include <iostream>


class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& bureaucrat);
		Bureaucrat(std::string const& name, unsigned int grade);
		Bureaucrat& operator=(const Bureaucrat& bureaucrat);
		~Bureaucrat();
		
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
		const std::string _name;
		int _grade;
};

std::ostream &operator<<(std::ostream& out, const Bureaucrat& bureaucrat);


#endif