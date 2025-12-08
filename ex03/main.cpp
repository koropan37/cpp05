#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define BLACK   "\033[0;30m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"
#define RESET   "\033[0m"
#define B_RED	"\033[1;31m"
#define B_GREEN "\033[1;32m"
#define B_CYAN  "\033[1;36m"

void printColor(std::string const& str, std::string const& color) {
    std::cout
	<< RESET << "======="
	<< color << str
	<< RESET << "=======" << color << std::endl;
}

int main(void) {
	std::srand(std::time(0));
	printColor("Constracutor", CYAN);
	try {
		Intern i1;
		AForm* form = i1.makeForm("shrubbery creation", "home");
		std::cout << *form << std::endl;
		Intern i2(i1);
		std::cout << *form << std::endl;
		Intern i3;
		i3 = i1;
		std::cout << *form << std::endl;
		delete form;
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	  }
	std::cout << std::endl;

	printColor("Intern Grade 42", BLUE);
	try {
		Bureaucrat b("Trump", 42);
		Intern intern;
		AForm* form = intern.makeForm("shrubbery creation", "home");
		if (form) {
			std::cout << *form << std::endl;
			b.signForm(*form);
			b.executeForm(*form);
			delete form;
		}
	std::cout << std::endl;

		form = intern.makeForm("robotomy request", "tommy");
		if (form) {
			std::cout << *form << std::endl;
			b.signForm(*form);
			b.executeForm(*form);
			delete form;
		}
	std::cout << std::endl;

		form = intern.makeForm("presidential pardon", "guiltiness");
		if (form) {
			std::cout << *form << std::endl;
			b.signForm(*form);
			b.executeForm(*form);
			delete form;
		}
	std::cout << std::endl;

		form = intern.makeForm("nothing", "invalid");
		if (form) {
			std::cout << *form << std::endl;
			b.signForm(*form);
			b.executeForm(*form);
			delete form;
		}
		} catch (std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
    }
	std::cout << std::endl;
	printColor("Intern Grade 1", GREEN);
	try {
		Bureaucrat b("Trump", 1);
		Intern intern;
		AForm* form = intern.makeForm("shrubbery creation", "home");
		if (form) {
			std::cout << *form << std::endl;
			b.signForm(*form);
			b.executeForm(*form);
			delete form;
		}
	std::cout << std::endl;

		form = intern.makeForm("robotomy request", "tommy");
		if (form) {
			std::cout << *form << std::endl;
			b.signForm(*form);
			b.executeForm(*form);
			delete form;
		}
	std::cout << std::endl;

		form = intern.makeForm("presidential pardon", "guiltiness");
		if (form) {
			std::cout << *form << std::endl;
			b.signForm(*form);
			b.executeForm(*form);
			delete form;
		}
	std::cout << std::endl;
		} catch (std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
    }

	printColor("Intern Grade 150", RED);
	try {
		Bureaucrat b("Trump", 150);
		Intern intern;
		AForm* form = intern.makeForm("shrubbery creation", "home");
		if (form) {
			std::cout << *form << std::endl;
			b.signForm(*form);
			b.executeForm(*form);
			delete form;
		}
	std::cout << std::endl;

		form = intern.makeForm("robotomy request", "tommy");
		if (form) {
			std::cout << *form << std::endl;
			b.signForm(*form);
			b.executeForm(*form);
			delete form;
		}
	std::cout << std::endl;

		form = intern.makeForm("presidential pardon", "guiltiness");
		if (form) {
			std::cout << *form << std::endl;
			b.signForm(*form);
			b.executeForm(*form);
			delete form;
		}
		} catch (std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
    }
	std::cout << std::endl;

}
