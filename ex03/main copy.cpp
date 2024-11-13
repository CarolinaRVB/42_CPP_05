/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:31:41 by crebelo-          #+#    #+#             */
/*   Updated: 2024/11/13 04:54:15 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	std::cout << YELLOW;
	Bureaucrat	personHigh("PersonHigh", 2);
	Bureaucrat	personLow("PersonLow", 149);
	Form	form1("Form1", false, 5, 3);
	Form	form2("Form2", false, 5, 3);
	Form	form3("Form3", false, 5, 3);
	
	std::cout << RESET << "\n";
	std::cout << GREEN;
	std::cout << form1;
	std::cout << RESET << "\n";

	{
		std::cout << BLUE "Bureaucrat valid attempt to sign form: " GREEN;
		personHigh.signForm(&form1);			
		std::cout << BLUE << "Form status: " << GREEN << form1.getSigned() << RESET << "\n";	
		
		std::cout << BLUE "Bureaucrat atempt to sign form that's already signed: " GREEN;
		personHigh.signForm(&form1);
		std::cout << "\n";
		
		std::cout << BLUE << "Bureaucrat invalid attempting to sign form: " << GREEN;
		personLow.signForm(&form2);
		std::cout << BLUE << "Form status: " << GREEN << form2.getSigned() << RESET << "\n";	
	}
	
	{
		try {
			std::cout << BLUE << "Testing Form beSigned method with invalid Bureaucrat: " << GREEN;
			form3.beSigned(personLow);
		}
		catch (const std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	
	{
		try {
			std::cout << BLUE << "Testing Form beSigned method with valid Bureaucrat: " << GREEN;
			form3.beSigned(personHigh);
			std::cout << form3;
			std::cout << BLUE "Testing Form beSigned method on signed form: " GREEN;
			form3.beSigned(personHigh);
			std::cout << "\n";
		}
		catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	
	{
		try {
			std::cout << BLUE << "Testing invalid Form constuctor - grade too low exception: " << GREEN;
			Form invalidForm("Invalid", true, 151, 151);
		}
		catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	
	std::cout << "\n" << YELLOW;

	return 0;
}