/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:45:28 by crebelo-          #+#    #+#             */
/*   Updated: 2024/11/20 10:53:57 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*
	All of them can only take one parameter in their constructor: target,
	therefore the copy constructor and the default constructor should be removed?
*/

// ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyForm", false, 145, 137), _target("Default") {
// 	std::cout << "ShrubberyCreationForm: default constructor called\n";
// }

// ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& shrubberyCreationForm)
// 	: AForm(shrubberyCreationForm), _target(shrubberyCreationForm.getTarget()) {
// 	std::cout << "ShrubberyCreationForm: copy constructor called\n";
// }

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) : AForm("ShrubberyForm", false, 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm: name constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm: destructor called\n";
}

std::string	const ShrubberyCreationForm::getTarget() const {
	return (_target);
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& shrubberyCreationForm) {
	if (this == &shrubberyCreationForm) return (*this);
	
	AForm::operator=(shrubberyCreationForm);
	_target = shrubberyCreationForm.getTarget();
	
	return (*this);
}

const char* ShrubberyCreationForm::FailedToExecuteException::what(void) const throw() {
	return ("Shrubbery file was not created either due to low Bureaucrat's grade or form wasn't signed\n");
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (this->checkRequirements(executor))
	{
		std::string filename = _target + "_shrubbery";

		std::ofstream file(filename.c_str(), std::ios::app); //opens the file in append mode to write input at the end of it
		if (file.is_open()){
			file << TREE;
			file.close();
			std::cout << this->_target << " was created\n";
		}
		else
			std::cerr << "Error: couldn't open file.\n";
	}
	else
		throw FailedToExecuteException();
}

std::ostream &operator<<(std::ostream& out, const ShrubberyCreationForm& form) {
	out << std::boolalpha;
		out << form.getName() << ": signed status: " << form.getSigned() << ", grade to sign: " << form.getGradeSign()
		<< ", grade to execute: " << form.getGradeExec() << "Target name: " << form.getTarget() << std::endl;
	
	return out;
}
