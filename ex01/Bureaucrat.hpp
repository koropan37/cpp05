#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

class Form;

#include <string>
#include <iostream>
#include <exception>
//#include "Form.hpp"

#define HIGHEST_GRADE  1
#define LOWEST_GRADE 150

class  Bureaucrat {
 private:
	std::string const name_;
	int 			  grade_;

 public:
	Bureaucrat(const std::string& name = "", int grade = LOWEST_GRADE );
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	class GradeTooHighException : public std::exception {
	 public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	 public:
		virtual const char* what() const throw();
	};

	std::string getName() const;
	int			getGrade() const;

	void incrementGrade(int grade);
	void decrementGrade(int grade);

	void validateOverflow(long grade);

	void signForm(Form& form);
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &value);

#endif
