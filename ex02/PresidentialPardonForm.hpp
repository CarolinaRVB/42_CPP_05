/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    PresidentialPardonForm.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:11:43 by crebelo-          #+#    #+#             */
/*   Updated: 2024/11/11 13:08:31 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    private:
		std::string _target;
	
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& PresidentialPardonForm);
		PresidentialPardonForm(std::string const& target);
		
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& PresidentialPardonForm);

		class FailedToExecuteException : public std::exception {
			public:
				const char *what() const throw();
		};

		void		execute(Bureaucrat const& executor) const;
		std::string const getTarget() const;
		
};

std::ostream &operator<<(std::ostream& out, const PresidentialPardonForm& form);


#endif