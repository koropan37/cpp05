#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <string>
#include <iostream>
#include <exception>

#define HIGHEST_GRADE  1
#define LOWEST_GRADE 150

class  Bureaucrat {
 private:
	std::string name_;
	int 		grade_;

 public:
	Bureaucrat(const std::string& name = "", int grade = LOWEST_GRADE );
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	class GradeTooHighException : public std::exception {
	 public:
		virtual const char* what() const throw();
	};
	// class はデフォルトでは private なので public:をつけて外部から呼び出せるように
	// std::exception の what() は仮想関数(virtual 付)だが明示的につけることが推奨

	class GradeTooLowException : public std::exception {
	 public:
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
