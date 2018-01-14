#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include "cxxops.hpp"
#include "template.h"


int main(int argc, char **argv) {
	std::vector<std::string> items;
	cxxopts::Options options("Template Parse", "Parse Templates using mustache like syntax");
	options.add_options()
	  ("d,debug", "Enable debugging")
	  ("f,file", "File name", cxxopts::value<std::string>()->default_value(""))
	  ("s,subject", "Subject string", cxxopts::value<std::string>()->default_value(""))
	  ("i,item", "Key value pair", cxxopts::value<std::vector<std::string>>(items))
	  ;
	auto result = options.parse(argc, argv);
	bool noFile=false;
	bool noSub=false;
	std::string file = result["f"].as<std::string>();
	std::string inputSubject = result["s"].as<std::string>();

	if(file.compare("") == 0 && inputSubject.compare("") == 0) {
		std::cout << "Please specify a file or subject" << std::endl;
		exit(1);
	}
	options.parse_positional({"i,item"});
	std::string subject;
	if(file.compare("") != 0) {
		std::ifstream inFile(file);
		if(!inFile) {
			std::cout << "Cant read from file" << std::endl;
			exit(2);
		}
		subject = std::string((std::istreambuf_iterator<char>(inFile)),
                 std::istreambuf_iterator<char>());
	}else{
		subject = inputSubject;
	}	
	Template tmp = Template(subject);
	int itemCount = result.count("i");
	for(int i = 0; i < itemCount; i++) {
		std::string item = items[i];
		std::string key = item.substr(0, item.find(":="));
		std::string value = item.substr(item.find(":=")+2, item.length());
		tmp.setValue(key, value);
	}	
	
	std::cout << tmp.generateTemplate() << std::endl;
    return 0;
}


