#include "template.h"
#include <sstream>
#include <iostream>

Template::Template(const std::string &subject){
    this->subject = subject;
}
std::string Template::getFilepath() {
    return this->filepath;
}
void Template::setValue(std::string key, std::string value) {
   this->items[key] = value; 
}

std::string Template::getName() {
    return this->name;
}

std::string Template::generateTemplate() {
    std::istringstream f(this->subject);
    std::string line;    
    while (std::getline(f, line)) {
        std::cout << line << std::endl;
	int count = 0;
	for(char& c : line) {
	    if(this->isOpenSep(line[count], line[count-1])) {
	    
	    }
	    count++;
	}
    }
    return "";
}