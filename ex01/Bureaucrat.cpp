#include "Bureaucrat.hpp"
#include <iostream>
#include <limits>

Bureaucrat::Bureaucrat(const std::string& name, int grade)
: name_(name), grade_(grade) {
	if	   (grade < highest_grade_)  throw GradeTooHighException();
	else if(grade > lowest_grade_)   throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
: name_(other.name_), grade_(other.grade_) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if(this != &other) {
		name_  = other.name_;
		grade_ = other.grade_;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::GradeTooHighException::GradeTooHighException() throw() {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat: grade too high";
}

Bureaucrat::GradeTooLowException::GradeTooLowException() throw() {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat: grade too low";
}

std::string Bureaucrat::getName() const { return name_; }

int			Bureaucrat::getGrade() const { return grade_; }

void Bureaucrat::incrementGrade(int grade) {
	long tmp = static_cast<long>(grade_) - static_cast<long>(grade);
	validateOverflow(tmp);
	if(tmp < highest_grade_) throw GradeTooHighException();
	if(tmp > lowest_grade_)  throw GradeTooLowException();
	grade_ = static_cast<int>(tmp);
}

void Bureaucrat::decrementGrade(int grade) {
	long tmp = static_cast<long>(grade_) + static_cast<long>(grade);
	validateOverflow(tmp);
	if(tmp < highest_grade_) throw GradeTooHighException();
	if(tmp > lowest_grade_)  throw GradeTooLowException();
	grade_ = static_cast<int>(tmp);
}

void Bureaucrat::validateOverflow(long grade) {
    const long max = static_cast<long>(std::numeric_limits<int>::max());
    const long min = static_cast<long>(std::numeric_limits<int>::min());
    if (grade < min) throw GradeTooHighException();
    if (grade > max) throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const& value) {
	out << value.getName() << ", bureaucrat grade"
		<< value.getGrade() << ".";
	return out;
}
