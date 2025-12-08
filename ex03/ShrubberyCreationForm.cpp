#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

#define FORM_NAME "ShrubberyCreationForm"
#define SIGN_GRADE 145
#define EXEC_GRADE 137
#define GREEN   "\033[0;32m"
#define WHITE   "\033[0;37m"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm(FORM_NAME, SIGN_GRADE, EXEC_GRADE, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name, const std::string& target)
: AForm(name, SIGN_GRADE, EXEC_GRADE, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if(this != &other) AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

static std::string printtree() {

return std::string(
"\n"
"           /*&&& &&* & &&\n"
"        && &\\/&\\|& ()|/ @, &&\n"
"        &\\/(/&/&||/& /_/)_&/_&\n"
"     &() &\\/&|()|/&\\/\\'%\" & () &\n"
"    &_\\_&&_\\ |& |&&/&__%_/_& & ()&\n"
"    &&   && & &| &| /& & % ()& /&&\n"
"     ()&_---()&\\&\\|&&-&&--%---()~\n"
"         &&    /\\|||		*'*	\n"
"                ||||\n"
"                ||||\n"
"                ||||\n"
"                ||||\n"
"          , -=-~  .-^- _*/\n"
);
}

void ShrubberyCreationForm::execAction() const {
    std::ofstream ofs((getTarget() + "_shrubbery").c_str());
    if(!ofs) throw std::runtime_error("Error: fail to open file");

    ofs << "\n" << printtree() << std::endl;
    return ;
}

AForm* ShrubberyCreationForm::create(const std::string& name, const std::string& target) const {
    return new ShrubberyCreationForm(name, target);
}
