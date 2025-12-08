#ifndef INTERN_HPP_
#define INTERN_HPP_

#include "AForm.hpp"
#include <iostream>
#include <string>

class Intern {
 private:
	AForm* forms_[3];
	static const std::string types_[3];

 public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& formname, const std::string& target);

    void copyIntern(const Intern& other);
    void deleteIntern();
};

std::ostream& operator<<(std::ostream& os, const Intern& other);

#endif
