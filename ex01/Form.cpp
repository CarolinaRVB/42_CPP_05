/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 22:08:50 by crebelo-          #+#    #+#             */
/*   Updated: 2024/11/14 08:06:14 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("DefaultForm"), _signed(false), _gradeSign(1), _gradeExec(1) {
   std::cout << "Form: default constructor called\n"; 
}

Form::Form(const Form& form)  : _name(form._name), _signed(form._signed),
								 _gradeSign(form._gradeSign), _gradeExec(form._gradeExec) {
	std::cout << "Form: copy constructor called\n";
}

Form::Form(std::string const& name, bool sign, const int gradeSign, const int gradeExec)
			 :_name(name), _signed(sign) {
	
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
	else {
		_gradeSign = gradeSign;
		_gradeExec = gradeExec;
	}
	std::cout << "Form: name constructor called\n";
}

Form::~Form() {
	std::cout << "Form: Destructor called\n";
}

Form& Form::operator=(const Form& form) {
	if (this == &form) return (*this);
	
	_signed = form._signed;
	_gradeSign = form._gradeSign;
	_gradeExec = form._gradeExec;

	std::cout << "Form: copy assignement constructor called\n";
	return *this;
}

const char* Form::GradeTooHighException::what(void) const throw() {
	return ("Grade to sign form is too high!");
}

const char* Form::GradeTooLowException::what(void) const throw() {
	return ("Grade to sign form is too low!");
}

std::string const Form::getName() const {
	return (_name);
}

bool Form::getSigned() const {
	return (_signed);
}

int Form::getGradeSign() const {
	return (_gradeSign);
}

int Form::getGradeExec() const {
	return (_gradeExec);
}

void	Form::beSigned(Bureaucrat &bureaucrat) {
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

std::ostream &operator<<(std::ostream& out, const Form& form) {
	out << std::boolalpha;
	out << form.getName() << ": signed status: " << form.getSigned() << ", grade to sign: " << form.getGradeSign()
		<< ", grade to execute: " << form.getGradeExec() << std::endl;

	return out;
}
