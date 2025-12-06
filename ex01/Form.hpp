#ifndef FORM_HPP_
#define FORM_HPP_

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>

class Form {
 private:
	std::string name_;
	bool is_signed_;
	const int grade_to_sign_;
	const int grade_to_execute_;

 public:
	Form(const std::string& name = "",
		 int grade_to_sign 	  = LOWEST_GRADE,
		 int grade_to_execute = LOWEST_GRADE);
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

	std::string getName(void) const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
};

std::ostream& operator<<(std::ostream &out, const Form &value);

#endif
