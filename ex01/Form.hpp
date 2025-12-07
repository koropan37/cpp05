#ifndef FORM_HPP_
#define FORM_HPP_

class Bureaucrat;

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>

class Form {
 private:
	std::string name_;
	bool is_signed_;
	int sign_grade_;
	int exec_grade_;

 public:
	Form(const std::string& name = "",
		 int sign_grade = LOWEST_GRADE,
		 int exec_grade = LOWEST_GRADE);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	void beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception {
	 public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	 public:
		virtual const char* what() const throw();
	};

	std::string getName() const;
	bool 		getIsSigned() const;
	int 		getSignGrade() const;
	int 		getExecGrade() const;
};

std::ostream& operator<<(std::ostream &out, const Form &value);

#endif
