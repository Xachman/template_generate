#include "template.h"

Template::Template(const std::string &subject){
    this->subject = subject;
}
std::string Template::getFilepath() {
    return this->filepath;
}
void Template::setValue(std::string key, std::string value) {
    
}

std::string Template::getName() {
    return this->name;
}