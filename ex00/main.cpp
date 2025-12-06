#include "Bureaucrat.hpp"
#include <iostream>

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
	printColor("CONSTRUCTOR", CYAN);
    try {
        Bureaucrat b("Trump", 0);
        std::cout << b << std::endl;
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	  }
	  std::cout << std::endl;
	try {
        Bureaucrat b("Trump", 1);
        std::cout << b << std::endl;
		std::cout << b.getName() << std::endl;
		std::cout << b.getGrade() << std::endl;
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	  }
	  std::cout << std::endl;
	try {
        Bureaucrat b("Trump", 151);
        std::cout << b << std::endl;
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	  }
	std::cout << std::endl;
	printColor("Increment", GREEN);
	try {
        Bureaucrat b("Trump", 42);
        std::cout << b << std::endl;
      	b.incrementGrade(1);
      	std::cout << b << std::endl;
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	  }
	  std::cout << std::endl;
	try {
        Bureaucrat b("Trump", 1);
        std::cout << b << std::endl;
      	b.incrementGrade(2147483647);
      	std::cout << b << std::endl;
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	  }
	  std::cout << std::endl;
	try {
        Bureaucrat b("Trump", 150);
        std::cout << b << std::endl;
      	b.incrementGrade(1);
      	std::cout << b << std::endl;
		b.incrementGrade(-2147483648);
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	  }
	std::cout << std::endl;
	printColor("Decrement", YELLOW);
	try {
        Bureaucrat b("Trump", 42);
        std::cout << b << std::endl;
      	b.decrementGrade(1);
      	std::cout << b << std::endl;
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	  }
	  std::cout << std::endl;
	try {
        Bureaucrat b("Trump", 1);
        std::cout << b << std::endl;
      	b.decrementGrade(1);
      	std::cout << b << std::endl;
      	b.decrementGrade(2147483647);
      	std::cout << b << std::endl;
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	  }
	  std::cout << std::endl;
	try {
        Bureaucrat b("Trump", 150);
        std::cout << b << std::endl;
		b.decrementGrade(-2147483648);
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	  }
	  std::cout << std::endl;
}
