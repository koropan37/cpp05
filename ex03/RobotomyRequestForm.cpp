#include "RobotomyRequestForm.hpp"
#include <cstdlib>

#define FORM_NAME "RobotomyRequestForm"
#define SIGN_GRADE 72
#define EXEC_GRADE 45

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm(FORM_NAME, SIGN_GRADE, EXEC_GRADE), target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other), target_(other.target_) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if(this != &other) {
		AForm::operator=(other);
		target_ = other.target_;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execAction() const {
	std::cout << "boboboobo.boobobo" <<std::endl;
	if(std::rand() % 2)
		std::cout << target_ << " has been robotomized successfully";
	else
		std::cout << target_ << " robotomy failed";
	std::cout << std::endl;
}
