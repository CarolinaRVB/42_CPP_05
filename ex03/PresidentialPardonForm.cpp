/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:13:59 by crebelo-          #+#    #+#             */
/*   Updated: 2024/11/20 11:00:13 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", false, 25, 5), _target("Default") {
// 	std::cout << "PresidentialPardonForm: default constructor called\n";
// }

// PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& presidentialPardonForm)
// 	: AForm(presidentialPardonForm), _target(presidentialPardonForm.getTarget()) {
// 	std::cout << "PresidentialPardonForm: copy constructor called\n";
// }

PresidentialPardonForm::PresidentialPardonForm(std::string const& target) : AForm("PresidentialPardonForm", false, 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm: name constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm: destructor called\n";
}

std::string	const PresidentialPardonForm::getTarget() const {
	return (_target);
}

const char* PresidentialPardonForm::FailedToExecuteException::what(void) const throw() {
	return ("Couldn't pardon either due to low Bureaucrat's grade or form wasn't signed\n");
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& presidentialPardonForm) {
	if (this == &presidentialPardonForm) return (*this);
	
	AForm::operator=(presidentialPardonForm);
	_target = presidentialPardonForm.getTarget();
	
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (this->checkRequirements(executor)) {
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox\n";
	}
	else
		throw FailedToExecuteException();
}

std::ostream &operator<<(std::ostream& out, const PresidentialPardonForm& form) {
	out << std::boolalpha;
		out << form.getName() << ": signed status: " << form.getSigned() << ", grade to sign: " << form.getGradeSign()
		<< ", grade to execute: " << form.getGradeExec() << "Target name: " << form.getTarget() << std::endl;
	
	return out;
}
