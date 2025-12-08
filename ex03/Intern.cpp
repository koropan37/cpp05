#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

const std::string Intern::types_[3] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
};

Intern::Intern() {
    forms_[0] = new ShrubberyCreationForm("");
    forms_[1] = new RobotomyRequestForm("");
    forms_[2] = new PresidentialPardonForm("");
}

Intern::Intern(const Intern& other) {
    copyIntern(other);
}

Intern& Intern::operator=(const Intern& other) {
    if (this != &other) {
        deleteIntern();
        copyIntern(other);
    }
    return *this;
}

Intern::~Intern() {
    deleteIntern();
}

void Intern::copyIntern(const Intern& other) {
    for (int i = 0; i < 3; ++i) {
        if (other.forms_[i])

            forms_[i] = other.forms_[i]->create(other.forms_[i]->getName(), "");
        else
            forms_[i] = NULL;
    }
}

void Intern::deleteIntern() {
    for (int i = 0; i < 3; ++i) {
        delete forms_[i];
        forms_[i] = NULL;
    }
}

AForm* Intern::makeForm(const std::string& formname,
                        const std::string& target) {
    for (int i = 0; i < 3; ++i) {
        if (formname == types_[i]) {
            std::cout << "Intern creates " << formname << std::endl;
            return forms_[i]->create(formname, target);
        }
    }
    std::cerr << "Intern: unknown form '" << formname << "'" << std::endl;
    return NULL;
}

std::ostream& operator<<(std::ostream& os, const Intern& other) {
    (void)other;
    os << "Intern";
    return os;
}
