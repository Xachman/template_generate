#ifndef TEMPLATE_H_ 
#define TEMPLATE_H_

typedef struct Template {
    char name[255];
    char filepath[4096];
} Template;

Template NewTemplate(char filepath[]);

#endif 