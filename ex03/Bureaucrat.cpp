#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <limits>

Bureaucrat::Bureaucrat(const std::string& name, int grade)
: name_(name), grade_(grade) {
	if	   (grade < HIGHEST_GRADE)  throw GradeTooHighException();
	else if(grade > LOWEST_GRADE)   throw GradeTooLowException();
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

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat: grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat: grade too low";
}

std::string Bureaucrat::getName() const { return name_; }

int			Bureaucrat::getGrade() const { return grade_; }

void Bureaucrat::incrementGrade(int grade) {
	long tmp = static_cast<long>(grade_) - static_cast<long>(grade);
	validateOverflow(tmp);
	if(tmp < HIGHEST_GRADE) throw GradeTooHighException();
	if(tmp > LOWEST_GRADE)  throw GradeTooLowException();
	grade_ = static_cast<int>(tmp);
}

void Bureaucrat::decrementGrade(int grade) {
	long tmp = static_cast<long>(grade_) + static_cast<long>(grade);
	validateOverflow(tmp);
	if(tmp < HIGHEST_GRADE) throw GradeTooHighException();
	if(tmp > LOWEST_GRADE)  throw GradeTooLowException();
	grade_ = static_cast<int>(tmp);
}

void Bureaucrat::validateOverflow(long grade) {
    const long max = static_cast<long>(std::numeric_limits<int>::max());
    const long min = static_cast<long>(std::numeric_limits<int>::min());
    if (grade < min) throw GradeTooHighException();
    if (grade > max) throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const& value) {
	out << value.getName() << ", bureaucrat grade "
		<< value.getGrade() << ".";
	return out;
}

void Bureaucrat::signForm(AForm& form) {
    if (form.getIsSigned()) {
        std::cerr << name_ << " couldn't sign " << form.getName()
                  << " because already signed" << std::endl;
        return;
    }
    try {
        form.beSigned(*this);
        std::cerr << name_ << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << name_ << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const& form) {
	try {
		form.execute(*this);
		std::cout << name_ << " executed " << form.getName() <<std::endl;
	} catch (std::exception& e) {
		std::cerr << name_ << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
	}
}
