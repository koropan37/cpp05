#include "PresidentialPardonForm.hpp"

#define FORM_NAME "PresidentialPardonForm"
#define SIGN_GRADE 25
#define EXEC_GRADE 5

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm(FORM_NAME, SIGN_GRADE, EXEC_GRADE, target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if(this != &other) AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execAction() const {
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." <<std::endl;
}
