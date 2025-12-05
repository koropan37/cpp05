#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <string>
#include <iostream>
#include <exception>

class  Bureaucrat {
 private:
	std::string name_;
	int 		grade_;

	static const int highest_grade_ = 1;
	static const int lowest_grade_ = 150;

 public:
	Bureaucrat(const std::string& name = "", int grade = lowest_grade_ );
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	class GradeTooHighException : public std::exception {
	 public:
	  	GradeTooHighException() throw();
    	virtual ~GradeTooHighException() throw();
		virtual const char* what() const throw();
	};
	// class はデフォルトでは private なので public:をつけて外部から呼び出せるように
	// std::exception の what() は仮想関数(virtual 付)だが明示的につけることが推奨

	class GradeTooLowException : public std::exception {
	 public:
		GradeTooLowException() throw();
    	virtual ~GradeTooLowException() throw();
		virtual const char* what() const throw();
	};

	std::string getName(void) const;
	int			getGrade(void) const;

	void incrementGrade(int grade);
	void decrementGrade(int grade);

	void validateOverflow(long grade);
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &value);

#endif
