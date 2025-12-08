#ifndef PRESIDENTIALPARDONFORM_HPP_
#define PRESIDENTIALPARDONFORM_HPP_

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 private:
 	void execAction() const;

 public:
	PresidentialPardonForm(const std::string& target = "");
	PresidentialPardonForm(const std::string& name, const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	AForm* create(const std::string& name, const std::string& target) const;
};

#endif
