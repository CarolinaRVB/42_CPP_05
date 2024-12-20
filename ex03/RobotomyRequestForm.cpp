/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:07:51 by crebelo-          #+#    #+#             */
/*   Updated: 2024/11/20 14:49:53 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& robotomyRequestForm)
	: AForm(robotomyRequestForm), _target(robotomyRequestForm.getTarget()) {
	std::cout << "RobotomyRequestForm: copy constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target) : AForm("RobotomyForm", false, 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm: name constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm: destructor called\n";
}

std::string	const RobotomyRequestForm::getTarget() const {
	return (_target);
}

const char* RobotomyRequestForm::FailedToExecuteException::what(void) const throw() {
	return ("Robotomy request was not executed either due to low Bureaucrat's grade or form wasn't signed\n");
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& RobotomyRequestForm) {
	if (this == &RobotomyRequestForm) return (*this);
	
	AForm::operator=(RobotomyRequestForm);
	_target = RobotomyRequestForm.getTarget();
	
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (this->checkRequirements(executor)) {
		std::cout << "*** drilling noises ***\n"<<this->_target << " has been robotomized successfully 50% of the time\n";
	}
	else
		throw FailedToExecuteException();
}

std::ostream &operator<<(std::ostream& out, const RobotomyRequestForm& form) {
	out << std::boolalpha;
	out << form.getName() << ": signed status: " << form.getSigned() << ", grade to sign: " << form.getGradeSign()
		<< ", grade to execute: " << form.getGradeExec() << ", Target name: " << form.getTarget() << std::endl;
	
	return out;
}
