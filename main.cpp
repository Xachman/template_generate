#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cxxops.hpp"
#include "template.h"

char* getFilePath(int argc, char **argv);
void getDefinitions(int argc, char **argv, char **defs);

int main(int argc, char **argv) {
	std::vector<std::string> keys;
	cxxopts::Options options("Template Parse", "Parse Templates using mustache like syntax");
	options.add_options()
	  ("d,debug", "Enable debugging")
	  ("f,file", "File name", cxxopts::value<std::string>())
	  ("k,key", "Key value", cxxopts::value<std::vector<std::string>>(keys))
	  ;
	auto result = options.parse(argc, argv);

	std::string file = result["f"].as<std::string>();

	options.parse_positional({"k,key"});


	std::cout << file << std::endl;
	std::cout << keys[0] << std::endl;
	std::cout << keys[1] << std::endl;

    return 0;
}
