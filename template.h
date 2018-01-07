#ifndef TEMPLATE_H_ 
#define TEMPLATE_H_

#include <string>
#include <map>

class Template {
    private:
        std::string name;
        std::string filepath;
		std::string subject;
		std::map<std::string, std::string> items;
    public:
        Template(std::string name, std::string filepath);
        Template(const std::string &subject);
        std::string getFilepath();
        std::string getName();
		std::string generateTemplate();
		void setValue(std::string key, std::string value);
};

Template NewTemplate(char filepath[]);

#endif 