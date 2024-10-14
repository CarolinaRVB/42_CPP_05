/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:31:41 by crebelo-          #+#    #+#             */
/*   Updated: 2024/10/14 19:34:28 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	{
		try
		{
			std::cout << "Bureaucrat whose grade will be too high:\n";
			Bureaucrat	personHigh("Person", 2);
			
			std::cout << "Bureaucrat's name: " << personHigh.getName() << std::endl;
			std::cout << "Bureaucrat's initial grade: " << personHigh.getGrade() << std::endl;
			personHigh.incrementGrade();
			personHigh.incrementGrade();
		}
		catch(const Bureaucrat::GradeTooHighException& e) {
			std::cerr << e.what() << '\n';
		}
		catch(const Bureaucrat::GradeTooLowException& e) {
			std::cerr << e.what() << '\n';
		}
	}

		{
		try
		{
			std::cout << "\nBureaucrat whose grade will be too low:\n";
			
			Bureaucrat	personLow("Person", 149);

			std::cout << "Bureaucrat's name: " << personLow.getName() << std::endl;
			std::cout << "Bureaucrat's initial grade: " << personLow.getGrade() << std::endl;
			personLow.decrementGrade();
			personLow.decrementGrade();
		}
		catch(const Bureaucrat::GradeTooHighException& e) {
			std::cerr << e.what() << '\n';
		}
		catch(const Bureaucrat::GradeTooLowException& e) {
			std::cerr << e.what() << '\n';
		}
	}

	return 0;
}