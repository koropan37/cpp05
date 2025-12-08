#ifndef SHRUBBERYCREATIONFORM_HPP_
#define SHRUBBERYCREATIONFORM_HPP_

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 private:
	void execAction() const;

 public:
	ShrubberyCreationForm(const std::string& target = "");
	ShrubberyCreationForm(const std::string& name, const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	AForm* create(const std::string& name, const std::string& target) const;
};

#endif
