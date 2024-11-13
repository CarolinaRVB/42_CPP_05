/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:31:41 by crebelo-          #+#    #+#             */
/*   Updated: 2024/11/13 05:50:53 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	std::cout << YELLOW;

	Bureaucrat				personHigh("PersonHigh", 2);
	Bureaucrat				personLow("PersonLow", 149);
	Bureaucrat				personAdmin("Admin", 1);

	ShrubberyCreationForm	shrub_form("Home");
	RobotomyRequestForm		robo_form("Robo");
	PresidentialPardonForm	presidential_form("President");
	
	std::cout << RESET << "\n" BLUE;
	// std::cout << "Calling the Robotomy copy constructor: \n" YELLOW;
	// RobotomyRequestForm	robo_copy_form(robo_form);
	// std::cout << GREEN << robo_copy_form << "\n" BLUE;

	{
		try {
			std::cout << "Signing form to test the execute method\n" BLUE;
			robo_form.beSigned(personAdmin);
			
			std::cout << "Trying to execute Robo's execute method with valid Bureau: \n" GREEN;
			robo_form.execute(personHigh);
			std::cout << BLUE "\nTrying to execute Robo's execute method with invalid Bureau: \n" GREEN;
			robo_form.execute(personLow);
						
		} catch (const std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	{	
		try {
			std::cout << "Signing form to test the execute method\n" BLUE;
			shrub_form.beSigned(personAdmin);
			
			std::cout << "Trying to execute Shrub's execute method with valid Bureau: \n" GREEN;
			shrub_form.execute(personHigh);
			std::cout << BLUE "\nTrying to execute Shrub's execute method with invalid Bureau: \n" GREEN;
			shrub_form.execute(personLow);
						
		} catch (const std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	{	
		try {
			std::cout << "Signing form to test the execute method\n" BLUE;
			presidential_form.beSigned(personAdmin);
			
			std::cout << "Trying to execute Presidential's execute method with valid Bureau: \n" GREEN;
			presidential_form.execute(personHigh);
			std::cout << BLUE "\nTrying to execute Presidential's execute method with invalid Bureau: \n" GREEN;
			presidential_form.execute(personLow);
						
		} catch (const std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << YELLOW;

	return 0;
}
