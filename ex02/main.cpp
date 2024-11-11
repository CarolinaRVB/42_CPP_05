/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:31:41 by crebelo-          #+#    #+#             */
/*   Updated: 2024/11/11 13:14:07 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	std::cout << YELLOW;

	// Create Bureaucrats with different grades
	Bureaucrat personHigh("PersonHigh", 2);   // High-ranking bureaucrat
	Bureaucrat personLow("PersonLow", 149);   // Low-ranking bureaucrat

	std::cout << RESET << "\n";
	std::cout << GREEN;

	// Create ShrubberyCreationForm with a target (e.g., a file name)
	ShrubberyCreationForm form1("Home");
	
	// Try signing the form with the high-ranking bureaucrat
	// try {
	// 	personHigh.signForm(form1);
	// } catch (const std::exception &e) {
	// 	std::cerr << "Exception: " << e.what() << std::endl;
	// }

	// Try executing the form with both bureaucrats
	try {
		std::cout << "\nExecuting form with PersonHigh:" << std::endl;
		form1.execute(personHigh);  // Should succeed

		std::cout << "\nExecuting form with PersonLow:" << std::endl;
		form1.execute(personLow);   // Should fail due to grade requirement
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << RESET;

	return 0;
}
