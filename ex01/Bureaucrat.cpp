/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:31:20 by crebelo-          #+#    #+#             */
/*   Updated: 2024/11/11 09:48:42 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(1) {
   std::cout << "Bureaucrat: default constructor called\n"; 
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat)  : _name(bureaucrat._name), _grade(bureaucrat._grade) {
	std::cout << "Bureaucrat: copy constructor called\n";
}

Bureaucrat::Bureaucrat(std::string const& name, unsigned int grade) : _name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;

	std::cout << "Bureaucrat: name constructor called\n";
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat: Destructor called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat) {
	if (this == &bureaucrat) return (*this);
	
	_grade = bureaucrat._grade;
	
	std::cout << "Bureaucrat: copy assignement constructor called\n";
	return *this;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Grade is too low!");
}

std::string const Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getGrade() const {
	return (_grade);
}

void	Bureaucrat::signForm(Form *form) {
	if (_grade <= form->getGradeSign())
	{
		if (!form->getSigned())
			std::cout << this->_name << " signed " << form->getName() << std::endl;
		form->beSigned(*this);
	}
	else
		std::cout << this->_name << " couldn't sign " << form->getName() << " because grade is too low" << std::endl;		
}

void Bureaucrat::incrementGrade() {
	if (_grade > 1)
		_grade--;
	else
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
	if (_grade < 150)
		_grade++;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return out;
}
