#ifndef TEMPLATE_H_ 
#define TEMPLATE_H_

#include <string>

class Template {
    private:
        std::string name;
        std::string filepath;
    public:
        Template(std::string name, std::string filepath);
        std::string getFilepath();
        std::string getName();
};

Template NewTemplate(char filepath[]);

#endif 