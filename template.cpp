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
	this->processTemplate();
	std::cout << this->subject <<  std::endl;
    return this->subject;
}
void Template::processTemplate() {
    std::istringstream ss(this->subject);
    std::string line;    
	this->processLine(this->subject);
}
void Template::processLine(std::string line) {
	int count = 0;
	std::string current;
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
				end = count+2;	
				std::string replace =  this->items[current];
				this->subject.replace(start, end - start, replace);
				isCollecting = false;
				return this->processTemplate();
			}
			if(c != ' ' && count > start+1) {	
				current += c;	
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
