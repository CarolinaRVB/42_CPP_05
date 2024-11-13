/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:31:41 by crebelo-          #+#    #+#             */
/*   Updated: 2024/11/13 08:23:29 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <sstream>


int main() {
	std::cout << YELLOW;
	Intern someRandomIntern;
	AForm* r;
	AForm* s;
	AForm* p;
	AForm* fail;

	std::cout << "\n" GREEN;
	{
		try {
			r = someRandomIntern.makeForm("robotomy request", "Bender");
			std::cout << *r << std::endl;
			s = someRandomIntern.makeForm("shrubbery request", "Shrub");
			std::cout << *s << std::endl;
			p = someRandomIntern.makeForm("presidential request", "President");
			std::cout << *p << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << "Exception: " << e.what() << "\n";
		}
	}
	{
		try {
			fail = someRandomIntern.makeForm("invalid request", "Bender");
			if (fail)
				std::cout << *fail << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << "Exception: " << e.what() << "\n";
		}
	}
	
	std::cout << "\n" YELLOW;
	delete r;
	delete s;
	delete p;
}