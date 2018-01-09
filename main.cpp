#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cxxops.hpp"
#include "template.h"

char* getFilePath(int argc, char **argv);
void getDefinitions(int argc, char **argv, char **defs);

int main(int argc, char **argv) {

	cxxopts::Options options("Template Parse", "Parse Templates using mustache like syntax");
	options.add_options()
	  ("d,debug", "Enable debugging")
	  ("f,file", "File name", cxxopts::value<std::string>())
	  ;
	auto result = options.parse(argc, argv);

	std::string file = result["f"].as<std::string>();
	std::cout << file << std::endl;

    return 0;
}
