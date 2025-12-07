#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
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
	std::srand(std::time(0)); //rand()を初期化する。これがないと乱数が同じになりやすい
	printColor("Constracutor", CYAN);
	try {
        Bureaucrat b("Trump", 42);
		RobotomyRequestForm r("rob");
		PresidentialPardonForm p("pre");
		ShrubberyCreationForm s("shr");
        std::cout << b << std::endl;
        std::cout << r << std::endl;
		std::cout << p << std::endl;
		std::cout << s << std::endl;
		b.signForm(r);
		std::cout << r << std::endl;
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	  }
	  std::cout << std::endl;

	printColor("Robotomy", YELLOW);
	try {
        Bureaucrat b("Trump", 42);
		RobotomyRequestForm r("rob");
        std::cout << b << std::endl;
        std::cout << r << std::endl;
		b.signForm(r);
		b.executeForm(r);
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	  }
	  std::cout << std::endl;
	try {
        Bureaucrat b("Trump", 150);
		RobotomyRequestForm r("rob");
        std::cout << b << std::endl;
        std::cout << r << std::endl;
		b.signForm(r);
		b.executeForm(r);
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	  }
	  std::cout << std::endl;
	try {
        Bureaucrat b("Trump", 50);
		RobotomyRequestForm r("rob");
        std::cout << b << std::endl;
        std::cout << r << std::endl;
		b.signForm(r);
		b.executeForm(r);
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	  }
	  std::cout << std::endl;

	printColor("Presidential", MAGENTA);
	try {
        Bureaucrat b("Trump", 5);
		PresidentialPardonForm p("pre");
        std::cout << b << std::endl;
        std::cout << p << std::endl;
		b.signForm(p);
		b.executeForm(p);
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	  }
	  std::cout << std::endl;
	try {
        Bureaucrat b("Trump", 150);
		PresidentialPardonForm p("pre");
        std::cout << b << std::endl;
        std::cout << p << std::endl;
		b.signForm(p);
		b.executeForm(p);
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	  }
	  std::cout << std::endl;
	try {
        Bureaucrat b("Trump", 20);
		PresidentialPardonForm p("pre");
        std::cout << b << std::endl;
        std::cout << p << std::endl;
		b.signForm(p);
		b.executeForm(p);
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	  }
	  std::cout << std::endl;
	printColor("Shrubbery", GREEN);
	try {
        Bureaucrat b("Trump", 42);
		ShrubberyCreationForm s("shr");
        std::cout << b << std::endl;
        std::cout << s << std::endl;
		b.signForm(s);
		b.executeForm(s);
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	  }
	  std::cout << std::endl;
	try {
        Bureaucrat b("Trump", 150);
		ShrubberyCreationForm s("ubb");
        std::cout << b << std::endl;
        std::cout << s << std::endl;
		b.signForm(s);
		b.executeForm(s);
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	  }
	  std::cout << std::endl;
	try {
        Bureaucrat b("Trump", 138);
		ShrubberyCreationForm s("ery");
        std::cout << b << std::endl;
        std::cout << s << std::endl;
		b.signForm(s);
		b.executeForm(s);
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	  }
	  std::cout << std::endl;
}
