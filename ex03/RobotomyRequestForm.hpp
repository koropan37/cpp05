#ifndef ROBOTOMYREQUESTFORM_HPP_
#define ROBOTOMYREQUESTFORM_HPP_

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 private:
	void execAction() const;

 public:
	RobotomyRequestForm(const std::string& target = "");
	RobotomyRequestForm(const std::string& name, const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	AForm* create(const std::string& name, const std::string& target) const;
};

#endif
