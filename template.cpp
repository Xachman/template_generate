#include "template.h"

Template::Template(std::string name, std::string filepath)
:name(name), filepath(filepath)  {

}

std::string Template::getFilepath() {
    return this->filepath;
}


std::string Template::getName() {
    return this->name;
}