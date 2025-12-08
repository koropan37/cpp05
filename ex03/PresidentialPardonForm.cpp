#include "PresidentialPardonForm.hpp"

#define FORM_NAME "PresidentialPardonForm"
#define SIGN_GRADE 25
#define EXEC_GRADE 5

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm(FORM_NAME, SIGN_GRADE, EXEC_GRADE, target) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name, const std::string& target)
: AForm(name, SIGN_GRADE, EXEC_GRADE, target) {}

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

AForm* PresidentialPardonForm::create(const std::string& name, const std::string& target) const {
    return new PresidentialPardonForm(name, target);
}
