#ifndef TEMPLATE_H_ 
#define TEMPLATE_H_

#include <string>

class Template {
    private:
        std::string name;
        std::string filepath;
		std::string subject;
    public:
        Template(std::string name, std::string filepath);
        Template(const std::string &subject);
        std::string getFilepath();
        std::string getName();
		std::string generateTemplate();
		void setValue();
};

Template NewTemplate(char filepath[]);

#endif 