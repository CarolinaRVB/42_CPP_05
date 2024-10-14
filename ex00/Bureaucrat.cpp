/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:31:20 by crebelo-          #+#    #+#             */
/*   Updated: 2024/10/14 20:59:29 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(1) {
   std::cout << "Bureaucrat: default constructor called\n"; 
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat)  : _name(bureaucrat._name), _grade(bureaucrat._grade) {
	std::cout << "Bureaucrat: copy constructor called\n";
	
}

Bureaucrat::Bureaucrat(std::string const& name, unsigned int grade) : _name(name), _grade(grade) {
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
