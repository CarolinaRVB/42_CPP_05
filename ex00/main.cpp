/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:31:41 by crebelo-          #+#    #+#             */
/*   Updated: 2024/11/20 14:28:31 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void handler(Bureaucrat& bureaucrat, bool increment) {
	
	try
	{
		std::cout << "New Bureaucrat\n";
		std::cout << "Bureaucrat's name: " << bureaucrat.getName() << std::endl;
		std::cout << "Bureaucrat's initial grade: " << bureaucrat.getGrade() << std::endl;
		
		if (increment) {
			bureaucrat.incrementGrade();
			bureaucrat.incrementGrade();
		}
		else {
			bureaucrat.decrementGrade();
			bureaucrat.decrementGrade();
		}
	}
	catch(const Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << '\n';
	}
}


int main() {
	Bureaucrat	personHigh("PersonHigh", 2);
	Bureaucrat	personLow("PersonLow", 149);
	Bureaucrat	personTest1;
	personTest1 = personHigh;
	Bureaucrat	personTest2(personLow);
	Bureaucrat	personTest3;

	try {
		std::cout << "\nTesting invalid constructor" << "\n";
		Bureaucrat tooHigh("test", 0);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		std::cout << "\nTesting invalid constructor" << "\n";
		Bureaucrat tooLow("test", 151);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\n";
	personTest3 = personLow;
	std::cout << "\n";
	
	std::cout << "Testing operator '<<' overloader:" << "\n";
	std::cout << personHigh;
	std::cout << personLow;
	std::cout << personTest3;
	std::cout << "\n";

	std::cout << personTest1.getName() << " is a copy from personHigh" << std::endl; 
	std::cout << personTest2.getName() << " is a copy from personLow" << std::endl; 
	
	std::cout << "\n";
	
	handler(personHigh, true);
	std::cout << "\n";
	handler(personLow, false);

	std::cout << "\n";
	return 0;
}