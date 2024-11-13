/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 05:54:27 by crebelo-          #+#    #+#             */
/*   Updated: 2024/11/13 08:30:27 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern: Default constructor called\n";
}

Intern::Intern(const Intern& intern) {
	(void)intern;
}

Intern& Intern::operator=(const Intern& intern) {
	return (*this);
}

Intern::~Intern() {
	std::cout << "Intern: Destructor called\n";
}

int getAsciiCode(const std::string name) {
	int sum = 0;
	
	for (size_t i = 0; i < name.size(); i++) {
		sum += static_cast<int>(name[i]);
	}
	return sum;
}

const char *Intern::NoFormException::what(void) const throw() {
	return ("Error: form requested doesn't exist");
} 

AForm *Intern::makeForm(std::string name, std::string target) {
	int code = getAsciiCode(name);
	AForm *form = NULL;

	switch (code) {
		case 1700:
			form = new RobotomyRequestForm(target);
			break;
		case 1791:
			form = new ShrubberyCreationForm(target);
			break;
		case 2093:
			form = new PresidentialPardonForm(target);
			break;
		default:
			throw Intern::NoFormException();
	}
	return form;		
}
