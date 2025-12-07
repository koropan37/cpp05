#include "AForm.hpp"
#include <iostream>

AForm::AForm(const std::string& name, int sign_grade, int exec_grade)
: name_(name),
 is_signed_(false),
 sign_grade_(sign_grade),
 exec_grade_(exec_grade) {
    if(sign_grade_ < HIGHEST_GRADE || exec_grade_ < HIGHEST_GRADE)
        throw GradeTooHighException();
    else if (exec_grade_ > LOWEST_GRADE || exec_grade_ > LOWEST_GRADE)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
: name_(other.name_),
  is_signed_(other.is_signed_),
  sign_grade_(other.sign_grade_),
  exec_grade_(other.exec_grade_) {}

AForm& AForm::operator=(const AForm& other) {
	if(this != &other) {
		name_  = other.name_;
		is_signed_ = other.is_signed_;
        sign_grade_ = other.sign_grade_;
        exec_grade_ = other.exec_grade_;
	}
	return *this;
}

AForm::~AForm() {}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if(bureaucrat.getGrade() > sign_grade_)
        throw GradeTooLowException();
    is_signed_ = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm: grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm: grade too low";
}

const char* AForm::UnsignedException::what() const throw() {
    return "Form is unsigned";
}

std::string AForm::getName() const { return name_; }
bool AForm::getIsSigned() const { return is_signed_; }
int AForm::getSignGrade() const { return sign_grade_; }
int AForm::getExecGrade() const { return exec_grade_; }

void AForm::execute(Bureaucrat const& bureaucrat) const {
    if(!is_signed_)
        throw UnsignedException();
    if(bureaucrat.getGrade() > exec_grade_)
        throw GradeTooLowException();
    execAction();
}

std::ostream& operator<<(std::ostream &out, const AForm &value) {
    out << value.getName() << ", "
        << (value.getIsSigned() ? "signed" : "unsigned") << ", "
        << "grade required to sign " << value.getSignGrade() << ", "
        << "grade required to execute " << value.getExecGrade() << ".";
    return out;
}
