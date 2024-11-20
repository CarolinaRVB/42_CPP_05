/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:02:07 by crebelo-          #+#    #+#             */
/*   Updated: 2024/11/20 14:14:32 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string.h>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
		RobotomyRequestForm();
	
	public:
		RobotomyRequestForm(const RobotomyRequestForm& robotomyRequestForm);
		RobotomyRequestForm(std::string const& target);
		
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& robotomyRequestForm);

		class FailedToExecuteException : public std::exception {
			public:
				const char *what() const throw();
		};
		void		execute(Bureaucrat const& executor) const;
		std::string const getTarget() const;
		
};

std::ostream &operator<<(std::ostream& out, const RobotomyRequestForm& form);

#endif