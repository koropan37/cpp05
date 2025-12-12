#include "Form.hpp"
#include <iostream>

Form::Form(const std::string& name, int sign_grade, int exec_grade)
: name_(name),
 is_signed_(false),
 sign_grade_(sign_grade),
 exec_grade_(exec_grade) {
    if(sign_grade_ < HIGHEST_GRADE || exec_grade_ < HIGHEST_GRADE)
        throw GradeTooHighException();
    if (sign_grade_ > LOWEST_GRADE || exec_grade_ > LOWEST_GRADE)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
: name_(other.name_),
  is_signed_(other.is_signed_),
  sign_grade_(other.sign_grade_),
  exec_grade_(other.exec_grade_) {}

Form& Form::operator=(const Form& other) {
	if(this != &other) {
		is_signed_ = other.is_signed_;
	}
	return *this;
}

Form::~Form() {}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (is_signed_)
        throw AlreadySignedException();
    if(bureaucrat.getGrade() > sign_grade_)
        throw GradeTooLowException();
    is_signed_ = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form: grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form: grade too low";
}

const char* Form::AlreadySignedException::what() const throw() {
    return "Form: already signed";
}

std::string Form::getName() const { return name_; }
bool Form::getIsSigned() const { return is_signed_; }
int Form::getSignGrade() const { return sign_grade_; }
int Form::getExecGrade() const { return exec_grade_; }

std::ostream& operator<<(std::ostream &out, const Form &value) {
    out << value.getName() << ", "
        << (value.getIsSigned() ? "signed" : "unsigned") << ", "
        << "grade required to sign " << value.getSignGrade() << ", "
        << "grade required to execute " << value.getExecGrade() << ".";
    return out;
}
