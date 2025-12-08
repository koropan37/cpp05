#include "RobotomyRequestForm.hpp"
#include <cstdlib>

#define FORM_NAME "RobotomyRequestForm"
#define SIGN_GRADE 72
#define EXEC_GRADE 45

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm(FORM_NAME, SIGN_GRADE, EXEC_GRADE, target) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name, const std::string& target)
: AForm(name, SIGN_GRADE, EXEC_GRADE, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if(this != &other) AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execAction() const {
	std::cout << "boboboobo.boobobo" <<std::endl;
	if(std::rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully";
	else
		std::cout << this->getTarget() << " robotomy failed";
	std::cout << std::endl;
}

AForm* RobotomyRequestForm::create(const std::string& name, const std::string& target) const {
    return new RobotomyRequestForm(name, target);
}
