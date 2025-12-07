#ifndef AFORM_HPP_
#define AFORM_HPP_

class Bureaucrat;

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>

class AForm {
 private:
	std::string name_;
	bool 		is_signed_;
	int  		sign_grade_;
	int  		exec_grade_;

 public:
	AForm(const std::string& name = "",
		 int sign_grade = LOWEST_GRADE,
		 int exec_grade = LOWEST_GRADE);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	void beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception {
	 public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	 public:
		virtual const char* what() const throw();
	};

	class UnsignedException : public std::exception {
	 public:
		virtual const char* what() const throw();
	};

	std::string getName() const;
	bool 		getIsSigned() const;
	int 		getSignGrade() const;
	int 		getExecGrade() const;

	virtual void execAction() const = 0;
	void 		execute(Bureaucrat const& bureaucrat) const;
};

std::ostream& operator<<(std::ostream &out, const AForm &value);

#endif
