/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 22:08:50 by crebelo-          #+#    #+#             */
/*   Updated: 2024/11/11 09:47:44 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("DefaultAForm"), _signed(false), _gradeSign(1), _gradeExec(1) {
   std::cout << "AForm: default constructor called\n"; 
}

AForm::AForm(const AForm& AForm)  : _name(AForm._name), _signed(AForm._signed),
								 _gradeSign(AForm._gradeSign), _gradeExec(AForm._gradeExec) {
	
	std::cout << "AForm: copy constructor called\n";
}

AForm::AForm(std::string const& name, bool sign, const int gradeSign, const int gradeExec)
			 :_name(name), _signed(sign), _gradeSign(gradeSign), _gradeExec(gradeExec) {
	
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
	std::cout << "AForm: name constructor called\n";
}

AForm::~AForm() {
	std::cout << "AForm: Destructor called\n";
}

AForm& AForm::operator=(const AForm& AForm) {
	if (this == &AForm) return (*this);
	
	_signed = AForm._signed;
	
	std::cout << "AForm: copy assignement constructor called\n";
	return *this;
}

const char* AForm::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high!");
}

const char* AForm::GradeTooLowException::what(void) const throw() {
	return ("Grade is too low!");
}

std::string const AForm::getName() const {
	return (_name);
}

bool AForm::getSigned() const {
	return (_signed);
}

int AForm::getGradeSign() const {
	return (_gradeSign);
}

int AForm::getGradeExec() const {
	return (_gradeExec);
}

bool AForm::checkRequirements(Bureaucrat const& bureaucrat) const {
	if (bureaucrat.getGrade() <= this->getGradeExec() && this->getSigned())
		return true;
	return false;
}

void	AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= _gradeSign)
	{
		if (_signed == true)
			std::cout << "Form is already signed";
		else
			_signed = true;
	}
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream& out, const AForm& AForm) {
	out << std::boolalpha;
	out << AForm.getName() << ": signed status: " << AForm.getSigned() << ", grade to sign: " << AForm.getGradeSign()
		<< ", grade to execute: " << AForm.getGradeExec() << std::endl;

	return out;
}
