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
    std::istringstream ss(this->subject);
    std::string line;    
    while (std::getline(ss, line)) {
		this->processLine(line);
    }
    return this->subject;
}
void Template::processLine(std::string line) {
	int count = 0;
	bool isCollecting = false;
	int start = 0;
	int end = 0;
	for(char& c : line) {
		if(this->isOpenSep(line[count], line[count-1]))	{
			isCollecting = true;
			start = count-1;
		}
		if(isCollecting) {
			if(this->isCloseSep(line[count], line[count+1])) {
				end = count;	
				this->subject.replace(start, end, this->items[this->current]);
				isCollecting = false;
			}
			if(c != ' ' && count > start+1) {	
				this->current += c;	
			}
		}
		count++;
	}
}

bool Template::isOpenSep(const char& char1, const char& char2) {
	if(char1 == '{' && char2 == '{') {
		return true;
	}
	return false;
}
bool Template::isCloseSep(const char& char1, const char& char2) {
	if(char1 == '}' && char2 == '}') {
		return true;
	}
	return false;
}
